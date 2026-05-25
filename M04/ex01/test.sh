#!/bin/bash
cd "$(dirname "$0")"
make re
echo ""
echo "=== Running brain tests ==="
./brain
echo ""
echo "=== Checking memory (valgrind if available) ==="
if command -v valgrind &> /dev/null; then
    valgrind --leak-check=full --show-leak-kinds=all ./brain 2>&1 | tail -5
fi
make fclean
