#define task "SWGAME"
#include<bits/stdc++.h>
using namespace std;
int n, l, r, cnt = 0, t, k;
int a, pos[int(1e6)], f1[int(1e5) + 4], f2[int(1e5) + 4];
void init()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main()
{
    fastio();
    init();
    cin >> n >> l >> r;
    t = min(l, r);
    for(int i = 1;i <= n; i++)
    {
        cin >> a;
        if(a%2 != 0)
        {
            ++cnt;
            pos[cnt] = i;
        }
    }
    if(cnt == 1)
    {
        cout << 0;
        return 0;
    }
    else if(cnt == 2)
    {
        cout << min((pos[2] - pos[1])*t,(n + pos[1] - pos[2])*t);
        return 0;
    }
    f1[1] = 0;
    f2[0] = 0;
    for(int i = 2; i <= cnt; i++)
    {
        if(i % 2 == 0) f2[i] = f2[i - 2] + (pos[i] - pos[i - 1])*t;
        else f1[i] = f1[i - 2] + (pos[i] - pos[i - 1])*t;
    }
    if(cnt % 2 == 0)
    {
        cout << min(f2[cnt], f1[cnt - 1] + (n + pos[1] - pos[cnt])*t);
        return 0;
    }
    else
    {
        int v = (n + pos[1] - pos[cnt])*t;
        int minn = min(f1[cnt],f2[cnt - 1] - f2[2] + (pos[2] + n - pos[cnt])*t);
        for(int i = 2; i <= cnt - 2; i++)
        {
            if(i % 2 == 0)
            {
                k = min(f1[cnt] - f1[i + 1] + (pos[i + 1] - pos[i - 1])*t + f2[i - 2],
                        f2[cnt - 1] - f2[i] + f1[i - 1] + v);
                minn = min(k, minn);
            }
            else
            {
                k = min(f1[cnt] - f1[i] + f2[i - 1],
                        v + f1[i - 2] + (pos[i + 1] - pos[i-1])*t + f1[cnt] - f1[i]);
                minn = min(k, minn);
            }
        }
        k = min(f2[cnt - 3] + (pos[cnt] - pos[cnt - 2])*t,
                 f1[cnt - 2] + v);
        minn = min(k, minn);
        k = min(f2[cnt - 1],
                f1[cnt - 2] +(pos[1] + n - pos[cnt - 1])*t);
        minn = min(k, minn);
        cout << minn << '\n';
    }
    return 0;
}
