#!/bin/bash

EXPECTED="Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
Destructor called"

# Compile
make re 2>&1 || { echo "Compilation failed"; exit 1; }

# Run and capture output
OUTPUT=$(./fixed)
echo "$OUTPUT"

echo ""
echo "=== Verifying expected output ==="

# Check key values
if echo "$OUTPUT" | grep -q "a is 1234.43"; then
    echo "[OK] a float value correct"
else
    echo "[FAIL] a float value mismatch"
    exit 1
fi

if echo "$OUTPUT" | grep -q "b is 10"; then
    echo "[OK] b int value correct"
else
    echo "[FAIL] b int value mismatch"
    exit 1
fi

if echo "$OUTPUT" | grep -q "c is 42.4219"; then
    echo "[OK] c float value correct"
else
    echo "[FAIL] c float value mismatch"
    exit 1
fi

if echo "$OUTPUT" | grep -q "d is 10"; then
    echo "[OK] d copy correct"
else
    echo "[FAIL] d copy mismatch"
    exit 1
fi

if echo "$OUTPUT" | grep -q "a is 1234 as integer"; then
    echo "[OK] a toInt correct"
else
    echo "[FAIL] a toInt mismatch"
    exit 1
fi

if echo "$OUTPUT" | grep -q "b is 10 as integer"; then
    echo "[OK] b toInt correct"
else
    echo "[FAIL] b toInt mismatch"
    exit 1
fi

if echo "$OUTPUT" | grep -q "c is 42 as integer"; then
    echo "[OK] c toInt correct"
else
    echo "[FAIL] c toInt mismatch"
    exit 1
fi

if echo "$OUTPUT" | grep -q "d is 10 as integer"; then
    echo "[OK] d toInt correct"
else
    echo "[FAIL] d toInt mismatch"
    exit 1
fi

# Check constructor messages
if echo "$OUTPUT" | grep -q "Default constructor called"; then
    echo "[OK] Default constructor"
else
    echo "[FAIL] Default constructor missing"
    exit 1
fi

if echo "$OUTPUT" | grep -q "Int constructor called"; then
    echo "[OK] Int constructor"
else
    echo "[FAIL] Int constructor missing"
    exit 1
fi

if echo "$OUTPUT" | grep -q "Float constructor called"; then
    echo "[OK] Float constructor"
else
    echo "[FAIL] Float constructor missing"
    exit 1
fi

echo ""
echo "All tests passed!"

make fclean 2>&1 > /dev/null