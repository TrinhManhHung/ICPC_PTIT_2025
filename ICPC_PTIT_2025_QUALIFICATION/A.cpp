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
const int maxn = 200000;

void solve(){   
    int n; cin >> n;
    ll a[n + 5];
    FOR(i, 1, n) cin >> a[i];

    unordered_map<ll, set<int>> mp; //<Ap * 3 - Ak, k>

    FOR(p, 1, n){
        FOR(k, 1, n){
            ll sum = a[p] * 3 - a[k];
            mp[sum].insert(k);
        }
    }

    set<ll> validNums;

    FOR(i, 1, n-1){
        FOR(j, i+1, n){
            ll sum = a[i] + a[j];
            for(auto k : mp[sum]){
                if(k != i && k != j){
                    ll Ap = (a[k] + sum) / 3;
                    validNums.insert(Ap);
                }
            }
        }
    }
    
    int cnt = 0;

    FOR(i, 1, n){
        if(validNums.find(a[i]) != validNums.end()){
            cnt++;
        }
    }

    cout << cnt << endl;
}   

int main(){
    faster();
    int t = 1;
    // cin >> t;
    while(t--){  
        solve();
    }
    return 0;
}