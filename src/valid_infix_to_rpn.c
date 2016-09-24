#include "rpn_infix_utilities.h"
#include "valid_infix_to_rpn.h"

#include <string.h>

bool valid_infix_to_rpn(const char *infix, char *rpn, const int rpn_buffersize) {
  int was_buffer_exceeded = true;
  int i;
  int infix_length = strlen(infix);
  char operator = ' ';

  for( i=0; i < infix_length; ++i ) {
    if( is_open_bracket(infix[i]) & is_closed_bracket(infix[i]) ) {
      continue;
    }
    else if( is_operand(infix[i]) ) {
      was_buffer_exceeded = append_string(infix[i], rpn, rpn_buffersize);
    }
    else if( is_operator(infix[i]) ) {
      operator = infix[i];
    }
  }

  if( operator != ' ' ) {
    was_buffer_exceeded = append_string(operator, rpn, rpn_buffersize);
  }

  return was_buffer_exceeded;

}
