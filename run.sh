#!bin/bash

echo Checking File status

if [ -f "$PWD"/"$1" ]; 
then

	echo Compilling $1
	gcc $1 -o .bashrun
	echo Program compilled
	echo
	./.bashrun
	echo
	rm .bashrun
	echo End of script

else

	echo File $1 not found

fi
