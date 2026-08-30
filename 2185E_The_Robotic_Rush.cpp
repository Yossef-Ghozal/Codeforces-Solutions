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
    TEST{
        ll n,m,k; cin>>n>>m>>k;
        vector<ll> a(n);
        vector<ll> b(m);
 
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<m;i++) cin>>b[i];
        SORT(b);
 
        string s; cin>>s;
 
        map<ll, vector<ll> > mp;
 
        for(ll i=0;i<n;i++) {
            auto it = lower_bound(b.begin(), b.end(), a[i]);
            if ( it != b.begin() ) {
                ll dist = a[i] - *prev(it);
                mp[ dist ].push_back( i );
            }
            if ( it != b.end() ) {
                ll dist = *it - a[i];
                mp[ -dist ].push_back( i );
            }
        }
 
        vector<ll> vis(n,0);
        ll cnt = 0;
        ll ans=n;
        for ( int i=0 ; i<k ; i++ ) {
            if ( s[i] == 'R' ) cnt--;
            else cnt++;
 
            for ( auto h : mp[ cnt ] ) {
                if ( vis[h] == 0 ) {
                    vis[h] = 1;
                    ans--;
                }
            }
            cout<<ans<<' ';
            mp[cnt].clear();
        }
 
        cout<<endl;
    }
}