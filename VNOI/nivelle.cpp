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
int dd[30];
double maxx=100000;
ll l=1,r=1;
void nhap()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    s=' '+s;
     for(int k = 1 ; k <= 26 ; k++)
     {
         memset(dd,0,sizeof dd);
         int khac=0,j=1;
         for(int i = 1 ; i <= n ; i++)
         {
             if(dd[s[i]-'a']==0)khac++;
             dd[s[i]-'a']++;
             if(khac==k)
             {
                 double sum =double(k) /(i-j+1);
                 if(maxx>sum)
                 {
                     maxx=sum;
                     l=j;
                     r=i;
                 }
             }
             else
             {
                 while(khac>k)
                 {
                     dd[s[j]-'a']--;
                     if(dd[s[j]-'a']==0)khac--;
                     j++;
                 }
             }
         }
     }
     cout << l << " "<< r ;
}
int main()
{

    fastio();
    // inti();
    nhap();
}




