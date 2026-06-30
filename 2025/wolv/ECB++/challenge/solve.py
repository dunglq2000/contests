from pwn import remote, process, context

# context.log_level = 'Debug'

pr = remote("ecbpp.kctf-453514-codelab.kctf.cloud", "1337")
# pr = process(["python", "chal.py"])
known = b'wctf{1_m4d3_th15_fl4G_r34lly_l0ng_s0_th4t_y0u_w0ulD_h4v3_t0_d34L_w1t'

for i in range(128 - 2):
    for ch in range(32, 127):
        pr.recvline()
        pr.sendline(b"Y")
        pr.recvline()
        padding = b'A' * (95 - len(known))
        payload = padding + known + bytes([ch]) + padding
        pr.sendline(payload)
        pr.recvuntil(b"Your message is:  ")
        ct = pr.recvline().strip()
        ct = bytes.fromhex(ct.decode())
        if ct[:96] == ct[96:96*2]:
            print(f"Found at index {i} character {ch}")
            known = known + bytes([ch])
            break
    print(known)

print(known)

# wctf{1_m4d3_th15_fl4G_r34lly_l0ng_s0_th4t_y0u_w0ulD_h4v3_t0_d34L_w1th_muL7iPl3_bl0cKs_L0L}
