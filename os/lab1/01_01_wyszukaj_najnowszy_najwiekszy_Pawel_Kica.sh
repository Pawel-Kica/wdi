#!/bin/bash

find $1 -type f -size +$2c -print0 | xargs -0 ls -alt | head -1 | tr -s " " | awk -F" " '{print $9}'