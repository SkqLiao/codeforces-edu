/*
 * @date:2021-04-26 14:25:57
 * @source:https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/G
*/
#include <bits/stdc++.h>

using namespace std;


int n;
vector<long long> v;

struct Stack {
    vector<long long> stk, val = {0};
    void push(long long x) {
        stk.push_back(x);
        val.push_back(__gcd(val.back(), x));
    }
    long long top() {
        return val.back();
    }
    long long pop() {
        long long x = stk.back();
        stk.pop_back();
        val.pop_back();
        return x;
    }
    bool empty() {
        return stk.empty();
    }
} s1, s2;

void remove() {
    if (s1.empty()) {
        while (!s2.empty()) s1.push(s2.pop());
    }
    s1.pop();
}

int main() {
    scanf("%d", &n);
    v.resize(n);
    for (auto &x : v) scanf("%lld", &x);
    int l = 0, ans = n + 1;
    for (int i = 0; i < n; ++i) {
        s2.push(v[i]);
        while (__gcd(s1.top(), s2.top()) == 1) {
            remove();
            ans = min(ans, i - l + 1);
            l++;
        }
    }
    if (ans > n) ans = -1;
    printf("%d\n", ans);
    return 0;
}