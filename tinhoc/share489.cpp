#define task "SHARE948"
#include<bits/stdc++.h>
using namespace std;
int n;
long long m, s = 0, a[int(1e5) + 1];
struct data
{
    long long val;
    int id;
};
data b[int(1e5) + 1];
bool cmp(data u, data v)
{
    if(u.val < v.val) return true;
    if(u.val > v.val) return false;
}
int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld",&a[i]);
        s += a[i];
        b[i].val = a[i];
        b[i].id = i;
    }
    if(s < m)
    {
        cout << -1;
        return 0;
    }
    if(s == m)
    {
        for(int i = 1; i <= n; i++) cout << a[i] << " ";
        return 0;
    }
    sort(b + 1, b + n + 1, cmp);
    for(int i = 1; i <= n; i++)
    {
        int tb = m/(n - i + 1);
        if(b[i].val > tb) a[b[i].id] = tb;
        m = m - a[b[i].id];
    }
    for(int i = 1; i <= n; i++) printf("%lld ", a[i]);
    return 0;
}

