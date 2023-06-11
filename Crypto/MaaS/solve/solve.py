from pwn import *
io = process('../attachments/chall.py')
alpha = 'abcdefghijklmnopqrstuvwxyz'.upper()
to_guess = ''
for solve in range(16):
	factors1 = []
	factors2 = []
	factors3 = []
	for i in range(1,4):
		if i == 1:
			x = 1
		elif i == 2:
			x == 3
		elif i == 3:
			x = 7
		io.readuntil(b': ')
		io.sendline(str(x).encode())
		to_factor = (x << 16) - int(io.readline().strip())
		for j in range(1,to_factor-1):
			if i == 1:
				if to_factor % j == 0:
					factors1.append(j)
			elif i == 2:
				if to_factor % j == 0:
					factors2.append(j)
			elif i == 3:
				if to_factor % j == 0:
					factors3.append(j)	
	# print(factors1,factors2)
		common_factor = [i for i in factors1 if i in factors2 and i in factors3]
	# print(common_factor)
	for i in common_factor:
		if chr(i) in alpha:
			to_guess += chr(i)
print(to_guess)
io.sendline(to_guess.encode())
io.interactive()