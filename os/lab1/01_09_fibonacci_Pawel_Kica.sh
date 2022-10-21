#!/bin/bash
read -p "Podaj liczbe " input
el1=0
el2=1
echo "Fibonacci:"
for (( x=0; x<input; x++ ))
do
    echo "$el1"
    next=$((el1 + el2))
    el1=$el2
    el2=$next
done