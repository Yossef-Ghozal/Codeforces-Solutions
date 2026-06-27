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
vector<ll> a;
bool check(ll mid) {
    auto it = lower_bound(a.begin(), a.end(), mid+1)-a.begin();
    ll x = 0;
    if ( it < a.size() ) x = a[it];
    else return false;
    ll rem =0;
    for (ll i = it ; i < a.size() ; i++) {
        rem = max( rem , a[i]%x );
    }
    if ( rem == mid ) return true;
    else return false;
}
 
signed The_king() { fast(); file();
    ll n; cin>>n;
    a.resize(n);
    FORcin(a);
    SORT(a);
    REmoving(a);
 
    ll ans=0;
    for ( ll i = 0 ; i < a.size() ; i++ ) {
        for ( ll j = 2*a[i] ; j <= a.back()+a[i] ; j+=a[i] ) {
            auto it = lower_bound(a.begin(), a.end(), j);
            if ( it != a.begin() ) {
                it--;
                ans = max(ans,*it%a[i]);
            }
        }
    }
    pans;
}