/*
🛸　　　 　🌎　°　　🌓　•　　.°•　　　🚀 ✯
　　　★　*　　　　　°　　　　🛰 　°·　　                           🪐
.　　　•　° ★　•  ☄
______________________________________________________
    You are watching a brute force code
        CODE IS WRITTEN BY 13MINUSONE
*/
#include<bits/stdc++.h>
using namespace std;
#define task "c"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
typedef long long ll ;
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
const ll maxsize = 30005;
const ll mod =1e9+9;
const ll base = 311;
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
struct node
{
    int type,s;
} st[5*maxsize];
void update(int id,int l,int r, int u,int v, int val)
{
    if(l>v||r<u){
    return;
    }
    if(l>=u&&r<=v)
    {
        st[id].type+=val;
        if(val==1)
        {
            st[id].s=r-l+1;
        }
        else if(st[id].type==0)
            {
                st[id].s=st[id*2].s+st[id*2+1].s;
            }
        return;
    }
    int m=(l+r)/2;
    update(id*2,l,m,u,v,val);
    update(id*2+1,m+1,r,u,v,val);
    if(st[id].type==0)
    {
        st[id].s=st[id*2].s+st[id*2+1].s;
    }
}
struct canh
{
    int x,y1,y2,type;
};
vector<canh>vec;
bool cmp(canh a,canh b)
{
    if(a.x==b.x)return a.type>b.type;
    else return a.x<b.x;
}
void nhap()
{
    int n,x,y,z,d;
    cin >> n;
    while(n--)
    {
        cin >> x>> y >> z >> d;
        vec.push_back({x,y+1,d,1});
        vec.push_back({z,y+1,d,-1});
    }
    sort(all(vec),cmp);
    ll res=0;
    for(int i = 0 ; i < SZ(vec) ; i++)
    {
        if(i>0)
        {
            res+=st[1].s*(vec[i].x-vec[i-1].x);
            //cout << res<<" " << st[1].s << endl;

        }
        //cout << vec[i].y1 <<" "<< vec[i].y2 << " "<< vec[i].type << endl;
        update(1,1,30000,vec[i].y1,vec[i].y2,vec[i].type);
    }
    cout << res << endl;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




