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
 
struct nah {
    long long p;
    long long r;
};
 
vector< nah > haa;
vector< ll > pref;
 
ll hmm( ll cnt , ll n , ll d ) {
    ll oooh = cnt / n;
    ll rem = cnt % n;
 
    ll scooooooooooore = oooh * (n*d+ pref.back()) + rem*d;
 
    ll idx = upper_bound(haa.begin(), haa.end(), rem, [](ll val, const nah& element) {
        return val < element.p;
    }) - haa.begin() -1;
    if ( idx >= 0 ) scooooooooooore += pref[idx];
 
    return scooooooooooore;
}
 
 
 
signed dkhan_mn_ghyr_kwfta() { fast(); file();
    TEST{
        ll n,m,d; cin>>n>>m>>d;
        haa.resize(m);
        pref.resize(m);
        for ( int i = 0; i < m; i++ ) {
            cin>>haa[i].p>>haa[i].r;
            pref[i] = haa[i].r;
            if (i) { pref[i] += pref[i - 1]; }
        }
        bool found = false;
 
        for ( int i = 0 ; i < m; i++ ) {
            for ( int j = 0 ; j < m; j++ ) {
                ll x = haa[i].p;
                ll y = haa[j].p;
 
                if ( x == n or y == n ) continue;
 
                ll point1 = hmm( x , n , d );
                ll point2 = hmm( y , n , d );
                ll point3 = hmm( x+y+1 , n , d );
 
                if ( point1 + point2 > point3 ) {
                    found = true;
                    break;
                }
            }
 
            if ( found ) break;
        }
 
 
        if ( found ) YES;
        else NO;
    }
}