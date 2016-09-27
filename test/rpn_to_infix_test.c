#include <check.h>
#include "../src/rpn_to_infix.h"

#define INFIX_BUFFER_SIZE 50

START_TEST(When_Given_a_Returns_a_And_Success) {
  char infix[INFIX_BUFFER_SIZE];
  const char rpn[] = "a";
  strcpy(infix,"");

  bool return_value = rpn_to_infix(rpn, infix, INFIX_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(infix, "a");
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("rpn_to_infix_tests");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, When_Given_a_Returns_a_And_Success);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
