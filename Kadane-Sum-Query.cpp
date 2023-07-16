#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
// using namespace __gnu_pbds;

#define int long long
#define ld long double
#define endl "\n"
#define pi  3.141592653589
#define INF 1e18
#define vi  vector<int>
#define vb vector<bool>
#define vc vector<char>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvb vector<vector<bool>>
#define vpi vector<pair<int,int>>
#define mi map<int,int>
#define mpi map<pair<int,int>,int>
#define pr  pair<int,int>
#define mp  make_pair
#define triplet pair<int,pair<int,int>>
#define ff first
#define ss second
#define pb push_back
#define MAX INT_MAX
#define MIN INT_MIN
#define fr(i,n) for(int i=0; i<n; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define read(x) int x; cin>>x
#define pD(x,y) cout<<fixed<<setprecision(y)<<x
#define google(tno) cout<<"Case #"<<tno<<": "
#define pqb priority_queue<int>
#define pqs priority_queue<int,vi,greater<int> >
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mod 998244353
#define LMAX 9223372036854775807
#define upperToLower(x) char(x | ' ')
#define lowerToUpper(x) char(x & '_')
const int MOD=1e9+7;
const int GN=1e5+10;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

vi fact(GN,1);
vb sieve(GN,1);
vi dsieve(GN,0);

/*---------------------------------------------------------------------------------------------------------------------------*/

bool isPrime(int n){if(n==1)return 0;for(int i=2;i*i<=n;i++){if(n%i==0)return false;}return true;}
void primeSieve(){sieve[0] = sieve[1] = false;for (int i = 2; i*i<GN; i++) {if (sieve[i]) {for (int j = i*i; j<GN; j += i)sieve[j] = false;}}}
void divSieve(){for(int i=1;i<GN;i++){for(int j=i;j<GN;j=j+i){++dsieve[j];}}}
void factSieve(){for(int i=1;i<GN;i++)fact[i]=(fact[i-1]%MOD*1LL*i%MOD)%MOD;}
mi primeFactorise(int n){mi mpp;for(int i=2;i*i<=n;i++){if(n%i==0){int cnt=0;while(n%i==0){++cnt;n=n/i;}mpp[i]=cnt;}}if(n>1)mpp[n]=1;return mpp;}
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
int binexp(int x,int n){int a=x;int prod=1;while(n){if(n%2==1)prod=prod*a;a=a*a;n=n/2;}return prod;}
int modexp(int a, int b, int m) {a %= m;int res = 1LL;while (b > 0) {if (b & 1)res = (res%m *1LL* a%m) % m;a = (a%m *1LL* a%m) % m;b >>= 1;}return res%m;}
int modadd(int a,int b,int m){return (a%m+b%m)%m;}
int modsub(int a,int b,int m){return (a%m-b%m+m)%m;}
int modmul(int a,int b,int m){return (a%m*1LL*b%m)%m;}
int modinv(int a,int m){return modexp(a,m-2,m);}
int moddiv(int a,int b,int m){return (a%m*1LL*modinv(b,m)%m)%m;}
int C(int n,int r){if(n<r || r<0)return 0;if(r==1)return n;int nmr=fact[n]%MOD;int dmr=(fact[r]%MOD*1LL*fact[n-r]%MOD)%MOD;return (nmr%MOD *1LL* modinv(dmr,MOD)%MOD)%MOD;}

/*--------------------------------------------------------------------------------------------------------------------------*/



void solve()
{
    int n;
    cin>>n;
    vi arr(n);
    for(auto &it : arr)cin>>it;
    vi pre(n);
    int psum=0;
    for(int i=0;i<n;i++){
        psum+=arr[i];
        if(psum<0){
            pre[i]=psum;
            psum=0;//carry forward
        }else{
            pre[i]=psum;
        }
    }
    reverse(all(arr));
    vi suff(n);
    int ssum=0;
    for(int i=0;i<n;i++){
        ssum+=arr[i];
        if(ssum<0){
            suff[n-i-1]=ssum;
            ssum=0;//carry forward
        }else{
            suff[n-i-1]=ssum;
        }
    }

    int q;
    cin>>q;
    // debug(q)
    while(q--){
        int t,x;
        cin>>t>>x;
        x--;
        if(t==1){
            cout<<suff[x]<<endl;
        }else{
            cout<<pre[x]<<endl;
        }        
    }
}
int32_t main()
{
#ifndef ONLINE_JUDGE
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    auto start1 = high_resolution_clock::now();
    int T=1;
    // cin>>T;
    while(T--)
    {
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cerr << "Time : " << duration . count() / 1000 << endl;

return 0;
}
