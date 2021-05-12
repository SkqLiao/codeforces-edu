/*
 * @date:2021-05-12 10:17:54
 * @source:https://codeforces.com/edu/course/2/lesson/7/3/practice/contest/289392/problem/C
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fir first
#define sec second
template<class T> bool chkMax(T &x, T &y) {
    return y > x ? x = y, 1 : 0;
}
template<class T> bool chkMin(T &x, T &y) {
    return y < x ? x = y, 1 : 0;
}

int N, M;
map<int, int> Ans;
map<pair<int, int>, int> Map;

struct DSU {
    vector<int> Anc, Siz;
    stack<int> Stk;
    int num;
    void init(int n) {
        Anc.resize(n + 1);
        Siz.resize(n + 1);
        num = n;
        for (int i = 1; i <= n; ++i) {
            Anc[i] = i;
            Siz[i] = 1;
        }
    }
    int findAnc(int x) {
        while (Anc[x] != x) x = Anc[x];
        return x;
    }
    void merge(int x, int y) {
        x = findAnc(x);
        y = findAnc(y);
        if (x == y) return ;
        if (Siz[x] > Siz[y]) swap(x, y);
        Anc[x] = y;
        Siz[y] += Siz[x];
        Stk.push(x);
        --num;
    }
    void rewind(int sz) {
        while (Stk.size() > sz) {
            int x = Stk.top();
            Stk.pop();
            Siz[Anc[x]] -= Siz[x];
            Anc[x] = x;
            ++num;
        }
    }
} t;

struct SegmentTree {
    vector<vector<pii>> E;
    void init(int n) {
        E.resize(n * 4);
    }
    void update(int rt, int l, int r, int a, int b, pair<int, int> e) {
        if (a <= l && r <= b) {
            E[rt].push_back(e);
            return ;
        }
        int m = (l + r) >> 1;
        if (a <= m) update(rt << 1, l, m, a, b, e);
        if (m < b) update(rt << 1 | 1, m + 1, r, a, b, e);
    }
    void dfs(int rt, int l, int r) {
        int tmp = t.Stk.size();
        for (auto e : E[rt]) t.merge(e.fir, e.sec);
        if (l == r) {
            if (Ans.find(l) != Ans.end()) Ans[l] = t.num;
        } else {
            int m = (l + r) >> 1;
            dfs(rt << 1, l, m);
            dfs(rt << 1 | 1, m + 1, r);
        }
        t.rewind(tmp);
    }
} sgt;

int main() {
    scanf("%d%d", &N, &M);
    sgt.init(++M);
    char opt[5];
    for (int i = 1, u, v; i < M; ++i) {
        scanf("%s", opt);
        if (opt[0] == '?') {
            Ans[i] = 0;
        } else {
            scanf("%d%d", &u, &v);
            if (u > v) swap(u, v);
            if (opt[0] == '+') {
                Map[ {u, v}] = i;
            } else {
                sgt.update(1, 1, M, Map[ {u, v}], i, {u, v});
                Map.erase({u, v});
            }
        }
    }
    for (auto e : Map) {
        sgt.update(1, 1, M, e.second, M, e.first);
    }
    t.init(N);
    sgt.dfs(1, 1, M);
    for (auto x : Ans) printf("%d\n", x.sec);
    return 0;
}