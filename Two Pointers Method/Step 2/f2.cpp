/*
 * @date:2021-04-26 16:33:50
 * @source:https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/F
*/
#include <bits/stdc++.h>

using namespace std;

int n;
long long k;
vector<long long> v;

struct Stack {
    vector<long long> v, mn = {LLONG_MAX}, mx = {LLONG_MIN};
    void push(long long x) {
        v.push_back(x);
        mn.push_back(std::min(mn.back(), x));
        mx.push_back(std::max(mx.back(), x));
    }
    long long max() {
        return mx.back();
    }
    long long min() {
        return mn.back();
    }
    long long pop() {
        long long x = v.back();
        v.pop_back();
        mn.pop_back();
        mx.pop_back();
        return x;
    }
    bool empty() {
        return v.empty();
    }
} s1, s2;

void remove() {
    if (s1.empty()) {
        while (!s2.empty()) s1.push(s2.pop());
    }
    s1.pop();
}

int main() {
    scanf("%d%lld", &n, &k);
    v.resize(n);
    for (auto &x : v) scanf("%lld", &x);
    long long ans = 0;
    int l = 0;
    for (int i = 0; i < n; ++i) {
        s2.push(v[i]);
        while (max(s1.max(), s2.max()) - min(s1.min(), s2.min()) > k) {
            remove();
            l++;
        }
        ans += i - l + 1;
    }
    printf("%lld\n", ans);
    return 0;
}