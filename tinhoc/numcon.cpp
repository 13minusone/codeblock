#define task "NUMCON"
#include<bits/stdc++.h>
using namespace std;
string a[int(1e6)];
string s;
int n = 0;
bool cmp(string u, string v)
{
    if(u + v > v + u) return true;
    if(u + v <= v + u ) return false;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    while(cin >> s)
    {
        a[n] = s;
        ++n;
    }
    sort(a, a + n, cmp);
    for(int i = 0; i < n; i++) cout << a[i];

    return 0;
}



