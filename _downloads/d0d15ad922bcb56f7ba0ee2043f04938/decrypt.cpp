// decrypt.cpp
#include <iostream>
#include <fstream>
#include <map>
#include <omp.h>
#include "common.hpp"

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

int main()
{
    std::vector<uint16_t> cts = {
        12210, 15594, 18592, 47466, 23526, 48987, 44863,
        19536, 52633, 21435, 34703, 5383, 16355, 46571, 
        59850, 35352, 16108, 38178, 50671, 64648
    };

    uint16_t rk0 = 11892, rk1 = 8704, rk2 = 3384, rk3 = 38922;
    std::vector<uint16_t> pts = {};
    for (uint16_t i = 0; i < cts.size(); i++)
    {
        uint16_t pt = cts[i];
        for (uint16_t r = 0; r < (100000 / 4); r++)
        {
            pt = S_f_inv(P_f_inv(pt)) ^ rk3;
            pt = S_f_inv(P_f_inv(pt)) ^ rk2;
            pt = S_f_inv(P_f_inv(pt)) ^ rk1;
            pt = S_f_inv(P_f_inv(pt)) ^ rk0;
        }
        char x = pt & 0xff;
        char y = pt >> 8;
        std::cout << x << y;
    }
    std::cout << std::endl;

    return 0;
}