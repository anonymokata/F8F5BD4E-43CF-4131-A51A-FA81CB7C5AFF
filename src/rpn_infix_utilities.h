#ifndef IS_RPN_INFIX_UTILITIES_H
#define IS_RPN_INFIX_UTILITIES_H

#include <stdbool.h>

bool is_operand(const char character);
bool is_operator(const char character);
bool is_nonnull_string(const char *infix_string);

#endif /* IS_RPN_INFIX_UTILITIES_H */
