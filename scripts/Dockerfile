FROM ubuntu:18.04
ARG USERNAME=1000
ARG USER_UID=1000
ARG USER_GID=$USER_UID
ARG DEBIAN_FRONTEND=noninteractive

RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME

RUN apt update && apt install -y g++ \
    curl \
    unzip \
    zip \
    tar \
    git \
    gdb \
    apt-transport-https \
    gnupg \
    openjdk-11-jdk \
    wget

RUN wget https://github.com/bazelbuild/bazel/releases/download/4.2.2/bazel-4.2.2-installer-linux-x86_64.sh &&\
    chmod +x bazel-4.2.2-installer-linux-x86_64.sh &&\
    ./bazel-4.2.2-installer-linux-x86_64.sh

