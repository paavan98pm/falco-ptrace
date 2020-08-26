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
RUN wget https://dl.bintray.com/falcosecurity/deb/stable/falco-0.25.0-x86_64.deb
RUN apt install -y ./falco-0.25.0-x86_64.deb

RUN git clone https://github.com/paavan98pm/pdig.git
RUN git clone https://github.com/draios/sysdig.git
COPY . /falco-ptrace
RUN /falco-ptrace/bin/build
RUN apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*
CMD ["/falco-ptrace/bin/falco"]
