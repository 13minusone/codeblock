
#include<bits/stdc++.h>
using namespace std;
#define SZ(c) (long long)c.size()
#define task "c"
typedef long long ll;
typedef pair<int,int> ii;
const ll maxsize =2005;
void fastio()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void in()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
}
ll n;
ll p[2020],w[2020],a[2020];
struct node
{
    int x,y,z,d=0;
};
node s[2020];
bool cmp(node a,node b)
{
    ll sum=a.x-b.x+a.y-b.y+a.d-b.d;
    if(sum<0)
    {
        return true;
    }
    else
    {
        if(sum==0)
        {
            int p=max(max(a.x-b.x,a.y-b.y),a.d-b.d);
            int t=max(max(b.x-a.x,b.y-a.y),b.d-a.d);
            if(p<t)
            {
                return true;
            }
            else
            {
                if(p==t)
                {
                    if(a.d!=b.d)
                    {
                        return a.d<b.d;
                    }
                    else if(a.y!=b.y)
                    {
                        if(a.y<b.y)return true;
                        if(a.y>b.y)return false;
                    }
                    else
                    {
                        if(a.x!=b.x)
                        {
                            return a.x<b.x;
                        }
                        else
                        {
                            return true;
                        }
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}
node o[2020];
int main()
{
    fastio();
    //in();
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> p[i];
        s[i].x=min(p[i],a[i]);
        s[i].z=i;
        s[i].y =max(a[i],p[i]);
    }
    sort(s+1,s+1+n,cmp);
    //cout << s[1].z << " "<< s[2].z << endl;
    int g,f,h,sum,maxx[2020],minn[2020];
    for(int i = 1 ; i <= n ; i++)
    {
        maxx[s[i].z]=i;
        g=1;
        f=s[i].x;
        h=s[i].y;
        sum=g+f+h;
        f=min(min(s[i].x,g),s[i].y);
        h=max(max(s[i].x,g),s[i].y);
        o[i].x=f;
        o[i].d=h;
        o[i].y=sum-f-h;
        int k=2,maxi=i;
        if(k<=n)
        {
            for(int j = i-1; j>=1; j--)
            {
                 if(k>n)break;

                g=k;
                f=s[j].x;
                h=s[j].y;
                sum=g+f+h;
                f=min(min(s[j].x,g),s[j].y);
                h=max(max(s[j].x,g),s[j].y);
                g=sum-f-h;
                o[j].x=f;
                o[j].d=h;
                o[j].y=g;
                //cout << j << " "<< k << " "<< f << " "<< h << " "<< g<< endl;
                if(cmp(o[i],o[j])==true)
                {
                    //cout << j << " "<< k << endl;
                    maxi--;

                }
                else
                {
                    while(cmp(o[i],o[j])==false)
                    {
                        g=k;
                        f=s[j].x;
                        h=s[j].y;
                        sum=g+f+h;
                        f=min(min(s[j].x,g),s[j].y);
                        h=max(max(s[j].x,g),s[j].y);
                        g=sum-f-h;
                        o[j].x=f;
                        o[j].d=h;
                        o[j].y=g;
                        if(cmp(o[i],o[j])==true)
                        {
                            //cout << s[i].z << " "<< i << " " << j << endl;
                            maxi--;
                            break;
                        }

                        k++;
                        if(k>n)
                        {
                            break;
                        }
                    }
                    if(k>n)
                    {
                        break;
                    }

                }
                k++;
            }
        }
        maxx[s[i].z]=min(maxx[s[i].z],maxi);
        minn[s[i].z]=i;
        g=n;
        f=s[i].x;
        h=s[i].y;
        sum=g+f+h;
        f=min(min(s[i].x,g),s[i].y);
        h=max(max(s[i].x,g),s[i].y);
        o[i].x=f;
        o[i].d=h;
        o[i].y=sum-f-h;
        k = n-1;
        if(k>=1)
        {
            for(int j = i+1; j<=n  ; j++)
            {
                if(k<1)break;
                g=k;
                f=s[j].x;
                h=s[j].y;
                sum=g+f+h;
                f=min(min(s[j].x,g),s[j].y);
                h=max(max(s[j].x,g),s[j].y);
                g=sum-f-h;
                o[j].x=f;
                o[j].d=h;
                o[j].y=g;
                if(cmp(o[i],o[j])==false)
                {
                    minn[s[i].z]++;
                }
                else
                {
                    while(cmp(o[i],o[j])==true)
                    {
                        g=k;
                        f=s[j].x;
                        h=s[j].y;
                        sum=g+f+h;
                        f=min(min(s[j].x,g),s[j].y);
                        h=max(max(s[j].x,g),s[j].y);
                        g=sum-f-h;
                        o[j].x=f;
                        o[j].d=h;
                        o[j].y=g;
                        if(cmp(o[i],o[j])==false)
                        {
                            minn[s[i].z]++;
                            break;
                        }
                        k--;
                        if(k<1)break;

                    }
                    if(k<1)break;

                }
                k--;

            }
        }
    }
    for(int i = 1 ; i<= n ; i++)
    {
        cout << maxx[i] << " " << minn[i] << endl;
    }
}
