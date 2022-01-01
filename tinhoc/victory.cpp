#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int i = a; i <= b;i+=c)
#define fd(i,a,b,c) for(int i = a; i >= b;i-=c)
int m[200001],n,k,s,p[200001];
void inti()
{
    freopen("victory.inp","r",stdin);
    freopen("victory.out","w",stdout);

}
void tknp(int l,int r,long long  x,int j)
{
    if(l<=r)
    {
        int mid=(l+r)/2;

            if(m[mid]>x)
            {
                tknp(l,mid-1,x,j);
            }
            else
            {
                if(p[mid]==0&&mid!=j)
                {
                    k=mid;
                }
                tknp(mid+1,r,x,j);
                tknp(1,mid-1,x,j);
            }


    }

}
vector<int>a[200001];
void nhap()
{
    int t;
    cin>>t;
    fu(j,1,t,1)
    {
        cin>>n;
        fu(i,1,n,1)
        {
            cin>>m[i];
        }
        if(n==1)
        {
            cout<<"1"<<endl;
            cout<<m[1]<<endl;

        }
        else
        {sort(m+1,m+n+1);


        fu(i,1,n,1)
        {
            k=0;
            s=0;
           long long  l= m[i];
            //cout<<m[i]<<" ";
            //p[i]++;
            tknp(1,n,m[i],i);//cout<<i<<" "<<s<<endl;
            if(k!=0)
            {


                while(p[k]==0)
                {
                    p[k]++;
                    s++;
                    l=l+m[k];
                    tknp(1,n,l,i);
                    //cout<<i<<" "<<k<<" "<<l<<" "<<s<<endl;

                    if(s==n-1)
                    {

                    a[j].push_back(i);
                        break;
                    }

                }
            }
fu(t,1,n,1)p[t]=0;
        }
if(a[j].size()!=0)
{
    cout<<a[j].size()<<endl;
    fu(i,0,a[j].size()-1,1)cout<<a[j][i]<<" ";
    cout<<endl;
}

    }}

}
int main()
{
    //inti();
    nhap();
}
