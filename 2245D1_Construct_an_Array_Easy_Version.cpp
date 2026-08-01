// THE KING OF ICPC IS COMING
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
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
 
 
struct TwoSat {
    int n;
    vector<vector<int>> adj, adj_rev;
    vector<int> order, comp , assignment;
    vector<bool> vis;
 
    TwoSat(int n) : n(n) {
        adj.resize(2 * n);
        adj_rev.resize(2 * n);
        assignment.resize(n);
    }
 
    void add_implication(int u, int v) {
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }
 
    void add_clause(int x, bool val_x, int y, bool val_y) {
        int node_x = 2 * x + (val_x ? 0 : 1);
        int neg_x = 2 * x + (val_x ? 1 : 0);
        int node_y = 2 * y + (val_y ? 0 : 1);
        int neg_y = 2 * y + (val_y ? 1 : 0);
 
        add_implication(neg_x, node_y);
        add_implication(neg_y, node_x);
    }
 
    void dfs1(int u) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) dfs1(v);
        }
        order.push_back(u);
    }
 
    void dfs2(int u, int id) {
        comp[u] = id;
        for (int v : adj_rev[u]) {
            if (comp[v] == -1) dfs2(v, id);
        }
    }
 
    bool solve() {
        vis.assign(2 * n, false);
        for (int i = 0; i < 2 * n; ++i) {
            if (!vis[i]) dfs1(i);
        }
 
        comp.assign(2 * n, -1);
        int id = 0;
        for (int i = 2 * n - 1; i >= 0; --i) {
            int u = order[i];
            if (comp[u] == -1) {
                dfs2(u, id++);
            }
        }
 
        for (int i = 0; i < n; ++i) {
            if (comp[2 * i] == comp[2 * i + 1]) {
                return false;
            }
            assignment[i] = comp[2 * i] - comp[2 * i + 1];
        }
        return true;
    }
};
 
struct nah {
    int o,ai,aj;
};
 
signed dkhan_mn_ghyr_kwfta() { fast(); file();
    TEST{
        int n,m; cin>>n>>m;
        TwoSat ans(n);
 
        vector< nah > haa(m);
        for ( int i=0 ; i<m ; ++i ) {
            int o, ai , aj; cin>>o>>ai>>aj;
            haa[i] = {o,ai,aj};
            ai--,aj--;
            if ( o == 1 ) {
                ans.add_clause( ai , true , aj , true );
            }
            else {
                ans.add_clause( ai , false , aj , false );
            }
        }
 
        if ( ans.solve() ) {
            bool check = true;
            for ( int i = 0 ; i<m ; ++i ) {
                int kkk = ans.assignment[ haa[i].ai -1];
                int kk = ans.assignment[ haa[i].aj -1];
                if ( haa[i].o == 1 and kkk + kk < 0 ) check = false;
                if ( haa[i].o == 2 and kkk + kk >= 0 ) check = false;
            }
 
            if ( check ) {
                YES;
                for ( int i = 0 ; i<n ; ++i ) {
                    cout<< ans.assignment[ i ] << " ";
                }
                cout<<endl;
            }
            else NO;
        }
        else NO;
    }
}