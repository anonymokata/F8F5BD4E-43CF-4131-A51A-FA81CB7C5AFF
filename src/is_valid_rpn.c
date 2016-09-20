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

bool is_valid_rpn(const char *rpn_string) {
  if( !is_nonnull_string(rpn_string) || rpn_string == "") {
    return false;
  }
  else if (is_operator(rpn_string[0])) {
    return false;
  }
  else if (!has_valid_operand_operator_sequence(rpn_string)) {
    return false;
  }
  return has_one_less_operator_than_operand(rpn_string);
}
