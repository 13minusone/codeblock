#include <bits/stdc++.h>
using namespace std;

char a[1000][1000];
int m,n,p,q,s,t,top,bot,xq,yq,x,y;
int qx[1000000],qy[1000000],h[5]={-1,0,1,0,-1};
int d[1000][1000];
int dx[4]={-1,1,1,-1};
int dy[4]={1,1,-1,-1};

void nhap()
{
    scanf("%d %d %d %d %d %d\n",&n,&m,&p,&q,&s,&t);
    p=n+1-p;s=n+1-s;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) d[i][j]=-1;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d\n",&x,&y);
        x=n+1-x;
        d[x][y]=-2;
    }
}
void push(int x,int y)
{
    top++;
    qx[top]=x;qy[top]=y;
}
void pop()
{
    xq=qx[bot];yq=qy[bot];
    bot++;
}
bool kt_dich(int x,int y)
{
    if(x==s&&y==t) return true;
    return false;
}

void khoitao()
{
    bot=1;top=0;    //khoi tao hang doi rong
    for(int i=0;i<=n+1;i++)
    {
        d[0][i]=-2;
        d[n+1][i]=-2;
        d[i][0]=-2;
        d[i][n+1]=-2;
    }


}
void xuat_d()
{
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=n+1;j++) cout << d[i][j]<< " ";
        cout << endl;
    }


}
void giai()
{
    khoitao();
    push(p,q);d[p][q]=0;
    while(bot<=top)
    {
        pop();
        if(kt_dich(xq,yq))
        {
            cout << d[xq][yq];
            return;
        }
        for(int i=0;i<4;i++)
        {
            x=xq+dx[i];y=yq+dy[i];
            while(d[x][y]!=-2)
            {
                if(d[x][y]==-1)
                {
                    d[x][y]=d[xq][yq]+1;
                    push(x,y);
                }
                x=x+dx[i];y=y+dy[i];
             }
        }
    }
    cout << "-1";
}
int main()
{
    freopen("quantuong.inp","r",stdin);
    freopen("quantuong.out","w",stdout);
    nhap();
    giai();
}
