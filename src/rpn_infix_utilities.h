#ifndef IS_RPN_INFIX_UTILITIES_H
#define IS_RPN_INFIX_UTILITIES_H

#include <stdbool.h>

bool is_operand(const char);
bool is_operator(const char);
bool is_null_string(const char *);
bool is_empty_string(const char *);

#endif /* IS_RPN_INFIX_UTILITIES_H */
