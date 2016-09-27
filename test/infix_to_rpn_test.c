#include <check.h>
#include "../src/infix_to_rpn.h"

#define RPN_BUFFER_SIZE 50

START_TEST(When_Given_a_Returns_a_And_Success) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "a";
  strcpy(rpn,"");

  bool return_value = infix_to_rpn(infix, rpn, RPN_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(rpn, "a");
}
END_TEST

START_TEST(When_Buffer_Size_Is_Too_Small_Returns_Empty_And_Failure) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "a";
  const int buffer_size_too_small = 1;
  strcpy(rpn,"");

  bool return_value = infix_to_rpn(infix, rpn, buffer_size_too_small);

  ck_assert(return_value == true);
  ck_assert_str_eq(rpn, "");
}
END_TEST

START_TEST(When_Given_Null_Returns_Empty_String_And_Failure) {
  char rpn[RPN_BUFFER_SIZE];
  strcpy(rpn,"");

  bool return_value = infix_to_rpn(0, rpn, RPN_BUFFER_SIZE);

  ck_assert(return_value == true);
  ck_assert_str_eq(rpn, "");
}
END_TEST

START_TEST(When_Given_83738_Returns_Empty_String_And_Failure) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "83738";
  strcpy(rpn,"");

  bool return_value = infix_to_rpn(infix, rpn, RPN_BUFFER_SIZE);

  ck_assert(return_value == true);
  ck_assert_str_eq(rpn, "");
}
END_TEST

START_TEST(When_Given_OBR_a_ADD_g_CBR_MULT_3OOBR_b_SUB_a_CBR_ADD_c_POW_OBR_c_OBR_e_OBR_d_POW_f_4CBR_Returns_a_g_ADD_b_a_SUB_c_ADD_c_e_d_f_POW__MULT_ADD_POW_MULT_And_Success) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "(a+g)*(((b-a)+c)^(c+(e*(d^f))))";
  strcpy(rpn,"");

  bool return_value = infix_to_rpn(infix, rpn, RPN_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(rpn, "ag+ba-c+cedf^*+^*");
}
END_TEST

START_TEST(When_Given_Null_RPN_Pointer_Returns_Failure) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "a";
  strcpy(rpn,"");

  bool return_value = infix_to_rpn(infix, 0, RPN_BUFFER_SIZE);

  ck_assert(return_value == true);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("infix_to_rpn_tests");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, When_Given_a_Returns_a_And_Success);
  tcase_add_test(tc1_1, When_Buffer_Size_Is_Too_Small_Returns_Empty_And_Failure);
  tcase_add_test(tc1_1, When_Given_Null_Returns_Empty_String_And_Failure);
  tcase_add_test(tc1_1, When_Given_83738_Returns_Empty_String_And_Failure);
  tcase_add_test(tc1_1, When_Given_OBR_a_ADD_g_CBR_MULT_3OOBR_b_SUB_a_CBR_ADD_c_POW_OBR_c_OBR_e_OBR_d_POW_f_4CBR_Returns_a_g_ADD_b_a_SUB_c_ADD_c_e_d_f_POW__MULT_ADD_POW_MULT_And_Success);
  tcase_add_test(tc1_1, When_Given_Null_RPN_Pointer_Returns_Failure);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
