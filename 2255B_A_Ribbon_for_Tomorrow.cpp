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
 
 
signed The_king() { fast(); file();
    const ll MOD = 998244353;
    Combinatorics nah( 10000000 , MOD );
 
    TEST{
        ll n; cin>>n;
        string s; cin>>s;
 
        ll cnt0 = 0 , cnt1 = 0;
        ll k0 = 0 , k1 = 0;
 
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') cnt0++;
            else cnt1++;
 
            if (i == 0 || s[i] != s[i - 1]) {
                if (s[i] == '0') k0++;
                else k1++;
            }
        }
 
        if (cnt0 == 0 || cnt1 == 0) {
            cout << 1 << "\n";
        }
        else {
            ll ans = ( nah.nCr( cnt0-1 , k0-1 ) * nah.nCr( cnt1-1 , k1-1 ) ) % MOD;
 
            pans;
        }
    }
}