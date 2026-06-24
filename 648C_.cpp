// THE KING OF ICPC IS COMING
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define TEST int t; cin>>t; while(t--)
#define QTEST int q; cin>>q; while(q--)
#define ll long long
#define ld long double
#define int128 __int128_t
#define INTMX LONG_LONG_MAX
#define INTMN LONG_LONG_MIN
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define YES cout<<"YES"<<'\n'
#define N1 cout<<"-1"<<'\n'
#define NO cout<<"NO"<<'\n'
#define Yes cout<<"Yes"<<'\n'
#define No cout<<"No"<<'\n'
#define pans cout<<ans<<'\n'
#define FORcin(a) for( auto &i : (a) ) cin>>i
#define FORE(i, start, n) for(ll i=(start); i<=(n); ++i)
#define FOR(i, start, n)  for(ll i=(start); i<(n); ++i)
#define FORD(i, start, n) for(ll i=(start); i>=(n); --i)
#define REmoving(v) (v).erase(unique((v).begin(), (v).end()), (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define MAXV(v) *max_element((v).begin(), (v).end())
#define MINV(v) *min_element((v).begin(), (v).end())
#define endlt(i,n) (i == n ? '\n' : ' ')
#define The_king main
 
void fast(){ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
void file() {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
}
 
const int N = 1005;
char grid[N][N];
bool vis[N][N];
int n, m;
bool nah = true;
string ans;
//          U  D  L   R
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
 
bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}
 
void dfs(int i, int j , int pi = -1 , int pj = -1 ) {
    vis[i][j] = true;
    for (int k = 0; k < 4; ++k) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (valid(ni, nj) &&  grid[ni][nj] != '.' ) {
            if (ni == pi && nj == pj) continue;
 
            if (grid[ni][nj] == 'S') {
                if (k == 0) ans.push_back('U');
                else if (k == 1) ans.push_back('D');
                else if (k == 2) ans.push_back('L');
                else if (k == 3) ans.push_back('R');
                return;
            }
            if (!vis[ni][nj]) {
                if (k == 0) ans.push_back('U');
                else if (k == 1) ans.push_back('D');
                else if (k == 2) ans.push_back('L');
                else if (k == 3) ans.push_back('R');
 
                dfs(ni, nj, i, j);
 
                return;
            }
        }
    }
}
 
signed The_king() { fast(); file();
    cin>>n>>m;
    ll xs , ys;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>grid[i][j];
            if (grid[i][j] == 'S') { xs = i; ys = j; }
        }
    }
 
    dfs( xs, ys );
    pans;
}