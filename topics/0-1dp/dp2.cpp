/*
https://codeforces.com/problemset/problem/225/C
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
    int n , m, x, y ;
    cin >> n >> m >> x >> y ;
    char a[n + 1][m + 1];
    vi req(m + 1, 0 );
    rep(i , 1 , n) {
        string s;
        cin >> s;
        rep(j , 1, m) {
            a[i][j] = s[j - 1];
            req[j] += s[j - 1] == '#';
        }
    }
    dbg(req);
    int dp[m + 1][y + 1][2];
    rep(i , 1, m) {
        rep(j , 1, y) {
            rep(k , 0, 1) {
                dp[i][j][k] = 1e8;
            }
        }
    }
    dp[1][1][0] = req[1];
    dp[1][1][1] = n - req[1];
    dbg(dp[1][1][0]);
    dbg(dp[1][1][1]);
    rep(i , 2, m) {
        rep(j, x, y) {
            dp[i][1][0] = min(dp[i - 1][j][1] + req[i] , dp[i][1][0] );
            dp[i][1][1] = min(dp[i - 1][j][0] + n - req[i] , dp[i][1][1] );
        }
        dbg(i);
        dbg(dp[i][1][0]);
        dbg(dp[i][1][1]);
        rep(j , 2, y) {
            dp[i][j][0] = dp[i - 1][j - 1][0] +  req[i] ;
            dp[i][j][1] = dp[i - 1][j - 1][1] +  n - req[i] ;
        }
    }
    int ans = 1e8 ;
    rep(i , x , y) {
        ans = min(ans , min(dp[m][i][0] , dp[m][i][1] ));
    }
    cout << ans << endl ;
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

