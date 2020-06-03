#include <iostream>
#include <unordered_set>
#include <map>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, double> valmap;
        map<string, int> setmap;

        for (int j=0; j<values.size(); j++) {
            bool changed = false;
            for (int i=0; i<values.size(); i++) {
                const string& a = equations[i][0];
                const string& b = equations[i][1];
                const double& val = values[i];
                if (valmap.find(a) != valmap.end() && valmap.find(b) != valmap.end()) {
                    if (setmap[a] < setmap[b]) {
                        setmap[b] = setmap[a];
                        valmap[b] = valmap[a] / val;
                        changed = true;
                    } else if (setmap[a] > setmap[b]) {
                        setmap[a] = setmap[b];
                        valmap[a] = valmap[b] * val;
                        changed = true;
                    }
                } else if (valmap.find(a) != valmap.end()) {
                    setmap[b] = setmap[a];
                    valmap[b] = valmap[a] / val;
                    changed = true;
                } else if (valmap.find(b) != valmap.end()) {
                    setmap[a] = setmap[b];
                    valmap[a] = valmap[b] * val;
                    changed = true;
                } else {
                    valmap[b] = 1;
                    valmap[a] = val;
                    setmap[a] = setmap[b] = i;
                    changed = true;
                }
                cout << "0:" << a << " (set:" << setmap[a] << ", val:" << valmap[a] << ")" << endl;
                cout << "1:" << b << " (set:" << setmap[b] << ", val:" << valmap[b] << ")" << endl;
            }
            cout << "changed=" << changed << endl;
            if (changed == false) break;
        }

        vector<double> res;
        for (auto q : queries) {
            double d = -1;
            const string& a = q[0];
            const string& b = q[1];
            if (setmap.find(a) != setmap.end() && setmap.find(b) != setmap.end()) {
                if (valmap[a] == 0 && valmap[b] != 0) d = 0;
                else if (setmap[a] == setmap[b] && valmap[b] != 0) d = valmap[a] / valmap[b];
            }
            res.push_back(d);
        }

        return res;
    }

};


/**
 a / z = 3  
 a=3 (0)
 z=1 (0)

 b / c = 2
 c=1 (1)
 b=2 (1)

 e / g = 5
 e=5 (2)
 g=1 (2)

 c / z = 2
 c=1  (1)
 z=0.5(1)

 d / f = 1
 d=1 (4)
 f=1 (4)

 f / g = 2
 f=1 (4)
 g=0.25(4)


 */

int main()
{
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries);
    Solution s;
    vector<vector<string>> equations;
    vector<double> values;
    vector<string> eqt;
    double value;

    eqt = {"a", "b"};
    value = 3;
    equations.push_back(eqt);
    values.push_back(value);

    eqt = {"d", "c"};
    value = 2;
    equations.push_back(eqt);
    values.push_back(value);

    eqt = {"a", "d"};
    value = 10;
    equations.push_back(eqt);
    values.push_back(value);
    
    
    vector<vector<string>> queries;
    vector<string> query;
    query = {"b", "c"};
    queries.push_back(query);
    query = {"x", "x"};
    queries.push_back(query);
    query = {"a", "e"};
    queries.push_back(query);
    vector<double> res = s.calcEquation(equations, values, queries);

    for (auto d : res) {
        cout << d << endl;
    }
    return 0;
}
