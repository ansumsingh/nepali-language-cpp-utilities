#!/bin/bash

#set -ex

script=$1

DOCKER_IMAGE_TAG=nepaliunicodecpp-build-env

image_created=$(docker image ls | grep "${DOCKER_IMAGE_TAG}")
echo "${image_created}"
if [ "${image_created}" == "" ]
then
  pushd scripts
    ls

    docker build --build-arg USERNAME=${USER} -t ${DOCKER_IMAGE_TAG} . 
  popd
fi

docker run -v $(pwd):/workspace 
            -v /home/${USER}/.cache:/home/${USER}/.cache 
            -w /workspace -i -u $UID:$GID 
            -t ${DOCKER_IMAGE_TAG}