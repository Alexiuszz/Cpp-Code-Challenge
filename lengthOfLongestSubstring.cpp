#include <iostream>
#include <string>
#include <cstring>

using namespace std;
class Solution
{
public:
        int lengthOfLongestSubstring(string s)
        {
                int maxLength = 0, start = 0;
                int chars[128];
                std::fill_n(chars, 128, -1);

                for (int end = 0; end < s.length(); ++end)
                {
                        const int charCode = static_cast<int>(s[end]);
                        start = start > chars[charCode] + 1 ? start : chars[charCode] + 1;
                        chars[charCode] = end;
                        maxLength = maxLength > end - start + 1 ? maxLength : end - start + 1;
                }
                return maxLength;
        }
};

int main()
{
        Solution length;
        cout << length.lengthOfLongestSubstring("hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
}