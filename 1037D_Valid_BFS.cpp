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
#define dkhan_mn_ghyr_kwfta main
 
void fast(){ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
void file() {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
}
 
 
 
signed dkhan_mn_ghyr_kwfta() { fast(); file();
    ll n; cin>>n;
    vector<ll> adj[n+1];
    vector<ll> lvl(n+1,-1);
 
    for ( int i = 1 ; i <= n-1 ; ++i ) {
        ll u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    queue<ll> q;
    q.push(1);
    lvl[1] = 1;
 
    vector<ll> b(n);
    for ( int i=0 ; i<n ; ++i ) cin>>b[i];
 
    vector<ll> pos(n + 1);
    for (int i = 0; i < n; ++i) {
        pos[b[i]] = i;
    }
 
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end(), [&](ll x, ll y) {
            return pos[x] < pos[y];
        });
    }
 
    vector<ll> order;
    order.push_back(1);
 
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        for ( auto v : adj[u] ) {
            if ( lvl[v] == -1 ) {
                q.push(v);
                order.push_back(v);
                lvl[v] = lvl[u] + 1;
            }
        }
 
 
    }
 
    if ( order == b ) Yes;
    else No;
 
}