# deobfuscate original chall.py
import hashlib

SNEEZE_FORK = "AurumPotabileEtChymicumSecretum"
BLOCK_SIZE = 8 

def keygen(seed):
    key = {}
    key_hash = hashlib.sha256(seed.encode()).digest() 
    key['flibber'] = list(key_hash[:BLOCK_SIZE])
    key['twizzle'] = list(key_hash[BLOCK_SIZE:BLOCK_SIZE+16])
    glimbo = list(key_hash[BLOCK_SIZE+16:])
    S = list(range(256))
    i = 0
    for _ in range(256): 
        for z in glimbo:
            j = (i + z) % 256
            S[i], S[j] = S[j], S[i]
            i = (i + 1) % 256
    key['drizzle'] = S
    return key

def encrypt_block(block, key):
    if len(block) != BLOCK_SIZE:
        raise ValueError(f"Must be {BLOCK_SIZE} wumps for crankshaft.")
    Sbox_key_third = bytes([key['drizzle'][x] for x in block])
    key_second = key['twizzle']
    third_X_second = bytes([Sbox_key_third[i] ^ key_second[i % len(key_second)] for i in range(BLOCK_SIZE)])
    key_first = key['flibber'] 
    key_first_srt = sorted([(key_first[i], i) for i in range(BLOCK_SIZE)])
    zort = [oof for _, oof in key_first_srt]
    ct = [0] * BLOCK_SIZE
    for y in range(BLOCK_SIZE):
        x = zort[y]
        ct[y] = third_X_second[x]
    return bytes(ct)

def encrypt(plaintext, key):
    pad = BLOCK_SIZE - (len(plaintext) % BLOCK_SIZE)
    if pad == 0: 
        pad = BLOCK_SIZE
    plaintext += bytes([pad] * pad)
    ciphertext = b""
    for b in range(0, len(plaintext), BLOCK_SIZE):
        block = plaintext[b:b+BLOCK_SIZE]
        zap = encrypt_block(block, key)
        ciphertext += zap
    return ciphertext

def main():
    try:
        with open("flag.txt", "rb") as f:
            flag_content = f.read().strip()
    except FileNotFoundError:
        print("Error: flag.txt not found. Create it with the flag content.")
        return

    if not flag_content:
        print("Error: flag.txt is empty.")
        return

    print(f"Original Recipe (for generation only): {flag_content.decode(errors='ignore')}")

    key = keygen(SNEEZE_FORK)
    encrypted_recipe = encrypt(flag_content, key)

    with open("encrypted.txt", "w") as f_out:
        f_out.write(encrypted_recipe.hex())

    print(f"\nEncrypted recipe written to encrypted.txt:")
    print(encrypted_recipe.hex())

if __name__ == "__main__":
    main()