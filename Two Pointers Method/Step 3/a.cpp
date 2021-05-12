/*
 * @date:2021-04-27 10:43:31
 * @source:https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/A
*/
#include <bits/stdc++.h>

using namespace std;

int n;
long long p;
vector<int> v;

int main() {
    scanf("%d%lld", &n, &p);
    v.resize(n);
    long long total = 0;
    for (auto &x : v) {
        scanf("%d", &x);
        total += x;
    }
    long long ans = (p - v[0]) / total * n + 1, sum = (p - v[0]) / total * total + v[0];
    int l = 0, pos = 0;
    if (sum >= p) l = pos = 0;
    else {
        for (int i = n - 1; i >= 0; --i) {
            sum += v[i];
            ++ans;
            if (sum >= p) {
                pos = l = i;
                break;
            }
        }
    }
    long long len = ans;
    for (int r = 1; r < n; ++r) {
        sum += v[r];
        ++len;
        while (sum >= p) {
            sum -= v[l++];
            l %= n;
            --len;
        }
        if (len + 1 < ans) {
            pos = (l - 1 + n) % n;
            ans = len + 1;
        }
    }
    printf("%d %lld\n", pos + 1, ans);
    return 0;
}