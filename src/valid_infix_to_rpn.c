#include "rpn_infix_utilities.h"
#include "valid_infix_to_rpn.h"

#include <string.h>

static int get_operator_precedence(const char operator) {
  int precedence = 0;
  switch(operator) {
    case '^':
      precedence = 5;
      break;
    case '/':
      precedence = 4;
      break;
    case '*':
      precedence = 3;
      break;
    case '-':
      precedence = 2;
      break;
    case '+':
      precedence = 1;
      break;
  }
  return precedence;
}

static int number_of_operands(const char *infix) {
  int i;
  const int infix_length = strlen(infix);
  int count = 0;

  for( i=0; i < infix_length; ++i ) {
    if(is_operand(infix[i])) {
      ++count;
    }
  }
  return count;
}

static bool push_to_stack(const char token, char *stack, const int stack_buffersize) {
  return append_string(token, stack, stack_buffersize);
}

static char pop_from_stack(char *stack) {
  int stack_length = strlen(stack);
  const char token = stack[stack_length-1];
  stack[stack_length-1] = '\0';
  return token;
}

static bool apply_remaining_operators_to_rpn(char *operator_stack, char *rpn, const int rpn_buffersize) {
  bool was_buffer_exceeded = false;
  int operator_stack_length = strlen(operator_stack);

  while( operator_stack_length ) {
    operator_stack_length = strlen(operator_stack);
    was_buffer_exceeded = push_to_stack(pop_from_stack(operator_stack), rpn, rpn_buffersize);
  }

  return was_buffer_exceeded;
}

static bool empty_paren_operators_on_stack(char *operator_stack, char *rpn, const int rpn_buffersize) {
  bool rpn_buffer_was_exceeded = false;
  char tmp_token = pop_from_stack(operator_stack);

  while( !is_open_paren(tmp_token) ) {
    rpn_buffer_was_exceeded = push_to_stack(tmp_token, rpn, rpn_buffersize);
    tmp_token = pop_from_stack(operator_stack);

    if(rpn_buffer_was_exceeded) {
      return rpn_buffer_was_exceeded;
    }
  }
}

static bool apply_operator_precedence(const char infix, char *operator_stack, char *rpn, const int rpn_buffersize) {
  bool rpn_buffer_was_exceeded = false;
  const int operator_stack_length = strlen(operator_stack);

  if(operator_stack_length >= 1 && is_operator(operator_stack[operator_stack_length-1]) ){
    if( get_operator_precedence(infix) <= get_operator_precedence(operator_stack[operator_stack_length-1]) ) {
      rpn_buffer_was_exceeded = push_to_stack(pop_from_stack(operator_stack), rpn, rpn_buffersize);
    }
  }
  return rpn_buffer_was_exceeded;
}

bool valid_infix_to_rpn(const char *infix, char *rpn, const int rpn_buffersize) {
  bool rpn_buffer_was_exceeded = false;
  bool operator_stack_buffer_was_exceeded = false;
  int i;
  const int infix_length = strlen(infix);
  const int operator_stack_buffersize = infix_length - number_of_operands(infix) + 1;
  char operator_stack[operator_stack_buffersize];
  strcpy(operator_stack,"");

  for( i=0; i < infix_length; ++i ) {
    if( is_operand(infix[i]) ) {
      rpn_buffer_was_exceeded = push_to_stack(infix[i], rpn, rpn_buffersize);
    }
    else if( is_open_paren(infix[i]) ) {
      operator_stack_buffer_was_exceeded = push_to_stack(infix[i], operator_stack, operator_stack_buffersize);
    }
    else if( is_closed_paren(infix[i]) ) {
      rpn_buffer_was_exceeded = empty_paren_operators_on_stack(operator_stack, rpn, rpn_buffersize);
    }
    else if( is_operator(infix[i]) ) {
      rpn_buffer_was_exceeded = apply_operator_precedence(infix[i], operator_stack, rpn, rpn_buffersize);
      operator_stack_buffer_was_exceeded = push_to_stack(infix[i], operator_stack, operator_stack_buffersize);
    }
    if(rpn_buffer_was_exceeded || operator_stack_buffer_was_exceeded) {
      return true;
    }
  }

  rpn_buffer_was_exceeded = apply_remaining_operators_to_rpn(operator_stack, rpn, rpn_buffersize);

  return (rpn_buffer_was_exceeded || operator_stack_buffer_was_exceeded);
}
