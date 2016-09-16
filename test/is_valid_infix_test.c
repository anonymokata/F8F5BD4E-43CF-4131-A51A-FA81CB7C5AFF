#include <check.h>
#include "../src/is_valid_infix.h"

START_TEST(WhenGivenEmptyStringReturnsTrue)
{
  bool return_value = is_valid_infix("");
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
    tcase_add_test(tc1_1, WhenGivenEmptyStringReturnsTrue);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
