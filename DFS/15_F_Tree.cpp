#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ll long long
#define MOD 1000000007
#define F first
#define S second
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
int gcd(int a,int b){if(b==0)return a;else return gcd(b,a%b);}
int lcm(int a,int b){return a*b/gcd(a,b);}

void pushElement(int &a, int &b , int &c , queue<int>&q){
    if(a >= 1) {
        a--;
        q.push(2);
    }
    else if(b >= 1) {
        q.push(1);
        b--;
    }else if(c >= 1){
        q.push(0);
        c--;
    }
}
bool check(int c){
    if(c <= 0){
        cout<< -1<<endl;
        return true;
    }
    return false;
}
void solve() {
    int a, b, c;
    cin>>a>>b>>c;
    queue<int> q;
    if(check(c))return;
    pushElement(a,b,c,q);
    int count = 0;
    while(q.size()){
        int n = q.size();
        while(n--){      
            int t = q.front(); q.pop();
            if(t == 2) {
                if(check(c)) return;
                pushElement(a,b,c,q);
                if(check(c)) return;
                pushElement(a,b,c,q);
            }else if(t == 1){
                if(check(c)) return;
                pushElement(a,b,c,q);
            }
        }
        count++;
    }
    if(c > 0) count = 0;
    cout<<count-1<<endl;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast_io;
    int t = 1;
    cin>>t;
    while(t--) solve();
    return 0;
}