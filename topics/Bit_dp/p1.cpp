/*
https://atcoder.jp/contests/abc215/tasks/abc215_e
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
    int n ; 
    cin >> n ; 
    string s; 
    cin >>s ;
    int mod = 998244353; 
    int dp[n+1][1024][10];
    memset(dp , 0 ,sizeof(dp)); 
    rep(i ,0, n-1) {
        int x = s[i]-'A'; 
        rep(j ,0 ,1023){
            rep(c, 0, 9){
                dp[i+1][j][c] = dp[i][j][c]; 
                if(c == x){
                    dp[i+1][j][x]= (dp[i+1][j][x]+ dp[i][j][x])%mod; 
                } 
            }
        }
        rep(j ,0, 1023){
            if(j&(1<<x)){
                continue;
            }
            rep(c, 0, 9){
                    dp[i+1][j|((1<<x))][x]+= dp[i][j][c]; 
                    dp[i+1][j|((1<<x))][x]%=mod; 
            }
        }
        dp[i+1][(1<<x)][x]++;
        dp[i+1][(1<<x)][x]%=mod; 
         
    }
    int ans =0 ; 
    rep(i ,0 ,1023){
        rep(j ,0 ,9){
            ans+= dp[n][i][j]; 
            ans%=mod; 
        }
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

