#!/bin/bash

HEADER=include/AllHeaders.hpp
echo "#pragma once" > $HEADER
DIR="include"
for file in $DIR/*.hpp
do
    if [ $file != "include/AllHeaders.hpp" ]; then
        echo "#include \"$(basename "$file")\"" >> $HEADER
    fi
done
