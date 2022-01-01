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
#define task "teams"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
typedef long long ll;
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
const ll maxsize = 400005;
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
int n;
struct minh
{
    int x,y,id,z;
};
ll z,y,x;
minh a[maxsize];
bool cmp(minh x,minh y)
{
    if(x.z ==y.z)
    {
        return x.x <y.x;
    }
    else
    {
        return x.z < y.z;
    }
}
vector<int>vec;
int b[maxsize],cnt=0;
void nhap()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].z;
        a[i].id=i;
    }
    if(n>20)
    {
        cout << 0 ;
        return;
    }
    for(int i = 0 ; i < mu2(n); i++)
    {
        vec.clear();
        int maxx=0,l=0,r=0,mi=0,ma=0;
        for(int j = 0 ; j < n ; j++)
        {
            if(getbit(i,j)==1)
            {
                if(maxx==0)
                {
                    vec.push_back(j+1);
                }
            }
        }
        bool te =true;
        for(int k = 0 ; k < SZ(vec); k++)
        {
            int g=vec[k];
            for(int j = k + 1 ; j<SZ(vec); j++)
            {
                int h=vec[j];
                if(a[h].x>a[g].y||a[h].z<a[g].y||a[g].z<a[h].y||a[g].x>a[h].y)
                {
                    te=false;
                    break;
                }
            }
        }
        if(te==true)
        {
            if(SZ(vec)>cnt)
            {
                cnt=SZ(vec);
                for(int j = 0 ; j <SZ(vec); j++)
                {
                    b[j+1]=vec[j];
                }
            }
        }
    }
    cout << cnt << endl;
    for(int i = 1 ; i <=cnt; i++)
    {
        cout << b[i] << " ";
    }
}
int main()
{

    fastio();
    //inti();
    nhap();
}



