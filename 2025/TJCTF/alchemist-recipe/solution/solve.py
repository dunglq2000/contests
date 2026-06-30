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

def decrypt_block(block, key):
    if len(block) != BLOCK_SIZE:
        raise ValueError(f"Must be {BLOCK_SIZE} wumps for crankshaft.")
    key_second = key['twizzle']
    key_first = key['flibber'] 
    key_first_srt = sorted([(key_first[i], i) for i in range(BLOCK_SIZE)])
    zort = [oof for _, oof in key_first_srt]
    
    third_X_second = [0] * BLOCK_SIZE

    for y in range(BLOCK_SIZE):
        x = zort[y]
        third_X_second[x] = block[y]
    Sbox_key_third = bytes([third_X_second[i] ^ key_second[i % len(key_second)] for i in range(BLOCK_SIZE)])
    
    return bytes([key['drizzle'].index(x) for x in Sbox_key_third])

key = keygen(SNEEZE_FORK)

with open("encrypted.txt") as f:
    ct = bytes.fromhex(f.read())
    print(b''.join(decrypt_block(ct[i:i+8], key) for i in range(0, len(ct), 8)))