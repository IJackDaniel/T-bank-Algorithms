#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits.h>
#include <cassert>
#include <cstring>
#include <float.h>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <math.h>
#include <random>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define mx 1000006
#define pii              pair <int,int>
#define pll              pair <long long,long long>
#define sc               scanf
#define pf               printf
#define Pi               2*acos(0.0)
#define ms(a,b)          memset(a, b, sizeof(a))
#define pb(a)            push_back(a)
#define MP               make_pair
#define db               double
#define ll               long long
#define EPS              10E-10
#define ff               first
#define ss               second
#define sqr(x)           (x)*(x)
#define D(x)             cerr<<#x " = "<<(x)<<endl
#define VI               vector <int>
#define DBG              pf("Hi\n")
#define MOD              1000000007
#define CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define stlloop(v)       for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define loop(i,n)        for(int i=0;i<n;i++)
#define loop1(i,n)       for(int i=1;i<=n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define TEST_CASE(t)     for(int z=1;z<=t;z++)
#define PRINT_CASE       printf("Case %d: ",z)
#define LINE_PRINT_CASE  printf("Case %d:\n",z)
#define CASE_PRINT       cout<<"Case "<<z<<": "
#define all(a)           a.begin(),a.end()
#define intlim           2147483648
#define infinity         (1<<28)
#define ull              unsigned long long
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))

ll tree[2][mx];
ll ara[mx],ara2[mx];

void update(int id, int idx, ll val)
{
    for(; idx<mx && idx; idx+=idx&-idx)
        tree[id][idx]+=val;
}

ll query(int id, int idx)
{
    ll ret=0;
    for(; idx; idx-=idx&-idx)
        ret+=tree[id][idx];
    return ret;
}

vector<ll>v;

int main()
{

//    freopen("in.txt","r",stdin);
//	  freopen("out.txt","w",stdout);

    int n;
    sf(n);
    v.pb(0);
    loop1(i,n)
    {
        sfl(ara[i]);
        v.pb(ara[i]);
    }
    sort(all(v));

    ll ans=0;

    for(int i=n; i>0; i--)
    {
        int id=lower_bound(all(v),ara[i])-v.begin();
        ara2[i]=query(0,id);
        update(0,id+1,1);
//        update(0,id-1,-1);
    }

    for(int i=n; i>0; i--)
    {
        int id=lower_bound(all(v),ara[i])-v.begin();
        ans+=query(1,id);
        update(1,id+1,ara2[i]);
//        update(1,id-1,-ara2[i]);
    }

    printf("%lld\n",ans);

    return 0;
}