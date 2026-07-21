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
 
bool topologicalSortBFS_Char(unordered_map<char, vector<char>>& adj, vector<char>& topo_order) {
    unordered_map<char, int> in_degree;
 
    for (char c = 'a'; c <= 'z'; ++c) {
        in_degree[c] = 0;
    }
 
    for (auto& pair : adj) {
        char u = pair.first;
        if (in_degree.find(u) == in_degree.end()) {
            in_degree[u] = 0;
        }
        for (char v : pair.second) {
            in_degree[v]++;
        }
    }
 
    queue<char> q;
    for (auto& pair : in_degree) {
        if (pair.second == 0) {
            q.push(pair.first);
        }
    }
 
    topo_order.clear();
 
    while (!q.empty()) {
        char u = q.front();
        q.pop();
 
        topo_order.push_back(u);
 
        for (char v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }
 
    return topo_order.size() == 26;
}
 
 
 
signed dkhan_mn_ghyr_kwfta() { fast(); file();
    ll n; cin>>n;
    unordered_map<char, vector<char>> adj(26);
 
    vector<string> s(n);
    for ( int i = 0 ; i < n ; i++ ) cin>>s[i];
 
    bool check = true;
 
    for ( int i = 0 ; i+1 < n ; i++ ) {
        string c1 = s[i];
        string c2 = s[i+1];
 
        ll mn = min( (ll)c1.length(), (ll)c2.length() );
        bool hmmm = false;
 
        for ( int k=0 ; k < mn ; k++ ) {
            if ( c1[k] != c2[k] ) {
                adj[c1[k]].push_back(c2[k]);
                hmmm = true;
                break;
            }
        }
 
 
        if ( !hmmm and c1.length() > c2.length() ) {
            check = false;
            break;
        }
    }
 
    if ( !check ) {
        cout<<"Impossible"<<endl;
        return 0;
    }
 
    vector<char> topo_order;
    if ( topologicalSortBFS_Char(adj, topo_order) ) {
        for ( auto u : topo_order ) {
            cout << u;
        }
        cout << endl;
    }
    else {
        cout<<"Impossible"<<endl;
    }
 
}