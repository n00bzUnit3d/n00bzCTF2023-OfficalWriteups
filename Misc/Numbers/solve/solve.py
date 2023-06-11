from pwn import *
# io = process('../src/chall.py')
io = remote('challs.n00bzunit3d.xyz', 13541)
def solve(x,y):
	possible = []
	answer = 0
	for i in range(1,y):
		possible.append(str(i))
	for i in possible:
		answer += i.count(str(x))
	return answer
for i in range(1,101):
	if i > 1:
		io.readline()
	io.readline()
	io.readuntil(b'How many ')
	line = io.readline().strip()
	x = chr(int(line[0]))
	y = int(line.replace(f"{x}'s appear till ".encode(),b"").replace(b"?",b""))
	answer = solve(x,y)
	io.sendline(str(answer).encode())
io.interactive()