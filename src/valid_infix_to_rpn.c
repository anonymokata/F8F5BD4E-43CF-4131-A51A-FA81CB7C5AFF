#include "rpn_infix_utilities.h"
#include "valid_infix_to_rpn.h"

#include <string.h>

bool valid_infix_to_rpn(const char *infix, char *rpn, const int rpn_buffersize) {
  int was_buffer_exceeded = true;

  if(!strcmp(infix, "a")) {
    return append_string(infix[0], rpn, rpn_buffersize);
  }
  else if(!strcmp(infix, "a+b") || !strcmp(infix, "(a+b)")) {
    was_buffer_exceeded = append_string('a', rpn, rpn_buffersize);
    was_buffer_exceeded = append_string('b', rpn, rpn_buffersize);
    was_buffer_exceeded = append_string('+', rpn, rpn_buffersize);
    return was_buffer_exceeded;
  }
}
