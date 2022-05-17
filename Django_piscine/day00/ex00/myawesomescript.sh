#!/bin/sh

if [ $1 ]; then
curl -s $1 | grep "href=" | cut -f 2 -d \"
fi
