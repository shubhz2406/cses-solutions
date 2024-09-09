#include<bits/stdc++.h>
 
#ifdef Shubh37
#include "debug.h"
#else
#define debug(x)  
#endif
 
using namespace std;
using namespace chrono;
 
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define for0(i,x) for(int i=0;i<x;i++)
#define for1(i,x) for(int i=1;i<=x;i++) 
#define forR(i,x) for(int i=x-1;i>=0;i--)
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<long long> vill;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
 
void solve()
{
 
         int a,b;
         cin >> a >> b;
         int n = max(a,b);
         debug(n)
         vector dp(n+1,vector(n+1,INT_MAX));
   
         dp[0][0] = 0;
         
         function<int(int,int)>f = [&](int i, int j)
         {
            if(i < j) swap(i,j);
            if(dp[i][j] != INT_MAX) return dp[i][j];
            if(i==j || i==0 || j==0) return dp[i][j] = 0;
            
            for(int k = (i+1)/2 ;k>=1;k--)
            {
                if(i - k > 0) dp[i][j] = min(1 + f(k,j) + f(i-k,j),dp[i][j]);
            }
            for(int k = (j+1)/2; k >= 1;k--)
            {
                if(j - k > 0) dp[i][j] = min(1 + f(i,k) + f(i,j-k),dp[i][j]);
            }
            return dp[i][j];
 
         };
 
         cout<<f(a,b)<<nline;
         debug(dp)
 
}
 
 
int main()
{
   #ifdef Shubh37
      freopen("Error.txt", "w", stderr);
   #endif
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
 
    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
   #ifdef Shubh37
    cerr << "Time: " << duration . count() / 1000 << endl;
   #endif
   
   return 0;
   
}