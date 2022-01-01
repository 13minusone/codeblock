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
#define task "3cay"
#define SZ(c) c.size()
#define getbit(x,i) (((x) >> (i)) & 1)
#define turnoff(x,i) (x)&(~(1<<(i)))
#define mu2(x) (1<<x)
#define __builtin_popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define endl '\n'
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
string d;
struct card
{
    int x;
    char a;
};
int f[30];
card a[4],b[4];
bool cmp(card a,card b)
{
    if(a.a==b.a)return a.x >b.x;
    else return f[int(a.a-'A')]<f[int(b.a-'A')];
}
bool check(int s1,int s2)
{
    s1%=10;
    s2%=10;
    if(s1==0)s1=10;
    if(s2==0)s2=10;
    if(s1!=s2)return s1>s2;
    else
    {
        sort(a+1,a+1+3,cmp);
        sort(b+1,b+1+3,cmp);
        if(a[1].a!=b[1].a)return f[int(a[1].a-'A')]<f[int(b[1].a-'A')];
        else return a[1].x>b[1].x;
    }
}
void nhap()
{
    int test;
    cin >> test;
    f[int('R'-'A')]=0;
    f[int('C'-'A')]=1;
    f[int('P'-'A')]=2;
    f[int('N'-'A')]=3;
    while(test--)
    {
        int s1=0,s2=0;
        char p1,p2;

        for(int i = 1; i <= 3;i++)
        {
            cin >> d;
            if(d[0]=='A')
            {
                s1++;
                a[i].x=10;
                a[i].a=d[1];
            }
            else
            {
                a[i].x=int(d[0]-'0');
                s1+=a[i].x;
                a[i].a=d[1];
            }
        }
        cin >> d;
        for(int i = 1; i <= 3;i++)
        {
            cin >> d;
            if(d[0]=='A')
            {
                s2++;
                b[i].x=10;
                b[i].a=d[1];
            }
            else
            {
                b[i].x=int(d[0]-'0');
                s2+=b[i].x;
                b[i].a=d[1];
            }
        }
        //  cout <<s1 << " "<< s2 ;
        if(check(s1,s2))cout << "Yes" << " ";
        else cout << "No" <<  " ";
//        for(int i = 1 ; i<= 3 ; i++)
//        {
//            cout << a[i].x << a[i].a << " ";
//        }
//        cout << endl;
//        for(int i = 1; i <=3 ; i++)
//        {
//            cout << b[i].x << b[i].a <<  " ";
//        }
//        cout << endl;
    }
}
int main()
{

    fastio();
    // inti();
    nhap();
}




