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
 
bool check( ll mid , const vector< pair<ll,ll> >& a, ll sum ) {
    if ( mid == 0 ) return true;
 
    ll nah = 1 , cur = mid-1 , hmm = a.size()-1 ;
    while ( cur > 0 ) {
        while ( hmm >= 0 and a[hmm].first > cur ) hmm--;
        
        ll bla1 = -1 , bla2 = 0 ;
        if ( hmm >= 0 ) {
            bla1 = a[hmm].first;
            bla2 = a[hmm].second;
        }
        if ( bla1 < cur ) {
            ll backToHome = max(0LL, bla1);
            ll diff = cur - backToHome ;
            
            if ( diff >= 60 ) return false;
            if ( nah > (2e15 / (1LL << diff)) ) return false;;
            
            nah *= (1LL << diff);;
            cur = backToHome ;
        }
        if ( cur > 0 and cur == bla1 ) {
            ll ooh = min(nah, bla2);
            sum -=ooh;
            nah += ( nah - ooh );
            
            if ( nah > 2e15 ) return false;
            cur--;
        }
    }
    
    return sum >= nah;
}
 
 
signed The_king() {
    fast(); file();
    TEST{
        ll n; cin >> n;
        vector< pair<ll,ll> >a(n);
        ll mx = INTMN;
        ll sum = 0;
        for ( ll i = 0; i < n; i++ ) {
            cin >> a[i].first >> a[i].second;
            sum += a[i].second;
            if ( a[i].first > mx ) {
                mx = a[i].first;
            }
        }
        SORT(a);
        ll l = 0 , r = mx + 919 , ans=0 , mid;
        while ( l <= r ) {
            mid = (l + r) / 2;
            if ( check( mid , a, sum ) ) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        cout << max( ans , mx ) << '\n';
    }
}