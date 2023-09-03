#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int MAX = 2*1e5+10;
vi visitados;
vector<vi> v(MAX);
vector<bool> vis(MAX);

bool dfs(int x, int prev){
    vis[x] = true;
    visitados.pb(x);
    
    bool ans = false;
    for(auto& ve: v[x]){
        if(!vis[ve]) dfs(ve, x);
        else if(ve != prev) ans = true;
    }

    return ans;
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--, b--;

        v[a].pb(b);
        v[b].pb(a);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) if(!vis[i]){
        if(dfs(i, -1)){
            for(auto& x: visitados) if(v[x].size() > 2){
                ans--;
                break;
            }
            ans++;
            visitados.clear();
        }
    }

    cout << ans << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

