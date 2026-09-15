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
bool naah(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}
 
ll solve( ll y , ll m , ll d , vector<ll>& nah ) {
    int days = 0;
 
    for (int year = 2017; year < y; ++year) {
        days += naah(year) ? 366 : 365;
    }
 
    for (int month = 1; month < m; ++month) {
        if (month == 2 && naah(y)) {
            days += 29;
        } else {
            days += nah[month];
        }
    }
 
    return days + d ;
}
 
signed The_king() {
    fast(); file();
 
    vector<ll> nah = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    ll y , m , d ; cin>>y>>m>>d ;
 
    cout << solve(2025,9,18,nah) - solve(y,m,d,nah) << endl;
 
}