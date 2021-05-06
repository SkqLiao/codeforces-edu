/*
 * @date:2021-04-25 22:08:02
 * @source:https://codeforces.com/edu/course/2/lesson/9/2/practice/status
*/
#include <bits/stdc++.h>

using namespace std;

int n;
long long k;
vector<long long> v;
deque<int> Mn, Mx;

int main() {
    scanf("%d%lld", &n, &k);
    v.resize(n);
    for (auto &x : v) scanf("%lld", &x);
    long long ans = 0;
    int l = 0;
    for (int i = 0; i < n; ++i) {
        while (!Mn.empty() && v[Mn.back()] > v[i]) Mn.pop_back();
        while (!Mx.empty() && v[Mx.back()] < v[i]) Mx.pop_back();
        Mn.push_back(i), Mx.push_back(i);
        while (v[Mx.front()] - v[Mn.front()] > k) {
            l++;
            while (Mx.front() < l) Mx.pop_front();
            while (Mn.front() < l) Mn.pop_front();
        }
        ans += i - l + 1;
    }
    printf("%lld\n", ans);
    return 0;
}