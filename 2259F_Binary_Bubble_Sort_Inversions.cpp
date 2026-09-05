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
 
signed The_king() { fast(); file();
    TEST{
        ll n; cin>>n;
        vector<ll> a(n);
        for(ll i=0;i<n;i++) cin>>a[i];
        string s; cin>>s;
 
 
 
        ll cnt1  =0 , cntR = 0;
        for(ll i=0;i<n;i++) {
            if ( a[i] == 1 ) cnt1++;
            else cntR+=cnt1;
        }
 
        deque<ll> pos0, pos1;
        for ( int i=0 ; i<n ; i++ ) {
            if ( a[i] == 1 ) pos1.push_back(i);
            else pos0.push_back(i);
        }
        cout<<cntR<<" ";
 
        ll r = n , l = -1 ;
 
        for ( int i=0 ; i<n ; i++) {
            if ( s[i] == '1' ) {
                if ( !pos1.empty() ) {
                    ll idx = pos1.front();
                    auto it = lower_bound(pos0.begin(), pos0.end(), idx);
                    ll zb = it - pos0.begin();
 
                    cntR -= pos0.size() - zb;
 
                    pos1.pop_front();
                    pos1.push_back(r);
                    r++;
                }
            }
            else {
                if ( !pos0.empty() ) {
                    ll idx = pos0.back();
                    auto it = lower_bound(pos1.begin(), pos1.end(), idx);
                    ll ob = it - pos1.begin();
 
                    cntR -= ob;
 
                    pos0.pop_back();
                    pos0.push_front(l);
                    l--;
                }
            }
 
            cout<< cntR << " ";
        }
        cout << endl;
    }
}