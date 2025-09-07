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

int n, k; 
int a[maxn + 5];

bool uoc[maxn + 5];

void ptich(int x){
    uoc[x] = false;
    for(int i =2; i <= sqrt(x); i++){
        if(x % i == 0){
            uoc[i] = false;
            uoc[x / i] = false;
        }
    }
}

void solve(){   
    memset(uoc, true, sizeof(uoc));
    cin >> n >> k;
    FOR(i, 1, n){ 
        cin >> a[i];
        ptich(a[i]);
    }
    uoc[1] = true;
    
    FOR(i, 1, k){
        if(!uoc[i]){
            for(int j = i; j <=k; j+=i){
                uoc[j] = false;
            }
        }
    }
    

    int res = 0;
    vi v;
    FOR(i, 1, k){
        if(uoc[i]){ 
            res++;
            v.pb(i);
        }
    }

    cout << res << endl;
    for(auto x : v) cout << x << " ";
    cout << endl;
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