From i386/ubuntu

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update -qq
RUN apt-get install -y automake build-essential vim less git bison gawk flex wget curl qemu-system-i386

RUN mkdir -p /srv/tftp/
RUN mkdir -p /build/
COPY / /build/

RUN apt purge -y texinfo gcc-7
RUN apt install -y gcc-4.8 && ln -sf /usr/bin/gcc-4.8 /usr/bin/gcc && hash -r

RUN cd /build/compile \
  && make 
