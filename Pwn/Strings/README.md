# Strings | NoobMaster

Description - I love Strings! Do you? Let me know!

# Writeup
This challenge has a format string vulnreability. Note that the fake_flag is actually a global variable and can be overwritten. The solution is to overwrite fake_flag by "%s" so when main2 function does printf(fake_flag), it actually does printf("%s") and hence leaking the flag which is stored on the stack. solve script at `solve/exploit.py`

# - Flag - n00bz{f0rm4t_5tr1ng5_4r3_th3_b3s7!!!!!}