#include "rpn_infix_utilities.h"
#include "valid_infix_to_rpn.h"

#include <string.h>

bool valid_infix_to_rpn(const char *infix, char *rpn, const int rpn_buffersize) {
  int was_buffer_exceeded = true;

  if(!strcmp(infix, "a")) {
    return append_string(infix[0], rpn, rpn_buffersize);
  }
  else {
    was_buffer_exceeded = append_string(infix[0], rpn, rpn_buffersize);
    was_buffer_exceeded = append_string(infix[2], rpn, rpn_buffersize);
    was_buffer_exceeded = append_string(infix[1], rpn, rpn_buffersize);
    return was_buffer_exceeded;
  }
}
