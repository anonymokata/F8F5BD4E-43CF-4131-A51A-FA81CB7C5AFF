#include "rpn_infix_utilities.h"
#include "valid_infix_to_rpn.h"

#include <string.h>

bool valid_infix_to_rpn(const char *infix, char *rpn, const int rpn_buffersize) {
  return append_string(infix[0], rpn, rpn_buffersize);
}
