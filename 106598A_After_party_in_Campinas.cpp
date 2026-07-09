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
    ll n , q ; cin>>n>>q;
    vector< pair<ll , ll > > a(n);
    for ( int i = 0 ; i < n ; i++ ) {
        cin>>a[i].first>>a[i].second;
    }
 
    vector<ll> idx(n,-1);
    for ( int i = n-2 ; i >= 0 ; i-- ) {
        if ( a[i].second == a[i+1].second ) idx[i] = idx[i+1];
        else idx[i] = i+1;
    }
 
    while ( q-- ) {
        ll x , y; cin>>x>>y;
        auto it = lower_bound( a.begin() , a.end() , x , []( const pair<ll,ll>& p , ll num ) {
            return p.first > num;
        } );
 
        ll id = distance(a.begin(), it);
 
        if ( it == a.end() ) cout<<"-1"<<'\n' ;
        else {
            ll ans = -1;
            if ( a[id].second != y ) ans = id + 1;
            else if ( idx[id] != -1 ) ans = idx[id]+1;
 
 
            if ( ans == -1 ) cout<<"-1"<<'\n' ;
            else{ pans; }
        }
    }
}