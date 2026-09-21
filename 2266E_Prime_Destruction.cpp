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
 
vector<ll> lp;
vector<ll> primes;
void linear_sieve(ll n) {
    lp.assign(n + 1, 0);
    primes.clear();
 
    for (ll i = 2; i <= n; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back(i);
        }
 
        for (ll p : primes) {
            if (p > lp[i] || i * p > n) break;
            lp[i * p] = p;
        }
    }
}
 
 
signed The_king() {
    fast(); file();
    linear_sieve(2e5+8491);
    TEST{
        ll n,k; cin>>n>>k;
        vector<ll> a(n);
        for(ll i=0;i<n;i++) cin>>a[i];
 
        vector<ll> dp(n+1,0);
        for ( int i=k+1 ; i<=n; i++ ) {
            ll mn = INTMX;
            ll nah = i;
            while ( nah > 1 ) {
                ll p = lp[nah];
                mn = min( mn , 1+ p * dp[i/p]);
                while ( nah%p == 0 ) nah /=p;
            }
            dp[i] = mn;
        }
 
        ll ans = 0 ;
        for ( ll x : a ) ans += dp[x];
        pans;
    }
}