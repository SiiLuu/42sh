#!/bin/bash
##comment

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

echo "ls ; ls -a ; ls | grep src | wc -l" | ./42sh c
if [ $? == 0 ]
then
    echo "TEST : PASSED"
else
    echo "TEST : FAILED"
fi
echo

echo "ls ; ls -a ; ls | grep src | wc -l ; cd src ; ls -a ; cd .. ; ls -a" | ./42sh c
if [ $? == 0 ]
then
    echo "TEST : PASSED"
else
    echo "TEST : FAILED"
fi
echo