# Conditions | NoobMaster

Description - Come and get the flag... Only if you can pass this impossible to pass conditions!

# Writeup

Your input should be less than 40 characters but more than 50 characters which is impossible. The exploit is that it converts your input to uppercase before checking if it is more than 50 characters. Some special characters, like `ß` or `ﬃ`, when converted to uppercase, form two characters! For example `"ß".upper()` is 'SS' which is two characters. So if you give about 30 of `ß`, then the first check is passed because input is less than 40 and when converted to uppercase becomes 60 characters which passes the second check!

# Flag - n00bz{1mp0551bl3_c0nd1t10n5_m0r3_l1k3_p0551bl3_c0nd1t10ns}
