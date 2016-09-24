#include "rpn_infix_utilities.h"
#include "valid_infix_to_rpn.h"

#include <string.h>

bool valid_infix_to_rpn(const char *infix, char *rpn, const int rpn_buffersize) {
  int was_buffer_exceeded = true;
  int i;
  const int infix_length = strlen(infix);

  for( i=0; i < infix_length; ++i ) {
    if( is_operand(infix[i]) ) {
      was_buffer_exceeded = append_string(infix[i], rpn, rpn_buffersize);
    }
  }

  for( i=0; i < infix_length; ++i ) {
    if( is_operator(infix[i]) ) {
      was_buffer_exceeded = append_string(infix[i], rpn, rpn_buffersize);
    }
  }

  return was_buffer_exceeded;

}
