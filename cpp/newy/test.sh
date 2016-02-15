#!/bin/zsh

read string

if [ -n $string ]
then
	echo $string is not null
fi
if [ -z $string ]
then
	echo $string is null
fi

exit 0
