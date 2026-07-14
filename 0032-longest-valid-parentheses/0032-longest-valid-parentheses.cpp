class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n < 2) return 0;
        
        stack<int> st;
        st.push(-1);  // Base index for calculation
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {  // s[i] == ')'
                st.pop();
                
                if (st.empty()) {
                    st.push(i);  // New base
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        
        return maxLen;
    }
};