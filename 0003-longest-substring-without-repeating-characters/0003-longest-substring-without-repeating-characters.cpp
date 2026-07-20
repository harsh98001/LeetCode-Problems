#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex; // char -> most recent index seen
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];
            auto it = lastIndex.find(c);
            // Only move left if the duplicate is inside the current window
            if (it != lastIndex.end() && it->second >= left) {
                left = it->second + 1;
            }
            lastIndex[c] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};