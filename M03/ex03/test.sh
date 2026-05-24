#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

echo "=== M03/ex03 DiamondTrap Test ==="

make re 2>&1
if [ $? -ne 0 ]; then
	echo -e "${RED}Compilation failed${NC}"
	exit 1
fi
echo -e "${GREEN}Compilation OK${NC}"

./diamondtrap > output.txt 2>&1
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
check_msg "ClapTrap Girts_clap_name constructed!"
check_msg "DiamondTrap Girts constructed!"
check_msg "DiamondTrap name: Girts, ClapTrap name: Girts_clap_name"
check_msg "ScavTrap Girts_clap_name attacks Target, causing 30 points of damage!"
check_msg "ScavTrap Girts_clap_name is now in Gate keeper mode!"
check_msg "FragTrap Girts_clap_name requests a high five!"
check_msg "ClapTrap Girts_clap_name takes 30 points of damage!"
check_msg "ClapTrap Girts_clap_name repairs itself, gaining 20 hit points!"
check_msg "DiamondTrap Girts destroyed!"
check_msg "DiamondTrap Girts assigned!"

echo ""
echo "Results: $PASS passed, $FAIL failed"
[ $FAIL -eq 0 ] && echo -e "${GREEN}All tests passed!${NC}" || echo -e "${RED}Some tests failed${NC}"

make fclean > /dev/null 2>&1
rm -f output.txt

exit $FAIL