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

bool check(ll x) {
    string s = to_string(x);
    string t = s;
    reverse(s.begin(), s.end());
    return t == s;
}

void solve(){   
    ll n; cin >> n;

    for (ll i = 1000000; i >= 1; i--) {
        ll x = i*i*i;
        if (x <= n && check(x)){
            cout << x;
            break;
        }
    }
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