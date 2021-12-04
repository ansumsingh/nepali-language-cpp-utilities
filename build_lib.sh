#!/bin/bash

set -ex

script=$1
DOCKER_IMAGE_TAG=nepaliunicodecpp-build-env

pushd scripts
ls

docker build -t ${DOCKER_IMAGE_TAG} .

popd