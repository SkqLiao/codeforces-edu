/*
 * @date:2021-04-25 21:25:19
 * @source:https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/A
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
    int l = 0, ans = 0;
    long long sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
        while (sum > s) {
            sum -= v[l++];
        }
        ans = max(ans, i - l + 1);
    }
    printf("%d\n", ans);
    return 0;
}