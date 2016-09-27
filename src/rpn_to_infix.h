#ifndef RPN_TO_INFIX_H
#define RPN_TO_INFIX_H

#include <stdbool.h>

bool rpn_to_infix(const char *rpn, char *infix, const int infix_buffersize);

#endif /* RPN_TO_INFIX_H */
