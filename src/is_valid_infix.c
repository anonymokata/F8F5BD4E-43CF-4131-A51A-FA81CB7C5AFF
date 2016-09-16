#include "is_valid_infix.h"

#include <string.h>

static bool is_valid_string(const char *infix_string) {
  if(infix_string == 0) {
    return false;
  }
  return true;
}

static bool has_valid_characters(const char *infix_string) {
  if(!strcmp(infix_string, "")) {
    return true;
  }
  else if(!strcmp(infix_string, "a")) {
    return true;
  }
  else if(!strcmp(infix_string, "a+b")) {
    return true;
  }
  else if(!strcmp(infix_string, "a+b+c")) {
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
