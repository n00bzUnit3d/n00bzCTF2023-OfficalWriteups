FROM ubuntu:latest

# Install some libs
RUN apt-get update && apt-get -y install xinetd
RUN apt-get -y install python3 python3-pip

# create ctf-user
RUN groupadd -r ctf && useradd -r -g ctf ctf

#add chall items
COPY flag.txt /home/ctf/flag.txt
COPY requirements.txt /home/ctf/requirements.txt
COPY server.py /home/ctf/server.py
COPY xinetd /etc/xinetd.d/xinetd

#set some proper permissions
RUN chown -R root:ctf /home/ctf
RUN chmod 750 /home/ctf/server.py
RUN chmod 440 /home/ctf/flag.txt
RUN chmod 644 /etc/xinetd.d/xinetd
RUN chmod 440 /home/ctf/requirements.txt
RUN chown root:root /etc/xinetd.d/xinetd

RUN python3 -m pip install -r /home/ctf/requirements.txt

USER ctf
CMD ["python3", "server.py"]
