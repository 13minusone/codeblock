#include <bits/stdc++.h>
using namespace std;
int n,a[500005],top=0,st[500005],d[100000],s=0;
long long res=0;
void push(int x)
{
    top++;
    st[top]=x;
}

void pop()
{
    top--;
}

void nhap()
{
    //cin>>n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        //cin>>a[i];
        scanf("%d",&a[i]);
}

void xuat_st()
{
    for(int i=1;i<=top;i++)
        cout<<st[i]<<" ";
    cout<<endl;
    for(int i=1;i<=top;i++)
        cout<<d[i]<<" ";
    cout<<endl;
}


void xuli()
{
    int j;
    top=0;
    push(a[1]);d[top]=1;
    for (int i=2;i<=n;i++)
    {
        int x=1;
        while(top>0&&st[top]<=a[i])
        {
            res=res+d[top];
            if(st[top]==a[i]) x=d[top]+1;
            pop();
        }
        if(top>0)
        {
            res++;
        }
        push(a[i]);
        d[top]=x;
    }
    cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("pairwise.inp","r",stdin);
    freopen("pairwise.out","w",stdout);
    nhap();
    xuli();
}
