#!/bin/bash

g++ -lboost_system -std=c++11 -I/home/estinox/lib/curlpp/include/ $*.cpp -o $*.exe

echo "done"
