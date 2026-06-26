// THE KING OF ICPC IS COMING
 
#include <bits/stdc++.h>
using namespace std;
 
#define TEST int t; cin>>t; while(t--)
#define QTEST int q; cin>>q; while(q--)
#define ll long long
#define ld long double
#define INTMX INT_MAX
#define INTMN INT_MIN
#define int128 __int128_t
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define YES cout<<"YES"<<"\n"
#define Yes cout<<"Yes"<<"\n"
#define NO cout<<"NO"<<"\n"
#define No cout<<"No"<<"\n"
#define pans cout<<ans<<"\n"
#define FORcin(a) for( auto &i : (a) ) cin>>i
#define FORE(i, start, n) for(ll i=(start); i<=(n); ++i)
#define FOR(i, start, n)  for(ll i=(start); i<(n); ++i)
#define FORD(i, start, n) for(ll i=(start); i>=(n); --i)
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define endlt(i,n) (i == n ? '\n' : ' ')
void fast(){ ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
 
ll highest_set_bit_pos(ll mask) {
    if (mask == 0) return -1;
    return 31 - __builtin_clz(mask);
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
 
signed main(){ fast();
    TEST{
        ll n; cin>>n;
        ll bas = highest_set_bit_pos(n);
        cout<<fastPower(2,bas)-1<<endl;
    }
}