#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <unordered_map>
#include "linked_list.h"

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int duplicate_num = nums[0];
    int sum = 1;
    for (size_t i = 1; i < nums.size(); ++i)
    {
        if (duplicate_num == nums[i])
        {
            nums.erase(nums.begin() + i);
            --i;
        }
        else
        {
            duplicate_num = nums[i];
            ++sum;
        }
    }
    return sum;
}

int maxProfit(vector<int> &prices)
{
    int money = 0;
    bool up = false;
    for (size_t i = 1; i < prices.size(); i++)
    {
        if (prices[i - 1] < prices[i])
        {
            if (!up)
                money -= prices[i - 1]; // buy
            up = true;
        }
        else if (prices[i - 1] > prices[i])
        {
            if (up)
                money += prices[i - 1]; //sell
            up = false;
        }
        if (i == prices.size() - 1 && prices[i - 1] <= prices[i] && up)
            money += prices[i];
    }
    return money;
}

bool containsDuplicate(vector<int> &nums)
{
    for (size_t i = 1; i < nums.size(); ++i)
    {
        for (size_t j = 0; j < i; ++j)
        {
            if (nums[i] == nums[j])
                return true;
        }
    }
    return false;
}

int singleNumber(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums.front();

    sort(nums.begin(), nums.end());
    for (size_t i = 1; i < nums.size(); i += 2)
    {
        if (nums[i - 1] != nums[i])
            return nums[i - 1];
    }
    return nums.back();
}

vector<int> plusOne(vector<int> &digits)
{
    int carry = 1;
    int i = digits.size() - 1;
    while (carry)
    {
        digits[i] += carry;
        if (digits[i] == 10)
        {
            carry = 1;
            digits[i] = 0;
        }
        else
            carry = 0;
        --i;
        if (i < 0 && carry)
        {
            digits.insert(digits.begin(), 1);
            break;
        }
    }
    return digits;
}

void moveZeroes(vector<int> &nums)
{
    int count = 0;
    auto iter = nums.begin();
    while (iter < nums.end())
    {
        if (*iter == 0)
        {
            iter = nums.erase(iter);
            ++count;
        }
        else
            ++iter;
    }

    for (size_t i = 0; i < count; ++i)
        nums.push_back(0);
}

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> res{0, 0};
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = 0; j < nums.size(); j++)
        {
            if (i == j)
                continue;
            if (nums[i] + nums[j] == target)
            {
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    return res;
}

// row 0 -> col r0
// col r0 -> row b0
// row b0 -> col 0
// col 0 -> row 0

// 0, i -> i, n
// i, n -> n, n-i
// n, n-i -> n-i, 0
// n-i, 0 -> 0, i

// x, x
// n = n-(x*2)

// x, x+i -> x+i, x+n-1
// x+i, x+n-1 -> x+n-1, x+n-i-1
// x+n, x+n-i-1 -> x+n-i-1, x
// x+n-i-1, x -> x, x+i

// x = 第幾內圈
// n = x層的邊 size - 1
// i = iterator

void rotate(vector<vector<int>> &matrix)
{
    int side_length = matrix.size();
    int layer_size = side_length / 2;
    for (size_t x = 0; x < layer_size; x++)
    {
        for (size_t i = 0; i < side_length - 1; i++)
        {
            std::swap(matrix[x][x + i], matrix[x + i][x + side_length - 1]);
            std::swap(matrix[x][x + i], matrix[x + side_length - 1][x + side_length - i - 1]);
            std::swap(matrix[x][x + i], matrix[x + side_length - i - 1][x]);
        }
        side_length -= 2;
    }
}

void reverseString(vector<char> &s)
{
    for (size_t i = 0; i < s.size() / 2; i++)
        std::swap(s[i], s[s.size() - i - 1]);
}

// 123

// current_scalar = 3
// x = 12
// res = 3

// current_scalar = 2
// x = 1
// res = 32

// current_scalar = 1
// x = 0
// res = 321
int reverse(int x)
{
    int res = 0;
    while (x != 0)
    {
        if (res > INT_MAX / 10)
            return 0;
        if (res < INT_MIN / 10)
            return 0;
        int current_scalar = x % 10;
        x /= 10;
        res = res * 10 + current_scalar;
    }
    return res;
}

int firstUniqChar(string s)
{
    unordered_map<char, int> map;

    for (size_t i = 0; i < s.length(); i++)
    {
        if (map.find(s[i]) == map.end())
            map[s[i]] = 1;
        else
            map[s[i]] += 1;
    }

    for (size_t i = 0; i < s.length(); i++)
    {
        if (map.find(s[i]) != map.end() && map[s[i]] == 1)
            return i;
    }
    return -1;
}

bool isAnagram(string s, string t)
{
    unordered_map<char, int> map;

    for (size_t i = 0; i < s.length(); i++)
    {
        if (map.find(s[i]) == map.end())
            map[s[i]] = 1;
        else
            map[s[i]] += 1;
    }

    for (size_t i = 0; i < t.length(); i++)
    {
        if (map.find(t[i]) == map.end())
            return false;
        else
        {
            map[t[i]] -= 1;
        }
        if (map[t[i]] == 0)
            map.erase(t[i]);
    }
    return map.empty();
}

string countAndSay(int n)
{
    if (n == 1)
        return "1";
    else if (n == 2)
        return "11";
    else
    {
        auto str = countAndSay(n - 1);
        string res_str;
        int current_size = 1;
        for (size_t i = 1; i < str.length(); i++)
        {
            if (str[i - 1] == str[i])
            {
                current_size += 1;
                if (i == str.length() - 1)
                    res_str += to_string(current_size) + str[i - 1];
            }
            else
            {
                res_str += to_string(current_size) + str[i - 1];
                current_size = 1;
                if (i == str.length() - 1)
                {
                    res_str.append("1");
                    res_str += str[i];
                    cout << str[i] << endl;
                }
            }
        }
        return res_str;
    }
}

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
        return "";

    int i = 0;
    string s = strs[0];

    while (i >= 0)
    {
        for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it)
        {
            if (s[i] == '\0' || (*it)[i] == '\0' || s[i] != (*it)[i])
            {
                return (s.substr(0, i));
            }
        }
        i++;
    }
    return "";
}

int main()
{
    vector<int> vec1{0, 1, 3, 6, 10};
    vector<int> vec2{2, 4, 5, 7, 8, 9};

    auto list1 = CreateList(vec1);
    auto list2 = CreateList(vec2);
    auto merge = mergeTwoLists(list1, list2);  
    ShowList(merge);

    return 0;
}