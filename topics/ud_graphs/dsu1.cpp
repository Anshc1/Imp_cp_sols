/*
https://atcoder.jp/contests/abc214/tasks/abc214_d
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
const int N = 2e5+1; 
vi sz(N ,0 ); 
vi parent(N, -1); 
void makeset(int u){
    parent[u] =u ;
    sz[u] =1;  
}
int find_set(int u){
    if(u == parent[u]){
        return u; 
    }
    return find_set(parent[u]); 
}
void union_set(int a , int b){
    a =find_set(a); 
    b =find_set(b);
    if(a ==b) {
        return; 
    } 
    if(sz[a] < sz[b]){
        swap(a ,b); 
    }
    parent[b] =a; 
    sz[a]+= sz[b]; 
}
void solve()
{
    int n ; 
    cin >> n ; 
    v<pair<int,pair<int,int>>>e(n-1); 
    rep(i ,1 ,n ){
        makeset(i); 
        if(i == n ){
            continue;
        }
        int u ,v, w; 
        cin >>u>>v>>w; 
        e[i-1] ={w , {u,v}}; 
    }   
    sort(e.begin() ,e.end()); 
    int ans =0 ; 
    for (auto i :e)
    {
        ans += sz[find_set(i.second.first)]*sz[find_set(i.second.second)]*i.first; 
        union_set(i.second.first , i.second.second); 
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

