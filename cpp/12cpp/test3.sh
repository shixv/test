#!/bin/zsh

testuser=shixv
if grep $testuser  /etc/passwd
then
	echo The zsh file for user $testuser are:
	ls -a /home/$testuser/.b*
fi
for para in $@; do
	echo $para
done
for state in `cat error.cpp`
do
	echo "Visit beautiful $state"
done
exit 0
