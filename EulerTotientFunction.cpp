#include "bits/stdc++.h"
using namespace std;
#define ll long long 

const ll N = 1e6+5;
ll spf[N];

set<ll> ETF(ll n){
    set<ll> s;
    while( n != 1){
        s.insert(spf[n]);
        n = n / spf[n];
    }
    return s;
}

void precompute(){
    for(ll i = 0 ; i < N ; i++)spf[i] = i;
    ll y = sqrt(N); 
    for(ll i = 2 ; i <= y ; i++){
        if(spf[i] == i){
            for(ll j = i*2 ; j < N ; j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

ll Func(ll n){
    ll ans = 1;
    set<ll> s = ETF(n);
    ll value1 = 1 , value2 = 1;
    for(auto j:s){
        value1 = value1 * j;
        value2 = value2 * (j-1);
    }
    ans = n * value2 / value1;
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    n = Func(n);
    cout << n << endl;
}

int main(){
    ll t;
    cin >> t;
    precompute();
    while(t--){
        solve();
    }
    return 0;
}
