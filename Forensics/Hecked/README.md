# Hecked

- Description: 
Someone hacked my server :(
Can you please find out how?
Note: Flag is n00bz{md5sum(vulnerableService_serviceVersion_attackersFirstCommand)}
Replace the md5sum(...) with the ACTUAL MD5SUM of the above when you find it, like so: `echo -n vulnerableService_serviceVersion_attackersFirstCommand | md5sum`
Also, case and underscores are important!

dump.pcap:dump.pcap

# Write up

The given file is a pcap file, so open it up in Wireshark. Looking at the packets, there is only 1 main service: FTP. The name is 'vsFTPd' and version is '2.3.4'. The first command the attacker runs is 'id'. Putting this together, we get: 
```bash
echo -n vsFTPd_2.3.4_id | md5sum # a806fef72a92508b7a64776bb83ad4cb
```

# Flag - n00bz{a806fef72a92508b7a64776bb83ad4cb}
