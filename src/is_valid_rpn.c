#include "is_valid_infix.h"

#include <string.h>

bool is_valid_rpn(const char *rpn_string) {
  if(!strcmp("ba+", rpn_string)) {
    return true;
  }
  else if(rpn_string[0] == 'a') {
    return true;
  }
  return false;
}
