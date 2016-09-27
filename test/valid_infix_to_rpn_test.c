#include <check.h>
#include "../src/valid_infix_to_rpn.h"

#define RPN_BUFFER_SIZE 50

START_TEST(When_Given_a_Returns_a_And_Success) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "a";
  strcpy(rpn,"");

  bool return_value = valid_infix_to_rpn(infix, rpn, RPN_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(rpn, "a");
}
END_TEST

START_TEST(When_Buffer_Size_Is_Too_Small_Returns_Empty_And_Failure) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "a";
  const int buffer_size_too_small = 1;
  strcpy(rpn,"");

  bool return_value = valid_infix_to_rpn(infix, rpn, buffer_size_too_small);

  ck_assert(return_value == true);
  ck_assert_str_eq(rpn, "");
}
END_TEST

START_TEST(When_Given_a_PLUS_b_Returns_a_b_PLUS_And_Success) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "a+b";
  strcpy(rpn,"");

  bool return_value = valid_infix_to_rpn(infix, rpn, RPN_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(rpn, "ab+");
}
END_TEST

START_TEST(When_Given_OBR_a_PLUS_b_CBE_Returns_a_b_PLUS_And_Success) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "(a+b)";
  strcpy(rpn,"");

  bool return_value = valid_infix_to_rpn(infix, rpn, RPN_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(rpn, "ab+");
}
END_TEST

START_TEST(When_Given_OBR_c_SUB_d_CBE_Returns_c_d_SUB_And_Success) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "(c-d)";
  strcpy(rpn,"");

  bool return_value = valid_infix_to_rpn(infix, rpn, RPN_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(rpn, "cd-");
}
END_TEST

START_TEST(When_Given_OBR_e_MULT_f_CBE_Returns_e_f_MULT_And_Success) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "e*f";
  strcpy(rpn,"");

  bool return_value = valid_infix_to_rpn(infix, rpn, RPN_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(rpn, "ef*");
}
END_TEST

START_TEST(When_Given_g_Returns_g_And_Success) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "g";
  strcpy(rpn,"");

  bool return_value = valid_infix_to_rpn(infix, rpn, RPN_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(rpn, "g");
}
END_TEST

START_TEST(When_Given_h_SUB_i_SUB_j_Returns_h_i_j_2SUB_And_Success) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "h-i-j";
  strcpy(rpn,"");

  bool return_value = valid_infix_to_rpn(infix, rpn, RPN_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(rpn, "hi-j-");
}
END_TEST

START_TEST(When_Given_l_DIV_m_POW_n_Returns_l_m_n_POW_DIV_And_Success) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "l/(m^n)";
  strcpy(rpn,"");

  bool return_value = valid_infix_to_rpn(infix, rpn, RPN_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(rpn, "lmn^/");
}
END_TEST

START_TEST(When_Given_o_MULT_p_MULT_q_SUB_r_SUB_s_SUB_t_Returns_o_p_MULT_q_MULT_r_SUB_s_SUB_t_SUB_And_Success) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "o*p*q-r-s-t";
  strcpy(rpn,"");

  bool return_value = valid_infix_to_rpn(infix, rpn, RPN_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(rpn, "op*q*r-s-t-");
}
END_TEST

START_TEST(When_Given_u_SUB_v_DIV_w_DIV_x_SUB_z_Returns_u_v_w_DIV_x_DIV_y_SUB_z_2SUB_And_Success) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "u-v/w/x-y-z";
  strcpy(rpn,"");

  bool return_value = valid_infix_to_rpn(infix, rpn, RPN_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(rpn, "uvw/x/y-z--");
}
END_TEST

START_TEST(When_Given_a_POW_b_POW_c_MULT_d_POW_e_Returns_a_b_POW_c_POW_d_MULT_e_POW_And_Success) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "a^b^c*d^e";
  strcpy(rpn,"");

  bool return_value = valid_infix_to_rpn(infix, rpn, RPN_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(rpn, "ab^c^de^*");
}
END_TEST

START_TEST(When_Given_2OBR_l_DIV_OBR_m_POW_n_2CBR_MULT_o_CBR_p_Returns_l_m_n_POW_DIV_o_MULT_p_SUB_And_Success) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "((l/(m^n))*o)-p";
  strcpy(rpn,"");

  bool return_value = valid_infix_to_rpn(infix, rpn, RPN_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(rpn, "lmn^/o*p-");
}
END_TEST

START_TEST(When_Given_2OBR_v_DIV_w_CBR_POW_x_CBR_MULT_OBR_y_SUB_z_CBR_Returns_v_w_DIV_x_POW_y_z_SUB_MULT_And_Success) {
  char rpn[RPN_BUFFER_SIZE];
  const char infix[] = "((v/w)^x)*(y-z)";
  strcpy(rpn,"");

  bool return_value = valid_infix_to_rpn(infix, rpn, RPN_BUFFER_SIZE);

  ck_assert(return_value == false);
  ck_assert_str_eq(rpn, "vw/x^yz-*");
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
  tcase_add_test(tc1_1, When_Given_OBR_a_PLUS_b_CBE_Returns_a_b_PLUS_And_Success);
  tcase_add_test(tc1_1, When_Given_OBR_c_SUB_d_CBE_Returns_c_d_SUB_And_Success);
  tcase_add_test(tc1_1, When_Given_OBR_e_MULT_f_CBE_Returns_e_f_MULT_And_Success);
  tcase_add_test(tc1_1, When_Given_g_Returns_g_And_Success);
  tcase_add_test(tc1_1, When_Given_h_SUB_i_SUB_j_Returns_h_i_j_2SUB_And_Success);
  tcase_add_test(tc1_1, When_Given_l_DIV_m_POW_n_Returns_l_m_n_POW_DIV_And_Success);
  tcase_add_test(tc1_1, When_Given_o_MULT_p_MULT_q_SUB_r_SUB_s_SUB_t_Returns_o_p_MULT_q_MULT_r_SUB_s_SUB_t_SUB_And_Success);
  tcase_add_test(tc1_1, When_Given_u_SUB_v_DIV_w_DIV_x_SUB_z_Returns_u_v_w_DIV_x_DIV_y_SUB_z_2SUB_And_Success);
  tcase_add_test(tc1_1, When_Given_a_POW_b_POW_c_MULT_d_POW_e_Returns_a_b_POW_c_POW_d_MULT_e_POW_And_Success);
  tcase_add_test(tc1_1, When_Given_2OBR_l_DIV_OBR_m_POW_n_2CBR_MULT_o_CBR_p_Returns_l_m_n_POW_DIV_o_MULT_p_SUB_And_Success);
  tcase_add_test(tc1_1, When_Given_2OBR_v_DIV_w_CBR_POW_x_CBR_MULT_OBR_y_SUB_z_CBR_Returns_v_w_DIV_x_POW_y_z_SUB_MULT_And_Success);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
