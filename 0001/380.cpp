#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
    unordered_map<int, int> m;
    vector<int> v;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        m.clear();
        v.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) return false;
        m[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        int last = v.back();
        m[last] = m[val];
        v[m[val]] = last;
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % v.size()];
    }

    void debug() {
        return;
        cout << "+++++++++++++++++++++" << endl;
        for (auto d : v) {
            cout << d << endl;
        }
    }
};
int test3() {
    RandomizedSet* obj = new RandomizedSet();
    cout << "insert 1:" << obj->insert(1) << endl;
    obj->debug();
    cout << "insert 2:" << obj->insert(2) << endl;
    obj->debug();
    cout << "insert 3:" << obj->insert(3) << endl;
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
    RandomizedSet* obj = new RandomizedSet();
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
    RandomizedSet* obj = new RandomizedSet();
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
    test3();
    return 0;
}
