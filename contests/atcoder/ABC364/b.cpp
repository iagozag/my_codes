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

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n, m, sx, sy; cin >> n >> m >> sx >> sy; --sx, --sy;
    vector<string> v(n); forr(x, v) cin >> x;
    string s; cin >> s;

    rep(i, 0, sz(s)){
        int nx, ny;
        if(s[i] == 'L') nx = sx, ny = sy-1;
        else if(s[i] == 'R') nx = sx, ny = sy+1;
        else if(s[i] == 'D') nx = sx+1, ny = sy;
        else if(s[i] == 'U') nx = sx-1, ny = sy;
        if(nx < 0 or nx >= n or ny < 0 or ny >= m or v[nx][ny] == '#') continue;
        else sx = nx, sy = ny;
    }

    cout << sx+1 << " " << sy+1 << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}