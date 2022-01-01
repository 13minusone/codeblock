#include<bits/stdc++.h>
using namespace std;
#define fu(i,a,b,c) for(int i = a ;i <= b ;i+=c)
#define fd(i,a,b,c) for(int i = a ;i >= b ;i-=c)
#define ll long long
#define endl '\n'
const int maxx =100005;
int st[maxx*4],arr[maxx];
void build(int id , int l ,int r )
{
	if( l == r ){
		st[id]=arr[l];
		return;
	}
	int mid =(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	st[id]=min(st[id<<1],st[id<<1|1]);

}
ll get(int id ,int l ,int r ,int u, int v )
{
	if ( l > v || r < u )
	{
		return INT_MAX;
	}
	if(l >= u && r <= v )
	{
		return st[id];
	}
	int mid=(l+r)/2;
	return min(get(id<<1,l,mid,u,v),get(id<<1|1,mid+1,r,u,v));
}
int n,l;
int main()
{

	int t;
	cin >> t;
	fu(k,1,t,1)
	{
		cin >> n >> l;
	fu(i,1,n,1)
	{
		cin >> arr[i];
	}
	build(1,1,n);
	fu(i,1,n-l+1,1)
	{
		cout << get(1,1,n,i,i+l-1)<<" ";
	}
	cout <<endl;
}
}
