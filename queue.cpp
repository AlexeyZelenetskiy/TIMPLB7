#include <iostream>
#include <vector>



extern "C";


using namespace std;


void get(const vector<int>& q) { cout << q[0] << endl; }
void del(vector<int>& q) { q.erase(q.begin()); }
void add(vector<int>& q, int k) { q.push_back(k); }
