#include "gtest/gtest.h"
#include "array_and_strings.h"

TEST(array_and_strings_tests, permutation_test) {
    // method 1
    std::string str = "abcdef";
    std::string to_check = "fedcba";
    ASSERT_TRUE(is_permutation(str, to_check));
    str = "fedcbf";
    to_check = "fedcba";
    ASSERT_FALSE(is_permutation(str, to_check));
    str = "fedcbaa";
    to_check = "abcdef";
    ASSERT_FALSE(is_permutation(str, to_check));

    // method 2
    str = "abcdef";
    to_check = "fedcba";
    ASSERT_TRUE(is_permutation_count_method(str, to_check));
    str = "fedcbf";
    to_check = "fedcba";
    ASSERT_FALSE(is_permutation_count_method(str, to_check));
    str = "fedcbaa";
    to_check = "abcdef";
    ASSERT_FALSE(is_permutation_count_method(str, to_check));
}

TEST(array_and_strings_tests, urlify_test) {
    // method 1
    int len = 13;
    char str[len] = "Mr John Smith    ";
    urlify(str, len);
    std::string out_str(str);
    ASSERT_EQ("Mr%20John%20Smith", out_str);

    len = 4;
    char str2[len] = "            ";
    urlify(str2, len);
    std::string out_str2(str2);
    ASSERT_EQ("%20%20%20%20", out_str2);

    // method 2
    len = 13;
    char str3[len] = "Mr John Smith    ";
    urlify_count_method(str3, len);
    std::string out_str3(str3);
    ASSERT_EQ("Mr%20John%20Smith", out_str3);

    len = 4;
    char str4[len] = "            ";
    urlify_count_method(str4, len);
    std::string out_str4(str4);
    ASSERT_EQ("%20%20%20%20", out_str4);

}