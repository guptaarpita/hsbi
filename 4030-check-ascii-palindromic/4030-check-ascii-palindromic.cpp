class Solution {
public:
    bool isPalindromic(string s) {
        int n=s.size();
        vector<int>ans;
            for(int i=0;i<n;i++){
            vector<int>v(8);
            int xn= static_cast<int>(s[i]);
            cout<<xn<<endl;
            for(int i=7;i>=0;i--){
                if(xn%2==1){
                    v[i]=1;
                }
                xn/=2;
            }
            for(int i=0;i<8;i++){
              ans.push_back(v[i]);
            }
            }
        int si=n*8;
        for(int i=0;i<si/2;i++){
            if(ans[i]!=ans[si-1-i]){
                return false;
            }
        }
        
        return true;
    }
};