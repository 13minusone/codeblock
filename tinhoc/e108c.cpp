#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(i) push_back(i)
#define pu(i) push(i)
#define fu(i,a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(i,a,b,c) for(int i=a;i>=b;i=i-c)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int maxxn=100000;
    int m,n,x[2*maxxn+1],y;

void inti()
{
   freopen(".inp","r",stdin);
   freopen(".out","w",stdout);
}
bool cmp(int u,int v)
{
    if(u>=v)
    {
        return true;
    }
    return false;
}
map<ll,ll>s2[maxxn*2+1];
unsigned ll s[2*maxxn+1];

vector<int>vec[maxxn];
void nhap()
{

cin>>n;
fu(j,1,n,1)
{
    cin>>m;
    vector<int>dem;

    fu(i,1,m,1)
    {
        cin >> x[i];

    }
    fu(i,1,m,1)
    {
        cin >> y;
        if(vec[x[i]].size()==0)
        {
            dem.pb(x[i]);
        }
        vec[x[i]].pb(y);
        s[x[i]]+=y;

    }

    int g=dem.size();
     //cout <<g;
    fu(i,0,g-1,1)
    {
        sort(vec[dem[i]].begin(),vec[dem[i]].end(),cmp);
    int q=vec[dem[i]].size();
s2[i][q]=0;
            fd(l,q-1,0,1)
            {
                s2[i][l]=0;
                s2[i][l]=s2[i][l+1]+vec[dem[i]][l];

            }
    }



    fu(i,1,m,1)
    {
        unsigned ll res=0;
        fu(k,0,g-1,1)
        {
            int q=vec[dem[k]].size();
            int f=q%i;
            res=res+s[dem[k]]-s2[k][q-f];


        }
        cout << res << " " ;;
    }
    cout << endl;
fu(i,0,g-1,1)
    {




        s[dem[i]]=0;

vec[dem[i]].clear();
    }

}
}
int main()
{
IOS
//inti()
nhap();

}

