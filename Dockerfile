FROM ubuntu:latest AS base
LABEL maintainer="Paavan <paavan@protonmail.com>"
ARG DEBIAN_FRONTEND=noninteractive
RUN apt update \
	&& apt install -y --no-install-recommends \
    wget \
    cmake \
    make \
    build-essential \
    libyaml-0-2 \
    ca-certificates \
    ncat \
    git

COPY . /falco-ptrace
RUN /falco-ptrace/bin/build
RUN apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
CMD ["/falco-ptrace/bin/falco"]
