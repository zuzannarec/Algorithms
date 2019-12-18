#include "gtest/gtest.h"
#include "array_and_strings.h"
#include <vector>

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

TEST(array_and_strings_tests, is_palindrom_permutation_test) {
    // method 1
    std::string str = "Tact Coa";
    ASSERT_TRUE(is_palidrom_permutation(str));
    str = "Omper om erp";
    ASSERT_TRUE(is_palidrom_permutation(str));
    str = " Tactboa";
    ASSERT_FALSE(is_palidrom_permutation(str));

    // method 2
    str = "Tact Coa";
    ASSERT_TRUE(is_palidrom_permutation_toggle(str));
    str = "Omper om erp";
    ASSERT_TRUE(is_palidrom_permutation_toggle(str));
    str = " Tactboa";
    ASSERT_FALSE(is_palidrom_permutation_toggle(str));
}

TEST(array_and_strings_tests, one_away) {
    // method 1
    std::string str1 = "pales";
    std::string str2 = "pale";
    ASSERT_TRUE(one_away(str1, str2));
    str1 = "pale";
    str2 = "ple";
    ASSERT_TRUE(one_away(str1, str2));
    str2 = "bale";
    ASSERT_TRUE(one_away(str1, str2));
    str2 = "bake";
    ASSERT_FALSE(one_away(str1, str2));
}

TEST(array_and_strings_tests, string_compression) {
    // method 1
    std::string str1 = "aabcccccaaa";
    std::string str2 = "a2b1c5a3";
    ASSERT_EQ(string_compression(str1), str2);
    str1 = "aabcccccaaak";
    str2 = "a2b1c5a3k1";
    ASSERT_EQ(string_compression(str1), str2);
    str1 = "aabc";
    ASSERT_EQ(string_compression(str1), str1);
}

TEST(array_and_strings_tests, rotate_matrix) {
    // method 1
    std::vector<std::vector<int32_t>> matrix = {{1, 2, 3, 4, 5},
                                                {6, 7, 8, 9, 10},
                                                {11, 12, 13, 14, 15},
                                                {16, 17, 18, 19, 20},
                                                {21, 22, 23, 24, 25}};
    std::vector<std::vector<int32_t>> rotate_matrix = {{21, 16, 11, 6, 1},
                                                       {22, 17, 12, 7, 2},
                                                       {23, 18, 13, 8, 3},
                                                       {24, 19, 14, 9, 4},
                                                       {25, 20, 15, 10, 5}};
    int N = 5;
    matrix_rotation(matrix, N);
    ASSERT_EQ(matrix, rotate_matrix);
}

TEST(array_and_strings_tests, zero_matrix) {
    // method 1
    std::vector<std::vector<int32_t>> matrix = {{1, 2, 0, 3, 4, 5},
                                                {6, 7, 90, 8, 9, 10},
                                                {11, 12, 22, 13, 14, 15},
                                                {16, 17, 55, 18, 0, 20},
                                                {21, 22, 8, 23, 24, 25}};
    std::vector<std::vector<int32_t>> zeroed_matrix = {{0, 0, 0, 0, 0, 0},
                                                     {6, 7, 0, 8, 0, 10},
                                                     {11, 12, 0, 13, 0, 15},
                                                     {0, 0, 0, 0, 0, 0},
                                                     {21, 22, 0, 23, 0, 25}};
    zero_matrix(matrix);
    ASSERT_EQ(matrix, zeroed_matrix);
}