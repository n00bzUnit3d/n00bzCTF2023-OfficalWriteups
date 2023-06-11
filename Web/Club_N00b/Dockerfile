FROM ubuntu:latest

# Install some libs
# RUN apt-get update && apt-get -y install python socat
RUN apt-get update && apt-get -y install xinetd
# RUN apt-get install -y lib32z1 libseccomp-dev xinetd

# create ctf-user
RUN groupadd -r ctf && useradd -r -g ctf ctf

#add chall items
#ADD chall_init.sh /etc/chall_init.sh
# COPY public /home/ctf/
COPY yee/ /home/ctf/
# COPY chall /home/ctf/chall
# COPY xinetd /etc/xinetd.d/xinetd
# ADD redir.sh /home/ctf/redir.sh

#set some proper permissions
RUN chown -R root:ctf /home/ctf
RUN chmod 750 /home/ctf/club_n00b
RUN chmod 440 /home/ctf/static/*
# RUN chmod 644 /etc/xinetd.d/xinetd
# RUN chown root:root /etc/xinetd.d/xinetd

USER ctf
# COPY challenge.py .
# CMD socat TCP-LISTEN:2021,reuseaddr,fork EXEC:"./chall"
# CMD ["sh", "/home/ctf/entrypoint.sh"]
CMD ["/home/ctf/club_n00b"]

