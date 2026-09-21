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
 
struct SparceTable {
    vector<int> logs;
    vector<vector<int>> data;
 
    int merge(int &lf, int &ri) {
        return gcd(lf, ri);
    }
 
    SparceTable(vector<int> &arr) {
        int n = arr.size();
 
        logs.assign(n + 1, 0);
        for (int i = 2; i <= n; ++i)
            logs[i] = logs[i / 2] + 1;
 
        data.assign(logs[n] + 1, vector<int>(n));
        data[0] = arr;
 
        for (int i = 1; i <= logs[n]; ++i) {
            int len = 1 << i;
            for (int j = 0; j + len <= n; ++j)
                data[i][j] = merge(data[i - 1][j], data[i - 1][j + (len >> 1)]);
        }
    }
 
    int get(int l, int r) {
        int len = r - l + 1;
        int k = logs[len];
        return merge(data[k][l], data[k][r - (1 << k) + 1]);
    }
};
 
signed The_king() {
    fast(); file();
    TEST{
        ll n,q; cin>>n>>q;
        vector<int> a(n);
        for(ll i=0;i<n;i++) cin>>a[i];
        vector<int> diff(max(0LL, n - 1));
        for ( int i=0 ; i<n-1 ; i++) diff[i] = abs(a[i+1] - a[i]);
 
        SparceTable st(diff);
        while (q--){
            ll l,r; cin>>l>>r;
            l--,r--;
            if ( l == r ) cout<< 0 << " ";
            else cout<< st.get( l , r-1 )<<" ";;
        }
        cout<<endl;
    }
}