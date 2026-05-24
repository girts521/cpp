#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

echo "=== M03/ex01 ScavTrap Test ==="

make re 2>&1
if [ $? -ne 0 ]; then
	echo -e "${RED}Compilation failed${NC}"
	exit 1
fi
echo -e "${GREEN}Compilation OK${NC}"

./scavtrap > output.txt 2>&1
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
check_msg "ClapTrap Guardian constructed!"
check_msg "ScavTrap Guardian constructed!"
check_msg "ScavTrap Guardian attacks Bandit, causing 20 points of damage!"
check_msg "ScavTrap Guardian is now in Gate keeper mode!"
check_msg "ClapTrap Guardian takes 30 points of damage!"
check_msg "ClapTrap Guardian repairs itself, gaining 15 hit points!"
check_msg "ScavTrap Guardian destroyed!"
check_msg "ClapTrap Guardian destroyed!"

echo ""
echo "Results: $PASS passed, $FAIL failed"
[ $FAIL -eq 0 ] && echo -e "${GREEN}All tests passed!${NC}" || echo -e "${RED}Some tests failed${NC}"

make fclean > /dev/null 2>&1
rm -f output.txt

exit $FAIL