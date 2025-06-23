class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& e) {
        sortEvents(e);
        vector<int> ans(n), off(n);
        for (auto& v : e) {
            processEvent(v, n, off, ans);
        }
        return ans;
    }

private:
    void sortEvents(vector<vector<string>>& e) {
        sort(e.begin(), e.end(), [](auto& a, auto& b) {
            return (stoi(a[1]) < stoi(b[1]) || (stoi(a[1]) == stoi(b[1]) && a[0] == "OFFLINE"));
        });
    }

    void processEvent(const vector<string>& v, int n, vector<int>& off, vector<int>& ans) {
        int t = stoi(v[1]);
        if (v[0] == "OFFLINE") {
            processOffline(v, off, t);
        } else {
            vector<int> c = processMessage(v[2], t, n, off);
            updateMentions(ans, c);
        }
    }

    void processOffline(const vector<string>& v, vector<int>& off, int t) {
        int i = stoi(v[2]);
        off[i] = t + 60;
    }

    vector<int> processMessage(const string& s, int t, int n, const vector<int>& off) {
        vector<int> c;
        stringstream ss(s);
        string x;
        while (ss >> x) {
            if (x == "ALL") {
                addAllUsers(n, c);
            } else if (x == "HERE") {
                addOnlineUsers(n, t, off, c);
            } else if (x.rfind("id", 0) == 0 && x.size() > 2) {
                addUser(x, n, c);
            }
        }
        return c;
    }

    void addAllUsers(int n, vector<int>& c) {
        for (int i = 0; i < n; ++i) c.push_back(i);
    }

    void addOnlineUsers(int n, int t, const vector<int>& off, vector<int>& c) {
        for (int i = 0; i < n; ++i) {
            if (t >= off[i]) c.push_back(i);
        }
    }

    void addUser(const string& x, int n, vector<int>& c) {
       
            int id = stoi(x.substr(2));
            if (id >= 0 && id < n) c.push_back(id);
        
    }

    void updateMentions(vector<int>& ans, const vector<int>& c) {
        for (int i : c) ans[i]++;
    }
};
