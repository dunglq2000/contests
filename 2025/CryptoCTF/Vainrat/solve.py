from sage.all import *

nbit = 110
prec = 4 * nbit
R = RealField(prec)

# from pwn import remote, context

# context.log_level = 'Debug'

# pr = remote("91.107.252.0", "11117")

# pr.recvuntil(b'We know y0 = ')
# y0 = pr.recvline().strip().decode()

# y = [y0]
# x = ['0']

# for _ in range(19):
#     pr.sendlineafter(b'[Q]uit\n', b'c')
#     data = pr.recvline().strip()
#     # print(data)
#     if b'Unf' in data:
#         x.append('-1')
#         y.append('-1')
#     else:
#         x.append('-1')
#         y.append(data[8:].decode())

# print(y)

# pr.close()

y = ['0.836527775208345090080146664028740144926291676477683423207482580416835263616170796791375112480019072451850118476761591559486200579844', '-1', '-1', '-1', '-1', '-1', '-1', '-1', '-1', '-1', '-1', '-1', '-1', '-1', '0.783148587094686607911709903287537605988456617240230312373349425173193644071185620875521529186768280538401070957990100396407046472752', '-1', '-1', '0.783148586907817253176196211303437560223212490465805021911225110809377008400957647264354069956080421931533551448456344326492383418985', '0.783148586905592618001149431465371627748742302543511508061551322622024372512617138022173053226966666139745231886543985477454793793802', '-1']
y = [R(i) for i in y]

x = [R(-1)] * len(y)

end = len(y) - 1
while y[end] == -1:
    end -= 1

for i in range(end, 0, -1):
    if y[i - 1] == -1:
        y[i - 1] = R(y[i]**2) / R(x[i])
        x[i - 1] = 2 * R(x[i]) - R(y[i - 1])
    else:
        x[i] = R(y[i]**2) / R(y[i - 1])
        x[i - 1] = 2 * R(x[i]) - R(y[i - 1])

assert len(str(x[0])) == len(str(y[0]))
assert y[0] > x[0]

from Crypto.Util.number import long_to_bytes

for i in range(10, 200):
    m = long_to_bytes(int(R(x[0]) * 10**i))
    if b'CCTF' in m:
        print(i, m)