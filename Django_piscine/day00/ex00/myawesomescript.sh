#!/bin/sh

if [ $1 ]; then
curl -s $1 | grep "href=" > file.txt
cut -f 2 -d \" file.txt
rm -fr file.txt
fi
