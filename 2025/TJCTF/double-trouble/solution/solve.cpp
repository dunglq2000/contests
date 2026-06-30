#include <stdint.h>
#include <stdio.h>
#include <omp.h>
#include "aes.hpp"

// https://github.com/kokke/tiny-AES-c.git

uint8_t target[16] = { (uint8_t) 113, (uint8_t) 37, (uint8_t) 56, (uint8_t) 62, (uint8_t) 51, (uint8_t) 12, (uint8_t) 105, (uint8_t) 44, (uint8_t) 117, (uint8_t) 224, (uint8_t) 238, (uint8_t) 8, (uint8_t) 134, (uint8_t) 236, (uint8_t) 119, (uint8_t) 121 };

void phex(uint8_t* str)
{
    unsigned char i;
    for (i = 0; i < 16; ++i)
        printf("%.2x", str[i]);
    printf("\n");
}

void double_encrypt(
    uint8_t* pt,
    uint8_t k20, uint8_t k21, uint8_t k22, uint8_t k23, uint8_t k24, uint8_t k25, uint8_t k26, uint8_t k27,
    uint8_t k40, uint8_t k41, uint8_t k42, uint8_t k43, uint8_t k44, uint8_t k45, uint8_t k46, uint8_t k47)
{
    uint8_t k1[8] = { (uint8_t) 157, (uint8_t) 121, (uint8_t) 177, (uint8_t) 163, (uint8_t) 127, (uint8_t) 49, (uint8_t) 128, (uint8_t) 28 };
    uint8_t key1[16];
    uint8_t key2[16];
    for (int i = 0; i < 8; i++)
    {
        key1[i] = k1[i];
        key2[i + 8] = k1[i];
    }

    uint8_t* ct = new uint8_t[16];

    for (int i = 0; i < 16; i++)
        ct[i] = pt[i];

    key1[8] = k20; key1[9] = k21; key1[10] = k22; key1[11] = k23; key1[12] = k24; key1[13] = k25; key1[14] = k26; key1[15] = k27;
    key2[0] = k40; key2[1] = k41; key2[2] = k42; key2[3] = k43; key2[4] = k44; key2[5] = k45; key2[6] = k46; key2[7] = k47;
    struct AES_ctx ctx1;
    AES_init_ctx(&ctx1, key1);
    AES_ECB_encrypt(&ctx1, ct);

    struct AES_ctx ctx2;
    AES_init_ctx(&ctx2, key2);
    AES_ECB_encrypt(&ctx2, ct);

    bool found = true;
    for (int i = 0; i < 16; i++)
    {
        if (ct[i] != target[i]) found = false;
    }
    if (found)
    {
        printf("Found solution\n");
        phex(key1);
        phex(key2);
    }
    delete[] ct;
}

int main()
{
    uint8_t choices[4] = { (uint8_t) 26, (uint8_t) 103, (uint8_t) 6, (uint8_t) 209 };
    uint8_t pt[16] = { (uint8_t) 101, (uint8_t) 120, (uint8_t) 97, (uint8_t) 109, (uint8_t) 112, (uint8_t) 108, (uint8_t) 101, (uint8_t) 9, (uint8_t) 9, (uint8_t) 9, (uint8_t) 9, (uint8_t) 9, (uint8_t) 9, (uint8_t) 9, (uint8_t) 9, (uint8_t) 9 };
#pragma omp parallel for
    for(uint8_t k20 : choices)
    {
        for(uint8_t k21 : choices)
        {
            for(uint8_t k22 : choices)
            {
                for(uint8_t k23 : choices)
                {
                    for(uint8_t k24 : choices)
                    {
                        for(uint8_t k25 : choices)
                        {
                            for(uint8_t k26 : choices)
                            {
                                for(uint8_t k27 : choices)
                                {
                                    for(uint8_t k40 : choices)
                                    {
                                        for(uint8_t k41 : choices)
                                        {
                                            for(uint8_t k42 : choices)
                                            {
                                                for(uint8_t k43 : choices)
                                                {
                                                    for(uint8_t k44 : choices)
                                                    {
                                                        for (uint8_t k45 : choices)
                                                        {
                                                            for (uint8_t k46 : choices)
                                                            {
                                                                for (uint8_t k47 : choices)
                                                                {
                                                                    double_encrypt(pt, k20, k21, k22, k23, k24, k25, k26, k27, k40, k41, k42, k43, k44, k45, k46, k47);
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}