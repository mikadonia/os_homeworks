#!/bin/bash

gcc ex2.c
sysctl -a | grep machdep.cpu   | ./a.out ex2.txt
