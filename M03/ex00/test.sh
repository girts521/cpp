#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

echo "=== M03/ex00 ClapTrap Test ==="

# Compile
make re 2>&1
if [ $? -ne 0 ]; then
	echo -e "${RED}Compilation failed${NC}"
	exit 1
fi
echo -e "${GREEN}Compilation OK${NC}"

# Run
./claptrap > output.txt 2>&1
echo "Program output:"
cat output.txt
echo ""

# Check key messages
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
check_msg "ClapTrap Clappy constructed!"
check_msg "ClapTrap Clappy attacks Target1, causing 0 points of damage!"
check_msg "ClapTrap Clappy takes 3 points of damage!"
check_msg "ClapTrap Clappy repairs itself, gaining 5 hit points!"
check_msg "ClapTrap NoEP has no energy/hit points to attack!"
check_msg "ClapTrap NoHP has no energy/hit points to attack!"
check_msg "ClapTrap NoHP has no energy/hit points to repair!"
check_msg "ClapTrap NoHP takes 10 points of damage!"
check_msg "ClapTrap Clappy destroyed!"
check_msg "ClapTrap NoEP destroyed!"
check_msg "ClapTrap NoHP destroyed!"

echo ""
echo "Results: $PASS passed, $FAIL failed"
[ $FAIL -eq 0 ] && echo -e "${GREEN}All tests passed!${NC}" || echo -e "${RED}Some tests failed${NC}"

# Cleanup
make fclean > /dev/null 2>&1
rm -f output.txt

exit $FAIL