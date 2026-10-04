class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;  
        int high = 0;  

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else { 
                low--;   // treat '*' as ')'
                high++;  // treat '*' as '('
            }

            // We can never have fewer than 0 unmatched '('
            if (high < 0)
                return false;

            low = max(low, 0);
        }

        // If minimum possible unmatched '(' is 0,
        // we can make the string valid.
        return low == 0;
    }
};