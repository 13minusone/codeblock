#include <bits/stdc++.h>
using namespace std;
int r,c,h,w;
int p[3001][3001];
int l=INT_MAX;
int rr=0;
int main()
{
     ios::sync_with_stdio(!cin.tie(0));
    freopen("c.inp","r",stdin);
    //freopen("test.out","w",stdout);
    cin >>  r >> c >> h >> w;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cin >> p[i][j];
            l=min(p[i][j],l);
            rr=max(p[i][j],rr);
        }
    }
    int ans=0;
    while(l<=rr)
    {
        int s[r+1][c+1];
        int mid=(l+rr)/2;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
                if(p[i][j]>=mid) s[i][j]++;
            }
        }
        bool check=false;
        int val1=(h*w)/2+1;
        for(int i=h;i<=r;i++)
        {
            for(int j=w;j<=c;j++)
            {
                int val=s[i][j]-s[i-h][j]-s[i][j-w]+s[i-h][j-w];
                if(val>=val1)
                {
                    check=true;
                    break;
                }
            }
        }
        if(check)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            rr=mid-1;
        }
    }
    cout << ans;
}
