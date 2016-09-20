#include "is_valid_infix.h"

#include <string.h>
#include <stdio.h>

static char valid_characters[] = "abcdefghijklmnopqrstuvwxyz^+*/()";

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

static bool has_no_empty_brackets(const char *infix_string) {
  int i;
  const int infix_length = strlen(infix_string);

  for(i=0; i < infix_length; ++i) {
    if( (infix_string[i] == '(') && ((i+1) != infix_length) &&
        (infix_string[i+1] == ')')) {
          return false;
    }
  }
  return true;
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

static bool is_operation(const char character) {
  int i;
  const char operations[] = "^+*/";

  for(i=0; i < strlen(operations); ++i) {
    if( operations[i] == character ) {
      return true;
    }
  }
  return false;
}

static bool has_no_closed_bracket_operand(const char *infix_string) {
  int i;
  const int infix_length = strlen(infix_string);

  for(i=0; i < infix_length; ++i) {
    if( (infix_string[i] == ')') && ((i+1) != infix_length) &&
        (is_operand(infix_string[i+1])) ) {
          return false;
    }
  }
  return true;
}

static bool has_no_operand_open_bracket(const char *infix_string) {
  int i;
  const int infix_length = strlen(infix_string);

  for(i=0; i < infix_length; ++i) {
    if( is_operand(infix_string[i]) && ((i+1) != infix_length) &&
        (infix_string[i+1] == '(') ) {
          return false;
    }
  }
  return true;
}

static bool has_valid_brackets(const char *infix_string) {
  if( has_equal_number_of_open_close_brackets(infix_string) &&
      has_open_brackets_before_closed_brackets(infix_string) &&
      has_no_empty_brackets(infix_string) &&
      has_no_closed_bracket_operand(infix_string) &&
      has_no_operand_open_bracket(infix_string) ) {
    return true;
  }
  return false;
}

static bool has_no_operation_first(const char *infix_string) {
  if( is_operation(infix_string[0] ) ) {
    return false;
  }
  return true;
}

static bool is_valid_operand_operation_operand_sequence(const char *infix_string) {
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
  if( !is_valid_string(infix_string) || !has_valid_characters(infix_string) ||
      !has_valid_brackets(infix_string) ||
      !is_valid_operand_operation_operand_sequence(infix_string) ||
      !has_no_operation_first(infix_string)  ) {
    return false;
  }
  return true;
}
