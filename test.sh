#!/bin/bash

echo "ls" | ./42sh c
if [ $? == 0 ]
then
    echo "TEST : PASSED"
else
    echo "TEST : FAILED"
fi
echo

echo "ls ; ls -a" | ./42sh c
if [ $? == 0 ]
then
    echo "TEST : PASSED"
else
    echo "TEST : FAILED"
fi
echo

echo "ls ; ls | grep src | wc -l" | ./42sh c
if [ $? == 0 ]
then
    echo "TEST : PASSED"
else
    echo "TEST : FAILED"
fi
echo

echo "ls | grep src | wc -l ; ls" | ./42sh c
if [ $? == 0 ]
then
    echo "TEST : PASSED"
else
    echo "TEST : FAILED"
fi
echo

echo "ls ; ls -a ; ls | grep src | wc -l ; ls ; cd include ; ls" | ./42sh c
if [ $? == 0 ]
then
    echo "TEST : PASSED"
else
    echo "TEST : FAILED"
fi
echo

echo "ls | grep src | wc -l ; ls -a" | ./42sh c
if [ $? == 0 ]
then
    echo "TEST : PASSED"
else
    echo "TEST : FAILED"
fi
echo

echo "cd include ; ls ; cd .. ; ls ; pwd ; ls | grep src | wc -l ; ls -a" | ./42sh c
if [ $? == 0 ]
then
    echo "TEST : PASSED"
else
    echo "TEST : FAILED"
fi
echo

echo "cd include ; ls ; cd .. ; ls -a ; pwd ; ls | grep src | wc -l ; id ; who" | ./42sh c
if [ $? == 0 ]
then
    echo "TEST : PASSED"
else
    echo "TEST : FAILED"
fi
echo

echo "ls ; ls -a ; ls | grep src | wc -l" | ./42sh c
if [ $? == 0 ]
then
    echo "TEST : PASSED"
else
    echo "TEST : FAILED"
fi
echo