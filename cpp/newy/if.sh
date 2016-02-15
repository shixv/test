#!/bin/zsh

if [ -f /bin/bash ]
then
	echo "file /bin/bash exists"
fi

if [ -d /bin/bash ]
then
	echo "/bin/bash is adirectory"
else
	echo "/bin/bash is NOT a directory"
fi
