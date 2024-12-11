#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define per(i,n,x) for(auto i=n;i>=x;i--)
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

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "No" << endl; }
void yes(){ cout << "Yes" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

int n;
vi v, dp, black;

void f(int i, int c){
    dp[i] = c;
    if(dp[v[i]] != c) f(v[i], c);
}

void solve(){
    cin >> n; 
    v = black = vi(n);
    forr(x, v) cin >> x, --x;
    string s; cin >> s;
    rep(i, 0, n) black[i] = (s[i] == '0');

    int c = 0; dp = vi(n, -1);
    rep(i, 0, n) if(dp[i] == -1) f(i, c++); 

    map<int, int> mp;
    rep(i, 0, n) if(black[i]) mp[dp[i]]++;

    rep(i, 0, n) dp[i] = mp[dp[i]];

    forr(x, dp) cout << x << " ";
    cout << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}