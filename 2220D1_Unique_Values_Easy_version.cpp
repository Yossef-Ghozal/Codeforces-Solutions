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
 
bool ask ( const vector<ll>& s) {
    cout<<"? ";
    cout<< s.size() << " ";
    for ( ll it : s ) cout << it << ' ';
    cout << endl; cout.flush();
 
    ll ans; cin>>ans;
 
    if ( ans == -1 ) exit(0);
 
    return (s.size()-ans)%2 != 0;
}
 
 
signed The_king() { fast(); file();
    TEST{
        ll n; cin>>n;
        ll m = 2*n+1;
        vector<ll> ans(3);
 
        ll l = 3 , r = m , mid ;
        while ( l < r ) {
            mid = l + (r-l)/2;
            vector<ll> q(mid);
            iota(q.begin(), q.end(), 1);
 
            if ( ask(q) ) r = mid;
            else l = mid+1;
        }
        ans[2] = l;
 
        l = 1 , r = ans[2]-2 ;
        while ( l < r ) {
            mid = l + (r-l+1)/2;
            vector<ll> q;
            for (int i = mid; i <= ans[2]; ++i) {
                q.push_back(i);
            }
 
            if ( ask(q) ) l = mid;
            else r = mid-1;
 
        }
        ans[0] = l;
 
        l = ans[0] + 1, r = ans[2] - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            vector<ll> q;
            q.push_back(ans[0]);
            q.push_back(ans[2]);
            for (int i = ans[0] + 1; i <= mid; ++i) {
                q.push_back(i);
            }
 
            if (ask(q)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ans[1] = l;
 
        cout << "! " << ans[0] << " " << ans[1] << " " << ans[2] << endl;
        cout.flush();
    }
}