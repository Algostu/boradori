#!/bin/bash

./build.sh $1

if [ "$?" = 0 ]
then 
	./output/$1
fi
