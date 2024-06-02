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

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    ll n, m; cin >> n >> m;

    ll ans = n;
    repr(i, 30, 0){
        ll k = (1<<i);
        if(!(k&n)){
            if((k > n and k-n <= m) or (k < n and k <= m)) ans += k;
            else if(k < n){
                ll t = k;
                repr(j, 30, 0){
                    if(j == i) continue;
                    if(t+(1<<j) <= n) t += (1<<j);
                    else if(t+(1<<j)-n <= m) t += (1<<j);
                }
                if(abs(n-t) <= m) ans += k;
            }
        }
    }

    cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
