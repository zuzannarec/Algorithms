#pragma once    
#include <stdint.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <set>

bool check_if_unique(std::string str);

bool is_permutation(std::string str, std::string to_check);

bool is_permutation_(std::string str, std::string to_check);

bool is_permutation_count_method(std::string str1, std::string str2);

void urlify(char* str, int len);

void urlify_count_method(char* str, int len);

bool is_palidrom_permutation(std::string str);

bool is_palidrom_permutation_toggle(std::string str);

void palindrom_permutations(std::vector<char> unique, std::vector<uint> space_idx, char single);

void palindrom_permutations_(std::vector<char> unique, std::vector<uint> space_idx, char single, std::string out);

bool one_away(std::string str1, std::string str2);

std::string string_compression(std::string input_string);

void matrix_rotation(std::vector<std::vector<int32_t>>& matrix, int N);

void replace_value(std::tuple<int, int>& start_idx, std::tuple<int, int> current_idx, std::tuple<int, int> dest_idx, std::vector<std::vector<int32_t>>& matrix, int N);

void zero_matrix(std::vector<std::vector<int32_t>>& matrix);

bool string_rotation(std::string str1, std::string str2);