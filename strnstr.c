#include <assert.h>
#include <string.h>

#include "strnstr.h"

char *strnstr(const char *haystack, const char *needle, size_t len) {
  assert(haystack);
  assert(needle);
  assert(len > 0);

  char* next = (char*)haystack;
  int res = 0;

  if (*needle == '\0') {
    return (char*)haystack;
  }

  while ((next = strchr(haystack, *needle)) != NULL &&
         (res = ((size_t)(next - haystack) < len)) &&
         strncmp(next, needle, strlen(needle)) != 0) {
    haystack = next + 1;
  }

  return !res ? NULL : next;
}
