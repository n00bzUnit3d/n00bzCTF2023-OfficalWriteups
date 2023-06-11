FROM ubuntu:latest

RUN apt-get update && apt-get -y install python3 python3-pip
RUN groupadd -r ctf && useradd -r -g ctf ctf

COPY templates/ /home/ctf/templates/
COPY uploads /home/ctf/uploads
COPY requirements.txt /home/ctf/requirements.txt
COPY server.py /home/ctf/server.py


RUN chown -R root:ctf /home/ctf
RUN chmod 555 -R /home/ctf/server.py
RUN chmod 777 -R /home/ctf/uploads/
RUN chmod 777 -R /home/ctf/templates/
RUN chmod 555 /home/ctf/templates/1.html
RUN chmod 555 /home/ctf/templates/2.html
RUN chmod 555 /home/ctf/templates/3.html
RUN chmod 555 /home/ctf/templates/index.html

RUN python3 -m pip install -r /home/ctf/requirements.txt

# RUN export FLAG="n00bz{th@t5_50m3_fr3@ky_5tuff}"
# TODO add flag as env var

USER ctf
CMD ["python3", "/home/ctf/server.py"]
