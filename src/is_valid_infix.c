#include "is_valid_infix.h"

#include <string.h>

static bool is_valid_string(const char *infix_string) {
  if(infix_string == 0) {
    return false;
  }
  return true;
}

static bool has_valid_characters(const char *infix_string) {
  if(!strlen(infix_string)) {
    return true;
  }
  return false;
}

bool is_valid_infix(const char *infix_string) {
  if( !is_valid_string(infix_string) || !has_valid_characters(infix_string) ) {
    return false;
  }
  return true;
}
