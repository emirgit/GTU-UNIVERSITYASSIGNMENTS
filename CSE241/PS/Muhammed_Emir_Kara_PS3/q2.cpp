#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, last, i;

    cout << "Enter the number of suitors" << endl;
    cin >> n;

    vector<int> v(n);

    for (i = 0; i < n; i++) {
        v[i] = i + 1;
    }

    vector<int>::iterator iter = v.begin(); 

    while (v.size() > 2) { 

        for (i = 1; i < 3; i++) {
            if (iter == v.end()) 
                iter = v.begin();
            iter++;
        }
        
        iter = v.erase(iter); 

        if (iter == v.end()) 
            iter = v.begin();
    }

    cout << "The chosen suitor is: " << *(v.begin()) << endl;

    return 0;
}