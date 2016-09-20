#include <check.h>
#include "../src/is_valid_infix.h"

START_TEST(WhenGivenEmptyStringReturnsFalse)
{
  bool return_value = is_valid_infix("");
  ck_assert(return_value == false);
}
END_TEST

START_TEST(WhenGivenNullReturnsFalse)
{
  bool return_value = is_valid_infix(0);
  ck_assert(return_value == false);
}
END_TEST

START_TEST(WhenGiven_1_ReturnFalse)
{
  bool return_value = is_valid_infix("1");
  ck_assert(return_value == false);
}
END_TEST

START_TEST(WhenGiven_2_ReturnFalse)
{
  bool return_value = is_valid_infix("2");
  ck_assert(return_value == false);
}
END_TEST

START_TEST(WhenGiven_3_ReturnFalse)
{
  bool return_value = is_valid_infix("3");
  ck_assert(return_value == false);
}
END_TEST

START_TEST(WhenGiven_a_ReturnTrue)
{
  bool return_value = is_valid_infix("a");
  ck_assert(return_value == true);
}
END_TEST

START_TEST(WhenGiven_a_PLUS_b_ReturnTrue)
{
  bool return_value = is_valid_infix("a+b");
  ck_assert(return_value == true);
}
END_TEST

START_TEST(WhenGiven_a_PLUS_b_PLUS_c_ReturnTrue)
{
  bool return_value = is_valid_infix("a+b+c");
  ck_assert(return_value == true);
}
END_TEST

START_TEST(WhenGiven_d_PLUS_e_PLUS_f_PLUS_g_PLUS_h_PLUS_i_ReturnTrue)
{
  bool return_value = is_valid_infix("d+e+f+g+h+i");
  ck_assert(return_value == true);
}
END_TEST

START_TEST(WhenGiven_j_MULT_k_MULT_l_PLUS_m_PLUS_n_DIV_o_ReturnTrue)
{
  bool return_value = is_valid_infix("j*k*l+m+n/o");
  ck_assert(return_value == true);
}
END_TEST

START_TEST(WhenGiven_p_POW_q_MULT_r_MULT_s_PLUS_t_PLUS_u_ReturnTrue)
{
  bool return_value = is_valid_infix("p^q*r*s+t+u");
  ck_assert(return_value == true);
}
END_TEST

START_TEST(WhenGiven_OPEN_v_PLUS_w_CLOSED_MULT_x_MULT_y_PLUS_z_ReturnTrue)
{
  bool return_value = is_valid_infix("(v+w)*x*y+z");
  ck_assert(return_value == true);
}
END_TEST

START_TEST(WhenGiven_Missing_Closed_Bracket_ReturnFalse)
{
  bool return_value = is_valid_infix("(a+(b)");
  ck_assert(return_value == false);
}
END_TEST

START_TEST(WhenGiven_Closed_Bracket_Closed_Bracket_ReturnFalse)
{
  bool return_value = is_valid_infix("()");
  ck_assert(return_value == false);
}
END_TEST

START_TEST(WhenGiven_Closed_Bracket_Open_Bracket_ReturnFalse)
{
  bool return_value = is_valid_infix(")(");
  ck_assert(return_value == false);
}
END_TEST

START_TEST(WhenGiven_Operand_Operand_Without_Operation_ReturnFalse)
{
  bool return_value = is_valid_infix("ab");
  ck_assert(return_value == false);
}
END_TEST

START_TEST(WhenGiven_OPEN_a_PLUS_b_CLOSED_c_ReturnFalse)
{
  bool return_value = is_valid_infix("(a+b)c");
  ck_assert(return_value == false);
}
END_TEST

START_TEST(WhenGiven_a_OPEN_b_PLUS_c_CLOSED_ReturnFalse)
{
  bool return_value = is_valid_infix("a(b+c)");
  ck_assert(return_value == false);
}
END_TEST

START_TEST(WhenGiven_Operator_First_ReturnFalse)
{
  bool return_value = is_valid_infix("+c");
  ck_assert(return_value == false);
}
END_TEST

START_TEST(WhenGiven_c_SUB_c_ReturnTrue)
{
  bool return_value = is_valid_infix("c-c");
  ck_assert(return_value == true);
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("is_valid_infix_tests");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, WhenGivenEmptyStringReturnsFalse);
    tcase_add_test(tc1_1, WhenGivenNullReturnsFalse);
    tcase_add_test(tc1_1, WhenGiven_1_ReturnFalse);
    tcase_add_test(tc1_1, WhenGiven_2_ReturnFalse);
    tcase_add_test(tc1_1, WhenGiven_3_ReturnFalse);
    tcase_add_test(tc1_1, WhenGiven_a_ReturnTrue);
    tcase_add_test(tc1_1, WhenGiven_a_PLUS_b_ReturnTrue);
    tcase_add_test(tc1_1, WhenGiven_a_PLUS_b_PLUS_c_ReturnTrue);
    tcase_add_test(tc1_1, WhenGiven_d_PLUS_e_PLUS_f_PLUS_g_PLUS_h_PLUS_i_ReturnTrue);
    tcase_add_test(tc1_1, WhenGiven_j_MULT_k_MULT_l_PLUS_m_PLUS_n_DIV_o_ReturnTrue);
    tcase_add_test(tc1_1, WhenGiven_p_POW_q_MULT_r_MULT_s_PLUS_t_PLUS_u_ReturnTrue);
    tcase_add_test(tc1_1, WhenGiven_OPEN_v_PLUS_w_CLOSED_MULT_x_MULT_y_PLUS_z_ReturnTrue);
    tcase_add_test(tc1_1, WhenGiven_Missing_Closed_Bracket_ReturnFalse);
    tcase_add_test(tc1_1, WhenGiven_Closed_Bracket_Closed_Bracket_ReturnFalse);
    tcase_add_test(tc1_1, WhenGiven_Closed_Bracket_Open_Bracket_ReturnFalse);
    tcase_add_test(tc1_1, WhenGiven_Operand_Operand_Without_Operation_ReturnFalse);
    tcase_add_test(tc1_1, WhenGiven_OPEN_a_PLUS_b_CLOSED_c_ReturnFalse);
    tcase_add_test(tc1_1, WhenGiven_a_OPEN_b_PLUS_c_CLOSED_ReturnFalse);
    tcase_add_test(tc1_1, WhenGiven_Operator_First_ReturnFalse);
    tcase_add_test(tc1_1, WhenGiven_c_SUB_c_ReturnTrue);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
