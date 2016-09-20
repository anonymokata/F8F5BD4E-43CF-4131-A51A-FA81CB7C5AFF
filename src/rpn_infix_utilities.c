#include "rpn_infix_utilities.h"
#include <string.h>

bool is_operand(const char character) {
  int i;
  const char operands[] = "abcdefghijklmnopqrstuvwxyz";

  for(i=0; i < strlen(operands); ++i) {
    if( operands[i] == character ) {
      return true;
    }
  }
  return false;
}

bool is_operator(const char character) {
  int i;
  const char operators[] = "^+-*/";

  for(i=0; i < strlen(operators); ++i) {
    if( operators[i] == character ) {
      return true;
    }
  }
  return false;
}

bool is_null_string(const char *input_string) {
  return input_string == 0;
}

bool is_empty_string(const char *input_string) {
  return strlen(input_string) == 0;
}
