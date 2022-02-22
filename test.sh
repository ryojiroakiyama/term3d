#!/bin/bash

make > /dev/null

err_files="./3dfiles/error/*"

for file in $err_files; do
  echo q | ../term3D $file 2> log.txt > /dev/null
  if [ -s log.txt ]; then
    printf -- "${file}\t\033[32mOK\x1b[0m \n"
  else
    printf -- "${file}\t\e[31mNG\x1b[0m \n"
  fi
done

rm log.txt
