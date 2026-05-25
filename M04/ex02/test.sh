#!/bin/bash
cd "$(dirname "$0")"
make re
echo ""
echo "=== Running abstract class tests ==="
./abstract
echo ""
if command -v valgrind &> /dev/null; then
    echo ""
    echo "=== Memory check ==="
    valgrind --leak-check=full --show-leak-kinds=all ./abstract 2>&1 | tail -5
fi
make fclean
