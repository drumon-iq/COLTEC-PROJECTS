#!/bin/bash
clear
echo Checking File status

if [ -f "$PWD"/"$1" ]; 
then

	echo Compilling $1
	gcc $1 -o .bashrun -Wall -lm
	echo Program compilled
	echo ========================================================================================================
	echo
	./.bashrun
	echo
	rm .bashrun
	echo ========================================================================================================
	echo End of script

else

	echo File $1 not found

fi
