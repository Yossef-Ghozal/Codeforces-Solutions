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
        map<ll,ll> freq;
        for(ll i=0; i<n; i++) {
            cin>>a[i];
            freq[a[i]]++;
        }
        map<ll,ll> ans;
        vector< ll > nah = a;
        SORT(nah);
        REmoving(nah);
        if ( nah[0] > 0 ) N1;
        else {
            if ( nah.size() == 1  ) {
                for(int i = 0; i < n; i++) cout << nah[0] + 1 << " ";
                cout << endl;
            }
            else {
                bool check = false;
                vector<ll> hmm( nah.size() );
                for (int i = 0; i+1 < nah.size(); i++) hmm[i] = abs(nah[i+1] - nah[i]);
                for ( int i =0 ; i<hmm.size()-1 ; i++ ) {
                    if ( hmm[i]%freq[nah[i]] != 0 ) {
                        check = true;
                        break;
                    }
                    ans[ nah[i] ] = hmm[i]/freq[ nah[i] ];
                    if ( i != 0 and ans[nah[i]] <= ans[nah[i-1]] ) {
                        check = true;
                        break;
                    }
                }
                ans[nah.back()] = ans[nah[nah.size() - 2]] + 1;
                if ( check ) {
                    N1;
                    continue;
                }
 
                for ( int i = 0 ; i < n ; i++ ) {
                    cout << ans[ a[i] ] << " ";
                }
                cout <<endl;
            }
        }
    }
}