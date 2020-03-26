#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedCollection {
    unordered_map<int, vector<int>> m;
    vector<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        m.clear();
        v.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool res = (m.find(val) == m.end());
        m[val].push_back(v.size());
        v.push_back(val);
        return res;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        int pos = m[val].back();
        int last = v.back();
        m[last][m[last].size()-1] = pos;
        sort(m[last].begin(), m[last].end());
        v[pos] = last;
        v.pop_back();
        if (m[val].size() <= 1) m.erase(val);
        else m[val].pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % v.size()];
    }

    void debug() {
        cout << "+++++++++++++++++++++" << endl;
        for (auto d : v) {
            cout << d << endl;
        }
    }
};

int test5() {
    RandomizedCollection* obj = new RandomizedCollection();
    cout << "insert 1:" << obj->insert(1) << endl;
    obj->debug();                       
    cout << "insert 1:" << obj->insert(1) << endl;
    obj->debug();                       
    cout << "insert 2:" << obj->insert(2) << endl;
    obj->debug();                       
    cout << "insert 2:" << obj->insert(2) << endl;
    obj->debug();                       
    cout << "insert 3:" << obj->insert(3) << endl;
    obj->debug();                       
    cout << "insert 3:" << obj->insert(3) << endl;
    obj->debug();                       
    cout << "remove 1:" << obj->remove(1) << endl;
    obj->debug();                       
    cout << "remove 1:" << obj->remove(1) << endl;
    obj->debug();                       
    cout << "remove 3:" << obj->remove(3) << endl;
    obj->debug();                       
    cout << "remove 3:" << obj->remove(3) << endl;
    obj->debug();                       
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    return 0;
}

int test4() {
    RandomizedCollection* obj = new RandomizedCollection();
    cout << "insert 4:" << obj->insert(4) << endl;
    obj->debug();                       
    cout << "insert 3:" << obj->insert(3) << endl;
    obj->debug();                       
    cout << "insert 4:" << obj->insert(4) << endl;
    obj->debug();                       
    cout << "insert 2:" << obj->insert(2) << endl;
    obj->debug();                       
    cout << "insert 4:" << obj->insert(4) << endl;
    obj->debug();                       
    cout << "remove 4:" << obj->remove(4) << endl;
    obj->debug();                       
    cout << "remove 3:" << obj->remove(3) << endl;
    obj->debug();                       
    cout << "remove 4:" << obj->remove(4) << endl;
    obj->debug();                       
    cout << "remove 4:" << obj->remove(4) << endl;
    obj->debug();
    return 0;
}
int test3() {
    RandomizedCollection* obj = new RandomizedCollection();
    cout << "insert 1:" << obj->insert(1) << endl;
    obj->debug();
    cout << "remove 2:" << obj->remove(2) << endl;
    obj->debug();
    cout << "insert 2:" << obj->insert(2) << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "remove 1:" << obj->remove(1) << endl;
    obj->debug();
    cout << "insert 2:" << obj->insert(2) << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    return 0;
}

int test2() {
    RandomizedCollection* obj = new RandomizedCollection();
    cout << "insert 1:" << obj->insert(1) << endl;
    obj->debug();
    cout << "remove 1:" << obj->remove(1) << endl;
    obj->debug();
    cout << "insert 2:" << obj->insert(2) << endl;
    obj->debug();
    cout << "remove 1:" << obj->remove(1) << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    return 0;
}

int test1() {
    RandomizedCollection* obj = new RandomizedCollection();
    cout << "insert 1:" << obj->insert(1) << endl;
    obj->debug();
    cout << "insert 2:" << obj->insert(2) << endl;
    obj->debug();
    cout << "insert 3:" << obj->insert(3) << endl;
    obj->debug();
    cout << "remove 1:" << obj->remove(1) << endl;
    obj->debug();
    cout << "remove 1:" << obj->remove(1) << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "insert 4:" << obj->insert(4) << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    cout << "random  :" << obj->getRandom() << endl;
    obj->debug();
    return 0;
}

int main() {
    test5();
    return 0;
}
