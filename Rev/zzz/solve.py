#!/usr/bin/env python3
# Flag: n00bz{ZzZ_zZZ_zZz_ZZz_zzZ_Zzz}
from z3 import *

secret = [BitVec(f"secret_{i}", 8) for i in range(30)]
s = Solver()

for i in range(6, 29):
    s.add(secret[i] >= 65)
    s.add(secret[i] <= 123)

s.add(secret[0] == ord('n'))
s.add(secret[1] == ord('0'))
s.add(secret[2] == ord('0'))
s.add(secret[3] == ord('b'))
s.add(secret[4] == ord('z'))
s.add(secret[5] == ord('{'))
s.add(secret[29] == ord('}'))

s.add(secret[0] >> 4 == 6)
s.add((secret[1] ^ secret[2]) == 0)
s.add((secret[3] | secret[6]) == 122)
s.add((secret[3] & secret[6]) == 66)
s.add(secret[4] ^ secret[28] == 0)
s.add(secret[5] * secret[29] * 0x1337 == 75629625)
s.add((secret[6] + secret[7] + secret[8]) == 302)
s.add(((secret[6] * secret[7]) - secret[8]) == 10890)
s.add((secret[9] - secret[8]) == 5)
s.add((secret[10] - secret[9]) == 27)
s.add((secret[11] ^ secret[10]) == 32)
s.add(secret[12] - secret[15] == 0)
s.add(secret[12] + secret[11] == 180)
s.add(secret[13] + secret[12] == 185)
s.add((secret[13] + secret[14] - secret[16]) == secret[13])
s.add(secret[16] + secret[17] == 217)
s.add(secret[17] ^ secret[13] == 0)
s.add(secret[18] == secret[19])
s.add(secret[18] == 90)
s.add((secret[19] ^ secret[20] ^ secret[21]) == 127)
s.add(secret[21] == 95)
s.add((secret[20] ^ secret[21] ^ secret[22]) == secret[21])
s.add((~secret[23] + secret[24]) == -33)
s.add(secret[24] + secret[6] == 180)
s.add(secret[25] == secret[9])
s.add(secret[26] + secret[27] == 212)
s.add(secret[27] == secret[28])


print(s.check())
m = s.model()

for i in range(30):
    print(chr(m[secret[i]].as_long()), end='')
print()
