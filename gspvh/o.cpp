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
#define task "allstars"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
#define fi first
#define se second
typedef long long ll ;
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<int> vi;
template<class T> void minimize(T &A, T B) {A=min(A,B);}
template<class T> void maximize(T &A, T B) {A=max(A,B);}
const ll N = 1e5;
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
int r,c,a[7005][7005],d,upl,upr,dl,dr;
vector<ii>vec[7005];
void nhap()
{
    char x;
    cin >> r >> c ;
    memset(a,0,sizeof a);
    int p=c/6;
    if(c%6!=0)p++;
    for (int i = 1; i <= r; i++)
    {
        int dem = 0;
        for(int j =1 ; j <=p;j++)
        {
            cin >> x;
            int num = 0;
            if ('0' <= x && x <= '9') num = x - '0';
            else if ('A' <= x && x <= 'Z')num = x - 'A' + 10;
            else if ('a' <= x && x <= 'z')num = x - 'a' + 36;
            else if (x == '#')num = 62;
            else num = 63;
            for (int j = 0; j <= 5 && dem <= c; j++)
            {
                a[i][++dem] = getbit(num, j);
            }
            if (dem > c)
                break;
        }
    }
    int h=0;
    for(int i = 1 ;  i <= r ; i++)
    {
        h=0;
        for(int j = 1 ; j <=c ; j++)
        {
            if(a[i][j]==1)h++;
            else h=0;
            vec[j].push_back(ii(h,i));
            //cout << f[j] << " ";
        }
        //cout << endl;
    }
    for(int i = 1; i <= c ;i++)
    {
        sort(all(vec[i]));
    }
    ll maxx=0;

    for(int i = 1 ; i <= c ;i++)
    {
        for(int j = 0 ; j < r ; j++)
        {
            ll s=vec[i][j].fi*(r-j);
            if(s>maxx)
            {
                maxx=s;
                d=i;
                upl=i - vec[i][j].fi+1; upr=j+1;
                dr=r;dl=i;
            }
        }
    }
    //cout << maxx << endl;
    for(int i = 0 ; i <r ; i++) cout << vec[d][i].se << " ";
    cout << endl;
    cout << upr << " "<< dr << " " << upl << " "<< dl;

}
int main()
{

    fastio();
     //inti();
    nhap();
}



 

