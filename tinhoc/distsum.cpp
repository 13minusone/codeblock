#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fu(a,b,c) for(int i=a;i<=b;i=i+c)
#define fd(a,b,c) for(int i=a;i>=b;i=i-c)
struct pont
{
    ll v,u;
};
    int n;
    ll s=0,o=0;
    pont a[200001];
void nhap()
{

cin>>n;
fu(1,n,1)
{
    cin>>a[i].u>>a[i].v;
}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
nhap();
for(int i=n;i>=2;i--)
{

        ll f=abs(a[i].u-a[i-1].u),k=abs(a[i].v-a[i-1].v);
         ll h=abs(a[i-2].u-a[i].u),g=abs(a[i-2].v-a[i].v);

        s=s+f+k+h+g+abs((f+k)-(h+g));
    }

cout<<s-(o/(n/2+1))*(n/2);
}
