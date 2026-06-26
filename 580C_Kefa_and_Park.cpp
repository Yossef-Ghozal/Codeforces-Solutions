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
 
const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
vector<int> nah;
bool vis[MAXN];
ll n,m;
 
ll ans = 0;
 
bool dfs(int node , int cats ) {
    vis[node] = true;
    bool is_leaf = true;
    for (int it: adj[node]) {
        if (!vis[it]) {
            if ( cats > m )  continue;
            is_leaf = false;
            if ( nah[it] == 1 ) dfs( it , cats+1 );
            else  dfs( it , 0 );
        }
    }
    if ( is_leaf && cats <= m ) {
        ans++;
    }
    return is_leaf;
}
 
signed The_king() { fast(); file();
    cin>>n>>m;
    nah.resize(n+1);
    FORE(i,1,n) cin>>nah[i];
 
    for (int i=0;i<n-1;i++) {
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if ( nah[1] == 1 ) dfs( 1 , 1 );
    else dfs(1,0);
 
 
    pans;
}