#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "strnstr.h"

void test_find_at_begining() {
  char* haystack = "abcdef";
  char* needle = "ab";

  char* res = strnstr(haystack, needle, strlen(haystack));
  assert(res == haystack);
}

void test_find_at_middle() {
  char* haystack = "abcdef";
  char* needle = "cd";

  char* res = strnstr(haystack, needle, strlen(haystack));
  assert(res == (haystack + 2));
}

void test_find_at_end() {
  char* haystack = "abcdef";
  char* needle = "ef";

  char* res = strnstr(haystack, needle, strlen(haystack));
  assert(res == (haystack + 4));
}

void test_not_found() {
  char* haystack = "abcdef";
  char* needle = "gh";

  char* res = strnstr(haystack, needle, strlen(haystack));
  assert(res == NULL);
}

void test_return_haystack_if_needle_is_empty_string() {
  char* haystack = "abcdef";
  char* needle = "";

  char* res = strnstr(haystack, needle, strlen(haystack));
  assert(res == haystack);
}

void test_not_found_after_the_length() {
  char* haystack = "abcdef";
  char* needle = "ef";

  char* res = strnstr(haystack, needle, strlen(haystack) - 2);
  assert(res == NULL);
}

void test_not_found_when_not_matched_entire_needle() {
  char* haystack = "abcdef";
  char* needle = "efg";

  char* res = strnstr(haystack, needle, strlen(haystack) - 2);
  assert(res == NULL);
}

int main(void) {
  printf("test strnstr.\n");
  test_find_at_begining();
  test_find_at_middle();
  test_find_at_end();
  test_return_haystack_if_needle_is_empty_string();
  test_not_found();
  test_not_found_after_the_length();
  test_not_found_when_not_matched_entire_needle();
  printf("done.\n");
  return 0;
}
