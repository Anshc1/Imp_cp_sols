/*
https://codeforces.com/problemset/problem/118/D
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


void _print(int x ) {
    cerr << x << " ";
} void _print(float x ) {
    cerr << x << " ";
} void _print(double x ) {
    cerr << x << " ";
} void _print(char x ) {
    cerr << x << " ";
} void _print(string x ) {
    cerr << x << " ";
} void _print(bool x) {
    cerr << x << " ";
}
template<class T, class V> void _print(pair<T, V>x) {
    cerr << "{"; _print(x.first); cerr << ","; _print(x.second); cerr << "}";
}
template<class T> void _print(vector<T> x) {
    cerr << "[ ";
    for (T i : x) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template<class T> void _print(set<T> x) {
    cerr << "[ ";
    for (T i : x) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template<class T> void _print(multiset<T>x) {
    cerr << "[ ";
    for (T i : x) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template<class T , class V> void _print(map<T, V> x) {
    cerr << "[ ";
    for (auto i : x) {
        _print(i);
        cerr << " ";
    }
    cerr << " ]";
}
int ERR_CT = 0;
bool err_counter() {
    ERR_CT++;
    if (ERR_CT > 1e3) {
        dbg("FATAL_ERROR_INF_LOOP");
        return 1;
    }
    return 0 ;
}
void solve()
{
    int n , m, k1 , k2 ;
    cin >> n >> m >> k1 >> k2 ;
    int l = n + m ;
    int dp[n + 1][m + 1][2] ;
    dp[0][0][1] = dp[0][0][0] = 1 ;
    int mod = 1e8 ;
    rep(i , 0 , n) {
        rep(j , 0 , m) {
            if (i == 0  && j == 0 ) {
                continue ;
            }
            dp[i][j][0] = dp[i][j][1] = 0 ;
            rep(k , 1 , min( i , k1)) {
                dp[i][j][0] += dp[i - k][j][1];
                dp[i][j][0] %= mod ;
            }
            rep(k , 1, min(j , k2)) {
                dp[i][j][1] += dp[i][j - k][0];
                dp[i][j][1] %= mod ;
            }
        }
    }
    cout << (dp[n][m][0] + dp[n][m][1]) % mod ;
}
signed main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin );
    freopen("output.txt", "w" , stdout);
    freopen("err.txt", "w", stderr);
#endif
    clock_t start, end;
    start = clock();
    int t;
    //cin >> t;
    t = 1;
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

