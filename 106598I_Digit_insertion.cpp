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
vector<string> ans;
 
bool check( string s ) {
    return s.length() == 11 && s[0] == '1' && s[1] != '0' && s[2] == '9' ;
}
 
void nah( string s , ll i ) {
    if ( s.length() == 11 || i > s.length() ) {
        if ( check( s ) ) ans.push_back(s);
        return;
    }
 
    string c = s;
 
    nah( c, i+1 );
 
    c.insert( i , "1" );
 
    nah( c, i+1 );
 
    c.erase( i , 1 );
    c.insert( i , "9" );
 
    nah( c, i+1 );
 
    c.erase( i , 1 );
 
 
}
 
signed The_king() { fast(); file();
    string s; cin>>s;
    if ( s.length() > 11 ) cout<<0<<endl;
    else if ( s.length() == 11 ) {
        if ( check( s ) ) cout<<1<<endl<<s<<endl;
        else cout<<0<<endl;
    }
    else {
        nah( s , 0 );
        SORT(ans);
        REmoving(ans);
 
        cout<< ans.size()<<endl;
        for ( string  x : ans ) cout<< x <<endl;
    }
}