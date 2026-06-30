// findkey.cpp
#include <iostream>
#include <fstream>
#include <map>
#include <omp.h>
#include <inttypes.h>
#include <vector>
#include <utility>

using namespace std;

constexpr int rounds = 100000;

typedef uint8_t Byte;

typedef uint16_t Word;

typedef uint32_t RKey;

typedef uint64_t Key;

Byte Sbox[256] = { 58, 66, 209, 131, 35, 82, 37, 249, 78, 74, 129, 168, 244, 207, 155, 102, 175, 22, 248, 63, 24, 172, 114, 4, 216, 105, 116, 44, 196, 137, 42, 45, 118, 110, 124, 90, 139, 119, 56, 238, 3, 121, 65, 112, 30, 146, 36, 202, 94, 19, 163, 188, 68, 104, 170, 10, 227, 16, 69, 165, 210, 41, 52, 8, 115, 240, 49, 197, 174, 195, 89, 134, 246, 43, 62, 91, 199, 83, 96, 101, 223, 92, 11, 128, 7, 99, 160, 225, 109, 28, 47, 204, 190, 14, 192, 86, 226, 181, 140, 54, 2, 239, 200, 171, 71, 184, 254, 29, 23, 85, 141, 176, 222, 189, 205, 122, 72, 87, 81, 211, 133, 117, 6, 169, 130, 212, 247, 25, 156, 127, 31, 93, 67, 142, 206, 107, 158, 95, 60, 12, 193, 27, 79, 232, 229, 177, 149, 100, 167, 243, 235, 20, 26, 32, 46, 231, 40, 157, 34, 230, 253, 18, 153, 80, 213, 39, 159, 125, 64, 203, 241, 138, 220, 132, 53, 147, 98, 97, 0, 185, 123, 77, 150, 218, 161, 136, 13, 61, 173, 21, 111, 251, 50, 221, 208, 250, 15, 178, 182, 59, 70, 194, 214, 236, 33, 75, 108, 9, 255, 38, 113, 5, 217, 237, 224, 152, 215, 201, 242, 164, 198, 145, 144, 57, 186, 106, 245, 233, 162, 126, 103, 143, 135, 120, 84, 180, 228, 154, 76, 219, 234, 183, 88, 1, 252, 51, 166, 48, 191, 148, 151, 55, 73, 17, 179, 187 };

Byte invSbox[256] = { 178, 243, 100, 40, 23, 211, 122, 84, 63, 207, 55, 82, 139, 186, 93, 196, 57, 253, 161, 49, 151, 189, 17, 108, 20, 127, 152, 141, 89, 107, 44, 130, 153, 204, 158, 4, 46, 6, 209, 165, 156, 61, 30, 73, 27, 31, 154, 90, 247, 66, 192, 245, 62, 174, 99, 251, 38, 223, 0, 199, 138, 187, 74, 19, 168, 42, 1, 132, 52, 58, 200, 104, 116, 252, 9, 205, 238, 181, 8, 142, 163, 118, 5, 77, 234, 109, 95, 117, 242, 70, 35, 75, 81, 131, 48, 137, 78, 177, 176, 85, 147, 79, 15, 230, 53, 25, 225, 135, 206, 88, 33, 190, 43, 210, 22, 64, 26, 121, 32, 37, 233, 41, 115, 180, 34, 167, 229, 129, 83, 10, 124, 3, 173, 120, 71, 232, 185, 29, 171, 36, 98, 110, 133, 231, 222, 221, 45, 175, 249, 146, 182, 250, 215, 162, 237, 14, 128, 157, 136, 166, 86, 184, 228, 50, 219, 59, 246, 148, 11, 123, 54, 103, 21, 188, 68, 16, 111, 145, 197, 254, 235, 97, 198, 241, 105, 179, 224, 255, 51, 113, 92, 248, 94, 140, 201, 69, 28, 67, 220, 76, 102, 217, 47, 169, 91, 114, 134, 13, 194, 2, 60, 119, 125, 164, 202, 216, 24, 212, 183, 239, 172, 193, 112, 80, 214, 87, 96, 56, 236, 144, 159, 155, 143, 227, 240, 150, 203, 213, 39, 101, 65, 170, 218, 149, 12, 226, 72, 126, 18, 7, 195, 191, 244, 160, 106, 208 };

Word S_f(Word in)
{
	return (Sbox[in >> 8] << 8) | Sbox[in & 0xff];
}

Word P_f(Word in)
{
	int r = 3;

	Word out = 0;
	out |= (in >> 8) & 0xff;
	out |= (in & 0xff) << 8;
	out ^= out >> 8;
	
	Word out2 = 0;
	out2 |= out >> r;
	out2 |= out << (16 - r);

	return out2;
}

Word S_f_inv(Word in)
{
    return (invSbox[in >> 8] << 8) | invSbox[in & 0xff];
}

Word P_f_inv(Word in)
{
    int r = 3;
    Word out2 = 0;
    out2 |= in >> (16 - r);
    out2 |= in << r;

    Word out = out2;
    out ^= out >> 8;
    out = (out << 8) | (out >> 8);
    return out;
}

uint16_t G(uint16_t in, uint16_t kin)
{
    return P_f(S_f(in ^ kin));
}

uint16_t round(uint16_t in, uint32_t kin)
{
	uint32_t k = kin;
	in ^= (k & 0xffff) ^ ((k >> 16) & 0xffff);
	return P_f(S_f(in));
}

uint16_t round_inv(uint16_t in, uint32_t kin)
{
    uint32_t k = (kin & 0xffff) ^ ((kin >> 16) & 0xffff);
    return S_f_inv(P_f_inv(in)) ^ (k & 0xffff);
}

uint16_t G_inv(uint16_t ct, uint32_t key)
{
    uint32_t key1 = key ^ 3811777446;
    key1 = (key1 * 1240568533);

    uint32_t key2 = key ^ 3915669785;
    key2 = (key2 * 1247778533);

    uint32_t key3 = key ^ 3140176925;
    key3 = (key3 * 1934965865);

    return round_inv(round_inv(round_inv(ct, key3), key2), key1);
}

int main()
{
    std::vector<std::pair<uint16_t, uint16_t>> pairs;
    pairs.push_back({ 46797, 26174});
    pairs.push_back({ 33355, 8806 });
    pairs.push_back({ 12127, 30892});
    pairs.push_back({ 36367, 9717});
    pairs.push_back({ 44727, 24673});
    pairs.push_back({ 3529, 47408});
    pairs.push_back({ 31925, 20694});
    pairs.push_back({ 28137, 56468});
    pairs.push_back({ 52803, 52774});
    pairs.push_back({ 44410, 46131});
    pairs.push_back({ 45425, 12595});
    pairs.push_back({ 54554, 26552});
    pairs.push_back({ 12635, 58598});
    pairs.push_back({ 12932, 46831});
    pairs.push_back({ 8597, 32794});
    pairs.push_back({ 62968, 279});
    pairs.push_back({ 26520, 54428});
    pairs.push_back({ 13693, 32325});
    pairs.push_back({ 49153, 21047});
    pairs.push_back({ 11475, 62360});

    int T = pairs.size();

    std::vector<uint16_t> pts = {};
    std::vector<uint16_t> cts = {};
    uint16_t O[65536] = { 0 };
    for (uint16_t i = 0; i < T; i++) 
    {
        pts.push_back(pairs[i].first);
        cts.push_back(pairs[i].second);
    }

    for (uint16_t i = 0; i < T; i++)
    {
        if(S_f_inv(S_f(pts[i])) != pts[i])
        {
            cout << "S_f_inv wrong!" << endl;
            return 1;
        }
        if (P_f_inv(P_f(pts[i])) != pts[i])
        {   
            cout << "P_f_inv wrong!" << endl; 
            return 1;
        }
        if (round_inv(round(pts[i], 0xdeadbeaf), 0xdeadbeaf) != pts[i])
        {   
            cout << "round_inv wrong!" << endl; 
            return 1;
        }
    }

    for (uint16_t i = 0; i < T; i++)
    {
        for (uint32_t key0 = 0; key0 < 0x10000; key0++)
            O[P_f(S_f(pts[i] ^ key0))] = key0;

        for (uint16_t j = 0; j < T; j++)
        {
            if (i == j) continue;

            #pragma omp parallel for
            for (uint32_t key = 0; key < 0x1000000; key++)
            {
                uint32_t key0 = S_f_inv(P_f_inv(G_inv(pts[j], key))) ^ pts[i];

                uint32_t key1 = key ^ 3811777446;
                key1 = (key1 * 1240568533);

                uint32_t key2 = key ^ 3915669785;
		        key2 = (key2 * 1247778533);

                uint32_t key3 = key ^ 3140176925;
		        key3 = (key3 * 1934965865);

                uint16_t rk0 = (key0 & 0xffff);
                uint16_t rk1 = ((key1 >> 16) & 0xffff) ^ (key1 & 0xffff);
                uint16_t rk2 = ((key2 >> 16) & 0xffff) ^ (key2 & 0xffff);
                uint16_t rk3 = ((key3 >> 16) & 0xffff) ^ (key3 & 0xffff);

                uint16_t c = cts[i];
                c = P_f(S_f(c ^ rk0));
                c = P_f(S_f(c ^ rk1));
                c = P_f(S_f(c ^ rk2));
                c = P_f(S_f(c ^ rk3));
                if (c == cts[j])
                {
                    uint16_t pt = pts[0];
                    for (uint16_t r = 0; r < (100000 / 4); r++)
                    {
                        pt = G(G(G(G(pt, rk0), rk1), rk2), rk3);
                    }
                    if (pt == cts[0])
                    {
                        uint16_t pt2 = pts[15];
                        for (uint16_t r = 0; r < (100000 / 4); r++)
                        {
                            pt2 = G(G(G(G(pt2, rk0), rk1), rk2), rk3);
                        }
                        if (pt2 == cts[15])
                        {
                            cout << "Found key!" << endl;
                            cout << rk0 << ", " << rk1 << ", " << rk2 << ", " << rk3 << endl;
                            exit(0);
                        }
                    }
                    
                }
            }
        }
    }
    return 0;
}