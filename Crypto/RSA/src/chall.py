#!/usr/bin/env python3
from Crypto.Util.number import *
import time
flag = bytes_to_long(b'n00bz{5m4ll_3_1s_n3v3r_g00d!}')
e = 17
p = getPrime(1024)
q = getPrime(1024)
n = p*q
ct = pow(flag,e,n)
time.sleep(0.5)
print(f'{e = }')
print(f'{ct = }')
print(f'{n = }')



