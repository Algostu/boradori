#!/bin/bash

if [ $# -ne 1 ]
then
	echo "빌드할 파일을 찾을 수 없음"
	exit 101
fi

if [ -e "$1.cpp" ]
then
	g++ -o ../output/$1 $1.cpp
else
	echo "$1.cpp를 찾을 수 없음" 
	exit 100
fi
