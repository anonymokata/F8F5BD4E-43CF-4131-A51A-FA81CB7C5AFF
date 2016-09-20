#include <check.h>
#include "../src/is_valid_rpn.h"

START_TEST(WhenGivenEmptyStringReturnsFalse)
{
  bool return_value = is_valid_rpn("");
  ck_assert(return_value == false);
}
END_TEST

START_TEST(WhenGiven_a_ReturnTrue)
{
  bool return_value = is_valid_rpn("a");
  ck_assert(return_value == true);
}
END_TEST

START_TEST(WhenGiven_b_a_PLUS_ReturnTrue)
{
  bool return_value = is_valid_rpn("ba+");
  ck_assert(return_value == true);
}
END_TEST

START_TEST(WhenGiven_a_b_ReturnFalse)
{
  bool return_value = is_valid_rpn("ab");
  ck_assert(return_value == false);
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("is_valid_rpn_tests");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, WhenGivenEmptyStringReturnsFalse);
    tcase_add_test(tc1_1, WhenGiven_a_ReturnTrue);
    tcase_add_test(tc1_1, WhenGiven_b_a_PLUS_ReturnTrue);
    tcase_add_test(tc1_1, WhenGiven_a_b_ReturnFalse);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}