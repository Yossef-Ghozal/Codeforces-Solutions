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
 
const int N = 2e5 + 5;
vector<ll> adj[N];
ll vis[N];
ll cycle;
ll n;
 
void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v] == 0) {
            dfs(v);
        } else if (vis[v] == 1) {
            cycle++;
        }
    }
    vis[u] = 2;
}
 
signed The_king() { fast(); file();
    TEST{
        cin>>n;
        cycle=0;
        memset(vis, 0, sizeof(vis));
        for ( int i = 1; i <= n; i++ ) adj[i].clear();
        vector<ll> a(n+1,0);
        for(ll i = 1 ; i <= n ; i++) {
            ll x; cin>>x;
            a[i] = x;
            adj[i].push_back(x);
        }
        ll cnt=0;
 
        for(int i = 1; i <= n; i++) {
            if (a[a[i]] == i && a[i] > i) {
                cnt++;
            }
        }
 
        for(int i = 1; i <= n; i++) {
            if(vis[i] == 0) {
                dfs(i);
            }
        }
 
        cout<< ( (cycle - cnt) + (cnt > 0 ? 1 : 0) ) << " " <<  cycle << endl;
    }
}