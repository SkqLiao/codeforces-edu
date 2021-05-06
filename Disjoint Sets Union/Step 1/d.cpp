/*
 * @date:2021-05-01 10:17:29
 * @source:https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50000 + 5;

int N, M, K;
set<pair<int, int>> S;
vector<pair<int, pair<int, int>>> a;
vector<int> Ans;
int Anc[MAXN];

int findAnc(int x) {
    return x == Anc[x] ? x : Anc[x] = findAnc(Anc[x]);
}

void merge(int u, int v) {
    u = findAnc(u), v = findAnc(v);
    Anc[u] = v;
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1, u, v; i <= M; ++i) {
        scanf("%d%d", &u, &v);
        S.insert({min(u, v), max(u, v)});
    }
    char s[5];
    for (int i = 1, u, v; i <= K; ++i) {
        scanf("%s%d%d", s, &u, &v);
        a.push_back({s[0] == 'c', {u, v}});
        if (s[0] == 'c') S.erase({min(u, v), max(u, v)});
    }
    for (int i = 1; i <= N; ++i) Anc[i] = i;
    for (auto x : S) merge(x.first, x.second);
    for (int i = K - 1; i >= 0; --i) {
        if (a[i].first == 0) {
            Ans.push_back(findAnc(a[i].second.first) == findAnc(a[i].second.second));
        } else {
            merge(a[i].second.first, a[i].second.second);
        }
    }
    for (int i = Ans.size() - 1; i >= 0; --i) {
        puts(Ans[i] ? "YES" : "NO");
    }
    return 0;
}