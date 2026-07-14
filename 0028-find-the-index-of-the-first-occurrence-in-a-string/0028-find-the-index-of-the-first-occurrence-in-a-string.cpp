class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        
        if (n == 0) return 0;
        if (n > m) return -1;
        
        // Build LPS (Longest Proper Prefix which is also Suffix) array
        vector<int> lps(n, 0);
        int len = 0;  // length of previous longest prefix suffix
        int i = 1;
        
        while (i < n) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        // Search using KMP
        i = 0;  // index for haystack
        int j = 0;  // index for needle
        
        while (i < m) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                
                if (j == n) {
                    return i - j;  // Found pattern
                }
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        return -1;
    }
};