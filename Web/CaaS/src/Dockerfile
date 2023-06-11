FROM ubuntu:latest

# Install some libs
# RUN apt-get update && apt-get -y install python socat
RUN apt-get update && apt-get -y install xinetd
RUN apt-get -y install python3 python3-pip curl
# RUN apt-get install -y lib32z1 libseccomp-dev xinetd

# create ctf-user
RUN groupadd -r ctf && useradd -r -g ctf ctf

#add chall items
#ADD chall_init.sh /etc/chall_init.sh
COPY templates/ /home/ctf/templates/
COPY flag.txt /home/ctf/flag.txt
COPY requirements.txt /home/ctf/requirements.txt
COPY server.py /home/ctf/server.py
COPY xinetd /etc/xinetd.d/xinetd
# ADD redir.sh /home/ctf/redir.sh

#set some proper permissions
RUN chown -R root:ctf /home/ctf
RUN chmod 550 /home/ctf/server.py
RUN chmod 440 /home/ctf/flag.txt
RUN chmod 444 /etc/xinetd.d/xinetd
RUN chmod 440 /home/ctf/requirements.txt
RUN chmod 440 /home/ctf/templates/*
RUN chown root:root /etc/xinetd.d/xinetd

RUN python3 -m pip install -r /home/ctf/requirements.txt

USER ctf
# COPY challenge.py .
# CMD socat TCP-LISTEN:2021,reuseaddr,fork EXEC:"./chall"
CMD ["python3", "server.py"]

