/*
 * @date:2021-04-25 21:57:26
 * @source:https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/D
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
    long long sum = 0, ans = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
        while (sum >= s) sum -= v[l++];
        ans += l;
    }
    printf("%lld\n", ans);
    return 0;
}