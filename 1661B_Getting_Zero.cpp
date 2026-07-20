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
 
const int MOD = 32768;
 
ll bfs( ll m ) {
    if ( m == 0 ) return 0;
 
    vector <ll> dist(32768,-1);
    queue<ll> q;
    dist[m] = 0;
    q.push(m);
 
    while(!q.empty()) {
        ll node = q.front();
        q.pop();
 
        if ( node == 0 ) return dist[node];
 
        ll op1 = (node+1)%MOD;
        ll op2 = (node*2)%MOD;
 
        if ( dist[op1] == -1 ) {
            dist[op1] = dist[node]+1;
            q.push(op1);
        }
        if ( dist[op2] == -1 ) {
            dist[op2] = dist[node]+1;
            q.push(op2);
        }
    }
    return 0;
}
 
 
signed dkhan_mn_ghyr_kwfta() { fast(); file();
    TEST{
        ll n; cin>>n;
        cout << bfs(n) << " ";
    }
}