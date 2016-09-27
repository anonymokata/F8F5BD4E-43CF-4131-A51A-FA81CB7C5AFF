#include "valid_rpn_to_infix.h"

bool rpn_to_infix(const char *rpn, char *infix, const int infix_buffersize) {
    if( is_valid_rpn(rpn) && infix != 0) {
      return valid_rpn_to_infix(rpn, infix, infix_buffersize);
    }
    else {
      return true;
    }
}
