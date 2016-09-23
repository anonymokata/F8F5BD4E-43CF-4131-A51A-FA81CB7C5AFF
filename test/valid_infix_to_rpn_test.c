#include <check.h>
#include "../src/valid_infix_to_rpn.h"

#define RPN_BUFFER_SIZE 50

START_TEST(When_Given_a_Returns_a_And_Success) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "a";

  bool return_value = valid_infix_to_rpn(infix, rpn, RPN_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(rpn, "a");
}
END_TEST

START_TEST(When_Buffer_Size_Is_Too_Small_Returns_Empty_And_Failure) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "a";
  const int buffer_size_too_small = 1;

  bool return_value = valid_infix_to_rpn(infix, rpn, buffer_size_too_small);

  ck_assert(return_value == true);
  ck_assert_str_eq(rpn, "");
}
END_TEST

START_TEST(When_Given_a_PLUS_b_Returns_a_b_PLUS_And_Success) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "a+b";

  bool return_value = valid_infix_to_rpn(infix, rpn, RPN_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(rpn, "ab+");
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("valid_infix_to_rpn_tests");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, When_Given_a_Returns_a_And_Success);
  tcase_add_test(tc1_1, When_Buffer_Size_Is_Too_Small_Returns_Empty_And_Failure);
  tcase_add_test(tc1_1, When_Given_a_PLUS_b_Returns_a_b_PLUS_And_Success);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
