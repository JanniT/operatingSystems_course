#!/bin/bash

# Printing the environment variables
echo "Environment variables:"
echo " "
printenv
echo ""

# Printing the positional parameters
echo "Positional parameters:"
echo " "
echo "Number of Positional Parameters (aguments): $#"
echo "Script Name: $0"
echo "All Positional Parameters: $@"
echo ""

# Printing the Special parameters
echo "Special parameters:"
echo " "
echo "Exit Status: $?"
echo "Process ID: $$"
echo "Last Background Process ID: $!"
echo "Options: $-"
echo "Shell Option Flags: $-"
echo ""
