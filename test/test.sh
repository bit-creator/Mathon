#!/bin/bash

cd ..
./Mathon -rb
cd test

rm -rf main

 clang++-14\
 -std=c++20\
 -stdlib=libc++\
 -fmodules\
 -O3\
 -fPIC\
 -Wall\
 -Wextra\
 -fmath-errno\
 -march=native\
 -ffast-math\
 -fcxx-exceptions\
 -fprebuilt-module-path=../precompiled/ \
 main.cpp -o main

./main