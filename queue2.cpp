#include <iostream>
#include <vector>


extern "C";


using namespace std;


int left(int i) { return 2*i + 1; }
int right(int i) { return 2*i + 2; }
int parent(int i) { return i/2 - (1 - i%2); }


void get(const vector<int>& q) { cout << q[0] << endl; }
void del(vector<int>& q) { q.erase(q.begin()); }
void add(vector<int>& q, int k) {
    q.push_back(k);
    
    int p, i = q.size()-1;
    while ((q[p = parent(i)] > q[i]) && (i != 0)) {
        swap(q[i], q[p]);
        i = p;
    }
    
    return;
}
