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
        ll n; cin>>n;
        vector<ll> a(n);
        FORcin(a);
 
        vector<pair<ll, ll>> v;
        for (ll i = 0; i < n; i++) {
            if (v.empty() || v.back().first != a[i]) {
                v.push_back({a[i], 1LL});
            } else {
                v.back().second++;
            }
        }
 
        ll ans = v.size();
 
        bool check1 = false;
        for (int i = 0; i < ans - 1; i++) {
            if (v[i].second >= 2 && v[i + 1].second >= 2) {
                check1 = true;
                break;
            }
        }
 
        if ( check1 ) ans+=2;
        else {
            bool check2 = false;
            for (int i = 0; i < ans ; i++) {
                if ( v[i].second >= 2 ) {
 
                    if ( i+1 < ans and (i+2 >= ans or v[i+2].first != v[i].first ) ) {
                        check2 = true;
                        break;
                    }
                    if ( i-1 >= 0 and (i - 2 < 0 or v[i - 2].first != v[i].first) ) {
                        check2 = true;
                        break;
                    }
                }
            }
            if ( check2 ) ans++;
        }
 
        pans;
    }
}