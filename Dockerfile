FROM ubuntu:14.04

RUN apt-get update 
RUN apt-get -y install software-properties-common python-pip

# ocpkg tool to install repositories and dependencies
COPY scripts/ocpkg scripts/install-dependencies-trusty\
    opencog/python/web/api/install_dependencies.sh /tmp/
RUN chmod +x /tmp/install-dependencies-trusty /tmp/install_dependencies.sh
RUN /tmp/install-dependencies-trusty
RUN /tmp/install_dependencies.sh

# Create and switch user. The user is privileged with no password required
RUN adduser --disabled-password --gecos "OpenCog Developer" opencog
RUN adduser opencog sudo
RUN echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers
USER opencog

# Tools
RUN sudo apt-get -y install git
RUN sudo apt-get -y install rlwrap
RUN sudo apt-get -y install telnet

# Environment
WORKDIR /home/opencog
CMD bash
EXPOSE 5000
