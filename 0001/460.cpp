#include <iostream>
#include <unordered_map>

struct Node {
    int key;
    int val;
    int freq;
    Node* next;
    Node* prev;
    Node(int _key, int _val) {key = _key; val = _val; freq = 0; prev = NULL; next = NULL;}
};

using namespace std;
class LFUCache {
    unordered_map<int, Node*> _map;
    Node* head;
    int _capacity;
public:
    void debug() {
        Node* p=head->next;
        cout << "->";
        while (p) {
            cout << p->key << "(" << p->freq << ")" <<  ' ';
            p = p->next;
        }
        cout << endl;
    }

    LFUCache(int capacity) {
        _map.clear();
        head = new Node(0,0);
        _capacity = capacity;
    }

    void helper(Node* p) {
        if (!p) return;
        Node* r = p;
        Node* q = p->prev;
        r->freq++;
        while (r->next &&  p->freq >= r->next->freq) r = r->next;
        if (r == p) return;
        if (q) q->next = p->next;
        if (p->next) p->next->prev = q;

        p->prev = r;
        p->next = r->next;
        r->next = p;
        if (p->next) r->next->prev = p;
    }
    
    int get(int key) {
        if (_map.find(key) != _map.end()) {
            Node* p = _map[key];
            helper(p);
            return _map[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (_map.find(key) != _map.end()) {
            _map[key]->val = value;
            helper(_map[key]);
        }
        else {
            if (_capacity == 0) return;

            if (_map.size() == _capacity) {
                Node* p = head->next;
                if (p) {
                    _map.erase(p->key);
                    head->next = p->next;
                    if (p->next) p->next->prev = head;
                    delete p;
                }
            }

            Node* tmp = new Node(key, value);
            tmp->next = head->next;
            if (tmp->next) tmp->next->prev = tmp;
            tmp->prev = head;
            head->next = tmp;
            _map[key] = tmp;
            helper(tmp);
        }
    }
};

int main() {
 LFUCache* obj = new LFUCache(2);

 assert(obj->get(1) == -1);
 obj->put(1,1);
 obj->debug();
 assert(obj->get(1) == 1);
 obj->put(2,2);
 obj->debug();
 assert(obj->get(2) == 2);
 assert(obj->get(1) == 1);
 obj->debug();
 assert(obj->get(3) == -1);
 obj->put(3,3);
 obj->debug();
 assert(obj->get(2) == -1);
 assert(obj->get(3) == 3);
 assert(obj->get(3) == 3);
 assert(obj->get(1) == 1);
 obj->put(1,1);
 obj->debug();
 assert(obj->get(1) == 1);
 assert(obj->get(2) == -1);
 assert(obj->get(3) == 3);
}
