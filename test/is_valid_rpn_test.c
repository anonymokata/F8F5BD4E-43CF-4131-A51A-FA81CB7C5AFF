#include <check.h>
#include "../src/is_valid_rpn.h"

START_TEST(WhenGivenEmptyStringReturnsFalse) {
  bool return_value = is_valid_rpn("");
  ck_assert(return_value == false);
}
END_TEST

START_TEST(WhenGiven_a_ReturnTrue) {
  bool return_value = is_valid_rpn("a");
  ck_assert(return_value == true);
}
END_TEST

START_TEST(WhenGiven_b_a_PLUS_ReturnTrue) {
  bool return_value = is_valid_rpn("ba+");
  ck_assert(return_value == true);
}
END_TEST

START_TEST(WhenGiven_a_b_ReturnFalse) {
  bool return_value = is_valid_rpn("ab");
  ck_assert(return_value == false);
}
END_TEST

START_TEST(WhenGiven_a_b_c_PLUS_ReturnFalse) {
  bool return_value = is_valid_rpn("abc+");
  ck_assert(return_value == false);
}
END_TEST

START_TEST(WhenGiven_a_b_c_PLUS_PLUS_ReturnTrue) {
  bool return_value = is_valid_rpn("abc++");
  ck_assert(return_value == true);
}
END_TEST

START_TEST(WhenGiven_a_b_c_d_PLUS_PLUS_ReturnFalse) {
  bool return_value = is_valid_rpn("abcd++");
  ck_assert(return_value == false);
}
END_TEST

START_TEST(WhenGiven_a_b_c_d_PLUS_PLUS_MINUS_ReturnTrue) {
  bool return_value = is_valid_rpn("abcd++-");
  ck_assert(return_value == true);
}
END_TEST

START_TEST(WhenGiven_e_f_g_h_i_j_k_6PLUS_ReturnTrue) {
  bool return_value = is_valid_rpn("efghijk++++++");
  ck_assert(return_value == true);
}
END_TEST

START_TEST(WhenGiven_l_m_o_p_q_r_s_7SUB_ReturnTrue) {
  bool return_value = is_valid_rpn("lmnopqrs-------");
  ck_assert(return_value == true);
}
END_TEST

START_TEST(WhenGiven_t_u_v_w_x_y_z_6SUB_ReturnTrue) {
  bool return_value = is_valid_rpn("tuvwxyz------");
  ck_assert(return_value == true);
}
END_TEST

START_TEST(WhenGiven_t_u_v_w_x_y_z_6MULT_ReturnTrue) {
  bool return_value = is_valid_rpn("tuvwxyz******");
  ck_assert(return_value == true);
}
END_TEST

START_TEST(WhenGiven_t_u_v_w_x_y_z_6DIV_ReturnTrue) {
  bool return_value = is_valid_rpn("tuvwxyz//////");
  ck_assert(return_value == true);
}
END_TEST

START_TEST(WhenGiven_t_u_v_w_x_y_z_6POW_ReturnTrue) {
  bool return_value = is_valid_rpn("tuvwxyz^^^^^^");
  ck_assert(return_value == true);
}
END_TEST

START_TEST(WhenGivenNullReturnsFalse) {
  bool return_value = is_valid_rpn(0);
  ck_assert(return_value == false);
}
END_TEST

START_TEST(WhenGiven_MULT_s_r_ReturnFalse) {
  bool return_value = is_valid_rpn("*sr");
  ck_assert(return_value == false);
}
END_TEST

START_TEST(WhenGiven_n_POW_m_ReturnFalse) {
  bool return_value = is_valid_rpn("n^m");
  ck_assert(return_value == false);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("is_valid_rpn_tests");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, WhenGivenEmptyStringReturnsFalse);
  tcase_add_test(tc1_1, WhenGiven_a_ReturnTrue);
  tcase_add_test(tc1_1, WhenGiven_b_a_PLUS_ReturnTrue);
  tcase_add_test(tc1_1, WhenGiven_a_b_ReturnFalse);
  tcase_add_test(tc1_1, WhenGiven_a_b_c_PLUS_ReturnFalse);
  tcase_add_test(tc1_1, WhenGiven_a_b_c_PLUS_PLUS_ReturnTrue);
  tcase_add_test(tc1_1, WhenGiven_a_b_c_d_PLUS_PLUS_ReturnFalse);
  tcase_add_test(tc1_1, WhenGiven_a_b_c_d_PLUS_PLUS_MINUS_ReturnTrue);
  tcase_add_test(tc1_1, WhenGiven_e_f_g_h_i_j_k_6PLUS_ReturnTrue);
  tcase_add_test(tc1_1, WhenGiven_l_m_o_p_q_r_s_7SUB_ReturnTrue);
  tcase_add_test(tc1_1, WhenGiven_t_u_v_w_x_y_z_6SUB_ReturnTrue);
  tcase_add_test(tc1_1, WhenGiven_t_u_v_w_x_y_z_6MULT_ReturnTrue);
  tcase_add_test(tc1_1, WhenGiven_t_u_v_w_x_y_z_6DIV_ReturnTrue);
  tcase_add_test(tc1_1, WhenGiven_t_u_v_w_x_y_z_6POW_ReturnTrue);
  tcase_add_test(tc1_1, WhenGivenNullReturnsFalse);
  tcase_add_test(tc1_1, WhenGiven_MULT_s_r_ReturnFalse);
  tcase_add_test(tc1_1, WhenGiven_n_POW_m_ReturnFalse);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
