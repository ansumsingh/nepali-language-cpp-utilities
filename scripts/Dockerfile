FROM ubuntu:18.04
ARG USERNAME=1000
ARG USER_UID=1000
ARG USER_GID=$USER_UID
ARG DEBIAN_FRONTEND=noninteractive

RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME

RUN apt update && apt install -y g++ \
    curl \
    cmake \
    unzip \
    zip \
    tar \
    git \
    gdb \
    apt-transport-https \
    gnupg \
    python3-pip

RUN pip3 install conan

