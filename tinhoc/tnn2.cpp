#include <bits/stdc++.h>
#define MAX 1e12 + 5
using namespace std;
#define task "test"
map <long long , int> a;
vector <long long> b;
vector <long long>::iterator up;
void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
void create()
{
	long long sum = 0;
	b.push_back(0);
	for (long long i = 1; ; i++)
	{
		sum += i ;
		if (sum > MAX) break;
		a[sum] = i;
		b.push_back(sum);
	}
}
int main()
{
	fastio();
	create();
	int t;
	cin>>t;
	long long n;
	long long vitri;
	for (int i = 1 ; i<= t ; i++)
	{
		cin>>n;
		if (a.find(n) != a.end()) cout<<a[n]<<endl;
		else
		{
			up = upper_bound(b.begin(),b.end(),n);
			vitri = (up - b.begin());
			while (true)
			{
				if ((b[vitri] - n) % 2 == 0) break;
				vitri++;
			}
			cout<<vitri<<endl;
		}
	}

}
