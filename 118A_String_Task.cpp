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
#define INTMX INT_MAX
#define INTMN INT_MIN
#define int128 __int128_t
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define Yes cout<<"Yes"<<"\n"
#define No cout<<"No"<<"\n"
#define pans cout<<ans<<"\n"
#define FORcin(a) for( auto &i : (a) ) cin>>i
#define FORE(i, start, n) for(ll i=(start); i<=(n); ++i)
#define FOR(i, start, n)  for(ll i=(start); i<(n); ++i)
#define FORD(i, start, n) for(ll i=(start); i>=(n); --i)
#define REMOVED(v) (v).erase(unique((v).begin(), (v).end()), (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define endlt(i,n) (i == n ? '\n' : ' ')
void fast(){ ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
 
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}
ll lcm(ll a, ll b) {
    return a*b*1ll / gcd(a, b);
}
 
signed main(){ fast();
    string s;
    cin >> s;
 
    for (char &c : s) {
        c = tolower(c);
    }
 
    string ans= "";
    for( char x : s ){
        if( x != 'a' &&  x != 'o' && x != 'e' && x != 'y' && x != 'u' && x != 'i' ) ans += x;
    }
 
    for( char x : ans ){
        cout<<"."<<x;
    }
}