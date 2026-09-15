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
 
 
signed The_king() {
    fast(); file();
 
    ll n1 = 0 , n2 = 0 , n3 = 0 ; cin>> n1 >> n2 >> n3;
    vector<ll> a(n1);
    vector<ll> b(n2);
    vector<ll> c(n3);
    for(ll i=0;i<n1;i++) cin>>a[i];
    for(ll i=0;i<n2;i++) cin>>b[i];
    for(ll i=0;i<n3;i++) { cin>>c[i]; }
    SORT(c);
    REmoving(c);
 
    vector<ll> d;
    d.reserve(n1 * n2);
    for ( int i =0 ; i<n1 ; i++ ) {
        for ( int j =0 ; j<n2 ; j++ ) {
            d.push_back(a[i] + b[j]);
        }
    }
    SORT(d);
    REmoving(d);
 
    if ( d == c ) YES;
    else NO;
}