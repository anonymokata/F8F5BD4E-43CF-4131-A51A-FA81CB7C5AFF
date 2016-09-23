#include "valid_infix_to_rpn.h"

#include <string.h>

bool valid_infix_to_rpn(const char *infix, char *rpn, const int rpn_buffersize) {
  char proposed_rpn_ammend_string[2];
  proposed_rpn_ammend_string[0] = infix[0];
  proposed_rpn_ammend_string[1] = '\0';

  if( ( strlen(rpn)+strlen(proposed_rpn_ammend_string) ) < rpn_buffersize ) {
    strcat(rpn, proposed_rpn_ammend_string);
    return false;
  }
  strcpy(rpn, "");
  return true;
}
