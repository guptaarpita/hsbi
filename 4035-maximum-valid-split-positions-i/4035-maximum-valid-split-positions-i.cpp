class Solution {
public:
    int f(vector<int>&nums){
         int n=nums.size();
        if(n==1){
            return 0;
        }
        vector<int>pre(n);
        vector<int>suf(n);
        pre[0]=nums[0];
        suf[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            
            pre[i]=__gcd(pre[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            suf[i]=__gcd(suf[i+1],nums[i]);
        }
        int cn=0;;
        for(int i=0;i<n-1;i++){
            if(pre[i]==suf[i+1]){
                cn++;
            }
        }
        cout<<cn<<endl;
        return cn;
    }
    int maxValidSplits(vector<int>& nums) {
     int ans=f(nums);
        int n=nums.size();
       
        for(int i=0;i<n;i++){
            vector<int>cur;
           for(int j=0;j<n;j++){
               if(j!=i){
                   
                   cur.push_back(nums[j]);
               }
           }
            ans=max(ans,f(cur));
        }
        return ans;
    }
};