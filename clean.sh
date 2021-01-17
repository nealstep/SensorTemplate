#!/bin/bash

if [ $# -ne 1 ] ; then
    echo "Usage: fix NAME"
    exit 1
fi

name=$1
nameL=${name,,};

rm -f include/${nameL}.h
rm -f src/${nameL}.cpp
rm -f src/main.cpp

