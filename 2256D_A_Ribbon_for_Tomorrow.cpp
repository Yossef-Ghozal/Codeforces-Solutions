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
 
struct Combinatorics {
    int MOD;
    vector<long long> fact;
    vector<long long> invFact;
 
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
 
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }
 
    Combinatorics(int n, int mod) {
        this->MOD = mod;
        fact.resize(n + 1);
        invFact.resize(n + 1);
 
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
 
        invFact[n] = modInverse(fact[n]);
 
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }
 
    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }
 
    long long nPr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[n - r] % MOD;
    }
};
 
 
ll mul(ll a,ll b,ll m){ return ((a%m)*(b%m))%m; }
 
signed dkhan_mn_ghyr_kwfta() { fast(); file();
    const ll MOD = 998244353;
    Combinatorics ans( 1000008 , MOD);
    TEST{
        ll n; cin >> n;
        string s; cin >> s;
 
        ll cnt1=0, cnt0=0;
        for ( char nah : s ) {
            if ( nah == '1' ) cnt1++;
            else cnt0++;
        }
 
        if ( cnt1 == 0 or cnt0 == 0 ) cout<<1<<endl;
        else {
            ll nah0 = 0, nah1 = 0;
            for (int i = 0; i < n; i++) {
                if (i == 0 or s[i] != s[i - 1]) {
                    if (s[i] == '0') nah0++;
                    else nah1++;
                }
            }
 
            ll res = mul( ans.nCr( cnt0 - 1 , nah0 - 1   ) , ans.nCr( cnt1-1 , nah1-1 ) , MOD );
            cout << res << endl;
        }
    }
}