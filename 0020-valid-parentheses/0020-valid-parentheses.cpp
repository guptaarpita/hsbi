class Solution {
public:
    bool isValid(string s) {
        std::stack<char>st;
        std::unordered_map<char,char> bracketPairs = {
            {')' , '('},
            {']' , '['},
            {'}' , '{'}
        };
        for(char c:s){
            if(bracketPairs.count(c)){
                if(st.empty() || st.top() != bracketPairs[c]){
                    return false;
                }
                st.pop();
            }else{
                st.push(c);
            }
        }
        return st.empty();
    }
};