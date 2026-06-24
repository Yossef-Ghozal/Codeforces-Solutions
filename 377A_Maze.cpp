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
 
int n, m, k;
vector<string> grid;
vector< vector<bool> > vis;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
 
bool isValid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == '.' && !vis[r][c];
}
 
void dfs(int r, int c) {
    vis[r][c] = true;
    
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (isValid(nr, nc)) {
            dfs(nr, nc);
        }
    }
    
    if (k > 0) {
        grid[r][c] = 'X';
        k--;
    }
}
signed The_king() { fast(); file();
    cin >> n >> m >> k;
    grid.resize(n);
    vis.assign(n, vector<bool>(m, false));
    int start_r = -1, start_c = -1;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        if (start_r == -1) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.') {
                    start_r = i;
                    start_c = j;
                    break;
                }
            }
        }
    }
 
    if (start_r != -1) {
        dfs(start_r, start_c);
    }
 
    for (int i = 0; i < n; i++) {
        cout << grid[i] << "\n";
    }
}