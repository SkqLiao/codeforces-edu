/*
 * @date:2021-04-27 11:56:05
 * @source:https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/D
*/
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;
int a[4], b[4];

int main() {
    for (int i = 0, n; i < 4; ++i) {
        scanf("%d", &n);
        for (int j = 0, x; j < n; ++j) {
            scanf("%d", &x);
            v.push_back({x, i});
        }
    }
    sort(v.begin(), v.end());
    int l = 0, num = 0, ans = INT_MAX;
    int ll = 0, rr = 0;
    for (int r = 0; r < v.size(); ++r) {
        if (!b[v[r].second]++) ++num;
        if (num < 4) continue;
        while (b[v[l].second] > 1) {
            --b[v[l++].second];
        }
        if (ans > v[r].first - v[l].first) {
            ans = v[r].first - v[l].first;
            ll = l, rr = r;
        }
    }
    a[v[ll].second] = v[ll].first;
    a[v[rr].second] = v[rr].first;
    for (int i = ll + 1; i < rr; ++i) {
        if (!a[v[i].second]) a[v[i].second] = v[i].first;
    }
    for (int i = 0; i < 4; ++i) printf("%d ", a[i]);
    return 0;
}