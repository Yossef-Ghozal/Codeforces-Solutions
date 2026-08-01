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
 
 
signed dkhan_mn_ghyr_kwfta() { fast(); file();
    TEST{
        ll n,q; cin>>n>>q;
        string s; cin>>s;
        string c; cin>>c;
 
        vector<ll> cnt1s(n+1,0);
        vector<ll> cnt1c(n+1,0);
        vector<ll> cnt(n+1,0);
 
        for ( int i = 1; i <= n; ++i ) {
            if ( s[i-1] == '1' ) cnt1s[i] = cnt1s[i-1] + 1;
            else cnt1s[i] = cnt1s[i-1];
        }
 
        for ( int i = 1; i <= n; ++i ) {
            if ( c[i-1] == '1' ) cnt1c[i] = cnt1c[i-1] + 1;
            else cnt1c[i] = cnt1c[i-1];
        }
 
        for ( int i = 1; i <= n; ++i ) {
            if ( s[i-1] == c[i-1] ) cnt[i] = cnt[i-1] + 1;
            else cnt[i] = cnt[i-1];
        }
 
        while ( q-- ) {
            ll l,r; cin>>l>>r;
            ll c1 , c2 , c3;
            if (l !=  1 ) {
                c1 = cnt1s[r] - cnt1s[l-1];
                c2 = cnt1c[r] - cnt1c[l-1];
                c3 = cnt[r] - cnt[l-1];
            }
            else {
                c1 = cnt1s[r];
                c2 = cnt1c[r];
                c3 = cnt[r];
            }
 
            if ( abs( c1 - c2 ) <= c3 ) YES;
            else NO;
        }
    }
}