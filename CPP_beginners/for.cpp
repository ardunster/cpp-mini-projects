#include <iostream>

using namespace std;

int main()
{
    /*
    for(int i=0; i<10;i++) 
    {
        cout << "loop: " << i << endl;
        if(i == 7){
            break;
        }
        cout << "Loopin like a boss" << endl;
    } */

    for(int i=0; i<10;i++) 
    {
        cout << "loop: " << i << endl;
        if(i == 7){
            continue;
        }
        cout << "Loopin like a boss" << endl;
    }

    cout << "Done looping :(" << endl;

    return 0;
}