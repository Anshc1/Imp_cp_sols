//https://codeforces.com/problemset/problem/1730/B

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

int n ;
int check(int m , vi&x , vi&t ) {
   int mnr = 1e16  , mxl = 0 ;
   rep(i , 0 , n - 1) {
      if (m < t[i]) {
         return 1e18;
      }
      mnr = min(mnr , x[i] + (m - t[i]));
      mxl = max(mxl , x[i] - (m - t[i]));
   }

   if (mxl <= mnr) {
      return mxl;
   }
   return 1e18;
}
void solve()
{
   cin >> n  ;
   vi x(n) , t(n);
   rep(i , 0 , n - 1) {
      cin >> x[i];
      x[i] *= 2;
   }
   rep(i , 0 , n - 1) {
      cin >> t[i];
      t[i] *= 2;
   }
   int l = -1 ,  r = 1e13;
   int ans ;
   int pos ;
   while ( r - l > 1 ) {
      int mid = (l + r ) / 2;
      ans = check(mid, x , t);
      if (ans != 1e18) {
         pos = ans;
         r = mid ;
      } else {
         l = mid ;
      }
   }
   cout << pos / 2   ;
   if (pos % 2 == 1) {
      cout << ".5";
   }
   cout << endl;

}
signed main()
{
   ios_base ::sync_with_stdio(false);
   cin.tie(NULL);
#ifndef ONLINE_JUDGE
   freopen("err.txt", "w", stderr);
#endif
   clock_t start, end;
   start = clock();
   int t;
   cin >> t;
   //t=1;
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

