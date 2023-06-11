#!/bin/bash
fcrackzip -v -u -D -p /usr/share/wordlists/rockyou.txt ../attachments/flag.zip # see that the password is '1337h4x0r'
unzip ../attachments/flag.zip # type the password '1337h4x0r'
pdfcrack -f flag.pdf -w /usr/share/wordlists/rockyou.txt # see that the password is 'noobmaster'
xdg-open flag.pdf # Enter the password 'noobmaster'
# Get the flag!
