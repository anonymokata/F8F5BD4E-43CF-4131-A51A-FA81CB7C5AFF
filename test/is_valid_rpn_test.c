#include <check.h>
#include "../src/is_valid_rpn.h"

START_TEST(WhenGivenEmptyStringReturnsFalse)
{
  bool return_value = is_valid_rpn("");
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

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
