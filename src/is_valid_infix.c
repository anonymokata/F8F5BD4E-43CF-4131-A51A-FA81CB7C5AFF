#include "rpn_infix_utilities.h"
#include "is_valid_infix.h"

#include <string.h>

static bool has_valid_characters(const char *infix_string) {
  int i;
  const char valid_characters[] = "abcdefghijklmnopqrstuvwxyz^+-*/()";

  for(i=0; i < strlen(infix_string); ++i) {
    if( strchr(valid_characters, infix_string[i]) == NULL ) {
      return false;
    }
  }
  return true;
}

static int count_open_parens(const char *infix_string) {
  int i;
  int open_paren_count = 0;

  for(i=0; i < strlen(infix_string); ++i) {
    if( is_open_paren(infix_string[i]) ) {
      ++open_paren_count;
    }
  }
  return open_paren_count;
}

static int count_closed_parens(const char *infix_string) {
  int i;
  int closed_paren_count = 0;

  for(i=0; i < strlen(infix_string); ++i) {
    if( is_closed_paren(infix_string[i]) ) {
      ++closed_paren_count;
    }
  }
  return closed_paren_count;
}

static bool has_equal_number_of_open_close_parens(const char *infix_string) {
  if( count_open_parens(infix_string) == count_closed_parens(infix_string) ) {
    return true;
  }
  return false;

}

static bool has_open_parens_before_closed_parens(const char *infix_string) {
  int i;
  int closed_paren_count = 0;
  int open_paren_count = 0;

  for(i=0; i < strlen(infix_string); ++i) {
    if( is_open_paren(infix_string[i]) ) {
      ++open_paren_count;
    }
    if( is_closed_paren(infix_string[i]) ) {
      ++closed_paren_count;
    }
    if( closed_paren_count > open_paren_count )
      return false;
  }
  return true;
}

static bool has_no_empty_parens(const char *infix_string) {
  int i;
  const int infix_length = strlen(infix_string);

  for(i=0; i < infix_length; ++i) {
    if( is_open_paren(infix_string[i]) && ((i+1) != infix_length) &&
        is_closed_paren(infix_string[i+1]) ) {
          return false;
    }
  }
  return true;
}

static bool has_no_closed_paren_operand(const char *infix_string) {
  int i;
  const int infix_length = strlen(infix_string);

  for(i=0; i < infix_length; ++i) {
    if( is_closed_paren(infix_string[i]) && ((i+1) != infix_length) &&
        (is_operand(infix_string[i+1])) ) {
      return false;
    }
  }
  return true;
}

static bool has_no_operand_open_paren(const char *infix_string) {
  int i;
  const int infix_length = strlen(infix_string);

  for(i=0; i < infix_length; ++i) {
    if( is_operand(infix_string[i]) && ((i+1) != infix_length) &&
        is_open_paren(infix_string[i+1]) ) {
          return false;
    }
  }
  return true;
}

static bool has_valid_parens(const char *infix_string) {
  if( has_equal_number_of_open_close_parens(infix_string) &&
      has_open_parens_before_closed_parens(infix_string) &&
      has_no_empty_parens(infix_string) &&
      has_no_closed_paren_operand(infix_string) &&
      has_no_operand_open_paren(infix_string) ) {
    return true;
  }
  return false;
}

static bool has_no_operator_first(const char *infix_string) {
  if( is_operator(infix_string[0] ) ) {
    return false;
  }
  return true;
}

static bool is_valid_operand_operator_operand_sequence(const char *infix_string) {
  int i;
  const int infix_length = strlen(infix_string);

  for(i=0; i < infix_length; ++i) {
    if( is_operand(infix_string[i]) && ((i+1) != infix_length) &&
        is_operand(infix_string[i+1])) {
          return false;
    }
  }
  return true;
}

bool is_valid_infix(const char *infix_string) {
  return !is_null_string(infix_string) &&
      !is_empty_string(infix_string) &&
      has_valid_characters(infix_string) &&
      has_valid_parens(infix_string) &&
      is_valid_operand_operator_operand_sequence(infix_string) &&
      has_no_operator_first(infix_string);
}
