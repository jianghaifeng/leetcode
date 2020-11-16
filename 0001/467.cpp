#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {

public:
    int findSubstringInWraproundString(string p) {
        vector<int> v(26, 0);
        int cont = 1, alpha = p[0];
        for (int i=1; i<=p.length(); i++) {
            if (i == p.length() || p[i]-p[i-1] != 1 && !(p[i] =='a' && p[i-1] == 'z')) {
                if (v[alpha-'a'] < cont) v[alpha-'a'] = cont;
                cont = 1;
                alpha = p[i];
            } else cont++;
        }

        //for (int i=0; i<26; i++) {cout << v[i] << " ";}

        int keep = 0, start = 0;

        while (keep < 26) {
            if (v[start] < v[prev(start)] - 1) {
                v[start] = v[prev(start)] - 1;
                keep = 0;
            } else keep++;
            start = next(start);
        }

        //for (int i=0; i<26; i++) {cout << v[i] << " ";}

        int total = 0;
        for (auto i : v) total += i;

        return total;
    }


    int next(int i) {
        return (i==25) ? 0 : i+1;
    }

    int prev(int i) {
        return (i==0) ? 25 : i-1;
    }
};

int main() {
    Solution s;
    cout << s.findSubstringInWraproundString("abceeebcd") << endl;
}
