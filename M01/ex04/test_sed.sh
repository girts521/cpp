#!/bin/bash

# Simple test script for sed_is_for_losers
# Usage: bash test_sed.sh

cd "$(dirname "$0")" || exit 1
BINARY=./sed_is_for_losers
PASS=0
FAIL=0

red()   { printf "\033[31m%s\033[0m\n" "$1"; }
green() { printf "\033[32m%s\033[0m\n" "$1"; }

run_test() {
    local desc="$1" expected="$2"
    shift 2
    # Run the binary, capture its output (if any) to stderr
    "$BINARY" "$@" 2>&1
    local got_file="$1.replace"
    if [ ! -f "$got_file" ]; then
        red "  ✗ FAIL: $desc"
        echo "    File '$got_file' was not created."
        ((FAIL++))
        return
    fi
    local content
    content=$(< "$got_file")
    rm -f "$got_file"
    if [ "$content" = "$expected" ]; then
        green "  ✓ PASS: $desc"
        ((PASS++))
    else
        red "  ✗ FAIL: $desc"
        echo "    Expected output: '$expected'"
        echo "    Got output:      '$content'"
        ((FAIL++))
    fi
}

run_test_error() {
    local desc="$1"
    shift
    "$BINARY" "$@" 2>&1
    # Just check the binary returned non-zero
    if [ $? -ne 0 ]; then
        green "  ✓ PASS: $desc (properly rejected)"
        ((PASS++))
    else
        red "  ✗ FAIL: $desc (should have errored but didn't)"
        ((FAIL++))
    fi
}

setup() {
    local f="$1" content="$2"
    printf "%s" "$content" > "$f"
}

echo "=============================="
echo " sed_is_for_losers — Test Suite"
echo "=============================="
echo ""

# ── Build first ──
echo "[Setup] Building..."
make -s 2>/dev/null
if [ ! -x "$BINARY" ]; then
    red "BUILD FAILED — binary not found"
    exit 1
fi
echo "[Setup] Build OK"
echo ""

# ──────────────────────────────────────────────────
echo "--- Basic replacement ---"
# 1) Simple single-word replacement
setup test_input.txt "hello world"
run_test "single word" "bye world" test_input.txt "hello" "bye"

# 2) Multiple occurrences on one line
setup test_input.txt "hello hello world"
run_test "multiple on same line" "bye bye world" test_input.txt "hello" "bye"

# 3) Multiple lines
setup test_input.txt $'line one\nline two\nline three'
run_test "multiple lines" $'line one\nline two\nline three' test_input.txt "xyz" "nope"

# ──────────────────────────────────────────────────
echo ""
echo "--- Delete (empty s2) ---"
# 4) Remove every occurrence (s2 is empty)
setup test_input.txt "hello world hello"
run_test "delete string (empty s2)" " world " test_input.txt "hello" ""

# ──────────────────────────────────────────────────
echo ""
echo "--- No match ---"
# 5) s1 not found in file
setup test_input.txt "this is a test"
run_test "no match" "this is a test" test_input.txt "zzzzz" "nope"

# ──────────────────────────────────────────────────
echo ""
echo "--- Edge cases ---"
# 6) Empty file
setup test_input.txt ""
run_test "empty input file" "" test_input.txt "hello" "bye"

# 7) s1 equals entire content
setup test_input.txt "hello"
run_test "s1 equals whole content" "bye" test_input.txt "hello" "bye"

# 8) Special characters (spaces, punctuation)
setup test_input.txt "foo bar baz"
run_test "spaces between words" "foo qux baz" test_input.txt "bar" "qux"

# 9) Multiple line replacement
setup test_input.txt $'aa\naa\naa'
run_test "multi-line replace" $'bb\nbb\nbb' test_input.txt "aa" "bb"

# 10) Leading/trailing content around match
setup test_input.txt "start middle end"
run_test "word in middle" "start REPLACED end" test_input.txt "middle" "REPLACED"

# ──────────────────────────────────────────────────
echo ""
echo "--- Overlapping patterns ---"
# 11) Overlapping "aaa" -> replace "aa" with "a"
# The manual find-loop should produce "aa" (first "aa" replaced, then the remaining "a" isn't "aa")
setup test_input.txt "aaa"
run_test "overlapping 'aa' in 'aaa'" "aa" test_input.txt "aa" "a"

# ──────────────────────────────────────────────────
echo ""
echo "--- Error handling ---"
# 12) No arguments
run_test_error "no arguments" 

# 13) Only 1 argument
run_test_error "1 argument" "test_input.txt"

# 14) Only 2 arguments
run_test_error "2 arguments" "test_input.txt" "hello"

# 15) Empty s1 (should be rejected)
run_test_error "empty s1" "test_input.txt" "" "bye"

# 16) Non-existent file
touch test_nonexistent.txt && rm -f test_nonexistent.txt
run_test_error "non-existent input file" "test_nonexistent.txt" "hello" "bye"

# ──────────────────────────────────────────────────
echo ""
# Clean up temp input files
rm -f test_input.txt test_input.txt.replace

# ── Summary ──
echo "=============================="
printf " Results: "
green "${PASS} passed"
if [ $FAIL -gt 0 ]; then
    printf ", "
    red "${FAIL} failed"
fi
echo "=============================="