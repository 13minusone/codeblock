#include <bits/stdc++.h>
#pragma GCC optimize(3)
//#define int long long
#define ri register
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define is insert
#define es erase
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define all(c) c.begin(),c.end()
using namespace std; const int N=410, M=160010;
inline int read()
{
	int s=0, w=1; ri char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
	return s*w;
}
int n,m,a[N][N],pre[N][N],r[M],ans;
vector<long long>vec;
signed main()
{
	cin >> n >> m;
	for( int i=1;i<=n;i++)
	for( int j=1;j<=m;j++){ cin >> a[i][j];
	   vec.push_back(a[i][j]);
        }
    sort(all(vec));
    vec.resize(unique(all(vec))-vec.begin());
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            long long k =lower_bound(all(vec),a[i][j])-vec.begin();
            a[i][j]=k;
        }
    }
	for( int i=1;i<=n;i++)
	{
		for( int j=i;j;j--)
		{
			for( int k=1;k<=m;k++)
			{
				int w1=a[j][k];
				int w2=a[i][k];
				pre[j][k]=max(pre[j][k],max(pre[j+1][k],pre[j][k-1]));
				if(w1==w2&&j!=i) pre[j][k]=k+1;
				else pre[j][k]=max(pre[j][k],max(r[w1],r[w2])+1);
				r[w1]=r[w2]=k;

				ans=max(ans,(i-j+1)*(k-pre[j][k]+1));
			}
			for( int k=1;k<=m;k++) r[a[j][k]]=r[a[i][k]]=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}
