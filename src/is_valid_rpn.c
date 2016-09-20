#include "rpn_infix_utilities.h"
#include "is_valid_infix.h"

#include <string.h>

static bool has_one_less_operator_than_operand(const char *rpn_string) {
  int i;
  const int rpn_length = strlen(rpn_string);
  int operand_count = 0;
  int operator_count = 0;

  for(i=0; i < rpn_length; ++i) {
    if( is_operand(rpn_string[i]) ) {
      ++operand_count;
    }
    else if ( is_operator(rpn_string[i]) ) {
      ++operator_count;
    }
  }

  return (operand_count - 1) == operator_count;
}

static bool has_valid_operand_operator_sequence(const char *rpn_string) {
  int i;
  const int rpn_length = strlen(rpn_string);
  int operand_count = 0;
  int operator_count = 0;

  for(i=0; i < rpn_length; ++i) {
    if( is_operand(rpn_string[i]) ) {
      ++operand_count;
    }
    else if ( is_operator(rpn_string[i]) ) {
      ++operator_count;
    }
    if( operand_count <= operator_count ) {
      return false;
    }
  }

  return true;
}

static bool is_first_character_operator(const char *rpn_string) {
  return is_operator(rpn_string[0]);
}

bool is_valid_rpn(const char *rpn_string) {
  return !is_null_string(rpn_string) &&
      !is_empty_string(rpn_string) &&
      !is_first_character_operator(rpn_string) &&
      has_valid_operand_operator_sequence(rpn_string) &&
      has_one_less_operator_than_operand(rpn_string);
}
