#include "is_valid_infix.h"

#include <string.h>

static bool is_operation(const char character) {
  int i;
  const char operations[] = "+-*/";

  for(i=0; i < strlen(operations); ++i) {
    if( operations[i] == character ) {
      return true;
    }
  }
  return false;
}

static bool is_operand(const char character) {
  int i;
  const char operands[] = "abcdefghijklmnopqrstuvwxyz";

  for(i=0; i < strlen(operands); ++i) {
    if( operands[i] == character ) {
      return true;
    }
  }
  return false;
}

static bool has_one_less_operator_than_operand(const char *rpn_string) {
  int i;
  const int rpn_length = strlen(rpn_string);
  int operand_count = 0;
  int operation_count = 0;

  for(i=0; i < rpn_length; ++i) {
    if( is_operand(rpn_string[i]) ) {
      ++operand_count;
    }
    else if ( is_operation(rpn_string[i]) ) {
      ++operation_count;
    }
  }

  return (operand_count - 1) == operation_count;
}

bool is_valid_rpn(const char *rpn_string) {
  if(rpn_string == "") {
    return false;
  }
  return has_one_less_operator_than_operand(rpn_string);
}
