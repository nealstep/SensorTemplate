#!/bin/bash

if [ $# -ne 1 ] ; then
    echo "Usage: fix NAME"
    exit 1
fi

name=$1
nameU=${name^^};
nameL=${name,,};

echo $nameU
echo $nameL

sed -e "s/SENSOR_/${nameU}_/g" -e "s/sensor_/${nameU}_/g" \
    < include/sensor.h > include/${nameL}.h
sed -e "s/sensor_/${nameL}_/g" -e "s/sensor\./${nameL}./g" \
    < src/sensor.cpp > src/${nameL}.cpp
sed -e "s/sensor_/${nameL}_/g" -e "s/sensor\./${nameL}./g" \
    < src/main.cpp > src/main_n.cpp
mv include/sensor.h include/sensor.h.old
mv include/sensor.cpp include/sensor.cpp.old
mv include/main.cpp include/main.cpp.old
mv include/main_n.cpp include/main.cpp


