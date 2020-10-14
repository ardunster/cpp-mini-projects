#include <iostream>

using namespace std;

int main() {

    string hello = "hello";

    cout << hello << endl;

    // char hello2[] = {'h', 'e', 'l', 'l', 'o', '2'};
    char hello2[] = "hello2";

    cout << hello2 << endl;

    cout << "========" << endl;

    for(int i=0; i < sizeof(hello2); i++){
        cout << "i: " << i << ": " << (int)hello2[i] << endl;
    } 

    char hello3[] = {104, 101, 108, 108, 111, 51, 0};

    cout << hello3 << endl;

    for(int i=0; i < sizeof(hello3); i++){
        cout << "i: " << i << ": " << (int)hello3[i] << endl;
    } 

    int k = 0;

    while(true) {
        if(hello2[k] == 0) {
            break;
        }
        cout << hello2[k] << flush;
        k++;

    } cout << endl;

    return 0;
}