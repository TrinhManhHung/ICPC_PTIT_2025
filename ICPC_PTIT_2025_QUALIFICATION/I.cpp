#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define FOR(i, a, b) for(int i =a; i <=b; i++)
#define FOD(i, a, b) for(int i =a; i >=b; i--)
#define INF INT_MAX
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define COUNT_ONE(x) __builtin_popcountll((x))
#define COUNT_LEAD_ZERO(x) __builtin_clzll((x))
#define COUNT_TRAIL_ZERO(x) __builtin_ctzll((x))
#define SHOW1(x) cout << #x << " = " << (x) << endl << flush
#define SHOW2(x, y) cout << #x << "=" << (x) << " " << #y << "=" << (y) << endl << flush
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

const ll MOD = 998244353;
const int maxn = 2000000;

ll cntUoc[maxn + 5];

void process(){
    memset(cntUoc, 0, sizeof(cntUoc));

    FOR(i, 1, maxn){
        for(int j = i; j <= maxn; j += i){
            cntUoc[j] += 1;
        }
    }
}

ll powMod(ll n, ll p){
    if(p == 0) return 1;
    if(p == 1) return n;

    ll half = pow(n, p / 2);
    if(half >= 1e9) return -1;

    ll res = half * half;
    if(p & 1){
        if(1e18 / res < n) return -1;
        res *= n;
    }

    return res;
}

bool isPrime(ll n){
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return n > 1;
}

void solve(){   
    ll x; cin >> x;

    FOR(i, 1, maxn){
        if(powMod(i, cntUoc[i]) == x){
            cout << i << endl;
            return;
        }
    }

    ll tmp = sqrt(x);
    if(tmp * tmp == x && isPrime(tmp)){
        cout << tmp << endl;
        return;
    }
    
    cout << -1 << endl;
}   

int main(){
    faster();
    int t = 1;
    process();
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}