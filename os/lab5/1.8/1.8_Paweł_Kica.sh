#!/bin/bash
#./main.sh <directory>
if [ $# -ne 1 ]; then
  exit 1
fi
dir=$1
files=$(find $dir -type f -exec stat -c "%A %n" {} \; | sed 's/^.\///g' | awk '{print $1 " " $NF}')
while read -r file; do
  permissions=$(echo $file | awk '{print $1}')
  count=$(echo "$files" | grep -c '$permissions')
  echo "$permissions $count"
done <<< "$files"
