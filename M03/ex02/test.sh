#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

echo "=== M03/ex02 FragTrap Test ==="

make re 2>&1
if [ $? -ne 0 ]; then
	echo -e "${RED}Compilation failed${NC}"
	exit 1
fi
echo -e "${GREEN}Compilation OK${NC}"

./fragtrap > output.txt 2>&1
echo "Program output:"
cat output.txt
echo ""

PASS=0
FAIL=0

check_msg() {
	if grep -q "$1" output.txt; then
		echo -e "  ${GREEN}[PASS]${NC} $1"
		PASS=$((PASS + 1))
	else
		echo -e "  ${RED}[FAIL]${NC} $1"
		FAIL=$((FAIL + 1))
	fi
}

echo "Checking output messages..."
check_msg "ClapTrap Fraggy constructed!"
check_msg "FragTrap Fraggy constructed!"
check_msg "ClapTrap Fraggy attacks Enemy, causing 30 points of damage!"
check_msg "FragTrap Fraggy requests a high five!"
check_msg "ClapTrap Fraggy takes 40 points of damage!"
check_msg "ClapTrap Fraggy repairs itself, gaining 25 hit points!"
check_msg "FragTrap Fraggy destroyed!"
check_msg "ClapTrap Fraggy destroyed!"

echo ""
echo "Results: $PASS passed, $FAIL failed"
[ $FAIL -eq 0 ] && echo -e "${GREEN}All tests passed!${NC}" || echo -e "${RED}Some tests failed${NC}"

make fclean > /dev/null 2>&1
rm -f output.txt

exit $FAIL