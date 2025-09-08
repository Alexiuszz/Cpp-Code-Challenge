#include <iostream>
#include <string>
#include <cstring>

using namespace std;
class Solution
{
public:
        int lengthOfLongestSubstring(string s)
        {
                int maxLength = 0, start = 0; // start of the current substring without repeating characters
                int chars[128]; // ASCII character set
                std::fill_n(chars, 128, -1);  // Initialize all characters as not seen

                for (int end = 0; end < s.length(); ++end) // end is the end of the current substring, 
                {
                        const int charCode = static_cast<int>(s[end]); // Get ASCII value of the character
                        // If the character was seen and is within the current substring
                        start = start > chars[charCode] + 1 ? start : chars[charCode] + 1;
                        chars[charCode] = end;// Update the last seen index of the character
                        
                        maxLength = maxLength > end - start + 1 ? maxLength : end - start + 1;// Update maxLength if we found a longer substring
                }
                return maxLength;
        }
};

int main()
{
        Solution length;
        cout << length.lengthOfLongestSubstring("hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
}