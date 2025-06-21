#define ll long long

class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        ll ans = -1; int a = 1e6 , b=-1e6 ; int c = a , d=b;
        unordered_map<int, int> x_min, y_min, x_max, y_max;
        for (auto& co : coords) {
            int x = co[0], y = co[1];
            if (!x_min.count(y)) x_min[y] = x;
            else x_min[y] = min(x_min[y], x);
            if (!x_max.count(y)) x_max[y] = x;
            else x_max[y] = max(x_max[y], x);
            if (!y_min.count(x)) y_min[x] = y;
            else y_min[x] = min(y_min[x], y);
            if (!y_max.count(x)) y_max[x] = y;
            else y_max[x] = max(y_max[x], y);
             a = min(x,a) ; b = max(x,b) ;c = min(y,c) ;d = max(y,d) ;
        }   for (auto& co : coords) {
            int x = co[0], y = co[1];
            ll h = abs(x_max[y] - x_min[y]);
            ll v = abs(y_max[x] - y_min[x]);
            ans = max({ans,1LL*h*abs(c-y),1LL*h*abs(d-y)}); 
            ans = max({ans, 1LL*v*abs(a-x),1LL*v*abs(b-x)}); 
        } if(!ans) return -1 ; return ans;
    }
};
