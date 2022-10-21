#!/bin/bash
echo $1^$2 | bc

podstawa=$1
potega=$2
wynik=1

while [ $potega -gt 0 ]
do
    wynik=$(( $wynik * $podstawa ))
    potega=$(( $potega - 1 ))
done

echo $wynik
