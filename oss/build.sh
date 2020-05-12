#!/bin/bash

if [ $# -ne 1 ]
then
	echo "select which file to build"
	exit 101
fi

if [ -e "$1.cpp" ]
then
	g++ -o ../output/$1 $1.cpp
else
	echo "$1.cpp is not found"
	exit 100
fi
