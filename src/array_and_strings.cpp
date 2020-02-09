#include "array_and_strings.h"
#include <sstream>

bool check_if_unique(std::string str)
{
    uint32_t size = str.size();
    char checked[size];
    for (uint32_t i = 0; i < size; i++)
    {
        for (uint32_t j = 0; j < i; j++)
        {
            if (str.at(i) == checked[j])
            {
                return false;
            }
        }
        checked[i] = str.at(i);
    }
    return true;
}

bool is_permutation(std::string str, std::string to_check)
{
    if (str.size() != to_check.size())
    {
        return false;
    }
    return is_permutation_(str, to_check);
}

bool is_permutation_(std::string str, std::string to_check)
{
    if (to_check == "")
    {
        return true;
    }
    for (uint32_t i = 0; i < str.size(); i++)
    {
        if (str[i] == to_check[0])
        {
            to_check.erase(to_check.begin());
            str = str.substr(0, i) + str.substr(i + 1, str.size() - i - 1);
            if (!is_permutation_(str, to_check))
            {
                return false;
            }
            return true;
        }
    }
    return false;
}

bool is_permutation_count_method(std::string str1, std::string str2)
{
    if (str1.length() != str2.length())
    {
        return false;
    }
    int count[256] = {0};
    for (uint i = 0; i < str1.length(); i++)
    {
        int val = str1[i];
        count[val]++;
    }
    for (uint j = 0; j < str2.length(); j++)
    {
        int val = str2[j];
        count[val]--;
        if (count[val] < 0)
        {
            return false;
        }
    }
    return true;
}

void urlify(char* str, int len)
{   int token_len = 3;
    const char token[token_len] = "%20";
    char* tmp = str + len - 1;
    int inserted = 0;
    for (int i = 0; i < len; i++)
    {
        if (*tmp == ' ')
        {
            char* tmp1 = str + len + token_len - 2 + inserted;
            char* tmp2 = str + len - 1 + inserted;
            for (int j = 0; j < i + inserted; j++)
            {
                *tmp1 = *tmp2;
                tmp1--;
                tmp2--;
            }
            for (int k = token_len - 1; k >= 0; k--)
            {
                *tmp1 = token[k];
                tmp1--;
            }
            inserted += 2;
        }
        tmp--;
    }
}

void urlify_count_method(char* str, int len)
{
    int token_len = 3;
    int spaces = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            spaces++;
        }
    }

    int additional = spaces * (token_len - 1);
    int expected_len = len + additional;
    char* tmp1 = str + expected_len - 1;
    char* tmp2 = str + len - 1;
    for (int j = 0; j < len; j++)
    {
        if (*tmp2 == ' ')
        {
            *tmp1 = '0';
            tmp1--;
            *tmp1 = '2';
            tmp1--;
            *tmp1 = '%';
        }
        else
        {
            *tmp1 = *tmp2;
        }
        tmp1--;
        tmp2--;
    }
}

bool is_palidrom_permutation_toggle(std::string str)
{
    int bitVector = 0;
    for (auto& ch : str)
    {
        if (ch == ' ')
        {
            continue;
        }
        int id = std::tolower(ch);
        int mask = 1 << id;
        if ((bitVector & mask) == 0)
        {
            bitVector |= mask;
        }
        else
        {
            bitVector &= ~mask;
        }
    }
    if ((bitVector == 0) || ((bitVector & (bitVector - 1)) == 0))
    {
        return true;
    }
    return false;
}


bool is_palidrom_permutation(std::string str)
{
    std::vector<char> unique;
    unique.reserve(str.length());
    std::vector<uint> space_idx;
    space_idx.reserve(str.length());
    char val_single = ' ';
    int single = 0;
    int chars_count = 0;
    int chars[256] = {0};
    for (auto& ch : str)
    {
        if (ch != ' ')
        {
            int val = std::tolower(ch);
            chars[val]++;
            chars_count++;
        }
    }
    // even length
    if (chars_count % 2 == 0)
    {
        for (uint i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ')
            {
                space_idx.push_back(i);
                continue;
            }
            int val = std::tolower(str[i]);
            if (chars[val] == 0)
            {
                continue;
            }
            if (chars[val] % 2 != 0)
            {
                return false;
            }
            unique.push_back(std::tolower(str[i]));
            chars[val] -= 2;
        }
    }
    // odd length
    else
    {
        for (uint i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ')
            {
                space_idx.push_back(i);
                continue;
            }
            int val = std::tolower(str[i]);
            if (chars[val] == 0)
            {
                continue;
            }
            if (chars[val] % 2 != 0)
            {
                if (single == 0)
                {
                    single++;
                    val_single = std::tolower(str[i]);
                    continue;
                }
                else
                {
                    return false;
                }
            }
            unique.push_back(std::tolower(str[i]));
            chars[val] -= 2;
       }      
    }
    std::cout << "Permutations: " << std::endl;
    palindrom_permutations(unique, space_idx, val_single);
    return true;
}

void palindrom_permutations(std::vector<char> unique, std::vector<uint> space_idx, char single)
{
    palindrom_permutations_(unique, space_idx, single, "");
}

void palindrom_permutations_(std::vector<char> unique, std::vector<uint> space_idx, char single, std::string out)
{
    if (unique.size() == 0)
    {
        uint length_tmp = out.length();
        if (single != ' ')
        {
            out += single;
        }
        for (int i = length_tmp - 1; i >= 0; i--)
        {
            out += out[i];
        }
        for (int j = out.length() - 1; j > 0; j--)
        {
            for (auto& idx : space_idx)
            {
                if (static_cast<int>(idx) == j)
                {
                    auto out1 = out.substr(0, j);
                    auto out2 = out.substr(j, out.length() - j);
                    out = out1 + ' ' + out2;
                }
            }
        }
        std::cout << out << std::endl;
    }
    for (uint i = 0; i < unique.size(); i++)
    {
        auto foo = out + unique[i];
        std::vector<char> unique_reduced;
        for (uint j = 0; j < unique.size(); j++)
        {
            if (j != i)
            {
                unique_reduced.push_back(unique[j]);
            }
        }
        palindrom_permutations_(unique_reduced, space_idx, single, foo);
    }
}

bool one_away(std::string str1, std::string str2)
{
    // check length
    if (abs(str1.length() - str2.length()) > 1)
    {
        return false;
    }
    std::string::iterator longer;
    std::string::iterator longer_end;
    std::string::iterator shorter;
    if (str1.length() >= str2.length())
    {
        longer = str1.begin();
        longer_end = str1.end();
        shorter = str2.begin();
    }
    else
    {
        longer = str2.begin();
        longer_end = str2.end();
        shorter = str1.begin();
    }
    int diff = 0;
    while (longer != (longer_end + 1))
    {
        if (*longer != *shorter)
        {
            diff++;
            if (str1.length() == str2.length())
            {
                shorter++;
            }
            longer++;
        }
        else
        {
            longer++;
            shorter++;
        }
        if (diff > 1)
        {
            return false;
        }     
    }
    return true;
}

std::string string_compression(std::string input_string)
{
    std::string out_string = "";
    int counter = 0;
    char last = input_string[0];
    for (auto& ch : input_string)
    {
        if (ch == last)
        {
            counter++;
        }
        else
        {
            out_string += last;
            out_string += std::to_string(counter);
            last = ch;
            counter = 1;
        }
    }
    out_string += last;
    out_string += std::to_string(counter);
    if (out_string.length() >= input_string.length())
    {
        return input_string;
    }
    return out_string;
}

void matrix_rotation(std::vector<std::vector<int32_t>>& matrix, int N)
{
    for (int i = 0, it_N = N - 1; i < it_N; i++, it_N--)
    {
        for (int j = i; j < it_N; j++)
        {
            std::tuple<int, int> dest_idx = std::make_tuple(j, N - 1 - i);
            auto current_idx = std::make_tuple(i, j);
            replace_value(current_idx, current_idx, dest_idx, matrix, N);
        }
    }
}

void replace_value(std::tuple<int, int>& start_idx, std::tuple<int, int> current_idx, std::tuple<int, int> dest_idx, std::vector<std::vector<int32_t>>& matrix, int N)
{
    auto tmp = matrix[std::get<0>(current_idx)][std::get<1>(current_idx)];
    auto new_current_idx = dest_idx;
    if (new_current_idx == start_idx)
    {
        matrix[std::get<0>(dest_idx)][std::get<1>(dest_idx)] = tmp;
        return;
    }
    auto new_dest_idx = std::make_tuple(std::get<1>(dest_idx), N - 1 - std::get<0>(dest_idx));
    replace_value(start_idx, new_current_idx, new_dest_idx, matrix, N);
    matrix[std::get<0>(dest_idx)][std::get<1>(dest_idx)] = tmp;
}

void zero_matrix(std::vector<std::vector<int32_t>>& matrix)
{
    size_t x = matrix.size();
    size_t y = matrix[0].size();
    std::set<uint> x_idx;
    std::set<uint> y_idx;
    for (uint i_x = 0; i_x < x; i_x++)
    {
        for (uint i_y = 0; i_y < y; i_y++)
        {
            if (matrix[i_x][i_y] == 0)
            {
                x_idx.insert(i_x);
                y_idx.insert(i_y);
            }
        }
    }
    auto x_start = x_idx.begin();
    auto y_start = y_idx.begin();
    for (uint i_x = 0; i_x < x; i_x++)
    {
        for (uint i_y = 0; i_y < y; i_y++)
        {
            if (*x_start == i_x || *y_start == i_y)
            {
                matrix[i_x][i_y] = 0;
                if (*y_start == i_y)
                {
                    y_start++;
                }
            }
        }
        if (*x_start == i_x)
        {
            x_start++;
        }
        y_start = y_idx.begin();
    }
}

bool string_rotation(std::string str1, std::string str2)
{
    if (str1.length() != str2.length() ||
        str1.length() == 0)
    {
        return false;
    }
    std::string concatenated = str1 + str1;
    if (concatenated.find(str2) != std::string::npos)
    {
        return true;
    }
    return false;
}

std::vector<std::string> get_substr(std::string str, char delimiliter)
{
    std::string s;
    std::vector<std::string> output;
    std::istringstream iss(str);
    while (std::getline(iss, s, delimiliter))
    {
        std::cout << s << std::endl;
        output.push_back(s);
    }
    return output;
}