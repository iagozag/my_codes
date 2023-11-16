#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(a) (a).begin(), (a).end()
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

void DBG() {
    cerr << "]" << endl;
}

void DBGC() {
    cerr << "]" << endl;
}

template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t)) cerr << ", ";
    DBG(t...);
}

template<class H, class... T> void DBGC(H h, T... t) {
    for(auto& x: h) cerr << x << " ";
    if(sizeof...(t)) cerr << "], [ ";
    DBGC(t...);
}

#ifdef _DEBUG
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define dbgc(...) cerr << "["<< #__VA_ARGS__ << "]: [ "; DBGC(__VA_ARGS__) 
#else
#define dbg(...) 0
#define dbgc(...) 0
#endif

int MAX = 1e5+10;
vl v(MAX); vector<pair<ll, ll>> seg(4*MAX);

pair<ll, ll> combine(ii a, ii b){
    return {max(a.f, b.f), (a.s+b.s > 0) ? a.s+b.s : 0};
}

pair<ll, ll> build(int node, int tl, int tr){
    if(tl == tr) return seg[node] = {v[tl], v[tl]};

    int tm = (tl+tr)>>1;
    return seg[node] = combine(build(node*2, tl, tm), build(node*2+1, tm+1, tr));
}

pair<ll, ll> update(int node, int tl, int tr, int idx, ll val){
    if(idx < tl || idx > tr) return seg[node];
    if(tl == tr) return seg[node] = {val, val};

    int tm = (tl+tr)>>1;
    return seg[node] = combine(update(node*2, tl, tm, idx, val), update(node*2+1, tm+1, tr, idx, val));
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> v[i];
    auto [x, y] = build(1, 0, n-1);
    cout << ((max(x, y) > 0) ? max(x, y) : 0) << endl;

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        auto [x, y] = update(1, 0, n-1, a, b);
        cout << ((max(x, y) > 0) ? max(x, y) : 0) << endl;
    }
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

