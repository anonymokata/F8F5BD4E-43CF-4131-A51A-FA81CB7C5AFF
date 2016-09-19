#include "is_valid_infix.h"

#include <string.h>
#include <stdio.h>

static char valid_characters[] = " abcdefghi+";

static bool is_valid_string(const char *infix_string) {
  if(infix_string == 0) {
    return false;
  }
  return true;
}

static bool has_valid_characters(const char *infix_string) {
  int i;
  char *p;
  char myChar;
  bool hasValidCharacters = false;

  if(!strcmp(infix_string, "")) {
    return true;
  }

  for(i=0; i < strlen(infix_string); ++i) {
    if( strchr(valid_characters, infix_string[i]) == NULL ) {
      return false;
    }
  }
  return true;
}

bool is_valid_infix(const char *infix_string) {
  if( !is_valid_string(infix_string) || !has_valid_characters(infix_string) ) {
    return false;
  }
  return true;
}
