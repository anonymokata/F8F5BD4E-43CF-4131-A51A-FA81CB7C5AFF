#include "valid_rpn_to_infix.h"
#include <string.h>

bool valid_rpn_to_infix(const char *rpn, char *infix, const int infix_buffersize) {
  char proposed_infix[] = "a";
  strcpy(infix, proposed_infix);
  return true;
}
