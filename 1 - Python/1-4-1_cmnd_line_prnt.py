#! /usr/bin/python

import sys

#Command-line arguments
def command_line():
    for x in sys.argv[1:]:
        print(x)

command_line()