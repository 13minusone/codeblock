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
bool cmp1(node a,node b)
{

    if(a.y!=b.y)
    {
        return a.y<b.y;
    }
    else
    {
        if(a.x!=b.x)
        {
            return a.x<b.x;
        }
        else
        {
            return true;;
        }
    }
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
        if(s[i].x==s[i].y)
        {
            s[i].x=0;
            s[i].y++;
        }
    }
    sort(s+1,s+1+n,cmp1);
    for(int i = 1 ; i <= n ; i++)
    {
        //cout << s[i].x << " " << s[i].y << " " << s[i].z << endl;
    }
    int g,f,h,sum,maxx[2020],minn[2020];
    for(int i = 1 ; i<= n; i++)
    {
        maxx[s[i].z]=i;
        g=1;
        f=s[i].x;
        h=s[i].y;
        if(g==f)
        {
            g=0;
            f++;
        }
        else
        {
            if(g==h)
            {
                h++;
                g=0;
            }
        }
        sum=g+f+h;
        f=min(min(f,g),h);
        h=max(max(f,g),h);
        o[i].x=f;
        o[i].d=h;
        o[i].y=sum-f-h;
        int k=2,maxi=i;
        for(int j = i-1; j>=1; j--)
        {
            if(k>n)break;
            g=k;
            f=s[j].x;
            h=s[j].y;
            if(g==f)
            {
                g=0;
                f++;
            }
            else
            {
                if(g==h)
                {
                    h++;
                    g=0;
                }
            }
            sum=g+f+h;
            f=min(min(s[j].x,g),s[j].y);
            h=max(max(s[j].x,g),s[j].y);
            g=sum-f-h;
            o[j].x=f;
            o[j].d=h;
            o[j].y=g;
            if(cmp(o[i],o[j])==true)
            {
                //cout << j << " "<< k << endl;
                maxx[s[i].z]--;
                //cout << k << " "<< j << " "<< s[i].y << endl;
                k++;

            }
            else
            {
                while(cmp(o[i],o[j])==false)
                {
                    g=k;
                    f=s[j].x;
                    h=s[j].y;
                    if(g==f)
                    {
                        g=0;
                        f++;
                    }
                    else
                    {
                        if(g==h)
                        {
                            h++;
                            g=0;
                        }
                    }
                    sum=g+f+h;
                    f=min(min(f,g),h);
                    h=max(max(f,g),h);
                    g=sum-f-h;
                    o[j].x=f;
                    o[j].d=h;
                    o[j].y=g;
                    if(cmp(o[i],o[j])==true)
                    {
                        //cout << s[i].z << " "<< i << " " << j << endl;
                        maxx[s[i].z]--;
                        ///cout << k << " "<< j << endl;

                        k++;

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


        }
        minn[s[i].z]=i;
        g=n;
        f=s[i].x;
        h=s[i].y;
        if(g==f)
        {
            g=0;
            f++;
        }
        else
        {
            if(g==h)
            {
                h++;
                g=0;
            }
        }
        sum=g+f+h;
        f=min(min(f,g),h);
        h=max(max(f,g),h);
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
                if(g==f)
                {
                    g=0;
                    f++;
                }
                else
                {
                    if(g==h)
                    {
                        h++;
                        g=0;
                    }
                }
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
                    k--;
                }
                else
                {
                    while(cmp(o[i],o[j])==true)
                    {
                        g=k;
                        f=s[j].x;
                        h=s[j].y;
                        if(g==f)
                        {
                            g=0;
                            f++;
                        }
                        else
                        {
                            if(g==h)
                            {
                                h++;
                                g=0;
                            }
                        }
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
                            k--;
                            break;
                        }
                        k--;
                        if(k<1)break;

                    }
                    if(k<1)break;
                    continue;
                }


            }
        }
    }
    for(int i = 1 ; i<= n ; i++)
    {
        cout << maxx[i] << " " << minn[i] << endl;
    }
}
