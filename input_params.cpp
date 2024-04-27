#include <iostream>
#include <string>
using std::cout;
using std::endl;

int main(int argc, char const *argv[]){

    cout << "Got " << argc << " params"<<endl;
    
    cout << "Program " << argv[0] << endl;

    for (int i=1; i < argc; i++) {
        cout << "argv[" << i << "]" << argv[i] <<endl;
    }

    return 0;    
}