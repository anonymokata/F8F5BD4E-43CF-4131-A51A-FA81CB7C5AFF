#include <check.h>
#include "../src/valid_rpn_to_infix.h"

#define INFIX_BUFFER_SIZE 50

START_TEST(When_Given_a_Returns_a_And_True) {
  char infix[INFIX_BUFFER_SIZE];
  const char rpn[] = "a";

  bool return_value = valid_rpn_to_infix(rpn, infix, INFIX_BUFFER_SIZE);

  ck_assert(return_value == true);
  ck_assert_str_eq(infix, "a");
}
END_TEST

START_TEST(When_Buffer_Size_Is_Too_Small_Returns_Empty_And_False) {
  char infix[INFIX_BUFFER_SIZE];
  const char rpn[] = "a";
  const int buffer_size_too_small = 1;

  bool return_value = valid_rpn_to_infix(rpn, infix, buffer_size_too_small);

  ck_assert(return_value == false);
  ck_assert_str_eq(infix, "");
}
END_TEST

START_TEST(When_Given_a_b_PLUS_Returns_OBR_a_PLUS_b_CBR_And_True) {
  char infix[INFIX_BUFFER_SIZE];
  const char rpn[] = "ab+";

  bool return_value = valid_rpn_to_infix(rpn, infix, INFIX_BUFFER_SIZE);

  ck_assert(return_value == true);
  ck_assert_str_eq(infix, "(a+b)");
}
END_TEST

START_TEST(When_Given_c_d_e_PLUS_PLUSReturns_c_PLUS_OBR_d_PLUS_e_CBR_And_True) {
  char infix[INFIX_BUFFER_SIZE];
  const char rpn[] = "cde++";

  bool return_value = valid_rpn_to_infix(rpn, infix, INFIX_BUFFER_SIZE);

  ck_assert(return_value == true);
  ck_assert_str_eq(infix, "c+(d+e)");
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("rpn_to_infix_tests");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, When_Given_a_Returns_a_And_True);
  tcase_add_test(tc1_1, When_Buffer_Size_Is_Too_Small_Returns_Empty_And_False);
  tcase_add_test(tc1_1, When_Given_c_d_e_PLUS_PLUSReturns_c_PLUS_OBR_d_PLUS_e_CBR_And_True);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
