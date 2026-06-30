#include <iostream>
#include <inttypes.h>
#include <vector>
#include <omp.h>
#include <string.h>
#include <stdlib.h>

#include "SHA256.h"

uint32_t bytes_to_u32(uint8_t* in)
{
    uint32_t result = 0;
    for (int i = 0; i < 4; i++)
        result |= (in[i] << (24 - 8 * i));
    return result;
}

void u32_to_bytes(uint32_t in, uint8_t* out)
{
    for (int i = 0; i < 4; i++)
        out[i] = (in >> (24 - 8 * i)) & 0xff;
}

void u64_to_bytes(uint64_t in, uint8_t* out)
{
    for (int i = 0; i < 8; i++)
        out[i] = (in >> (56 - 8 * i)) & 0xff;
}

uint32_t rrot(uint32_t word, uint32_t i)
{
    i %= 32;
    word = word & 0xffffffff;
    return ((word >> i) | (word << (32 - i))) & 0xffffffff;
}

void get_sbox(uint8_t* word, uint8_t* target)
{
    uint8_t Sbox[] = { 17, 16, 19, 18, 21, 20, 23, 22, 25, 24, 27, 26, 29, 28, 31, 30, 1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14, 49, 48, 51, 50, 53, 52, 55, 54, 57, 56, 59, 58, 61, 60, 63, 62, 33, 32, 35, 34, 37, 36, 39, 38, 41, 40, 43, 42, 45, 44, 47, 46, 81, 80, 83, 82, 85, 84, 87, 86, 89, 88, 91, 90, 93, 92, 95, 94, 65, 64, 67, 66, 69, 68, 71, 70, 73, 72, 75, 74, 77, 76, 79, 78, 113, 112, 115, 114, 117, 116, 119, 118, 121, 120, 123, 122, 125, 124, 127, 126, 97, 96, 99, 98, 101, 100, 103, 102, 105, 104, 107, 106, 109, 108, 111, 110, 145, 144, 147, 146, 149, 148, 151, 150, 153, 152, 155, 154, 157, 156, 159, 158, 129, 128, 131, 130, 133, 132, 135, 134, 137, 136, 139, 138, 141, 140, 143, 142, 177, 176, 179, 178, 181, 180, 183, 182, 185, 184, 187, 186, 189, 188, 191, 190, 161, 160, 163, 162, 165, 164, 167, 166, 169, 168, 171, 170, 173, 172, 175, 174, 209, 208, 211, 210, 213, 212, 215, 214, 217, 216, 219, 218, 221, 220, 223, 222, 193, 192, 195, 194, 197, 196, 199, 198, 201, 200, 203, 202, 205, 204, 207, 206, 241, 240, 243, 242, 245, 244, 247, 246, 249, 248, 251, 250, 253, 252, 255, 254, 225, 224, 227, 226, 229, 228, 231, 230, 233, 232, 235, 234, 237, 236, 239, 238 };
    uint8_t result[256];

    SHA256 sha256;
    sha256.update(word, 4);
    auto words = sha256.digest();
    memcpy(result, &words[0], 32);

    for (int i = 0; i < 7; i++)
    {
        SHA256 sha;
        sha.update(result + 32 * i, 32);
        auto words = sha.digest();
        memcpy(result + 32 * (i + 1), &words[0], 32);
    }

    for (int i = 0; i < 256; i += 2)
    {
        uint8_t a = result[i];
        uint8_t b = result[i + 1];
        uint8_t old = Sbox[a];
        Sbox[a] = Sbox[b];
        Sbox[b] = old;
    }

    memcpy(target, Sbox, 256);
}

uint32_t lrot(uint32_t word, uint32_t i)
{
    i %= 32;
    word = word & 0xffffffff;
    return ((word << i) | (word >> (32 - i))) & 0xffffffff;
}

uint32_t r1(uint32_t in, const uint8_t* box)
{
    uint8_t s[4] = { 0 };
    u32_to_bytes(in, s);
    for (int i = 0; i < 4; i++)
        s[i] = box[s[i]];

    for (int i = 1; i < 4; i++)
        s[i] ^= s[i-1];

    return bytes_to_u32(s);
}

uint32_t r2(uint32_t in, const uint8_t* box)
{
    uint8_t s[4] = { };
    u32_to_bytes(in, s);
    for (int i = 0; i < 4; i++)
        s[i] = box[s[i]];

    for (int i = 2; i >= 0; i--)
        s[i] ^= s[i+1];

    return bytes_to_u32(s);
}

uint32_t r345(uint32_t word, uint32_t k, uint32_t rnum)
{
    word ^= rrot(word, -463 + 439 * rnum + -144 * rnum * rnum + 20 * rnum * rnum * rnum - rnum * rnum * rnum * rnum) ^ lrot(word, 63 + -43 * rnum + 12 * rnum * rnum + -rnum * rnum * rnum);

    word = (4124669716 + word * k);
    word = word * word * word;

    word ^= word << 5;
    word ^= word << 5;

    word ^= rrot(word, -463 + 439 * rnum + -144 * rnum * rnum + 20 * rnum * rnum * rnum - rnum * rnum * rnum * rnum) ^ lrot(word, 63 + -43 * rnum + 12 * rnum * rnum + -rnum * rnum * rnum);


    return rrot(word, -504 + 418 * rnum -499 * rnum * rnum + -511 * rnum * rnum * rnum + 98 * rnum * rnum * rnum * rnum) & 0xffffffff;
}

uint8_t sbox1[256] = { };
uint8_t sbox2[256] = { };

uint64_t encrypt(uint64_t p, uint64_t key)
{
    uint32_t k1 = key >> 32;
    uint32_t k2 = key & 0xffffffff;

    uint8_t t1[4];
    u32_to_bytes(k1, t1);

    get_sbox(t1, sbox1);

    uint32_t l = p >> 32;
    uint32_t r = p & 0xffffffff;

    // Round 1
    l ^= r2(r, sbox2);
    std::swap(l, r);

    // Round 2
    l ^= r1(r, sbox1);
    std::swap(l, r);

    // Round 3
    l ^= r345(r, k1, 3);
    std::swap(l ,r);

    // Round 4
    l ^= r345(r, k2, 4);
    std::swap(l, r);

    // Round 5
    l ^= r345(r, k1 ^ k2, 5);
    std::swap(l, r);

    // Round 6
    l ^= r345(r, k1, 6);
    std::swap(l, r);

    // Round 7
    l ^= r345(r, k2, 7);
    r ^= l;

    return ((uint64_t)l << 32) | (uint64_t)r;
}

bool test_function()
{
    uint8_t sbox[256] = { 166, 167, 220, 18, 21, 171, 88, 124, 101, 25, 27, 130, 12, 15, 212, 14, 1, 233, 3, 160, 5, 4, 26, 53, 9, 8, 245, 10, 91, 29, 248, 223, 253, 64, 51, 50, 6, 52, 221, 54, 72, 114, 96, 103, 135, 60, 63, 74, 161, 32, 116, 0, 77, 36, 39, 163, 41, 40, 43, 42, 222, 211, 47, 46, 168, 80, 83, 177, 229, 84, 121, 86, 228, 56, 31, 16, 93, 92, 139, 94, 76, 152, 67, 66, 58, 68, 71, 97, 156, 57, 107, 62, 90, 65, 102, 247, 113, 34, 13, 22, 117, 244, 119, 118, 87, 11, 123, 122, 125, 179, 127, 48, 82, 59, 99, 70, 45, 100, 38, 201, 95, 178, 112, 106, 78, 242, 111, 110, 108, 144, 147, 146, 149, 148, 249, 105, 153, 172, 155, 154, 150, 131, 234, 143, 129, 225, 85, 7, 28, 35, 73, 49, 210, 136, 30, 191, 141, 140, 158, 142, 199, 176, 104, 209, 170, 137, 183, 182, 185, 184, 238, 186, 189, 188, 126, 230, 134, 2, 69, 255, 181, 195, 37, 162, 169, 81, 20, 165, 173, 190, 175, 174, 164, 208, 213, 17, 252, 193, 215, 214, 194, 216, 219, 89, 55, 218, 115, 128, 157, 192, 204, 44, 197, 196, 227, 198, 79, 200, 203, 202, 180, 23, 207, 206, 241, 240, 243, 145, 120, 75, 109, 187, 33, 133, 251, 250, 151, 246, 24, 254, 217, 98, 224, 226, 61, 19, 231, 138, 132, 232, 235, 159, 237, 236, 239, 205 };

    if (r1(211416476, sbox) != 210016026) return false;
    if (r2(1111418300, sbox) != 2596923053) return false;
    if (rrot(2386637329, 13) != 2425123337) return false;
    if (lrot(171861653, 13) != 3436355911) return false;
    if (r345(2332062217, 0xdeadbeef, 5) != 3992978025) return false;
    return true;
}

bool check_k2(uint64_t ct0, uint64_t ct1, uint32_t k)
{
    uint32_t L7 = ct0 >> 32;
    uint32_t R7 = ct0 & 0xffffffff;
    uint32_t R6 = R7 ^ L7;
    uint32_t L6 = R7 ^ r345(R6, k, 7);

    uint32_t L7_ = ct1 >> 32;
    uint32_t R7_ = ct1 & 0xffffffff;
    uint32_t R6_ = R7_ ^ L7_;
    uint32_t L6_ = R7_ ^ r345(R6_, k, 7);

    if ((L6 ^ L6_) == 0x80000000)
    {
        return true;
    }
    return false;
}

std::vector<uint32_t> bruteforce_k2()
{
    uint64_t pts[] = { 2194090266659289430ULL, 15801510715588955136ULL, 195752496155878917ULL };
    uint64_t ct0s[] = { 5313144679078469543ULL, 1721352893315118722ULL, 6831354680889557863ULL };
    uint64_t ct1s[] = { 14587251420890060969ULL, 17919522859960426701ULL, 5659069971483530659ULL };


    std::vector<uint32_t> key2 = { };
    
    #pragma omp for
    for (uint64_t k = 0; k < 0x100000000; k++)
    {
        if (check_k2(ct0s[0], ct1s[0], (uint32_t)k))
        {
            if (check_k2(ct0s[1], ct1s[1], (uint32_t)k))
            {
                if (check_k2(ct0s[2], ct1s[2], (uint32_t)k))
                {
                    key2.push_back(k);
                }
            }
        }
    }

    return key2;
}