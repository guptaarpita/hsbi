class Solution {
public:
    int minOperations(string s) {
        string target = s;
        sort(target.begin(), target.end());
        if(s == target)
        return 0;
        auto head = [](string t){
            sort(t.begin(), t.end() - 1);
            return t;
        };
        auto tail = [](string t){
            sort(t.begin() +1, t.end());
            return t;
        };
        vector<string> level = {s};
        for(int ops = 1; ops <= 3; ++ops){
            vector<string> next;
            for(string& t : level){
                for(string u : {head(t), tail(t)}){
                    if(u == target)
                    return ops;
                    next.push_back(u);
                }
            }
            level = next;
        }
        return -1;
    }
};