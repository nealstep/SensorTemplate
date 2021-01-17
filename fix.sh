#!/bin/bash

if [ $# -ne 1 ] ; then
    echo "Usage: fix NAME"
    exit 1
fi

name=$1
nameU=${name^^};
nameL=${name,,};

sed -e "s/SENSOR_/${nameU}_/g" -e "s/sensor_/${nameL}_/g" \
    < include/sensor.h.orig > include/${nameL}.h
sed -e "s/sensor_/${nameL}_/g" -e "s/sensor\./${nameL}./g" \
    < src/sensor.cpp.orig > src/${nameL}.cpp
sed -e "s/sensor_/${nameL}_/g" -e "s/sensor\./${nameL}./g" \
    < src/main.cpp.orig > src/main.cpp

