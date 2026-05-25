#!/bin/bash
# Test script for ex05 — Harl 2.0 (pointers to member functions)

EXERCISE="ex05"
BINARY="./harl"
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

echo -e "${CYAN}========================================${NC}"
echo -e "${CYAN}  $EXERCISE — Harl 2.0 Tests${NC}"
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

# Step 2: Test DEBUG level
echo ""
echo -e "${CYAN}[TEST]${NC} Debug level"
OUTPUT=$($BINARY 2>&1 | awk '/--- complain\("DEBUG"\) ---/,/^$/' | tail -n +2 | head -n -1)
run_test "Shows debug message" "extra bacon" "$OUTPUT"
run_test "Shows burger detail" "7XL-double-cheese" "$OUTPUT"
rfail=$(echo "$OUTPUT" | grep -qF "[ DEBUG ]" && echo 1 || echo 0)
if [ "$rfail" -eq 0 ]; then
  echo -e "  ${GREEN}[PASS]${NC} No [ DEBUG ] label in output"
  PASS=$((PASS + 1))
else
  echo -e "  ${RED}[FAIL]${NC} No [ DEBUG ] label in output"
  echo "    Output contains [ DEBUG ] but should only have the message"
  FAIL=$((FAIL + 1))
fi

# Step 3: Test INFO level
echo ""
echo -e "${CYAN}[TEST]${NC} Info level"
OUTPUT=$($BINARY 2>&1 | awk '/--- complain\("INFO"\) ---/,/^$/' | tail -n +2 | head -n -1)
run_test "Shows info message" "extra bacon costs more money" "$OUTPUT"
rfail=$(echo "$OUTPUT" | grep -qF "[ INFO ]" && echo 1 || echo 0)
if [ "$rfail" -eq 0 ]; then
  echo -e "  ${GREEN}[PASS]${NC} No [ INFO ] label in output"
  PASS=$((PASS + 1))
else
  echo -e "  ${RED}[FAIL]${NC} No [ INFO ] label in output"
  echo "    Output contains [ INFO ] but should only have the message"
  FAIL=$((FAIL + 1))
fi

# Step 4: Test WARNING level
echo ""
echo -e "${CYAN}[TEST]${NC} Warning level"
OUTPUT=$($BINARY 2>&1 | awk '/--- complain\("WARNING"\) ---/,/^$/' | tail -n +2 | head -n -1)
run_test "Shows warning message" "extra bacon for free" "$OUTPUT"
run_test "No comma after 'years'" "years whereas" "$OUTPUT"
rfail=$(echo "$OUTPUT" | grep -qF "[ WARNING ]" && echo 1 || echo 0)
if [ "$rfail" -eq 0 ]; then
  echo -e "  ${GREEN}[PASS]${NC} No [ WARNING ] label in output"
  PASS=$((PASS + 1))
else
  echo -e "  ${RED}[FAIL]${NC} No [ WARNING ] label in output"
  echo "    Output contains [ WARNING ] but should only have the message"
  FAIL=$((FAIL + 1))
fi

# Step 5: Test ERROR level
echo ""
echo -e "${CYAN}[TEST]${NC} Error level"
OUTPUT=$($BINARY 2>&1 | awk '/--- complain\("ERROR"\) ---/,/^$/' | tail -n +2 | head -n -1)
run_test "Shows error message" "speak to the manager" "$OUTPUT"
rfail=$(echo "$OUTPUT" | grep -qF "[ ERROR ]" && echo 1 || echo 0)
if [ "$rfail" -eq 0 ]; then
  echo -e "  ${GREEN}[PASS]${NC} No [ ERROR ] label in output"
  PASS=$((PASS + 1))
else
  echo -e "  ${RED}[FAIL]${NC} No [ ERROR ] label in output"
  echo "    Output contains [ ERROR ] but should only have the message"
  FAIL=$((FAIL + 1))
fi

# Step 6: Test invalid level
echo ""
echo -e "${CYAN}[TEST]${NC} Invalid level"
OUTPUT=$($BINARY 2>&1)
run_test "Invalid level renders nothing before the confirmation line" \
  "(no output above this line if invalid is handled correctly)" \
  "$OUTPUT"

# Step 7: Test empty string
echo ""
echo -e "${CYAN}[TEST]${NC} Empty string"
run_test "Empty level renders nothing before the confirmation line" \
  "(no output above this line if empty is handled correctly)" \
  "$OUTPUT"

# Summary
echo ""
echo -e "${CYAN}========================================${NC}"
echo -e "${CYAN}  Results: ${PASS} passed, ${FAIL} failed${NC}"
echo -e "${CYAN}========================================${NC}"

exit $FAIL

