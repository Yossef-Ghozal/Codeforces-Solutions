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
    TEST{
        ll n; cin>> n;
    vector<vector<ll>> adj(n+2);
    vector<ll> in_degree(n+2,0);
    vector< pair<ll,ll> > cost(n+1);
 
    for (ll i = 1; i < n; ++i) {
        ll x,y,u,v; cin >> u >> v >> x >> y;
        cost[i] = {x,y};
        if ( x > y ) {
            adj[v].push_back(u);
            in_degree[u]++;
        }else {
            adj[u].push_back(v);
            in_degree[v]++;
        }
    }
 
    queue<ll> q;
    vector<ll> ans(n+1);
    ll num = 1;
    for (ll i = 1; i <= n; ++i) {
        if ( in_degree[i] == 0 ) {
            q.push(i);
 
        }
    }
 
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        ans[u] = num++;
        for ( auto v : adj[u] ) {
            in_degree[v]--;
            if ( in_degree[v] == 0) {
                q.push(v);
            }
        }
    }
 
    for ( int i=1; i<=n; ++i ) {
        cout << ans[i] << " ";
    }
    cout << endl;
    }
}