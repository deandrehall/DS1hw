#!/bin/bash
g++ -std=c++11 fibonacci.cpp -o fib.o
./fib.o 8
read ok
exit 0