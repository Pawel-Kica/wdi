#!/bin/bash
if [ $1 -gt $2 ]
then
    echo "Arg2 (max) must be greater than Arg1 (min)"
else
    random=$(shuf -i $1-$2 -n 1)
    echo $var
    chances=3
    counter=0
    res=0

    while (( chances > counter ))
    do
        read -p "Jaka liczba przychodzi ci na myśl? " input
        if (( input == random ))
        then
            res=1
            echo "udalo ci sie zgadnac"
            break
        else
            echo "sprobuj jeszcze raz"
        fi
        counter=$(( $counter + 1 ))
    done
    
    if  [ $res -eq 0 ]
    then
        echo "koniec prób"
    else
        echo "brawo!!!"
    fi
fi