#include <bits/stdc++.h>
using namespace std;
char a[1000][1000];
int m,n,xq,yq,xs,ys;
int x1;
int yp;
int h[5]={-1,0,1,0,-1};
int cha[1000][1000];
int resx[1000000],resy[1000000],d=0;

void nhap()
{
    scanf("%d %d\n",&m,&n);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='E')
            {
                xs=i;ys=j;
            }
        }

    }
    //cout<<xs<<" "<<ys<<endl;
}
queue<int>xz;
queue<int>yz;
bool kt_dich(int x,int y)
{
    if(a[x][y]!='x')
    {
        if((x==1)||(x==m)||(y==1)||(y==n)) return true;
    }
    return false;
}
bool xuat(int x,int y)
{
    while(!(x==xs&&y==ys))
    {
        //cout << x << " " << y << endl;
        d++;
        resx[d]=x;resy[d]=y;
        if(cha[x][y]==0) x++;
        else
            if(cha[x][y]==1) y--;
            else
                if(cha[x][y]==2) x--;
                else y++;
    }
    cout << d+1 << endl;
    cout << xs << " " << ys << endl;
    for(int i=d;i>=1;i--)
        cout << resx[i] << " " << resy[i] << endl;

}
void khoitao()
{

    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++) cha[i][j]=-1;
    cha[xs][ys]=0;
}
void giai()
{
    khoitao();
    xz.push(xs);
    yz.push(ys);
    while(xz.empty()==false&&yz.empty()==false)
    {
         xq=xz.front();
         yq=yz.front();
         xz.pop();
         yz.pop();
        if(kt_dich(xq,yq)==true)
            {

                xuat(xq,yq);
                return;
            }
        for(int i=0;i<=3;i++)
        {
            x1=xq+h[i];yp=yq+h[i+1];
            if((a[x1][yp]=='.')&&(cha[x1][yp]==-1))
                {
                    cha[x1][yp]=i;
                   xz.push(x1);
                   yz.push(yp);
                }
        }

    }
    cout << "0";
}
int main()
{
    freopen("mecung708.inp","r",stdin);
    freopen("mecung708.out","w",stdout);
    nhap();
    giai();
}
