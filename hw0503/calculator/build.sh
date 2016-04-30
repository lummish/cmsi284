#!/bin/bash

clear

nasm -felf64 calc-ops.asm
gcc calc-ops.o add.c -o add
gcc calc-ops.o gcd.c -o gcd
gcc calc-ops.o power.c -o power
echo "Enter [add, gcd, power] {x} {y}"
