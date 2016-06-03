#include <iostream>
#include <string>
#include <dlfcn.h>
#include <vector>



using namespace std;


typedef void (*pAdd)(vector<int>&, int);
typedef void (*pGet)(const vector<int>&);
typedef void (*pDel)(vector<int>&);


int main(void) {
    pAdd add;
    pGet get;
    pDel del;
    
    string s;
    cin >> s;
    string lib_path = "./" + s; 
    cout << lib_path << endl;
    void *lib_handle = dlopen(lib_path.c_str(), RTLD_LAZY);
    
    if (!lib_handle) return -1;
    
    vector<int> q;
    int N;
    cin >> N;
    
    add = (pAdd)dlsym(lib_handle, "add");
    get = (pGet)dlsym(lib_handle, "get");
    del = (pDel)dlsym(lib_handle, "del");
    
    while (N-- >= 0) {
        string cmd;
        cin >> cmd;
        
        if (cmd == "add") {
            int k;
            cin >> k;
            add(q, k);
            cout << "sf" << endl;
        } else if (cmd == "get")
            get(q);
        else if (cmd == "del")
            del(q);
    }
    
    dlclose(lib_handle);
    return 0;
}
