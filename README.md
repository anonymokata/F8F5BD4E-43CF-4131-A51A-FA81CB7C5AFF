# Reverse Polish Notation and Infix Notation Exercise in C for Ubuntu Linux

This library allows the conversion of a mathematical expression in infix notation to reverse Polish notation (RPN) and visa versa. This kata is based on the http://www.spoj.com/problems/ONP/

## Usage

The following conversion routines are available to the user:

###Infix to RPN

	bool infix_to_rpn(const char *infix, char *rpn, const int rpn_buffersize)

####Input Arguments:
- <b>infix</b>: Infix character array.
- <b>rpn</b>: Character string pointer for the returned rpn result.
- <b>rpn_buffersize</b>: Fixed buffer size available for the rpn result.

####Returned Value:
- <b>boolean</b>:  Returns true if invalid inputs or invalid calculation results.

###RPN to Infix

	bool rpn_to_infix(const char *rpn, char *infix, const int infix_buffersize)

####Input Arguments:
- <b>rpn</b>: RPN character array.
- <b>infix</b>: Character string pointer for the returned infix result.
- <b>infix_buffersize</b>: Fixed buffer size available for the infix result.

####Returned Value:
- <b>boolean</b>:  Returns true if invalid inputs or invalid calculation results.

## Requirements to Run
- pkg-config if running outside the Docker.
- Ubuntu Linux 14.04
- The C programming language
- GNU GCC compiler tool chain
- GNU Make
- Check unit testing framework ( https://libcheck.github.io/check/ )
- Git

## Steps to Run
1. To build the application and perform unit tests use command:

		$ make test

2. To clean the project's build artifacts:

		$ make clean

## Infix Notation Rules:
- The placement of operators is between operands. For example: a+b
- Parentheses, (), can be used to surround groups of operands and operators to indicate the intended order in which operations are to be performed
- The order of operation, when not overridden by parentheses, is ^, /, *, -, +.  For example, a*b/c is equivalent to a*(b/c).
- Operators with equal precedence associate from left to right.  For example, a^b^c is equivalent to (a^b)^c.
- It is not necessary to include the unary negation operator as part of this exercise. Example: -b
- Valid operands are only lowercase letters: a, b, ..., z

## RPN Notation Rules:
- The operators follow their operands. For example: ab+
- Valid operators are ^, /, *, -, +
­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­- Valid operands are only lowercase letters: a, b, ..., z

## Additional Rules
- No blank or null pointer inputs are allowed.
- Spaces are not valid input characters.

## Algorithm Implementation Notes
- The RPN to infix algorithm was homegrown.
- The Infix to RPN algorithm was guided by the Shunting-yard algorithm (https://en.wikipedia.org/wiki/Shunting-yard_algorithm).
