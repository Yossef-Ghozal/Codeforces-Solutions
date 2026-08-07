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
 
 
signed dkhan_mn_ghyr_kwfta() { fast(); file();
    TEST{
        ll n,m; cin>>n>>m;
        ll x,y; cin>>x>>y;
 
 
        map<ll,ll> hmm;
        vector< pair<ll , ll > > v(x+y);
        FOR(i,0,x) {
            cin>>v[i].first;
            v[i].second = 1;
            hmm[v[i].first]++;
        }
        FOR(i,x,y+x) {
            cin>>v[i].first;
            v[i].second = true;
            if ( hmm[ v[i].first ] == 0 ) v[i].second = 2;
            else {
                v[i].second = 3;
            }
        }
 
        RSORT(v);
 
        ll R = 0, C = 0, B = 0;
        ll mx = n + m - 1;
 
        ll sum =0;
        map<ll,ll> use;
        for ( int i=0 ; i<x+y ; i++ ) {
            if (R + C + B >= mx ) break;
 
            if (use[v[i].first] == 1) continue;
            use[v[i].first] = 1;
 
            if ( v[i].second == 1 ) {
                if (R < n) {
                    R++;
                    sum += v[i].first;
                    use[v[i].first] = 1;
                }
            }
            else if ( v[i].second == 2 ) {
                if (C < m) {
                    C++;
                    sum += v[i].first;
                    use[v[i].first] = 1;
                }
            }
            else if ( v[i].second == 3 ) {
                B++;
                sum += v[i].first;
                use[v[i].first] = 1;
            }
        }
 
 
        cout<<sum<<'\n';
 
    }
}