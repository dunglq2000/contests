n = 0x61fa1a034c0e0ccc45401a3c32d12d979495aa793e5604ce415af536e4a89806cecae51af7a813d9a2eb662d1353a85621974d9f6fbb8f92d0a870be566a8c18229d964b51228824c1b4bfb3d8e57cebaecd6ade79832a73f745b09e96c5979dfd15f09b0d768a9651d64e8ebd4c603afd37c9a38297d35712d01c3afbedba866eaacf741f8789f6aaf2a9768d90c3235f6da5f49abcaa6a72578a9db97565e1bd58f99aad41d3bafefcfb632d6090f2e88e45312faec54557285a95747acea1aa61c3c6a638ab9793bb023df27c2fbd2c3ac66e8fafda6be50c64aeaed1a6b524faa854c5e12eb5cf8d42eaa8876606034ad238330e8946fa21274776e2e1b9
e = 0x10001
c = 0x526b82b209c8ab7a5e1384879849692369fc605980bdbf7674d287244648fd4effe2651a602bb6912c098701db1091d170154442a070169821781f129a0e5d8ee35ed666572c7412fcf3cc26f0aaa33705fad0bb55a77a7adff7c731cc819deb099c88c1c60eba150490534a04bdef8acbded68add6b70bffccd2a44f641daaee1abac57bb75a265c4af855e108dd06ced2ca341fb23b921885f163b49cb546cfe35fff464ea82df0665dedec6faf38aa8f0b5379105e72c7f370df9810b72db782e8e383eb16cd12cd403e3e7fce8a18ab37dce458745b8fbf9035029e5b2fc718c0649a3297c63e78a51566f4bd13db293ad26f9ff344c615870e71c27d2a4
v = (2, 5, 1, 4, 1, 4, 5, 2, 6, 0, 1, 6, 3, 4, 4, 5, 2, 2, 6, 2, 0, 3, 3, 2, 3, 5, 2, 6, 5, 1, 6, 6, 3, 0, 4, 3, 2, 1, 3, 1, 6, 4, 0, 2, 3, 3, 6, 3, 0, 5, 2, 0, 2, 4, 0, 1, 1, 2, 4, 4, 4, 0, 6, 1, 2, 5, 4, 2, 4, 4, 6, 6, 0, 5, 4, 1, 2, 6, 3, 1, 2, 2, 6, 3, 2, 6, 6, 0, 5, 5, 5, 3, 2, 4, 2, 5, 0, 0, 6, 3, 2, 2, 6, 2, 2, 6, 1, 3, 1, 2, 4, 0, 5, 2, 3, 6, 3, 1, 6, 6, 3, 6, 1, 1, 4, 2, 5, 2, 6, 0, 5, 2, 2, 0, 4, 5, 0, 4, 3, 0, 5, 1, 5, 1, 2, 4, 2, 3, 4, 0, 3, 1, 3, 3, 4, 1, 1, 5, 2, 1, 6, 3, 1, 2, 3, 3, 4, 0, 4, 2, 2, 0, 5, 2, 6, 6, 6, 3, 3, 6, 4, 3, 6, 2, 4, 3, 4, 2, 6, 1, 1, 2, 0, 1, 1, 5, 6, 4, 4, 6, 4, 1, 5, 6, 6, 6, 6, 3, 5, 3, 5, 4, 4, 6, 1, 1, 1, 4, 0, 4, 4, 2, 2, 5, 1, 0, 3, 6, 5, 3, 1, 2, 2, 3, 3, 4, 1, 3, 0, 3, 0, 1, 5, 3, 0, 2, 0, 0, 1, 0, 5, 2, 3, 2, 6, 6, 5, 2, 5, 5, 1, 2, 4, 5, 4, 3, 1, 6, 2, 2, 0, 3, 0, 2, 5, 5, 5, 2, 5, 5, 2, 2, 0, 0, 5, 6, 4, 3, 4, 3, 1, 4, 1, 3, 2, 0, 1, 4, 1, 0, 4, 4, 1, 4, 6, 1, 5, 3, 3, 6, 3, 1, 6, 3, 0, 3, 2, 0, 0, 6, 1, 3, 1, 1, 6, 3, 2, 3, 2, 1, 6, 2, 0, 6, 2, 4, 0, 0, 4, 0, 1, 2, 1, 1, 4, 5, 4, 2, 5, 0, 6, 1, 0, 3, 4, 5, 6, 4, 2, 4, 4, 6, 0, 2, 5, 0, 0)

p, q = [], []

def bruteforce(k):
    # print(f"{k = }")
    if k == len(v) - 1:
        pp = sum(j * 7**i for i, j in enumerate(p))
        qq = sum(j * 7**i for i, j in enumerate(q))
        if pp * qq == n:
            print(f"Found!\np = {pp}\nq = {qq}")
            d = pow(e, -1, (pp - 1) * (qq - 1))
            m = pow(c, d, n)
            print(m.to_bytes(m.bit_length() // 8 + 1, 'big'))
    else:
        pp = sum(j * 7**i for i, j in enumerate(p))
        qq = sum(j * 7**i for i, j in enumerate(q))
        
        for a in range(7):
            b = (v[k] - a) % 7
            pp = 7**k * a + pp
            qq = 7**k * b + qq
            if (n - pp * qq) % 7**(k) == 0:
                p.append(a)
                q.append(b)
                bruteforce(k + 1)
                p.pop()
                q.pop()

bruteforce(0)
