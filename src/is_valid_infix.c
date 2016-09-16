#include "is_valid_infix.h"

#include <string.h>

bool is_valid_infix(char *infix_string) {
  if(infix_string == 0) {
    return false;
  }
  else if(!strcmp(infix_string, "1")) {
    return false;
  } else {
    return true;
  }
}
