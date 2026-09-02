class Solution {
public:
    int f(int i,vector<int>&co,vector<int>&v,int &an){
        if(i==co.size()){
            int ans=0;
            for(int j=0;j<v.size();j++){

             ans=max(ans,v[j]);
            }
            an=min(an,ans);
            return ans;
        }
        int ans=1e9;
        for(int j=0;j<v.size();j++){
            v[j]+=co[i];
            if(v[j]>an){
                v[j]-=co[i];
                
            }
            else{
            ans=min(ans,f(i+1,co,v,an));
            v[j]-=co[i];
            }
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
         sort(cookies.rbegin(), cookies.rend());
       vector<int>v(k);
       int an=1e9;
       return f(0,cookies,v,an);
    }
};