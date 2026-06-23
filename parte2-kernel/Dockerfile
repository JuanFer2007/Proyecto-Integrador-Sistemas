FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    nasm \
    grub-pc-bin \
    grub-common \
    xorriso \
    gcc \
    make \
    && rm -rf /var/lib/apt/lists/*

VOLUME /root/env
WORKDIR /root/env
