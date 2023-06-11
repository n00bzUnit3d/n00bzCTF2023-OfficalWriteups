FROM ubuntu:latest

# Install some libs
RUN apt-get update && apt-get -y install xinetd

# create ctf-user
RUN groupadd -r ctf && useradd -r -g ctf ctf

# add chall items
COPY flag.txt /home/ctf/flag.txt
COPY flag_shop /home/ctf/flag_shop
COPY xinetd /etc/xinetd.d/xinetd

# set some proper permissions
RUN chown -R root:ctf /home/ctf
RUN chmod 750 /home/ctf/flag_shop
RUN chmod 440 /home/ctf/flag.txt
RUN chmod 644 /etc/xinetd.d/xinetd
RUN chown root:root /etc/xinetd.d/xinetd

USER ctf
CMD ["/usr/sbin/xinetd", "-dontfork"]
