/*
https://codeforces.com/problemset/problem/369/C
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
const int N = 1e5 + 1 ;
vi adj[N + 1] ;
vi p(N + 1  , 0 );
bool vis[N + 1];
map<pair<int, int>, int>w ;
void dfs_util(int u ,  int pr) {
    if (w[ {u, pr}] == 2 || w[ {pr, u}] == 2) {
        p[u] = 1;
    }
    vis[u] = 1;
    for (auto i : adj[u]) {
        if (!vis[i]) {
            dfs_util(i , u);
            p[u] += p[i];
        }
    }
}
set<int>ans ;
void dfs(int u) {
    vis[u] = 1;
    for (auto i : adj[u]) {
        if (!vis[i] ) {
            if ((w[ {i , u }] == 2 || w[ {u , i}] == 2) && p[i] == 1) {
                ans.insert(i);
            }
            dfs(i);
        }
    }
}
void solve()
{
    int n ;
    cin >> n ;
    rep(i , 1, n - 1) {
        int x, y , t;
        cin >> x >> y >> t;
        w[ {x, y}] = t ;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    memset(vis, 0 , sizeof(vis));
    dfs_util(1 , 0) ;
    memset(vis , 0 , sizeof(vis));
    dfs(1);
    cout << ans.size() << endl ;
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
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
