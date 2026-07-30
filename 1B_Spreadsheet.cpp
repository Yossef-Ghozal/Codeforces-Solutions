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
        string s; cin>>s;
        ll n = s.length();
 
        string x ="" , y ="";
        bool nah = true;
        for ( int i = 0; i < n; ++i ) {
            if ( isdigit( s[i] ) and nah ) {
                x += s[i];
            }
            else if ( !x.empty() ) {
                nah = false;
                if ( isdigit( s[i] ) ) y += s[i];
            }
        }
 
        if ( nah ) {
            string ans = "R" + x + "C";
            ll k = 0;
            ll cnt = 0;
            for ( int i = 0; i < n; ++i ) {
                if ( isdigit( s[i] )  ) break;
                else {
                    cnt++;
                    k = k * 26 + ( s[i] -'A' +1 );
                }
            }
            cout<< ans << k << endl;
        }
        else {
            ll k = stoll( s.substr( 1 , s.find('C') -1) );
            ll kk = stoll ( s.substr( s.find('C') +1 ) );
 
            string ans = "";
 
            while ( kk > 0 ) {
                kk--;
                char c = char( (kk%26) +'A' );
                ans += c;
                kk = kk / 26;
            }
            reverse(ans.begin(), ans.end());
            cout<< ans << k << endl;
 
        }
    }
}