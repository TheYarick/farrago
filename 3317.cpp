#include <iostream>
#include <vector>
 
using namespace std;
 
class FenwickTree {
    vector <long long int> sums;
 
public:
    long long int rsq(long long int k) {
        long long int result = 0;
        while (k >= 0) {
            result += sums[k];
            k = (k & (k + 1)) - 1;
        }
        return result;
    }
 
    void update(long long int k, long long int delta) {
        long long int s = sums.size();
        while (k < s) {
            sums[k] += delta;
            k = (k | (k + 1));
        }
    }
   
    FenwickTree(const vector <long long int> & arr) {
        long long int s = arr.size();
        sums = vector <long long int> (s, 0);
        for (long long int i = 0; i < s; ++i)
            update(i, arr[i]);
    }
 
    FenwickTree() {
        sums = vector <long long int> (0,0);
    }
    ~FenwickTree() {}
};
 
int main() {
    long long int n;
    cin >> n;
    vector <long long int> arr;
    for (long long int i = 0; i < n; ++i) {
        long long int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    FenwickTree tree(arr);
 
    long long int q;
    cin >> q;
    for (long long int j = 0; j < q; ++j) {
        char inp_c;
        cin >> inp_c;
        switch (inp_c) {
        case 's':
            long long int l, r;
            cin >> l >> r;
            --l, --r;
            cout << tree.rsq(r) - tree.rsq(l - 1) << ' ';
            break;
        case 'u':
            long long int k, inp, delta;
            cin >> k >> inp;
            --k;
            delta = inp - arr[k];
            arr[k] = inp;
            tree.update(k, delta);
            break;
        }
    }
 
    return 0;
}