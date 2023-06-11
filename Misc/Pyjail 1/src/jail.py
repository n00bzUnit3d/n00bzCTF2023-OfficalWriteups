#!/usr/bin/env python3
blacklist = ["/","0","1","2","3","4","5","6","7","8","9","setattr","compile","globals","os","import","_","breakpoint","exit","lambda","eval","exec","read","print","open","'","=",'"',"x","builtins","clear"]
print("="*25)
print(open(__file__).read())
print("="*25)
print("Welcome to the jail!")
print("="*25)

for i in range(2):
	x = input('Enter command: ')
	for c in blacklist:
		if c in x:
			print("Blacklisted word found! Exiting!")
			exit(0)
	exec(x)
