#!/bin/bash

# Compile
make re 2>&1 || { echo "Compilation failed"; exit 1; }

# Run and capture output
OUTPUT=$(./fixed)
echo "$OUTPUT"

# Check for expected messages
echo ""
echo "=== Verifying output ==="

if echo "$OUTPUT" | grep -q "Default constructor called"; then
    echo "[OK] Default constructor message found"
else
    echo "[FAIL] Default constructor message missing"
    exit 1
fi

if echo "$OUTPUT" | grep -q "Copy constructor called"; then
    echo "[OK] Copy constructor message found"
else
    echo "[FAIL] Copy constructor message missing"
    exit 1
fi

if echo "$OUTPUT" | grep -q "Copy assignment operator called"; then
    echo "[OK] Copy assignment operator message found"
else
    echo "[FAIL] Copy assignment operator message missing"
    exit 1
fi

if echo "$OUTPUT" | grep -q "Destructor called"; then
    echo "[OK] Destructor message found"
else
    echo "[FAIL] Destructor message missing"
    exit 1
fi

# Check output values (should be 0 three times)
VALUE_COUNT=$(echo "$OUTPUT" | grep -c "^0$")
if [ "$VALUE_COUNT" -eq 3 ]; then
    echo "[OK] Output is 0 three times"
else
    echo "[FAIL] Expected 3 zeros, got $VALUE_COUNT"
    exit 1
fi

echo ""
echo "All tests passed!"

make fclean 2>&1 > /dev/null