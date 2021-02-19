#include <iostream>
#include <vector>
#include "creditSpread.h"

using namespace std;

int main() {

    creditSpread one(100,2,400,2,260);
    one.simSpread();
    one.print();
    cout << endl; // Just for some spacing

    creditSpread two(100,2,400,2,260);
    two.setSecureFund(true);
    two.setSecure(4);
    two.simSpread();
    two.print();
    cout << endl;

    vector<creditSpread> foo;
    for(int i = 4; i <= 12; i++){
        creditSpread cs(100,2,400,2,260);
        cs.setSecureFund(true);
        cs.setSecure(i);
        cs.simSpread();
        foo.push_back(cs);
    }
    printCSVector(maxSecure(foo));
    return 0;

}
