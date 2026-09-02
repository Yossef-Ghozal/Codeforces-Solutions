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
 
bool hasCommonIntersection(const vector<pair<ll, ll>>& intervals) {
    if (intervals.empty()) return true;
 
    ll max_start = intervals[0].first;
    ll min_end = intervals[0].second;
 
    for (int i = 1; i < intervals.size(); i++) {
        max_start = max(max_start, intervals[i].first);
        min_end = min(min_end, intervals[i].second);
    }
 
    return max_start <= min_end;
}
 
signed The_king() { fast(); file();
    TEST{
        ll n; cin>>n;
        vector<ll> a(n);
        for(ll i=0;i<n;i++) cin>>a[i];
 
        if ( is_sorted(a.begin(), a.end()) ) {
            YES;
            continue;
        }
 
        ll mn = INTMN;
        ll mx = INTMX;
 
        vector<ll> idx;
        for(ll i=0;i<n-1;i++) {
            if ( a[i] > a[i+1]) {
                idx.push_back(i);
                mn = max(mn, a[i]-a[i+1]);
            }
        }
 
        bool check = true;
        for ( int i=0 ; i+1< idx.size() ; i++ ) {
            ll l = idx[i]+1;
            ll r = idx[i+1];
 
            if ( l == r ) {
                check = false;
                break;
            }
 
            ll mx2 = INTMN;
            for ( int j = l ; j < r ; j++ ) {
                mx2 = max(mx2, a[j+1]-a[j]);
            }
            mx = min(mx, mx2);
        }
 
        if ( mn <= mx and check ) YES;
        else NO;
    }
}