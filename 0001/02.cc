#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    int listToNumber(ListNode* l) {
        int i = 1;
        int ret = 0;
        while(l != NULL) {
            ret += l->val * i;
            i *= 10;
            l = l->next;
        }
        return ret;
    }
    ListNode* numToList(int a) {
        int b = a / 10;
        int c = a % 10;
        ListNode *l = new ListNode(c);
        ListNode *ptr = l;
        while (b!=0) {
            c = b % 10;
            b = b / 10;
            ListNode *tmp = new ListNode(c);
            ptr->next = tmp;
            ptr = tmp;
        }
        
        return l;
    }

    //ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //    cout << "l1 = " << listToNumber(l1) << endl;
    //    cout << "l2 = " << listToNumber(l2) << endl;
    //    int a = listToNumber(l1) + listToNumber(l2);
    //    return numToList(a);
    //}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a, b, c = 0, s;
        ListNode *l = new ListNode(0);
        ListNode *ptr = l;
        while (l1 != NULL || l2 != NULL) {
            a = b = 0;
            if (l1 != NULL) {
                a = l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                b = l2->val;
                l2 = l2->next;
            }
            s = a + b + c;
            c = s / 10;
            s = s % 10;
            cout << "s = " << s 
                 << "c = " << c << endl;
            ListNode *tmp = new ListNode(s);
            ptr->next = tmp;
            ptr = tmp;
        }
        if (c != 0) {
            ListNode *tmp = new ListNode(c);
            ptr->next = tmp;
        }
        return l->next;
    }
};

void tc1()
{
    ListNode a1(9),a2(0),a3(0);
    ListNode b1(1),b2(9),b3(9),b4(9),b5(9),b6(9);
    //a1.next = &a2;
    //a2.next = &a3;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &b4;
    b4.next = &b5;
    b5.next = &b6;
    
    Solution s;
    ListNode *p = s.addTwoNumbers(&a1, &b1);
    while (p != NULL) {
        cout << p->val << endl;
        p = p->next;
    }
}

int main()
{
    tc1();
}



