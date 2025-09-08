#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        unordered_map<char, int> charCount;
        int maxLen = 0;
        int maxCharCount = 0;

        while(right < s.size()){
            charCount[s[right]]++;// Increment the count of the current character
            maxCharCount = max(maxCharCount, charCount[s[right]]); // Update the count of the most frequent character in the current window
            int windowSize  = right - left + 1;

            if(windowSize - maxCharCount > k)  {
                charCount[s[left]]--; // Decrement the count of the character going out of the window
                left++; // Shrink the window from the left
            }
            right++; // Expand the window to the right
            maxLen = max(maxLen, right - left); // Update the maximum length found
        }
        return maxLen;
    }
};


int main() {
    Solution solution;
    string s = "AABABBA";
    int k = 1;
    int result = solution.characterReplacement(s, k);
    cout << "Result: " << result << endl; // Expected output: 4
    return 0;
}