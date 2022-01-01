#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
    int m,n,k,p[5001][5001];

    string s;
    int h[5]={-1,0,1,0,-1};
int cha[5001][5001];
int resx[1000000],resy[1000000],d=0;
queue<int>xz;
queue<int>yz;
bool kt_dich(int x,int y)
{
    if(p[x][y]==0)
    {
        if((x==1)&&(y==1)) return true;
    }
    return false;
}
int xuat(int x,int y,int xs,int ys)
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
    return d;

}
void khoitao(int xs,int ys)
{

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cha[i][j]=-1;
    cha[xs][ys]=0;
}
void giai(int xs,int ys,int maxx)
{
    khoitao(xs,ys);
    xz.push(xs);
    yz.push(ys);
    while(xz.empty()==false&&yz.empty()==false)
    {
        int xq,yq,x1,yp;
         xq=xz.front();
         yq=yz.front();
         xz.pop();
         yz.pop();
        if(kt_dich(xq,yq)==true)
            {

          // cout<<xuat(xq,yq,xs,ys)<<" "<<maxx<<endl;
                if(xuat(xq,yq,xs,ys)!=maxx)
                {
                    //cout<<d<<" "<<maxx<<endl;;
                    cout<<"NO";
                }
                else
                {
                    //cout<<d<<" "<<maxx<<endl;;
                    cout<<"YES";
                }
                return;
            }
        for(int i=0;i<=3;i++)
        {
            x1=xq+h[i];yp=yq+h[i+1];
            if(cha[x1][yp]==-1&&p[x1][yp]==0&&x1>0&&yp>0&&x1<n&&yp<m)
                {
                    cha[x1][yp]=i;
                   xz.push(x1);
                   yz.push(yp);
                }
        }

    }

}
void inti()
{
   freopen("robot709.inp","r",stdin);
   freopen("robot709.out","w",stdout);
}
void nhap()
{

cin>>n>>m>>k;

fu(i,1,k,1)
{
    int l,r;
    cin>>l>>r;
    p[l][r]=1;
}
cin>>s;
int i=1,j=1;
fu(f,0,s.size()-1,1)
{
    if(s[f]=='R')
    {
        j++;
    }
    if(s[f]=='L')
    {
        j--;
    }
    if(s[f]=='U')
    {
        i--;
    }
    if(s[f]=='D')
    {
        i++;
    }
    if(p[i][j]==1||i>n||j>m||i<0||j<0)
    {
        cout<<"-1"<<" "<<"-1"<<endl;
        cout<<"ERROR"<<endl;

        return;
    }
}
cout<<i<<" "<<j<<endl;
giai(i,j,s.size());
}
int main()
{
   inti();
nhap();
}

