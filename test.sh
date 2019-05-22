#!/bin/bash

echo "ls" | ./42sh c
if [ $? == 0 ]
then
    echo "ALLO J'ENVOIE"
else
    echo "RAYAYAIE"
fi
echo
echo "ls ; ls -a" | ./42sh c
if [ $? == 0 ]
then
    echo "ALLO J'ENVOIE"
else
    echo "RAYAYAIE"
fi
echo

echo "ls ; ls | grep src | wc -l" | ./42sh c
if [ $? == 0 ]
then
    echo "ALLO J'ENVOIE"
else
    echo "RAYAYAIE"
fi
echo

echo "ls | grep src | wc -l ; ls" | ./42sh c
if [ $? == 0 ]
then
    echo "ALLO J'ENVOIE"
else
    echo "RAYAYAIE"
fi
echo

echo "ls ; ls -a ; ls | grep src | wc -l ; ls ; cd include ; ls" | ./42sh c
if [ $? == 0 ]
then
    echo "ALLO J'ENVOIE"
else
    echo "RAYAYAIE"
fi
echo

echo "ls ; ls -a ; ls | grep src | wc -l" | ./42sh c
if [ $? == 0 ]
then
    echo "ALLO J'ENVOIE"
else
    echo "RAYAYAIE"
fi
echo

echo "ls | grep src | wc -l ; ls -a" | ./42sh c
if [ $? == 0 ]
then
    echo "ALLO J'ENVOIE"
else
    echo "RAYAYAIE"
fi
echo