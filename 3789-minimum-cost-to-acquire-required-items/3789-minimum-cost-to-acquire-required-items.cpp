#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi first
#define se second
#define so(v) sort(v.begin(),v.end())
#define fo(i,n) for(int i=0;i<n;i++)
#define co(x)   cout<<x
#define coe(x)   cout<<x<<endl
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vii;
typedef vector<pair<ll,ll>> vpl;
typedef pair<ll,ll> pll;
#define pb push_back
vector<ll> fact, inv_fact;
const int mod=1000000007;
long long int mmi(long long int a ,long long int m ){
long long int res=1;
ll b=mod-2;
while(b>0){
if(b&1){
res=(res*a)%m;
}
a=(a*a)%m;
b>>=1;
}
return res;
}
long long power(long long a, long long b, int mod) {
long long result = 1;
a = a % mod;  
while (b > 0) {
 if (b % 2 == 1) {
 result = (result * a) % mod;
}
 b = b >> 1; 
a = (a * a) % mod; 
}
return result;
}
void precompute(int n) {
fact.resize(n + 1);
inv_fact.resize(n + 1);
fact[0] = 1;
for (int i = 1; i <= n; i++) {
 fact[i] = (fact[i - 1] * i) % mod;
}
 inv_fact[n] = mmi(fact[n], mod); 
for (int i = n - 1; i >= 0; i--) {
inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
 }
}
 ll bc(int n, int k) {
 if (k > n || k < 0) return 0;
return (fact[n] * inv_fact[k] % mod) * inv_fact[n - k] % mod;
}
int nCr_mod2(int n, int r) {
    if (r > n) return 0;
    while(n || r) {
        if ((r & 1) > (n & 1))
            return 0;
        n >>= 1;
        r >>= 1;
    }
    return 1;
}
int nCr_mod5(int n, int r) {
    if (r > n) return 0;
    int table[5][5] = {
        {1, 0, 0, 0, 0},  
        {1, 1, 0, 0, 0},  
        {1, 2, 1, 0, 0},  
        {1, 3, 3, 1, 0},  
        {1, 4, 1, 4, 1}   
    };

    int res = 1;
   
    while(n > 0 || r > 0) {
        int n_digit = n % 5;
        int r_digit = r % 5;
        if(r_digit > n_digit)
            return 0;
        res = (res * table[n_digit][r_digit]) % 5;
        n /= 5;
        r /= 5;
    }
    return res;
}

int combineCRT(int a, int b) {
    for (int k = 0; k < 2; k++) {
        int x = b + 5 * k;
        if (x % 2 == a)
            return x % 10;
    }
    return -1; 
}

int bc2(int n, int r) {
    int res2 = nCr_mod2(n, r);
    int res5 = nCr_mod5(n, r);
    return combineCRT(res2, res5);
}
ll ad(ll a,ll b){
    return ((a%mod) + (b%mod)+mod)%mod;
}
ll mul(ll a,ll b){
    return ((a%mod) *(b%mod))%mod;
}
ll ceil(ll n,ll k){
if(n%k==0){
 return n/k;
}
 else{
return (n/k)+1;
}
}
bool comp (pair<ll,ll>a,pair<ll,ll>b){
if(max(a.first,a.second)>max(b.first,b.second)){
 return false;
}
else if(max(a.first,a.second)==max(b.first,b.second)){
if(min(a.first,a.second)>=min(b.first,b.second)){
return false;
}
else{
return true;
}
}
else{
return true;
}
}
void solve(){
ll n;
cin>>n;
vector<ll> v(n);
for(int i=0;i<n;i++){
   cin>>v[i];
}





}
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(cost1+cost2<=costBoth){
            return (ll)cost1*need1+(ll)cost2*need2;
        }
        ll ans=0;
        ans+=(ll)min(need1,need2)*(ll)costBoth;
        ll dif=abs(need1-need2);
        if(need1>need2){
            if(cost1<costBoth){
                ans+=dif*cost1;
            }
            else{
                ans+=dif*costBoth;
            }

        }
        else{
            if(cost2<costBoth){
                ans+=dif*cost2;
            }
            else{
                ans+=dif*costBoth;
            }
        }
        return ans;
    }
};