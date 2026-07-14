class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string result = "1";
        
        for (int i = 2; i <= n; i++) {
            string current = "";
            int count = 1;
            
            for (int j = 0; j < result.length(); j++) {
                // Count consecutive identical characters
                while (j + 1 < result.length() && result[j] == result[j + 1]) {
                    count++;
                    j++;
                }
                // Append count and the digit
                current += to_string(count) + result[j];
                count = 1;
            }
            
            result = current;
        }
        
        return result;
    }
};