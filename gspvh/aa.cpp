#include<bits/stdc++.h>
using namespace std;
#define task "syllable"
#define fu(i,a,b) for(int i=a; i<=b; i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)
#define pb push_back
#define popb pop_back
#define ll long long
#define ull unsigned long long
#define rt return
#define ctn continue
#define fi first
#define se second
const int mod = int(1e9)+7;
const ll MOD=1e12 + 7;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
void init()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
string s;
bool check(char x)
{
    if (x=='a' || x=='e' || x=='i' || x=='o' || x=='u') return true;
    return false;
}
void sol()
{
    int i=0, n=s.size(), ans=0;
    s=s+"  ";
    while(i<n)
    {
        if (check(s[i]))
        {
            ans++;
            if (s[i]=='a' && s[i+1]=='u') ans--;
            if (s[i]=='o')
            {
                if (s[i+1]=='o' || s[i+1]=='a') ans--;
            }
            if (s[i]=='i' && s[i+1]=='o' && s[i+2]=='u') ans--;
        }
        i++;
    }
    if (s[n-1]=='e')
    {
        ans--;
        if (n>=3 && s[n-2]=='l' && check(s[n-3])==false) ans++;
    }
    cout << max(1, ans);
}
int main()
{
    init();
    fastio();
    cin >> s;
    sol();
}
