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
#define dkhan_mn_ghyr_kwfta main
 
void fast(){ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
void file() {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
}
 
bool is_power_of_two(long long x) {
    return x > 0 && (x & (x - 1)) == 0;
}
 
ll highest_set_bit_pos(ll mask) {
    if (mask == 0) return -1;
    return 63 - __builtin_clzll(mask);
}
 
long long fastPower(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}
 
signed dkhan_mn_ghyr_kwfta() { fast(); file();
    TEST{
        ll n,k; cin>>n>>k;
        ll nah = n^k;
        if ( nah == 0 ) {
            YES;
            for (int i = 1; i < n; i++) cout << i << " ";
            cout << 0 << endl;
        }
        else {
            ll pos = highest_set_bit_pos( nah );
            ll x= fastPower(2, pos);
            ll y = nah ^ x ;
            if ( x >= n ) {
                NO;
            }
            else{
                vector<ll> see(n);
                see[x] = 1;
                if (y > 0) see[y] = 1;
                see[0] = 1;
 
                YES;
                for ( int i=0 ; i<n ; i++ ) {
                    if ( see[i] == 0 ) cout<<i<<" ";
                }
                cout<<0<<" ";
                if ( y > 0 ) cout<<y<<" ";
                cout<< x << endl;
            }
        }
    }
}