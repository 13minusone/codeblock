#include<bits/stdc++.h>
#define MAX   250052
#define LET   27
using namespace std;
struct nod {
    int pa;
    int ch[LET];
    bool isw;
    int cnt;
    nod(){}
    nod(const int &_pa) {
        pa=_pa;
        int i;
        for (i='a';i<='z';i=i+1) ch[i-'a']=-1;
        isw=false;
        cnt=0;
    }
};
vector<nod> trie;
int n,res;
int id[MAX];
char s[MAX];
void insert(const int &i,const char &c) {
    trie.push_back(nod(i));
    trie[i].ch[c-'a']=trie.size()-1;
}
void maximize(int &x,const int &y) {
    if (x<y) x=y;
}
void init(void) {
    trie.clear();
    trie.push_back(nod(-1));
    scanf("%d",&n);
    int i,j,l,u;
    for (i=1;i<=n;i=i+1) {
        scanf("%s",s);
        l=strlen(s);
        u=0;
        for (j=0;j<l;j=j+1) {
            if (trie[u].ch[s[j]-'a']<0) insert(u,s[j]);
            u=trie[u].ch[s[j]-'a'];
        }
        trie[u].isw++;
        id[i]=u;
    }
}
void visit(const int &u) {
    int i,v;
    for (i='a';i<='z';i=i+1) {
        v=trie[u].ch[i-'a'];
        if (v<0) continue;
        trie[v].cnt=trie[u].cnt+trie[v].isw;
        maximize(res,trie[v].cnt);
        visit(v);
    }
}
void process(void) {
    res=-1;
    visit(0);
    printf("%d",res);
}
int main(void) {
    init();
    process();
    return 0;
}
