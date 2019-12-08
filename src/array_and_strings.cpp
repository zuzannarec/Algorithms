#include "array_and_strings.h"

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