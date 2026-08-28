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
 
vector<ll> divs;
void getDivisors(ll n) {
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i != n / i) divs.push_back(n / i);
        }
    }
    sort(divs.begin(), divs.end());
}
 
signed The_king() { fast(); file();
    TEST{
        divs.clear();
        ll s; cin>>s;
        getDivisors(s);
 
        ll m = divs.size();
        vector< ll > H(m);
        vector<ll> pref(m);
 
        for (int i = 0; i < m; ++i) {
            H[i] = s / divs[i];
            ll nah = divs[i] - (i == 0 ? 0 : divs[i - 1]);
            pref[i] = (i == 0 ? 0 : pref[i - 1]) + nah * H[i];
        }
 
        QTEST{
            ll x,y; cin>>x>>y;
 
            ll r = lower_bound(divs.begin(), divs.end(), x) - divs.begin();
            ll lim = ( s+y-1 )/y;
            ll l = lower_bound(divs.begin(), divs.end(), lim) - divs.begin();
 
            ll ans= 0;
 
            if ( min( l , r ) > 0 ) ans += divs[ min(l,r) - 1] * y;
 
            ll naaah = min( l ,r );
            if ( min( l ,r ) < r ) {
                ll hmmm = ( naaah == 0) ? 0 : pref[ naaah - 1];
                ans += pref[r - 1] - hmmm;
            }
            ll w = x- ( ( r == 0 ) ? 0 : divs[ r - 1 ] );
            ll h = min( y , H[r] );
 
            ans += w*h;
            pans;
 
        }
    }
}