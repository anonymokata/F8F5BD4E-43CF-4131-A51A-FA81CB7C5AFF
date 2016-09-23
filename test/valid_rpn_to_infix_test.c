#include <check.h>
#include "../src/valid_rpn_to_infix.h"

#define INFIX_BUFFER_SIZE 50

START_TEST(When_Given_a_Returns_a_And_Success) {
  char infix[INFIX_BUFFER_SIZE];
  const char rpn[] = "a";

  bool return_value = valid_rpn_to_infix(rpn, infix, INFIX_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(infix, "a");
}
END_TEST

START_TEST(When_Buffer_Size_Is_Too_Small_Returns_Empty_And_Failure) {
  char infix[INFIX_BUFFER_SIZE];
  const char rpn[] = "a";
  const int buffer_size_too_small = 1;

  bool return_value = valid_rpn_to_infix(rpn, infix, buffer_size_too_small);

  ck_assert(return_value == true);
  ck_assert_str_eq(infix, "");
}
END_TEST

START_TEST(When_Given_a_b_PLUS_Returns_a_PLUS_b_And_Success) {
  char infix[INFIX_BUFFER_SIZE];
  const char rpn[] = "ab+";

  bool return_value = valid_rpn_to_infix(rpn, infix, INFIX_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(infix, "a+b");
}
END_TEST

START_TEST(When_Given_c_d_e_PLUS_PLUSReturns_c_PLUS_OBR_d_PLUS_e_CBR_And_Success) {
  char infix[INFIX_BUFFER_SIZE];
  const char rpn[] = "cde++";

  bool return_value = valid_rpn_to_infix(rpn, infix, INFIX_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(infix, "c+(d+e)");
}
END_TEST

START_TEST(When_Given_f_g_SUB_h_MULT_Returns_OBR_f_SUB_g_CBR_MULT_h_And_Success) {
  char infix[INFIX_BUFFER_SIZE];
  const char rpn[] = "fg-h*";

  bool return_value = valid_rpn_to_infix(rpn, infix, INFIX_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(infix, "(f-g)*h");
}
END_TEST

START_TEST(When_Given_i_j_h_k_POW_DIV_SUB_Returns_i_SUB_OBR_j_DIV_OBR_h_POW_k_2CBR_And_Success) {
  char infix[INFIX_BUFFER_SIZE];
  const char rpn[] = "ijhk^/-";

  bool return_value = valid_rpn_to_infix(rpn, infix, INFIX_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(infix, "i-(j/(h^k))");
}
END_TEST

START_TEST(When_Given_l_m_PLUS_n_o_SUB_p_PLUS_q_r_s_t_POW_MULT_PLUS_POW_MULT_Returns_OBR_l_PLUS_m_CBR_MULT_3OBR_n_SUB_o_CBR_PLUS_p_CBR_POW_OBR_r_MULT_OBR_r_OBR_s_POW_t_4CBR_And_Success) {
  char infix[INFIX_BUFFER_SIZE];
  const char rpn[] = "lm+no-p+qrst^*+^*";

  bool return_value = valid_rpn_to_infix(rpn, infix, INFIX_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(infix, "(l+m)*(((n-o)+p)^(q+(r*(s^t))))");
}
END_TEST

START_TEST(When_Given_v_w_DIV_x_POW_y_z_SUB_MULT_Returns_2OBR_v_DEV_w_CBR_POW_x_CBR_MULT_OBR_y_SUB_z_CBR_And_Success) {
  char infix[INFIX_BUFFER_SIZE];
  const char rpn[] = "vw/x^yz-*";

  bool return_value = valid_rpn_to_infix(rpn, infix, INFIX_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(infix, "((v/w)^x)*(y-z)");
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("rpn_to_infix_tests");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, When_Given_a_Returns_a_And_Success);
  tcase_add_test(tc1_1, When_Buffer_Size_Is_Too_Small_Returns_Empty_And_Failure);
  tcase_add_test(tc1_1, When_Given_a_b_PLUS_Returns_a_PLUS_b_And_Success);
  tcase_add_test(tc1_1, When_Given_c_d_e_PLUS_PLUSReturns_c_PLUS_OBR_d_PLUS_e_CBR_And_Success);
  tcase_add_test(tc1_1, When_Given_f_g_SUB_h_MULT_Returns_OBR_f_SUB_g_CBR_MULT_h_And_Success);
  tcase_add_test(tc1_1, When_Given_i_j_h_k_POW_DIV_SUB_Returns_i_SUB_OBR_j_DIV_OBR_h_POW_k_2CBR_And_Success);
  tcase_add_test(tc1_1, When_Given_l_m_PLUS_n_o_SUB_p_PLUS_q_r_s_t_POW_MULT_PLUS_POW_MULT_Returns_OBR_l_PLUS_m_CBR_MULT_3OBR_n_SUB_o_CBR_PLUS_p_CBR_POW_OBR_r_MULT_OBR_r_OBR_s_POW_t_4CBR_And_Success);
  tcase_add_test(tc1_1, When_Given_v_w_DIV_x_POW_y_z_SUB_MULT_Returns_2OBR_v_DEV_w_CBR_POW_x_CBR_MULT_OBR_y_SUB_z_CBR_And_Success);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
