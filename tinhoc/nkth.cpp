#define task "NKTH"
#include<bits/stdc++.h>
using namespace std;
int d = -1, n, m;
double p, q;
double a[int(1e5)];
bool cmp(double u, double v)
{
    if(u >= v) return true;
    else return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> n >> p >> m >> q;
    for(int i = 0; i < n; i++)
    {
        double f,k,u,l,w;
        cin >> f >> k >> u >> l >> w;
        if((w==1)&&(f != 0 )&&(k != 0)&&(u != 0))
        {
            double diem = (f + k)*double(2) + double(u) + double(l);
            if((diem >= p)&&(k >= q))
            {
                d++;
                a[d] = diem;
            }
        }
    }
    d++;
    sort(a, a + d, cmp);
    cout << fixed << setprecision(2) << a[0] << " ";
    while(a[m]==a[m - 1]) m--;
    cout << fixed << setprecision(2) << a[m - 1];
    return 0;
}
