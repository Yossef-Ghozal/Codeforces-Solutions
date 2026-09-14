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
 
 
signed The_king() { fast(); file();
    ll n,q; cin>>n>>q;
    vector< vector<ll> > adj(n+26);
    map<string ,ll> mp;
 
    for ( int i = 0; i < n; ++i ) {
        string s; cin >> s;
        mp[s] = i;
 
        vector<bool> vis(26,false);
        for (char c : s) {
            ll nah = c - 'a';
            if (!vis[nah]) {
                vis[nah] = true;
                int hmm = n + nah;
                adj[i].push_back(hmm);
                adj[hmm].push_back(i);
            }
        }
    }
 
    vector<ll> comp( n +26 , -1 );
    ll cur = 0;
 
    for ( int i = 0; i < n+26 ; ++i ) {
        if ( comp[i] == -1 ) {
            queue<ll> q;
            q.push(i);
            comp[i] = cur;
            while (!q.empty()) {
                ll x = q.front(); q.pop();
                for ( ll v : adj[x] ) {
                    if ( comp[v] == -1 ) {
                        comp[v] = cur;
                        q.push(v);
                    }
                }
            }
        }
        cur++;
    }
 
    while (q--){
        string a,b; cin>>a>>b;
        ll c1 = mp[a], c2 = mp[b];
        if ( comp[c1] == comp[c2] ) cout<<"LUA"<<endl;
        else cout<<"RYEI"<<endl;
    }
 
}