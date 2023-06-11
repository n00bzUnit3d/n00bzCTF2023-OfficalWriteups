#!/usr/bin/env python3

flag = [130, 37, 70, 115, 64, 106, 143, 34, 54, 134, 96, 98, 125, 98, 138, 104, 25, 3, 66, 78, 24, 69, 91, 80, 87, 67, 95, 8, 25, 22, 115]

for i in range(int(len(flag)/2)):
    if i % 2 == 0:
        t = flag[i] - 20
        flag[i] = flag[len(flag)-1-i] + 10
        flag[len(flag)-1-i] = t
    elif i % 2 == 1:
        flag[i] = flag[i] - 30

for i in range(len(flag)):
    if i % 2 == 0:
        flag[i] = flag[i] ^ 0x13
    else:
        flag[i] = flag[i] ^ 0x37

for i in flag:
    print(chr(i), end='')
print()
