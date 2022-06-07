/*
https://codeforces.com/problemset/problem/339/D
*/
#include <bits/stdc++.h>
#define int long long int
#define Maxx 10000000000000
#define pb push_back
#define v vector
#define vi vector<int>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#ifndef ONLINE_JUDGE
#define dbg(x)         \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define dbg(x)
#endif
using namespace std;

void _print(int x)
{
    cerr << x << " ";
}
void _print(float x)
{
    cerr << x << " ";
}
void _print(double x)
{
    cerr << x << " ";
}
void _print(char x)
{
    cerr << x << " ";
}
void _print(string x)
{
    cerr << x << " ";
}
void _print(bool x)
{
    cerr << x << " ";
}
template <class T, class V>
void _print(pair<T, V> x)
{
    cerr << "{";
    _print(x.first);
    cerr << ",";
    _print(x.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> x)
{
    cerr << "[ ";
    for (T i : x)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> x)
{
    cerr << "[ ";
    for (T i : x)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> x)
{
    cerr << "[ ";
    for (T i : x)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> x)
{
    cerr << "[ ";
    for (auto i : x)
    {
        _print(i);
        cerr << " ";
    }
    cerr << " ]";
}
const int N = 2e5 + 1;
int t[4*N];
int a[N+1];  
void build( int v, int tl, int tr, bool ops)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build( v * 2, tl, tm, !ops);
        build( v * 2 + 1, tm + 1, tr, !ops);
        if (ops)
        {
            t[v] = t[v * 2] | t[v * 2 + 1];
        }
        else
        {
            t[v] = t[v * 2] ^ t[v * 2 + 1];
        }
    }
}
int sum(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (l == tl && r == tr)
    {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int new_val, bool ops)
{
    if (tl == tr)
    {
        t[v] = new_val;
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val, !ops);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val, !ops);

        if (ops)
        {
            t[v] = t[v * 2] | t[v * 2 + 1];
        }
        else
        {
            t[v] = t[v * 2] ^ t[v * 2 + 1];
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    bool st = 0;
    if (n % 2 == 0)
    {
        st = 0;
    }
    else
    {
        st = 1;
    }
    n = 1 << n; 
    rep(i, 0, n - 1)
    {
        cin >> a[i];
    }

    build( 1, 0, n - 1, st);
    dbg(t);
    dbg(t[1]);
    rep(i, 0, m - 1)
    {
        int p, val;
        cin >> p >> val;
        p--;
        update(1, 0, n - 1, p, val, st);
        cout << t[1] << endl;
    }
}
signed main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
    clock_t start, end;
    start = clock();
    int t;
    // cin >> t;
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
