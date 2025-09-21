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

bool check(string s){
    bool have_3 = false, have_5 = false,  have_7 = false;
    for(auto x : s){
        if(x == '3') have_3 = true;
        if(x == '5') have_5 = true;
        if(x == '7') have_7 = true;
    }

    return (have_3 && have_5 && have_7);
}

void solve(){   
    ll n; cin >> n;
    queue<string> Q;
    Q.push("3");
    Q.push("5");
    Q.push("7");

    int cnt = 0;
    while(!Q.empty()){
        auto top = Q.front(); Q.pop();
        if(stoll(top) <= n){
            // cout << top << " ";
            if(check(top)) cnt++;
            Q.push(top + "3");
            Q.push(top + "5");
            Q.push(top + "7");
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