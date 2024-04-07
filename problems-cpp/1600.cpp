#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
using namespace std;

class ThroneInheritance {
public:
    string kingName;
    unordered_map<string, vector<string>> successor;
    unordered_map<string, bool> isDead;

    ThroneInheritance(string kingName) {
        this->kingName = kingName;
        successor[kingName] = {};
    }

    void birth(string parentName, string childName) {
        successor[parentName].push_back(childName);
        successor[childName] = {};
    }

    void death(string name) {
        isDead[name] = true;
    }

    vector<string> getInheritanceOrder() {
        vector<string> ret;
        function<void(const string&)> dfs = [&](const string& cur)->void {
            if (!isDead[cur]) {
                ret.push_back(cur);
            }
            for (auto x : successor[cur]) {
                dfs(x);
            }
            };
        dfs(kingName);
        return ret;
    }
};
