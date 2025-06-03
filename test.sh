#!/bin/bash

# Simple test for pipex

GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m" # Reset

echo -e "${GREEN}Compiling...${NC}"
make re || exit 1

echo -e "${GREEN}Creating input file...${NC}"
echo -e "Bonjour\nHello\nSalut" > infile.txt

echo -e "${GREEN}Running: ./pipex infile.txt \"grep Bonjour\" \"wc -l\" outfile.txt${NC}"
./pipex infile.txt "grep Bonjour" "wc -l" outfile.txt

EXPECTED="1"
ACTUAL=$(cat outfile.txt)

if [ "$ACTUAL" == "$EXPECTED" ]; then
	echo -e "${GREEN}✅ Test passed: '$ACTUAL' == '$EXPECTED'${NC}"
else
	echo -e "${RED}❌ Test failed: '$ACTUAL' != '$EXPECTED'${NC}"
fi

rm -f infile.txt outfile.txt
