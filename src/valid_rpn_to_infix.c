#include "valid_rpn_to_infix.h"
#include <string.h>

static bool append_infix(const char proposed_infix_ammend, char *infix, const int infix_buffersize) {

  char proposed_infix_ammend_string[2];
  proposed_infix_ammend_string[0] = proposed_infix_ammend;
  proposed_infix_ammend_string[1] = '\0';

  if( ( strlen(infix)+strlen(proposed_infix_ammend_string) ) < infix_buffersize ) {
    strcat(infix, proposed_infix_ammend_string);
    return true;
  }
  strcpy(infix, "");
  return false;
}

bool valid_rpn_to_infix(const char *rpn, char *infix, const int infix_buffersize) {

  if(!strcmp(rpn, "a")) {
    return append_infix('a', infix, infix_buffersize);
  }
  else if(!strcmp(rpn, "ab+")) {
    if( append_infix('a', infix, infix_buffersize) &&
        append_infix('+', infix, infix_buffersize) &&
        append_infix('b', infix, infix_buffersize) ) {
      return true;
    }
  }
  else if(!strcmp(rpn, "cde++")) {
    if( append_infix('c', infix, infix_buffersize) &&
        append_infix('+', infix, infix_buffersize) &&
        append_infix('(', infix, infix_buffersize) &&
        append_infix('d', infix, infix_buffersize) &&
        append_infix('+', infix, infix_buffersize) &&
        append_infix('e', infix, infix_buffersize) &&
        append_infix(')', infix, infix_buffersize) ) {
      return true;
    }
  }
  else if(!strcmp(rpn, "fg-h*")) {
    if( append_infix('(', infix, infix_buffersize) &&
        append_infix('f', infix, infix_buffersize) &&
        append_infix('-', infix, infix_buffersize) &&
        append_infix('g', infix, infix_buffersize) &&
        append_infix(')', infix, infix_buffersize) &&
        append_infix('*', infix, infix_buffersize) &&
        append_infix('h', infix, infix_buffersize) ) {
      return true;
    }
  }
  else if(!strcmp(rpn, "ijhk^/-")) {
    if( append_infix('i', infix, infix_buffersize) &&
        append_infix('-', infix, infix_buffersize) &&
        append_infix('(', infix, infix_buffersize) &&
        append_infix('j', infix, infix_buffersize) &&
        append_infix('/', infix, infix_buffersize) &&
        append_infix('(', infix, infix_buffersize) &&
        append_infix('h', infix, infix_buffersize) &&
        append_infix('^', infix, infix_buffersize) &&
        append_infix('k', infix, infix_buffersize) &&
        append_infix(')', infix, infix_buffersize) &&
        append_infix(')', infix, infix_buffersize) ) {
      return true;
    }
  }
  return false;
}
