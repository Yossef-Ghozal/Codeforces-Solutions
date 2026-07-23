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
 
const ll MOD = 1e6 + 3;
 
long long addmodulo(long long a, long long b) {
    return (a % MOD + b % MOD) % MOD;
}
 
long long fastpowermod(long long base, long long power) {
    long long res = 1;
    base %= MOD;
    while (power > 0) {
        if (power % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        power /= 2;
    }
    return res;
}
 
signed dkhan_mn_ghyr_kwfta() { fast(); file();
    string s; cin>>s;
    unordered_map<char, string> hmm = {
        {'>', "1000"}, {'<', "1001"}, {'+', "1010"}, {'-', "1011"},
        {'.', "1100"}, {',', "1101"}, {'[', "1110"}, {']', "1111"}
    };
 
    string nah = "";
    for ( char c : s ) {
        nah += hmm[c];
    }
 
    ll ans = 0;
    int len = nah.length();
    for ( int i = len - 1 ; i >= 0 ; i-- ) {
        if ( nah[i] == '1' ) {
            ll power = len - 1 - i;
            ll x = fastpowermod(2, power);
            ans = addmodulo(ans, x);
        }
    }
 
    pans;
}