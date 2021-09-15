//Author:Md. Liad Hossain
//KUET ECE 2K18
 
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
#define lld long long int
#define ulld unsigned long long int
#define vl vector<lld>
#define vll vector<pair<lld, lld>>
#define ff first
#define ss second
#define pf push_front
#define pb push_back
#define eb emplace_back
#define pof pop_front
#define pob pop_back
#define fbo find_by_order
#define ofk order_of_key
#define fo(i, a, b) for (lld i = a; i <= b; i++)
#define FOR(i, n) for (lld i = 0; i < n; i++)
#define F0R(j, n) for (lld j = 1; j <= n; j++)
#define ROF(i, n) for (lld i = n - 1; i >= 0; i--)
#define R0F(i, n) for (lld i = n; i >= 1; i--)
#define all(v) v.begin(), v.end()
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define rs random_shuffle
#define yes printf("YES\n")
#define no printf("NO\n")
#define mod 1000000007LL
#define M 998244353
#define setbit __builtin_popcount
#define elif else if
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define pi 2 * acos(0.0)
#define inf 9000000000000000000LL
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
void read(int &x)
{
    scanf("%d", &x);
}
void read(lld &x)
{
    scanf("%I64d", &x);
}
void read(lld &a, lld &b)
{
    scanf("%I64d %I64d", &a, &b);
}
void read(lld &a, lld &b, lld &c)
{
    scanf("%I64d %I64d %I64d", &a, &b, &c);
}
void read(lld &a, lld &b, lld &c, lld &d)
{
    scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d);
}
void read(double &x)
{
    scanf("%lf", &x);
}
void read(char &x)
{
    scanf("%c", &x);
}
void read(string &x)
{
    char y[1000006];
    scanf("%s", &y);
    x = y;
}
 
void print(lld x, bool flag = false)
{
    if (flag)
        printf("%I64d ", x);
    else
        printf("%I64d\n", x);
}
void print(int x, bool flag = false)
{
    if (flag)
        printf("%d ", x);
    else
        printf("%d\n", x);
}
void print(double x, bool flag = false)
{
    if (flag)
        printf("%0.14lf ", x);
    else
        printf("%0.14lf\n", x);
}
void print(char x)
{
    printf("%c\n", x);
}
 
void print(string x)
{
    for (lld i = 0; i < x.size(); i++)
    {
        printf("%c", x[i]);
    }
    printf("\n");
}
//knight moves...
//lld dx[]={-1,-2,-2,-1,1,2,2,1};
//lld dy[]={-2,-1,1,2,2,1,-1,-2};
 
//grid moves without diagonal
//lld dx[]={0,-1,0,1};
//lld dy[]={-1,0,1,0};
 
//*************************Code Begins Here*************************//
 
const lld mx=303;
lld fen[mx][mx];
void update(lld row,lld id,lld val)
{
    while(id<mx)
    {
        fen[row][id]+=val;
        id+=(id&-id);
    }
}
 
lld query(lld row,lld id)
{
    lld res=0;
    while(id>0)
    {
        res+=fen[row][id];
        id-=(id&-id);
    }
    return res;
}
 
lld binarySearch(lld val,lld row,lld col)
{
    lld low=1,high=row;
    lld ans=1;
    while(low<=high)
    {
        lld mid=(low+high)/2;
        if(val>=(col*(mid-1))+1)
        {
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
 
    return ans;
}
 
bool comp(pair<lld,lld>p1,pair<lld,lld>p2)
{
    if(p1.ff!=p2.ff)return p1.ff>p2.ff;
 
    return p1.ss<p2.ss;
}
 
void solve()
{ 
    lld n,m;
    read(n,m);
    lld a[n*m],b[n*m];
    FOR(i,n)
    {
        FOR(j,m)fen[i+1][j+1]=0;
    }
 
    FOR(i,n*m)
    {
        read(a[i]);
        b[i]=a[i];
    }
 
    lld cnt=0;
    sort(a,a+n*m);
    unordered_map<lld,lld>mp;
    FOR(i,n*m)
    {
        if(mp.count(a[i])==0)
        {
            mp[a[i]]=++cnt;
        }
    }
    lld maxi=cnt;
    cnt=0;
    vl vec[maxi+1];
    FOR(i,n*m)
    {
        ++cnt;
        vec[mp[a[i]]].pb(cnt);
    }
    vll mp2[maxi+1];
    FOR(i,n*m)
    {
        lld num=vec[mp[a[i]]].back();
        vec[mp[a[i]]].pob();
        lld row=binarySearch(num,n,m);
        num=num-((row-1)*m);
        mp2[mp[a[i]]].pb({row,num});
    }
 
    F0R(i,maxi)
    {
        sort(all(mp2[i]),comp);
    }
 
    lld ans=0;
    FOR(i,n*m)
    {
        lld row=mp2[mp[b[i]]].back().ff;
        lld col=mp2[mp[b[i]]].back().ss;
        mp2[mp[b[i]]].pob();
        ans+=query(row,col-1);
        //cout<<row<<" "<<col<<" "<<ans<<endl;
        update(row,col,1);
    }
 
    print(ans);
}  
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int t=1;
    read(t);
    while(t--)
    {
        solve();
    }
    return 0;
}
