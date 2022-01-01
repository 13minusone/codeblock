#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int a[505][505], n, m, s=0;
void read()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) cin >> a[i][j];
        s^=a[i][1];
    }
}
void sol()
{
    if (s>0)
    {
        cout << "TAK\n";
        for(int i=1; i<=n; i++) cout << 1 << " ";
        return;
    }
    else
    {
        int x=0, y=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=2; j<=m; j++)
            {
                if (a[i][j]!=a[i][1])
                {
                    x=i, y=j;
                    break;
                }
            }
            if (x>0) break;
        }
        if (x>0)
        {
            cout << "TAK\n";
            for(int i=1; i<=n; i++)
            {
                if (i==x) cout << y << " ";
                else cout << 1 << " ";
            }
            return;
        }
    }
    cout << "NIE";
}
int main()
{
    fastio();
    read();
    sol();
}
