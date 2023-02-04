#!/usr/bin/bash

for i in `ls -D`
do
	echo "Cleaning x64 for project" $i
	rm -rf $i/.vs
	rm -rf $i/$i/x64
	rm -rf $i/x64
done
