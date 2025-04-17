#!/usr/bin/env sh

ARG=$(seq 0 20 | shuf | tr '\n' ' ');

ARG="0
14
19
11
17
10
4
18
3"
make -s && ./push_swap $ARG    #| ./checker_linux $ARG)
