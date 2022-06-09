/*
https://codeforces.com/problemset/problem/455/A
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
    int n  ; 
    cin >> n;
    vi a(n); 
    int m = 1e5+1 ; 
    vi ct(m+1 , 0 ); 
    rep(i , 0 ,n-1){
        cin >> a[i]; 
        ct[a[i]]++; 
    } 

    vi b ;  
    rep(i , 1 , 1e5){
        if(ct[i] == 0){
            continue;
        }
        b.pb(i); 
    }
    n =b.size() ; 
    dbg(b); 
    int dp[n+1][2]; 
    memset(dp , 0 , sizeof(dp));
    dp[0][1] = ct[b[0]]*b[0]; 
    dp[0][0] = 0 ; 
    rep(i ,1 , n-1){
        if(b[i] - b[i-1] == 1 ){
            dp[i][1] = dp[i-1][0] + ct[b[i]]*b[i]; 
            dp[i][0] = max(dp[i-1][0] , dp[i-1][1]); 
        }else{
            dp[i][1] = max(dp[i-1][1] , dp[i-1][0]) + b[i]*ct[b[i]]; 
            dp[i][0] = max(dp[i-1][1] , dp[i-1][0]); 
        }
    }
    cout<<max(dp[n-1][0] , dp[n-1][1])<<endl; 
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

