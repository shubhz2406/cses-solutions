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
   
   /* 
      maintaining a temp array, storing the current max length of LIS that can be formed but the lis itself is not correct.
      
   */
      
   int n;
   cin >> n;
   vector a(n+1,0);
   vector<int> dp;
   for1(i,n) cin >> a[i];
   
   set<int> st;

   for(int i=1;i<=n;i++)
   {

      auto it = lower_bound(all(dp),a[i]);

      if(it == dp.end())
      {
         dp.pb(a[i]);
      }
      else 
      {
         int ind = it - dp.begin();
         dp[ind] = a[i];
      }

   
   }

   cout<<dp.size()<<nline;

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