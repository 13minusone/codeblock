#include<bits/stdc++.h>
using namespace std;
#define task "select"
#define ll long long
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll maxsize = 200005;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void inti()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
vector<ll>ds;
ll st[maxsize*4],values[maxsize];
struct in
{
    char x;
    ll y;
};
in a[maxsize+5];
void add(int id,int l,int r,int v,int x)
{
   st[id]+=x;
    if(l<r)
    {
        int m=(l+r)/2;
        if(v<=m)
        {
            add(id<<1,l,m,v,x);
        }
        else
        {
            add(id<<1|1,m+1,r,v,x);
        }

    }
}
ll sum(int id,int l,int r,ll k)
{
   if(ds[r]< k)
   {
       //cout << r << " "<< st[id]<<endl;
       return st[id];
   }

   if(ds[l]>=k)return 0;
   if(l<r)
   {
       int m=(l+r)/2;
       return sum(id<<1,l,m,k)+sum(id<<1|1,m+1,r,k);
   }
}
ll get(int id,int l,int r,int k)
{
    if(st[id]<k)return -1;
    if(l==r)
    {
        //cout << l << endl;
        return l;
    }
    if(l<r)
    {
        int m=(l+r)/2;
        if(st[id<<1]>=k)return get(id<<1,l,m,k);
        else
        {
            return get(id<<1|1,m+1,r,k-st[id<<1]);
        }
    }
}
void nhap()
{
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i].x >>a[i].y;
        if(a[i].x=='I')
        {
            ds.push_back(a[i].y);
        }
    }
    sort(ds.begin(),ds.end());
    ds.resize(unique(ds.begin(),ds.end())-ds.begin());
    int f=ds.size();
    for(int i = 1 ; i<= n ; i++)
    {
        if(a[i].x=='I')
        {
            ll k=lower_bound(ds.begin(),ds.end(),a[i].y)-ds.begin();
            if(values[k]==0)
            {

                add(1,0,f-1,k,1);
                values[k]=1;
            }
        }
        if(a[i].x=='D')
        {
            int k=lower_bound(ds.begin(),ds.end(),a[i].y)-ds.begin();
            if(k<f&&ds[k]==a[i].y&&values[k]==1)
            {
                add(1,0,f-1,k,-1);
                values[k]=0;
            }
        }
        if(a[i].x=='K')
        {
            int k=get(1,0,f-1,a[i].y);
            if(k<0||k>=f)cout << "invalid"<<'\n';
            else
            {
                cout << ds[k] <<'\n';
            }
        }
        if(a[i].x=='C')
        {
            ll k=sum(1,0,f-1,a[i].y);
            cout << k<< '\n';
        }
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



