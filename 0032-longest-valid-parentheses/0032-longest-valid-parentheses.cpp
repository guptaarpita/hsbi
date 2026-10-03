class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, ans = 0;
        for (char c : s) {
            if (c == '(')
                left++;
            else
                right++;

            if (left == right)
                ans = max(ans, 2 * right);
            else if (right > left)
                left = right = 0;
        }
        
       
        return ans;
    }
};