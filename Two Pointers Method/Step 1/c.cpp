/*
 * @date:2021-04-25 21:05:31
 * @source:https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C
*/
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v1, v2;

int main() {
    scanf("%d%d", &n, &m);
    v1.resize(n);
    for (auto &x : v1) scanf("%d", &x);
    v2.resize(m);
    for (auto &x : v2) scanf("%d", &x);
    int p1 = 0, p2 = 0;
    long long ans = 0;
    while (p1 < n && p2 < m) {
        if (v1[p1] == v2[p2]) {
            int num1 = 1, num2 = 1;
            ++p1;
            while (p1 < n && v1[p1] == v1[p1 - 1]) ++num1, ++p1;
            ++p2;
            while (p2 < m && v2[p2] == v2[p2 - 1]) ++num2, ++p2;
            ans += 1ll * num1 * num2;
        } else if (v1[p1] < v2[p2]) {
            ++p1;
            while (p1 < n && v1[p1] == v1[p1 - 1]) ++p1;
        } else if (v1[p1] > v2[p2]) {
            ++p2;
            while (p2 < m && v2[p2] == v2[p2 - 1]) ++p2;
        }
    }
    printf("%lld\n", ans);
    return 0;
}