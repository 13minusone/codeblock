#include<bits/stdc++.h>
using namespace std;
#define task ""
#define ll long long
#define SZ(c) c.size()
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
void solve()
{

}
void nhap()
{
 ll n;
 int maxx=1;
 string s;
 cin >> n ;
 for(int i = 1 ;i<=n;i++)
 {
     cin >> s;
     maxx=1;
     for(int j = 0 ;j<s.size();j++)
     {

             maxx=max(maxx,int(s[j]-'0'));

     }
     cout << maxx << endl;
 }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



