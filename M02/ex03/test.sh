#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'
PASS=0
FAIL=0

rm -f main.o Fixed.o Point.o bsp.o
rm -f "$NAME"

echo "=== Compiling BSP ==="
c++ -Wall -Wextra -Werror -std=c++98 -c main.cpp -o main.o
c++ -Wall -Wextra -Werror -std=c++98 -c Fixed.cpp -o Fixed.o
c++ -Wall -Wextra -Werror -std=c++98 -c Point.cpp -o Point.o
c++ -Wall -Wextra -Werror -std=c++98 -c bsp.cpp -o bsp.o
c++ -Wall -Wextra -Werror -std=c++98 -o bsp main.o Fixed.o Point.o bsp.o
echo ""

./bsp 2>&1 | tee bsp_output.txt
echo ""

echo "=== Verifying BSP results ==="
while IFS= read -r line; do
    if echo "$line" | grep -q "\[FAIL\]"; then
        echo -e "${RED}[FAIL]${NC} $line"
        FAIL=$((FAIL + 1))
    elif echo "$line" | grep -q "\[OK\]"; then
        echo -e "${GREEN}[OK]${NC} $line"
        PASS=$((PASS + 1))
    fi
done < bsp_output.txt

rm -f bsp_output.txt

echo ""
echo -e "${GREEN}${PASS} passed${NC}, ${RED}${FAIL} failed${NC}"
rm -f main.o Fixed.o Point.o bsp.o bsp
exit $FAIL