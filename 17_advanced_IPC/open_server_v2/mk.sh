#!/bin/bash

if [ "$1" == "" ];then
	make -C ./build/ all install
elif [ "$1" == "-c" ];then
	cmake -B ./build/
fi

