#include<bits/stdc++.h>
using namespace std;
#define SZ(c) (long long)c.size()
#define task "c"
typedef long long ll;
typedef pair<int,int> ii;
const ll maxsize =2005;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void in()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
int n;
ll f[205][5][205],a[205][05],dd[5],maxx[205],maxxi=0;;
ll quaylui(int i)
{
    if(i==n)
    {
        return max({a[i][1]-dd[1]-1,a[i][2]-dd[2]-1,a[i][3]-dd[3]-1});
    }
    maxx[i]=0;
    int h;
    for(int j = 1 ;j <= 3 ; j++)
    {
        dd[j]++;
        if(a[i][j]-dd[j]>maxx[i])
        {
            dd[h]--;
            h=j;
            maxx[i]=a[i][j]-dd[j];
            maxxi=max(maxx[i],maxxi);
        }
        else
        {
            dd[j]--;
        }
    }
    //cout << i << " "<< maxx[i] << endl;
    return maxx[i]+quaylui(i+1);
}
int main()
{
    fastio();
    //in();
    cin >> n;
    for(int i = 1 ; i<= n ; i++)
    {
        for(int j = 1 ; j<= 3 ; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << quaylui(1);
    //cout << maxxi ;


}
