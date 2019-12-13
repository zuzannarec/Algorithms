#include <stdint.h>
#include <iostream>
#include <vector>

bool check_if_unique(std::string str);

bool is_permutation(std::string str, std::string to_check);

bool is_permutation_(std::string str, std::string to_check);

bool is_permutation_count_method(std::string str1, std::string str2);

void urlify(char* str, int len);

void urlify_count_method(char* str, int len);

bool is_palidrom_permutation(std::string str);

void palindrom_permutations(std::vector<char> unique, std::vector<uint> space_idx, char single);

void palindrom_permutations_(std::vector<char> unique, std::vector<uint> space_idx, char single, std::string out);