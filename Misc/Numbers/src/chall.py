#!/usr/bin/env python3
import random
import time
starting_time=int(time.time())
def solve(x,y):
	possible = []
	answer = 0
	for i in range(1,y):
		possible.append(str(i))
	for i in possible:
		answer += i.count(str(x))
	return answer
for i in range(1,101):
	difficulty1 = 25
	difficulty2 = 1000
	print(f'Round {i}!')
	x = random.randrange(0,10)
	y = random.randint(difficulty1,difficulty2)
	current_time = int(time.time())
	if current_time - starting_time > 60:
		print("Time's up!")
		exit()
	user_answer =  int(input(f"How many {x}'s appear till {y}?\n"))
	correct_answer = solve(x,y)
	if user_answer == correct_answer:
		print("Moving On!")
		difficulty1 += difficulty1
		difficulty2 += difficulty2
	else:
		print("Incorrect!")
		exit()
	if i == 100:
		print(open('flag.txt').read())


