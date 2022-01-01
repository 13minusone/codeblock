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
template<class T> void minimize(T &A, T B)
{
    A=min(A,B);
}
template<class T> void maximize(T &A, T B)
{
    A=max(A,B);
}
const ll maxsize = 50000;
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

ll st[maxsize*4+5],d[maxsize+5];
void pushdown(int id,int l,int m,int r)
{
    if(st[id]==0&&d[id]==1)
    {
        st[id<<1]=0;
        st[id<<1|1]=0;
        d[id<<1]=1;
        d[id<<1|1]=1;
        d[id]=0;
    }
    else
    {
        if(st[id]!=0&&d[id]==0)
        {
            st[id<<1]=(m-l+1);
            d[id<<1]=0;
            st[id<<1|1]=(r-m);
            d[id<<1|1]=0;
            st[id]=0;
        }
    }
}
void upd(int id,int l,int r,int u,int v,int x)
{
    if(l>v||r<u)
    {
        return ;
    }
    if(l>=u&&r<=v)
    {
        if(x==1)
        {

            st[id]=(r-l+1);
            d[id]=0;
            //
            //cout <<st[id]<< " " << l << " " << r << " " << id << endl;
        }
        else
        {
            //cout << st[id] << endl;
            st[id]=0;
            d[id]=1;
        }
        return ;
    }
    int m=(l+r)/2;
    pushdown(id,l,m,r);
    upd(id<<1,l,m,u,v,x);
    upd(id<<1|1,m+1,r,u,v,x);
    st[id]=st[id<<1]+st[id<<1|1];
    //cout << st[id] << " "<< id <<endl;
}

int n,m,q,t,l,r,s=0,a[maxsize+5],o=1;
void nhap()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        s+=a[i];
    }
    for(int i = 1 ;i<= n ; i++)
    {
        upd(1,1,s,o,o+a[i]-2,1);
        o+=a[i];
    }
   cout << st[1] << endl;
    char c;
    for(int i = 1 ; i <= m ; i++)
    {
        cin >> c;
        if(c=='J')
        {
            cin >>l >> r;
            upd(1,1,s,l,r-1,1);
        }
        else
        {
            if(c=='D')
            {
                cin >>l >> r;
                upd(1,1,s,l,r-1,0);
            }
            else
            {
                //cout << st[1] << endl;
                cout << s-st[1] << endl;
            }
        }
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}



