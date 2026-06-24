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
ll n;
vector<string> grid(N, string(N, '.'));
bool vis[N][N];
 
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
 
bool valid(ll i, ll j) {
    return i >= 0 && i < n && j >= 0 && j < n;
}
 
void dfs(ll i, ll j) {
    vis[i][j] = true;
    for (int k = 0; k < 8; ++k) {
        ll ni = i + dx[k];
        ll nj = j + dy[k];
        if (valid(ni, nj) && !vis[ni][nj] && grid[ni][nj] != '#') {
            dfs(ni, nj);
        }
    }
}
signed The_king() { fast(); file();
    cin>>n;
    ll xq,yq; cin>>xq>>yq;
    ll xk,yk; cin>>xk>>yk;
    ll xs,ys; cin>>xs>>ys;
 
    xq--,yq--,xk--,yk--,xs--,ys--;
    grid[xq][yq] = '#';
 
    for (int i = 0; i < 8; ++i) {
        ll nx = xq + dx[i];
        ll ny = yq + dy[i];
 
        while (nx >= 0 && nx < n && ny >= 0 && ny < n) {
            grid[nx][ny] = '#';
            nx += dx[i];
            ny += dy[i];
        }
    }
 
    dfs(xk,yk);
 
    if ( vis[xs][ys] ) YES;
    else NO;
}