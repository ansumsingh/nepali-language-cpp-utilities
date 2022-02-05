#!/bin/bash

#set -ex

script=$1

DOCKER_IMAGE_TAG=nepali-language-util-cpp-build-env

image_created=$(docker image ls | grep "${DOCKER_IMAGE_TAG}")

if [ "${image_created}" == "" ]
then
  pushd scripts
    ls

    docker build --build-arg USERNAME=${USER} -t ${DOCKER_IMAGE_TAG} . 
  popd
fi

if [ "${script}" != "" ]
then
  docker run -v $(pwd):/workspace \
              -v /home/${USER}:/home/${USER} \
              -w /workspace -i -u $UID:$GID \
              -t ${DOCKER_IMAGE_TAG}  \
              /workspace/${script} 
else
  docker run -v $(pwd):/workspace \
              -v /home/${USER}:/home/${USER} \
              -w /workspace -i -u $UID:$GID \
              -t ${DOCKER_IMAGE_TAG}  
fi
