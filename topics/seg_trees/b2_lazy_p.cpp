/*
https://codeforces.com/problemset/problem/276/C
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
vi t(4 * N, 0), lazy(4 * N, 0);
int a[N + 1];
void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = 0;
    }
}
void push(int v)
{
    t[v * 2] += lazy[v];
    lazy[v * 2] += lazy[v];
    t[v * 2 + 1] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend)
{
    if (l > r)
        return;
    if (l == tl && tr == r)
    {
        t[v] += addend;
        lazy[v] += addend;
    }
    else
    {
        push(v);
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), addend);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

int query(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return -INT_MAX;
    if (l <= tl && tr <= r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return max(query(v * 2, tl, tm, l, min(r, tm)),
               query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void solve()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    vi b(n); 
    rep(i ,0 , n-1){
        cin >>b[i]; 
    }
    rep(i, 0, n - 1)
    {
        a[i] = 0;
    }
    build(1, 0, n - 1);

    rep(i, 1, q)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        update(1, 0, n - 1, l, r, 1);
    }
    priority_queue<pair<int,int>>pq;
    rep(i ,0 ,n-1){
        int val = query(1, 0 , n-1 ,i ,i ); 
        pq.push({val , i}); 
    } 
    int ans= 0 ; 
    sort(b.begin() ,b.end() ,greater<int>()) ; 
    for(auto i : b){
        ans+= pq.top().first*i;  
        pq.pop();  
    }
    cout<<ans<<endl;     
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
