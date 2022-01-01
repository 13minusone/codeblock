#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
int m,n,x;
void inti()
{
    freopen("victory.inp","r",stdin);
    freopen("victory.out","w",stdout);
}
queue<int>vec;
int a[1001];
void solve(int x,int m)
{
    int s=0;
    if(x>1)
    {
        fd(i,x,1,1)
        {
            if(i>m)
            {
                vec.push(i);
                s++;
            }
            if(i<m)
            {
                if(a[m-i]==0)
                {
                    vec.push(i);
                    s++;
                     a[i]++;
                }

            }
        }

        cout<<s<<endl;
        while(vec.empty()==false)
        {
            cout<<vec.front()<<" ";
            a[vec.front()]=0;
            vec.pop();
        }


    }
    else
    {
        cout<<"0";
    }
}
void nhap()
{

    cin>>n;
    fu(i,1,n,1)
    {
        cin>>x>>m;
        solve(x,m);
        cout<<endl;
    }
}
int main()
{
    //inti();

    nhap();
}

