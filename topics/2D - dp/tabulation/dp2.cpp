/*
https://atcoder.jp/contests/abc253/tasks/abc253_e
*/
#include <bits/stdc++.h>
#define int long long int
#define Maxx 10000000000000
#define pb push_back
#define v vector
#define vi vector<int>
#define rep(i,a,b) for(int i=a; i<=b; i++)
#ifndef ONLINE_JUDGE
#define dbg(x) cerr<<#x<< " "; _print(x);cerr<<endl; 
#else
#define dbg(x)
#endif
using namespace std;


void _print(int x ){
    cerr<<x<<" "; 
}void _print(float x ){
    cerr<<x<<" "; 
}void _print(double x ){
    cerr<<x<<" "; 
}void _print(char x ){
    cerr<<x<<" "; 
}void _print(string x ){
    cerr<<x<<" "; 
}void _print(bool x){
    cerr<<x<<" "; 
}
template<class T,class V> void _print(pair<T,V>x){
    cerr<<"{"; _print(x.first);cerr<<",";_print(x.second); cerr<<"}"; 
}
template<class T> void _print(vector<T> x){
    cerr<<"[ "; 
    for(T i : x){
        _print(i); 
        cerr << " "; 
    }
    cerr<<"]"; 
}
template<class T> void _print(set<T> x){
    cerr<<"[ "; 
    for(T i : x){
        _print(i); 
        cerr << " "; 
    }
    cerr<<"]"; 
}
template<class T> void _print(multiset<T>x){
    cerr<<"[ "; 
    for(T i : x){
        _print(i); 
        cerr << " "; 
    }
    cerr<<"]"; 
}
template<class T , class V> void _print(map<T, V> x){
    cerr<<"[ "; 
    for(auto i : x){
        _print(i); 
        cerr<<" "; 
    }
    cerr<<" ]"; 
}
void solve()
{
    int n , m , k ; 
    cin >>n >> m >> k ; 
    int dp[n+1][m+1];
    int mod = 998244353; 
    memset(dp , 0 ,sizeof(dp));  
    rep(i , 1 , m ) {
        dp[1][i] =1; 
    }
    rep(i ,2, n){
        vi val(m+1 , 0); 
        rep(j ,1 ,m){
            val[j] = (val[j-1] + dp[i-1][j] +mod)%mod ;   
        }
        vi val1(m+2 , 0 ); 
        for (int j = m ; j >= 1; j--){
            val1[j]= (dp[i-1][j] + val1[j+1]+mod)%mod; 
        }

        rep(j ,1, m ){
            dp[i][j] = (dp[i][j] + (j-k>=1 ? val[j-k]: 0) + (j+k <= m ? val1[j+k] : 0 ) - (k == 0 ? dp[i-1][j] : 0) +mod)%mod ; 
        }

    }
    int ans =0 ; 
    rep(i ,1, m){
        ans = (ans + dp[n][i]+mod)%mod; 
    }
    cout<<ans<<endl; 
}
signed main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("inputf.in" , "r" , stdin ); 
    freopen("outputf.out", "w" , stdout); 
    freopen("err.txt","w",stderr);
    #endif
    clock_t start, end;
    start = clock();
    int t;
    //cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cerr << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cerr << " sec " << endl;
    return 0;
}

