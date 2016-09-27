#include "is_valid_infix.h"
#include "valid_infix_to_rpn.h"

bool infix_to_rpn(const char *infix, char *rpn, const int rpn_buffersize) {
  if( is_valid_infix(infix) ) {
    return valid_infix_to_rpn(infix, rpn, rpn_buffersize);
  }
  else {
    return true;
  }
}
