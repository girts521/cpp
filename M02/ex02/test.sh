#!/bin/bash

# Compile
make re 2>&1 || { echo "Compilation failed"; exit 1; }

# Run and capture output
OUTPUT=$(./fixed)
echo "$OUTPUT"

echo ""
echo "=== Verifying expected values ==="

# Check each line of output (only numeric values, skip constructor/destructor messages)
VALUES=$(echo "$OUTPUT" | grep -E '^[0-9.]+$')

LINENUM=0
WRONG=0
while IFS= read -r line; do
    case $LINENUM in
        0)
            if [ "$line" != "0" ]; then
                echo "[FAIL] Line 1: expected 0, got $line"
                WRONG=1
            else
                echo "[OK] Line 1: 0"
            fi
            ;;
        1)
            if [ "$line" != "0.00390625" ]; then
                echo "[FAIL] Line 2: expected 0.00390625, got $line"
                WRONG=1
            else
                echo "[OK] Line 2: 0.00390625"
            fi
            ;;
        2)
            if [ "$line" != "0.00390625" ]; then
                echo "[FAIL] Line 3: expected 0.00390625, got $line"
                WRONG=1
            else
                echo "[OK] Line 3: 0.00390625"
            fi
            ;;
        3)
            if [ "$line" != "0.00390625" ]; then
                echo "[FAIL] Line 4: expected 0.00390625, got $line"
                WRONG=1
            else
                echo "[OK] Line 4: 0.00390625"
            fi
            ;;
        4)
            if [ "$line" != "0.0078125" ]; then
                echo "[FAIL] Line 5: expected 0.0078125, got $line"
                WRONG=1
            else
                echo "[OK] Line 5: 0.0078125"
            fi
            ;;
        5)
            if [ "$line" != "10.1016" ]; then
                echo "[FAIL] Line 6: expected 10.1016, got $line"
                WRONG=1
            else
                echo "[OK] Line 6: 10.1016"
            fi
            ;;
        6)
            if [ "$line" != "10.1016" ]; then
                echo "[FAIL] Line 7: expected 10.1016, got $line"
                WRONG=1
            else
                echo "[OK] Line 7: 10.1016"
            fi
            ;;
    esac
    LINENUM=$((LINENUM + 1))
done <<< "$VALUES"

if [ "$WRONG" -eq 1 ]; then
    echo ""
    echo "Some tests failed!"
    exit 1
fi

echo ""
echo "All tests passed!"

make fclean 2>&1 > /dev/null