#!/bin/bash


build_dir=$(ls -d */ | grep "build")
set -ex
echo "${build_dir}"

if [ "${build_dir}" == "" ]
then
  mkdir build 
  pushd build
  conan install ../conan
  popd
fi

pushd build
ls
cmake .. -DCMAKE_MODULE_PATH=${PWD}

cmake --build .

ctest -V
popd