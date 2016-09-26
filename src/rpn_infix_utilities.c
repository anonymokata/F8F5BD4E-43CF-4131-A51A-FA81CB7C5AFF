#include "rpn_infix_utilities.h"
#include <string.h>

#define END_OF_STRING_CHARACTER '\0'

bool is_open_paren(const char character) {
  return character == '(';
}

bool is_closed_paren(const char character) {
  return character == ')';
}

bool append_string(const char proposed_ammend, char *destination, const int destination_buffersize) {

  char proposed_ammend_string[2];
  proposed_ammend_string[0] = proposed_ammend;
  proposed_ammend_string[1] = END_OF_STRING_CHARACTER;

  if( ( strlen(destination)+strlen(proposed_ammend_string) ) < destination_buffersize ) {
    strcat(destination, proposed_ammend_string);
    return false;
  }
  strcpy(destination, "");
  return true;
}

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
