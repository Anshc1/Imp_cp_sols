/*
https://atcoder.jp/contests/abc222/tasks/abc222_e
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
map<pair<int,int> ,int>c;
const int N =1001 ; 
void sh_path(vi adj[] , int s , int des ,int n){
    bool vis[n+1]; 
    vi p(n+1); 
    memset(vis, 0 ,sizeof(vis)); 
    queue<int>q; 
    q.push(s); p[s] =-1 ;
    vi dis(n+1 , 1e9); 
    dis[s] =0 ; 
    while (!q.empty())
    {
        int tp = q.front();
        vis[tp]=1;  
        q.pop(); 
        for(auto i : adj[tp]){
            if(!vis[i]){
                if(dis[i] > dis[tp] + 1 ){
                    p[i] = tp ; 
                    dis[i] = dis[tp]+1; 
                } 
                q.push(i); 
            }
        }
    }
    int st= des; 
    while (st!= s)
    {
        int x = st; 
        int y = p[st];
        if(x>y){
            swap(x,y); 
        } 
        c[{x,y}]++; 
        st =p[st]; 
    }
    dbg(c); 
}
void solve()
{
    int n ; 
    cin >> n ; 
    int m, k ; 
    cin >> m >>k ; 
    vi adj[n+1]; 
    vi a(m); 
    rep(i ,0 ,m-1){
        cin >>a[i]; 
    }
    rep(i ,1 , n-1){
        int u ,v;
        cin >> u >>v; 
        if(u > v){
            swap(u ,v); 
        }
        c[{u,v}] =0 ; 
        adj[u].pb(v); 
        adj[v].pb(u);  
    }
    rep(i ,1 ,m-1){
        sh_path(adj , a[i-1] , a[i] , n); 
    }
    int s =0 ; 
    for(auto i : c){
        s+= i.second ; 
    }
    dbg(s); 
    if((k+s)%2 !=0 || (k+s)/2 < 0){
        cout<<0<<endl; 
        return; 
    }

    int mod = 998244353; 
    int mx =(k+s)/2; 
    v<v<int>>dp(n , v<int>(mx+1 , 0));   
    rep(i ,0 , n-1){
        dp[i][0] =1; 
    }
    dbg(mx); 
    vi e; 
    for(auto i : c){
        e.pb(i.second); 
    }
    rep(i ,1 , n-1){
        rep(j ,0 , mx ){
            dp[i][j] = dp[i-1][j]; 
            if(j < e[i-1]){
                continue;
            }
            dp[i][j] = (dp[i][j] + dp[i-1][j - e[i-1]] )% mod;
        }
        dbg(dp); 
    }
    cout<<dp[n-1][mx]; 
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

