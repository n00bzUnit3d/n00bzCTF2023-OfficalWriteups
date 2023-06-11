# Flag Shop | NoobMaster

- Description: Come and buy yourself a flag!

# Writeup

It checks if your balance is more than the fake_flag, but not how many you buy. For eg if you buy 3, you get `$-50`. The trick is that it prints your balance as an integer(hence $-50) but actually it's an unsigned int and it underflows to become a very big number. Now you can easily buy the real flag!

# Flag - n00bz{5h0p_g0t_h3ck3d_4nd_fl4g_g0t_570l3n!}
