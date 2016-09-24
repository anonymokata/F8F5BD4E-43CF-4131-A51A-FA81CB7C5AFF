#ifndef RPN_INFIX_UTILITIES_H
#define RPN_INFIX_UTILITIES_H

#include <stdbool.h>

bool is_open_bracket(const char character);
bool is_closed_bracket(const char character);
bool append_string(const char proposed_ammend, char *destination, const int destination_buffersize);
bool is_operand(const char);
bool is_operator(const char);
bool is_null_string(const char *);
bool is_empty_string(const char *);

#endif /* RPN_INFIX_UTILITIES_H */
