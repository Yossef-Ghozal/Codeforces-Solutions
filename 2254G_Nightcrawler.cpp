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
 
const ll N = 2e5 + 10;
vector<ll> adj[N];
vector<ll> a;
priority_queue<ll, vector<ll>, greater<ll>> p[N];
 
ll sum =0,cnt=0;
void dfs( ll u ) {
 
    for ( auto v : adj[u] ) {
        dfs(v);
 
        if ( p[u].size() < p[v].size() ) swap(p[u], p[v]);
 
        while ( !p[v].empty() ) { p[u].push(p[v].top()); p[v].pop(); }
 
    }
 
 
    if ( p[u].empty() ) {
        cnt++;
        p[u].push(a[u]);
    }
    else {
        ll mn = p[u].top();
        p[u].pop();
        p[u].push(max(mn, a[u]));
    }
 
}
 
signed dkhan_mn_ghyr_kwfta() { fast(); file();
    TEST{
        ll n; cin>>n;
        a.clear();
        a.resize(n+1);
        cnt=sum=0;
 
        FORE(i,1,n) cin>>a[i];
        for(ll i=0;i<=n;i++) {
            adj[i].clear();
            while(!p[i].empty()) p[i].pop();
        }
 
        for(ll i=2;i<=n;i++) {
            ll u; cin>>u;
            adj[u].push_back(i);
        }
 
        dfs(1);
 
        vector<ll> hmm;
        while(!p[1].empty()) {
            hmm.push_back(p[1].top());
            p[1].pop();
        }
 
        multiset<ll> s( a.begin()+1 , a.end() );
        for ( ll x : hmm ) {
            auto it = s.find(x);
            if (it != s.end()) {
                s.erase(it);
            }
        }
 
        vector<ll> haa ( s.begin() , s.end() );
 
 
        for ( ll i=0 ; i<hmm.size() ; i++ ) {
            sum += hmm[i];
        }
        vector<ll> ans(n+1,-1);
        RSORT(haa);
        ans[cnt] = sum;
 
        for ( ll k = cnt + 1, j = 0 ; k <= n ; k++, j++ ) {
            sum += haa[j];
            ans[k] = sum;
        }
 
        for ( ll i=1 ; i<=n ; i++ ) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}