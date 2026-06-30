from decimal import Decimal
from hashlib import md5

from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad

leak = 4336282047950153046404
ct = '7863c63a4bb2c782eb67f32928a1deceaee0259d096b192976615fba644558b2ef62e48740f7f28da587846a81697745'
ct = bytes.fromhex(ct)

for a in range(10**5, int(10**5.5)):
    for p in range(4):
        K = int(Decimal(str(a) + "." + str(leak))**2) + p
        # print(f"Found K = {K}")
        cipher = AES.new(md5(f"{K}".encode()).digest(), AES.MODE_ECB)
        try:
            pt = cipher.decrypt(ct)
            if b'uiu' in pt:
                print(pt)
        except:
            continue
    
# b'uiuctf{SQu4Re_Ro0T5_AR3nT_R4nD0M}\x0f\x0f\x0f\x0f\x0f\x0f\x0f\x0f\x0f\x0f\x0f\x0f\x0f\x0f\x0f'