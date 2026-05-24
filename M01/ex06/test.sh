#!/bin/bash
# Test script for ex06 — Harl filter (switch statement)

EXERCISE="ex06"
BINARY="./harlFilter"
PASS=0
FAIL=0

RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

run_test() {
    local desc="$1"
    local expected="$2"
    local actual="$3"

    if echo "$actual" | grep -qF "$expected"; then
        echo -e "  ${GREEN}[PASS]${NC} $desc"
        PASS=$((PASS + 1))
    else
        echo -e "  ${RED}[FAIL]${NC} $desc"
        echo "    Expected to contain: $expected"
        echo "    Got:"
        echo "$actual" | sed 's/^/    /'
        FAIL=$((FAIL + 1))
    fi
}

run_test_not_contain() {
    local desc="$1"
    local unexpected="$2"
    local actual="$3"

    if ! echo "$actual" | grep -qF "$unexpected"; then
        echo -e "  ${GREEN}[PASS]${NC} $desc"
        PASS=$((PASS + 1))
    else
        echo -e "  ${RED}[FAIL]${NC} $desc"
        echo "    Expected NOT to contain: $unexpected"
        echo "    Got:"
        echo "$actual" | sed 's/^/    /'
        FAIL=$((FAIL + 1))
    fi
}

echo -e "${CYAN}========================================${NC}"
echo -e "${CYAN}  $EXERCISE — Harl filter Tests${NC}"
echo -e "${CYAN}========================================${NC}"

# Step 1: Compile
echo ""
echo -e "${CYAN}[BUILD]${NC} make fclean && make"
BUILD_OUTPUT=$(make fclean && make 2>&1)
if [ $? -eq 0 ]; then
    echo -e "  ${GREEN}[PASS]${NC} Compilation"
    PASS=$((PASS + 1))
else
    echo -e "  ${RED}[FAIL]${NC} Compilation"
    echo "$BUILD_OUTPUT"
    FAIL=$((FAIL + 1))
fi

echo ""
echo -e "${CYAN}[TEST]${NC} Executable name is harlFilter"
run_test "Binary exists" "harlFilter" "$(ls -la $BINARY 2>&1)"

# Step 2: Test DEBUG (should show all 4)
echo ""
echo -e "${CYAN}[TEST]${NC} Level: DEBUG (should show all 4)"
OUTPUT=$($BINARY "DEBUG" 2>&1)
run_test "Shows [ DEBUG ]" "[ DEBUG ]" "$OUTPUT"
run_test "Shows [ INFO ]" "[ INFO ]" "$OUTPUT"
run_test "Shows [ WARNING ]" "[ WARNING ]" "$OUTPUT"
run_test "Shows [ ERROR ]" "[ ERROR ]" "$OUTPUT"

# Step 3: Test INFO (should show INFO, WARNING, ERROR)
echo ""
echo -e "${CYAN}[TEST]${NC} Level: INFO (should show INFO, WARNING, ERROR)"
OUTPUT=$($BINARY "INFO" 2>&1)
run_test_not_contain "Does NOT show [ DEBUG ]" "[ DEBUG ]" "$OUTPUT"
run_test "Shows [ INFO ]" "[ INFO ]" "$OUTPUT"
run_test "Shows [ WARNING ]" "[ WARNING ]" "$OUTPUT"
run_test "Shows [ ERROR ]" "[ ERROR ]" "$OUTPUT"

# Step 4: Test WARNING (should show WARNING, ERROR)
echo ""
echo -e "${CYAN}[TEST]${NC} Level: WARNING (should show WARNING, ERROR)"
OUTPUT=$($BINARY "WARNING" 2>&1)
run_test_not_contain "Does NOT show [ DEBUG ]" "[ DEBUG ]" "$OUTPUT"
run_test_not_contain "Does NOT show [ INFO ]" "[ INFO ]" "$OUTPUT"
run_test "Shows [ WARNING ]" "[ WARNING ]" "$OUTPUT"
run_test "Shows [ ERROR ]" "[ ERROR ]" "$OUTPUT"

# Step 5: Test ERROR (should show ERROR only)
echo ""
echo -e "${CYAN}[TEST]${NC} Level: ERROR (should show ERROR only)"
OUTPUT=$($BINARY "ERROR" 2>&1)
run_test_not_contain "Does NOT show [ DEBUG ]" "[ DEBUG ]" "$OUTPUT"
run_test_not_contain "Does NOT show [ INFO ]" "[ INFO ]" "$OUTPUT"
run_test_not_contain "Does NOT show [ WARNING ]" "[ WARNING ]" "$OUTPUT"
run_test "Shows [ ERROR ]" "[ ERROR ]" "$OUTPUT"

# Step 6: Test invalid level
echo ""
echo -e "${CYAN}[TEST]${NC} Level: INVALID (should complain about insignificant problems)"
OUTPUT=$($BINARY "blahblah" 2>&1)
run_test "Shows fallback message" "Probably complaining about insignificant problems" "$OUTPUT"

# Step 7: Test empty level (also invalid)
echo ""
echo -e "${CYAN}[TEST]${NC} Level: empty string"
OUTPUT=$($BINARY "" 2>&1)
run_test "Empty string shows fallback" "Probably complaining about insignificant problems" "$OUTPUT"

# Step 8: Test no arguments
echo ""
echo -e "${CYAN}[TEST]${NC} No arguments (should show usage)"
OUTPUT=$($BINARY 2>&1)
run_test "Shows usage message" "Usage:" "$OUTPUT"
run_test "Shows levels hint" "DEBUG, INFO" "$OUTPUT"

# Step 9: Test too many arguments
echo ""
echo -e "${CYAN}[TEST]${NC} Too many arguments (should show usage)"
OUTPUT=$($BINARY "DEBUG" "extra" 2>&1)
run_test "Extra arg shows usage" "Usage:" "$OUTPUT"

# Summary
echo ""
echo -e "${CYAN}========================================${NC}"
echo -e "${CYAN}  Results: ${PASS} passed, ${FAIL} failed${NC}"
echo -e "${CYAN}========================================${NC}"

exit $FAIL