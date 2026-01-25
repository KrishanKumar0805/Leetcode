class Solution {
    List<List<Integer>> adj;
    int[][] up;
    int[] dep;
    int lim = 20;

    void dfs(int u, int p, int d) {
        dep[u] = d;
        up[u][0] = p;
        for (int i = 1; i < lim; i++) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        for (int v : adj.get(u)) {
            if (v != p) dfs(v, u, d + 1);
        }
    }

    int getL(int u, int v) {
        if (dep[u] < dep[v]) { int t = u; u = v; v = t; }
        for (int i = lim - 1; i >= 0; i--) {
            if (dep[u] - (1 << i) >= dep[v]) u = up[u][i];
        }
        if (u == v) return u;
        for (int i = lim - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    int dst(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[getL(u, v)];
    }

    public int specialNodes(int n, int[][] eds, int x, int y, int z) {
        adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
        for (int[] e : eds) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }
        up = new int[n][lim];
        dep = new int[n];
        dfs(0, 0, 0);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            long da = dst(i, x);
            long db = dst(i, y);
            long dc = dst(i, z);
            long[] arr = {da, db, dc};
            Arrays.sort(arr);
            if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]) cnt++;
        }
        return cnt;
    }
}