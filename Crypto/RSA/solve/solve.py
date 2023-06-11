from pwn import *
from sage.all import *
from Crypto.Util.number import *
from gmpy2 import iroot
n = []
ct = []
e = 17
for i in range(17):
	io = process('../src/chall.py')
	io.readuntil(b'ct = ')
	ct.append(int(io.readline().strip()))
	io.readuntil(b'n = ')
	n.append(int(io.readline().strip()))
M = crt(ct,n)
flag = long_to_bytes(iroot(M,e)[0])
print(flag)
