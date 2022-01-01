#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int  i = a ; i <=b ;i+=c)
#define fd(i,a,b,c) for(int  i = a ; i >=b ;i-=c)
#define ll long long
#define SZ(c) c.size()
const ll maxsize = 100000;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int query()
{
    string s;
    cin >> s;
    int n = s.size();
    string t(s.rbegin(), s.rend());

    int best_l = 0, best_r = -1;
    for (int l = 0, r = 0; l < n; l = max(l, r) + 1)
    {
        for (r = l - 1; r + 1 < n && s[r + 1] == t[r + 1]; ++r);

        if (best_r - best_l < r - l)
        {
            best_l = l;
            best_r = r;
        }
    }

    cout << s.substr(best_l, best_r - best_l + 1) << '\n';
    return 0;
}
void inti()
{
    freopen(".inp","r",stdin);
    freopen(".our","w",stdout);
}
int main()
{
    fastio();
    int n;
    cin >> n;
    fu(i,1,n,1)
    {query();}
}

