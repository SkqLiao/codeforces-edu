/*
 * @date:2021-04-25 21:31:42
 * @source:https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/B
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
    int l = 0, ans = n + 1;
    long long sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
        if (sum < s) continue;
        while (sum >= s) {
            sum -= v[l++];
        }
        ans = min(ans, i - l + 2);
    }
    if (ans > n) ans = -1;
    printf("%d\n", ans);
    return 0;
}