#include <bits/stdc++.h>
using namespace std;
int n,m,st[1000001],top=0,bot=1,res=0,a,s=0;
void push(int x)
{
    top++;
    st[top]=x;
}

int pop()
{
    bot++;
    return st[bot-1];
}

void xuli()
{
    scanf("%d%d\n",&m,&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        push(a);
        s+=a;
        if (s>m)
        {
            //xuat();
            while (s>m) s-=pop();
            //cout<<s<<" "<<bot<<" "<<top<<endl;
            if (top-bot+1>res) res=top-bot+1;
        }
        else if (top-bot+1>res) res=top-bot+1;
    }
    printf("%d",res);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("giangden.inp","r",stdin);
    freopen("giangden.out","w",stdout);
    xuli();
}

