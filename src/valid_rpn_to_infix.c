#include "rpn_infix_utilities.h"
#include "valid_rpn_to_infix.h"
#include <string.h>

#define OFFSET_FOR_OPERATOR_AND_BRACKETS 3

static int find_operand_start(const char *infix, const int operand_end) {
  int i;
  int number_of_open_paren = 0;
  int number_of_closed_parens = 0;

  if( is_operand(infix[operand_end]) ) {
    return operand_end;
  }

  for(i = operand_end; i >= 0; --i) {
    if( is_closed_paren(infix[i]) ) {
      ++number_of_closed_parens;
    }
    else if( is_open_paren(infix[i]) ) {
      ++number_of_open_paren;
    }
    if(number_of_closed_parens == number_of_open_paren) {
      return i;
    }
  }
}

static int find_second_operand_start(const char *infix) {
  return find_operand_start(infix, strlen(infix)-1);
}

static int find_first_operand_start(const char *infix, const int operand_end) {
  return find_operand_start(infix, operand_end);
}

static bool make_space_for_operator_and_parens(char *infix, const int infix_buffersize) {
  int i;
  bool was_buffer_exceeded = true;

  for(i = 0; i < OFFSET_FOR_OPERATOR_AND_BRACKETS; ++i) {
    was_buffer_exceeded = append_string(' ', infix, infix_buffersize);
  }
  return was_buffer_exceeded;
}

static bool make_space_for_operator(char *infix, const int infix_buffersize) {
  int i;
  bool was_buffer_exceeded = true;
  was_buffer_exceeded = append_string(' ', infix, infix_buffersize);
  return was_buffer_exceeded;
}

static bool insert_operator_and_parens(const int first_operand_start,
                      const int second_operand_start,
                      const char operation,
                      char *infix, const int infix_buffersize) {
  bool was_buffer_exceeded = true;
  const int infix_length = strlen(infix);
  const int second_operand_end = infix_length - 1;
  int i = second_operand_end;
  int i_new = i + OFFSET_FOR_OPERATOR_AND_BRACKETS;

  was_buffer_exceeded = make_space_for_operator_and_parens(infix, infix_buffersize);

  if(was_buffer_exceeded)
    return was_buffer_exceeded;

  infix[i_new] = ')';

  for(; i >= second_operand_start; --i) {
    infix[--i_new] = infix[i];
  }

  infix[--i_new] = operation;

  for(; i >= first_operand_start; --i) {
    infix[--i_new] = infix[i];
  }

  infix[--i_new] = '(';

  return was_buffer_exceeded;
}

static bool insert_operator(const int first_operand_start,
                      const int second_operand_start,
                      const char operation,
                      char *infix, const int infix_buffersize) {
  int i;
  bool was_buffer_exceeded = true;
  const infix_length = strlen(infix);
  const second_operand_end = infix_length - 1;

  was_buffer_exceeded = make_space_for_operator(infix, infix_buffersize);

  if(was_buffer_exceeded)
    return was_buffer_exceeded;

  for(i = second_operand_end; i >= second_operand_start; --i) {
    infix[i+1] = infix[i];
  }

  infix[i+1] = operation;

  return was_buffer_exceeded;
}

static bool is_last_operator(const int rpn_index, const int rpn_length) {
  return rpn_index+1 == rpn_length;
}

bool valid_rpn_to_infix(const char *rpn, char *infix, const int infix_buffersize) {
  int i;
  int second_operand_start;
  int first_operand_start;
  const int rpn_length = strlen(rpn);
  bool was_buffer_exceeded = true;

  for(i = 0; i < rpn_length; ++i) {
    if( is_operand(rpn[i]) ) {
      was_buffer_exceeded = append_string(rpn[i], infix, infix_buffersize);
    }
    else if( is_operator(rpn[i]) ) {
      second_operand_start = find_second_operand_start(infix);
      first_operand_start = find_first_operand_start(infix, second_operand_start-1);

      if( is_last_operator(i, rpn_length) ) {
        was_buffer_exceeded = insert_operator(first_operand_start, second_operand_start,
              rpn[i], infix, infix_buffersize);
      }
      else {
        was_buffer_exceeded = insert_operator_and_parens(first_operand_start, second_operand_start,
              rpn[i], infix, infix_buffersize);
      }
    }
  }
  return was_buffer_exceeded;
}
