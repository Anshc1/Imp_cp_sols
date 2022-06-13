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
}
void _print(float x ) {
    cerr << x << " ";
}
void _print(double x ) {
    cerr << x << " ";
}
void _print(char x ) {
    cerr << x << " ";
}
void _print(string x ) {
    cerr << x << " ";
}
void _print(bool x) {
    cerr << x << " ";
}
template<class T, class V> void _print(pair<T, V>x) {
    cerr << "{";
    _print(x.first);
    cerr << ",";
    _print(x.second);
    cerr << "}";
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

vi adj[26];
bool visited[26];
stack<int>s;
// Function to perform DFS
void dfs(int u)
{
    // Set the vertex as visited
    visited[u] = 1;

    for (auto it : adj[u]) {

        // Visit connected vertices
        if (visited[it] == 0)
            dfs(it);
    }

    // Push into the stack on
    // complete visit of vertex
    s.push(u);
}
vi tsort;
// Function to check and return
// if a cycle exists or not
bool check_cycle()
{
    // Stores the position of
    // vertex in topological order
    unordered_map<int, int> pos;
    int index = 0;

    // Pop all elements from stack
    while (!s.empty()) {
        pos[s.top()] = index;

        // Push element to get
        // Topological Order
        tsort.push_back(s.top());

        index += 1;

        // Pop from the stack
        s.pop();
    }

    for (int i = 0; i < 26; i++) {
        for (auto it : adj[i]) {

            // If parent vertex
            // does not appear first
            if (pos[i] > pos[it]) {

                // Cycle exists
                return true;
            }
        }
    }

    // Return false if cycle
    // does not exist
    return false;
}

void solve()
{
    int n ;
    cin >> n ;
    string a[n];
    rep(i , 0 , n - 1) {
        cin >> a[i];
    }
    rep(i , 1 , n - 1) {
        int j = 0 ;
        int m = min(a[i].size() , a[i - 1].size());
        while (j < m && a[i][j] == a[i - 1][j]) {
            j++;
        }
        if (j == m) {
            if (a[i - 1].size() > a[i].size()) {
                cout << "Impossible\n";
                return;
            }
        } else {
            adj[a[i - 1][j] - 'a'].pb(a[i][j] - 'a') ;
        }
    }
    rep(i , 0 , 25) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    if (check_cycle()) {
        cout << "Impossible\n";
        return;
    } else {
        for (auto i : tsort) {
            char x = i + 'a';
            cout << x;
        }
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
