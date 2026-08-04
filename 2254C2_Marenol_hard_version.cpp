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
        ll n; cin>>n;
        string s,c; cin>>s>>c;
        string aO = "" , aE = "" , bO = "" , bE = "";
        vector<ll> iaO;
        vector<ll> iaE;
        vector<ll> ibO;
        vector<ll> ibE;
 
        ll cnt1a = 0 , cnt1b = 0 , cnt2a = 0 , cnt2b = 0 ;
        for ( int i = 1 ; i <= n ; ++i) {
            if ( i%2 == 0 and s[i-1] == '1' ) {
                cnt1a++;
                aO += s[i-1];
                iaO.push_back(i-1);
            }
            else if ( s[i-1] == '1' ) {
                cnt2a++;
                aE += s[i-1];
                iaE.push_back(i-1);
            }
            else if ( i%2 == 0 and s[i-1] == '0') {
                aO += s[i-1];
            }
            else if ( i%2 != 0 and s[i-1] == '0') aE += s[i-1];
        }
        for ( int i = 1 ; i <= n ; ++i) {
            if ( i%2 == 0 and c[i-1] == '1' ) {
                cnt1b++;
                bO += c[i-1];
                ibO.push_back(i-1);
            }
            else if ( c[i-1] == '1' ) {
                cnt2b++;
                bE += c[i-1];
                ibE.push_back(i-1);
            }
            else if ( i%2 == 0 and c[i-1] == '0') bO += c[i-1];
            else if ( i%2 != 0 and c[i-1] == '0') bE += c[i-1];
        }
 
        if ( cnt1a == cnt1b and cnt2a == cnt2b ) {
            ll ans = 0 ;
            for ( int i =0 ; i<iaO.size() ; ++i ) {
                ans += abs( iaO[i] - ibO[i] ) ;
            }
            for ( int i =0 ; i<ibE.size() ; ++i ) {
                ans += abs( ibE[i] - iaE[i] ) ;
            }
            ans =ans/2;
            pans;
        }
        else N1;
    }
}