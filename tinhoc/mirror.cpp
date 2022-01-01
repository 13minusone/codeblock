#include <bits/stdc++.h>
using namespace std;
int n;
char a[1005][1005];

void nhap()
{
    scanf("%d\n",&n);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++) scanf("%c", &a[i][j]);
        scanf("\n");
    }
}
void loang(int x,int y)
{
    int ha[4]={-1,0,1,0};
    int co[4]={0,1,0,-1};
    int s=0,xx,yy,d=0;
    queue<int> qx,qy;
    qx.push(x);qy.push(y);
    a[x][y]='a';
    while (!qx.empty())
    {
        xx=qx.front();yy=qy.front();
        qx.pop();qy.pop();
        for(int i=0;i<=3;i++)
        {
            if(a[xx+ha[i]][yy+co[i]]=='#') d++;
            if(a[xx+ha[i]][yy+co[i]]=='.')
            {
                qx.push(xx+ha[i]);qy.push(yy+co[i]);
                a[xx+ha[i]][yy+co[i]]='a';
            }
        }
    }
    cout<<(d-4)*9;
}
void giai()
{
    for(int i=0;i<=n+1;i++)
    {
        a[i][0]='#';
        a[i][n+1]='#';
        a[0][i]='#';
        a[n+1][i]='#';
    }
    loang(1,1);
}
int main()
{
    freopen("mirror.inp", "r", stdin);
    freopen("mirror.out", "w", stdout);
    nhap();
    giai();

}
