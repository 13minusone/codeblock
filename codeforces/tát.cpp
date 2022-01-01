#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
#define ed '\n'
#define pb push_back
#define ii pair<ll,ll>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long

using namespace __gnu_pbds;
using namespace std;

//
string dao(string &s) {
    string ans="" ;
    for(int i=s.size()-1; i>=0; --i) ans+=s[i];
    return ans ;
}
//
bool check(string s1, string s2) {
    int t = s2.find(s1) ;
    if (t==-1 || s2.size() <s1.size()) return false;
    for(int i=t-1; i>=0; --i) {
        if (s2[i] =='0') return false;
    }
    for(int i=t+s1.size(); i<s2.size(); ++i) {
        if (s2[i] =='0') return false;
    }
    return true;
}
//
bool solve(){
    int x,y;
    cin >> x>> y ;
    string s1 ="", s2="", s3="";;
    while (x>0) {
        if (x% 2==1) s1='1' +s1;
        else s1= '0' + s1;
        x/=2;
    }
    while (y>0) {
        if (y% 2==1) s2='1' +s2;
        else s2= '0' + s2;
        y/=2;
    }
    s3 = dao(s1) ;
    while(s3[0] == '0') {
        s3.erase(0,1) ;
    }

    if (s1 == s2) return true;
    s1+='1';
    return (check(s3,s2) || check(s1, s2) || check(dao(s3),s2) || check(dao(s1),s2));
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("e.inp", "r", stdin);
    //freopen("e.out", "w", stdout);
    if (solve()) cout << "YES" ;
    else cout << "NO";
    return 0 ;
}

