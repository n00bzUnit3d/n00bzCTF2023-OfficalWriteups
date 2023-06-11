# MaaS | NoobMaster

- Description: Welcome to MaaS - Modulo as a Service!

# Writeup

So basically let's say I send `1`, I actually send `1<<16` which is `65536`. Now lets say 65536%x = 61. X is the value of the character we need to find. so (65536-61)%x=0, hence x is a factor of 65536-61. Sending different numbers, for eg 3 and 7, gives us different responses. Doing the same thing above(subtracting the result from the input) and then finding factors, we only have one common factor (in the range of the ascii characters) between all three of our inputs. So doing this and finding common factors yields us the flag!

Solve script at `solve/solve.py`
Unintended solve by my teammate(rabbitsthecat) at `solve/unintended_solve.py`

# Flag - n00bz{M0dul0_f7w_1a4d3f5c!}