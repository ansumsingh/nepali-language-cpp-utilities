#!/bin/bash

#set -ex

build_dir=$(ls -d | grep build)
echo "${build_dir}"
if [ "${build_dir}" == "" ]
then
  mkdir build
  conan install ../conan
fi

pushd build
ls
cmake .. -DCMAKE_MODULE_PATH=${PWD}

cmake --build .

ctest -V
popd