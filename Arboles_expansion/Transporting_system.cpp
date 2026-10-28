#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge {
    int d2, u, v;
    bool operator<(const Edge &o) const { return d2 < o.d2; }
};
int parent[1005], sz[1005];

int find(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return  false;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

int main() {
    int T;
    scanf_s("%d", &T);
    for (int caso = 1; caso <= T; caso++) {
        int n, r;
        scanf_s("%d %d", &n, &r);
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) scanf_s("%d %d", &x[i], &y[i]);

        vector<Edge> Edges;
        Edges.reserve((size_t)n * (n - 1) / 2);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dx = x[i] - x[j], dy = y[i] - y[j];
                Edges.push_back({dx * dx + dy * dy, i, j });
            }
        }
        sort(Edges.begin(), Edges.end());
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }

        long long r2 = (long long)r * r;
        double roads = 0, rails = 0;
        int states = n;

        for (auto& e : Edges) {
            if (unite(e.u, e.v)) {
                if (e.d2 <= r2) {
                    roads += sqrt((double)e.d2);
                    states--;
                }
                else {
                    rails += sqrt((double)e.d2);
                }
            }
        }
        printf("Case #%d: %d %lld %lld\n", caso, states,
            (long long)floor(roads + 0.5), (long long)floor(rails + 0.5));
    }
    return 0;
}
