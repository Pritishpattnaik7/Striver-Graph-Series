//Triology 1st question
#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;

vector<int> digits(int n){
    vector<int> v;
    while (n){
        int ld = n%10;
        v.push_back(ld);
        n = n/10;
    }
    return v;
}

int findXOR(vector<int> t){
    int xor_sum = 0;
    for (auto x : t){
        xor_sum ^= x;
    }
    return xor_sum;
}

pair<int, int> findMaxMin(vector<int> t){
    int maxi = INT_MIN, mini = INT_MAX;
    for (auto x : t){
        maxi = max(maxi, x);
        mini = min(mini, x);
    }
    return {maxi, mini};
}

int solve(string a, string b){
    int a1 = stoi(a);
    int b1 = stoi(b);
    vector<int> v;
    for (int i=a1 ; i<=b1 ; i++){
        v.push_back(i);
    }
    long long int ctr = 0;
    for (auto x : v){
        vector<int> t = digits(x);
        int xor_sum = findXOR(t);
        pair<int, int> p = findMaxMin(t);
        double avg = (double)(p.first + p.second)/2;
        if (xor_sum > avg) ctr++;
    }
    return ctr % mod;
}

int main(){
    string a, b;
    cin >> a >> b;
    int ans = solve(a, b);
    cout << ans;
}