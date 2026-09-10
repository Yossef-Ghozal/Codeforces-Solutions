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
 
string add_strings(string num1, string num2) {
    string res = "";
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    int carry = 0;
 
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        res += to_string(sum % 10);
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
 
string get_min(string s1, string s2) {
    if (s1.empty()) return s2;
    if (s2.empty()) return s1;
 
    if (s1.length() != s2.length()) {
        return s1.length() < s2.length() ? s1 : s2;
    }
    return s1 < s2 ? s1 : s2;
}
 
signed The_king() { fast(); file();
    ll n; cin>>n;
    string h; cin>>h;
    ll mid = n/2;
 
    ll f = -1 , s = -1;
    for (int i = mid + 1; i < n; ++i) {
        if (h[i] != '0') {
            s = i;
            break;
        }
    }
    for (int i = mid; i > 0; --i) {
        if (h[i] != '0') {
            f = i;
            break;
        }
    }
 
    string ans = "";
 
    if ( f != -1 ) {
        string s1 = h.substr(0, f);
        string s2 = h.substr(f);
        ans = get_min(ans, add_strings(s1, s2));
    }
    if ( s != -1 ) {
        string s1 = h.substr(0, s);
        string s2 = h.substr(s);
        ans = get_min(ans, add_strings(s1, s2));
    }
 
    pans;
}