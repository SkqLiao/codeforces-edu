/*
 * @date:2021-04-27 11:29:15
 * @source:https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/B
*/
#include <bits/stdc++.h>

using namespace std;

int n;
long long s;
vector<int> v;

int main() {
    scanf("%d%lld", &n, &s);
    v.resize(n);
    for (auto &x : v) scanf("%d", &x);
    int l = 0;
    long long ans = 0, sum = 0;
    for (int r = 0; r < n; ++r) {
        sum += v[r];
        while (sum > s) sum -= v[l++];
        ans += 1ll * (r - l + 2) * (r - l + 1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}