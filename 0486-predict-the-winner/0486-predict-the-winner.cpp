class Solution {
public:
int f(int i,int j,vector<int>&v,vector<int>&pref,vector<vector<int>>&dp){
    int n=v.size();
    if(i>j){
        return 0;
    }
    if(i==j){
        return v[i];
    }
    if(dp[i][j]==-1){
        
        int x=pref[j];
        x-=pref[i];
        x-= f(i+1,j,v,pref,dp);
        int y=pref[j-1];
        if(i-1>=0){
            y-=pref[i-1];
        }
        y-=f(i,j-1,v,pref,dp);
        y+=v[j];
        x+=v[i];
        dp[i][j]=max(x,y);
    }
    return dp[i][j];
}
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n);
        for(int i=0;i<n;i++){
            pre[i]=nums[i];
            if(i){
                pre[i]+=pre[i-1];
            }
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int x=f(0,n-1,nums,pre,dp);
        int y=pre[n-1];
        y-=x;
        if(x>=y){
            return true;
        }
        return false;
    }
};