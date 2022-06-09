/*
https://codeforces.com/problemset/problem/219/C
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
    int n , k ; 
    cin >> n >> k; 
    string s; 
    cin >>s; 
    int dp[n][k]; 
    memset(dp ,1e9 , sizeof(dp));  
    rep(i ,0 , k-1){
        dp[0][i] = 0 ;
        if(s[0]-'A' != i){
            dp[0][i]++; 
        } 
    }
    rep(i ,1 , n-1){
        rep(j ,0 ,k-1){ 
            if(j == s[i]-'A'){
                dp[i][j] = 0 ; 
            }else{
                dp[i][j] = 1; 
            }
            int mn =1e18; 
            rep(t ,0 , k-1){
                if(j == t){
                    continue;
                }
                mn  = min(dp[i-1][t] , mn) ; 
            }
            dp[i][j] += mn; 
        }
    }
    dbg(dp); 
    int ans = 1e18; 
    char st ; 
    rep(i ,0 ,k-1){
        ans =min(dp[n-1][i] ,ans); 
    }
    string t = ""; 
    int p =1e18; 
    int val = ans; 
    for (int i = n-1; i >= 0; i-- )
    {
        if(i < n-1){
            if(s[i+1]-'A' !=  p){
                val--; 
            }
        }
        rep(j ,0 , k-1){
            if(j!= p && dp[i][j] == val){
                t+= 'A'+j ;
                p =  j ; 
                val = dp[i][j];  
                break;
            }
        }
    }
    reverse(t.begin() ,t.end()); 
    cout<<ans<<endl <<t;
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

