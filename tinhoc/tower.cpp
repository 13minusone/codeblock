#include<bits/stdc++.h>
using namespace std;
void check(long long d )
{
    long long h,g,f;
    h=sqrt(1+4*d);

    g=(-1+h)/2;
    if(g*(g+1)==d){cout<<"YES"<<'\n';}
    else
    {
        cout<<"NO"<<'\n';
    }

}
int main()
{
    int x;
    long long d;
    cin>>x;
    for(int i=1;i<=x;i++)
    {
        cin>>d;
        check(d*2);
    }
}
