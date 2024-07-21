#!/bin/bash

MAKEFILE_SOURCE=~/useful_scripts/files/Makefile
CPP_SOURCE=~/useful_scripts/files/AClass.cpp
HPP_SOURCE=~/useful_scripts/files/AClass.hpp

DESTINATION_DIR=$PWD

echo enter class name:
read CLASSNAME
echo copying files for class $CLASSNAME...


mkdir $DESTINATION_DIR/include
cp $MAKEFILE_SOURCE $DESTINATION_DIR
cp $CPP_SOURCE $DESTINATION_DIR
cp $HPP_SOURCE $DESTINATION_DIR

~/useful_scripts/files/replacer $DESTINATION_DIR/$CLASSNAME.cpp $CLASSNAME
~/useful_scripts/files/replacer $DESTINATION_DIR/include/$CLASSNAME.hpp $CLASSNAME
rm $DESTINATION_DIR/AClass.cpp
rm $DESTINATION_DIR/AClass.hpp
rm $DESTINATION_DIR/header

echo "Copied Makefile, $CLASSNAME.cpp, and $CLASSNAME.hpp to $DESTINATION_DIR :) happy coding!"
