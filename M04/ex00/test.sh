#!/bin/bash
cd "$(dirname "$0")"
make re
echo ""
echo "=== Running polymorphism tests ==="
./polymorphism
echo ""
echo "=== Testing memory leaks ==="
make fclean
