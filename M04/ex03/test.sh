#!/bin/bash
cd "$(dirname "$0")"
make re
echo ""
echo "=== Running interface tests ==="
./interface
echo ""
if command -v valgrind &> /dev/null; then
    echo ""
    echo "=== Memory check ==="
    valgrind --leak-check=full --show-leak-kinds=all ./interface 2>&1 | tail -10
fi
make fclean
