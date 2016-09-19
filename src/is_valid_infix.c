#include "is_valid_infix.h"

#include <string.h>
#include <stdio.h>

static char valid_characters[] = "abcdefghijklmnopqrstuvwxyz ^+*/()";

static bool is_valid_string(const char *infix_string) {
  if(infix_string == 0) {
    return false;
  }
  return true;
}

static bool has_valid_characters(const char *infix_string) {
  int i;

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

static int count_open_brackets(const char *infix_string) {
  int i;
  int open_bracket_count = 0;

  for(i=0; i < strlen(infix_string); ++i) {
    if( infix_string[i] == ')' ) {
      ++open_bracket_count;
    }
  }
  return open_bracket_count;
}

static int count_closed_brackets(const char *infix_string) {
  int i;
  int closed_bracket_count = 0;

  for(i=0; i < strlen(infix_string); ++i) {
    if( infix_string[i] == '(' ) {
      ++closed_bracket_count;
    }
  }
  return closed_bracket_count;
}

static bool has_equal_number_of_open_close_brackets(const char *infix_string) {
  if( count_open_brackets(infix_string) == count_closed_brackets(infix_string) ) {
    return true;
  }
  return false;

}

static bool has_open_brackets_before_closed_brackets(const char *infix_string) {
  int i;
  int closed_bracket_count = 0;
  int open_bracket_count = 0;

  for(i=0; i < strlen(infix_string); ++i) {
    if( infix_string[i] == '(' ) {
      ++open_bracket_count;
    }
    if( infix_string[i] == ')' ) {
      ++closed_bracket_count;
    }
    if( closed_bracket_count > open_bracket_count )
      return false;
  }
  return true;
}

static bool has_valid_brackets(const char *infix_string) {
  if( has_equal_number_of_open_close_brackets(infix_string) &&
      has_open_brackets_before_closed_brackets(infix_string) ) {
    return true;
  }
  return false;
}

bool is_valid_infix(const char *infix_string) {
  if( !is_valid_string(infix_string) || !has_valid_characters(infix_string) ||
      !has_valid_brackets(infix_string) ) {
    return false;
  }
  return true;
}
