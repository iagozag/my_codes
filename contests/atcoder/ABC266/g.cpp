#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a.size())
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 3e6+10, MOD = 998244353;

ll fexp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans = ans*a%MOD;
        a = a*a%MOD, b >>= 1;
    }
    return ans;
}

void solve(){
    ll r, g, b, k; cin >> r >> g >> b >> k;
    r -= k, g -= k; 

    vl fact(MAX), ifact(MAX);
    fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
    rep(i, 2, MAX) fact[i] = fact[i-1]*i%MOD;
    rep(i, 2, MAX) ifact[i] = ifact[i-1]*fexp(i, MOD-2)%MOD;

    ll sk = fact[k+r+g+b]*ifact[k]%MOD*ifact[r]%MOD*ifact[g]%MOD*ifact[b]%MOD;
    ll skm1 = (!r or !g ? 0 : fact[k+r+g+b-1]*ifact[k+1]%MOD*ifact[r-1]%MOD*ifact[g-1]%MOD*ifact[b]%MOD);

    cout << (((sk-skm1)%MOD)+MOD)%MOD << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
