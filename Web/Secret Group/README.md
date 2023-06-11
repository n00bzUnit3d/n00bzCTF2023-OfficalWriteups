# Secret Group | NoobMaster

- Description: To get the flag, you must be a member of the secret group!

# Writeup

When you go on the website, it says "Not an agent of the n00bz-4dm1n secure browser!". So using a tool like burpsuite, change your `User-Agent` to `n00bz-4dm1n`. Upon visiting the website again, it says "Does not Accept fl4g". So change your `Accept` to `fl4g`. Upon visiting the website again, it says "Connection not s3cur3". So change your `Connection` to `s3cur3`. Upon visiting the website again, it says "Not refered by s3cr3t.n00bz-4dm1n.xyz". So add a new header `Referer` and set the value to `s3cr3t.n00bz-4dm1n.xyz`. Make sure that referer header has the first letter uppercase. This is actually a header so you can find the exact header by searching it up. Upon visiting the website again, it says "Give-Flag is not 7ru3". So add another header, `Give-Flag` and set it to `7ru3`. Upon visiting the website again, you will get the flag!

# Flag - n00bz{y0u_4r3_n0w_4_v4l1d_m3mb3r_0f_th3_s3cr3t_gr0up!}
