import subprocess
process = subprocess.Popen(['python3', r"chall.py"], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
for i in range(16):
    process.stdin.write(b'1\n3\n7\n')
    process.stdin.flush()

res = [int(process.stdout.readline().strip().decode().split()[-1]) for _ in range(16 * 3)]
print(res)

from string import ascii_uppercase as alpha
guess1, guess2, guess3 = 1 << 16, 3 << 16, 7 << 16
dp = {(guess1 % ord(c), guess2 % ord(c), guess3 % ord(c)): c for c in alpha}

for i in range(0, len(res), 3):
    process.stdin.write(dp[(res[i], res[i + 1], res[i + 2])].encode())
process.stdin.write(b'\n')
process.stdin.flush()
print(process.stdout.readline())