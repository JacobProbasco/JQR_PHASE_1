#! /usr/bin/python

def printSomething(x):
    print "I am a function printing thisThing: {0}" .format(x)

def thisThing():
    return 1
    
printSomething(thisThing())

