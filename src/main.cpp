#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "VM.h"
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << endl
             << "please specify at least one bytecode file:"
             << endl
             << argv[0] << " <file> ..."
             << endl << endl;
        return 0;
    }

    VM vm;

    cout << endl;
    for (int i = 1; i < argc; i++)
    {
        ifstream file(argv[i], ios::in | ios::binary | ios::ate);
        if (file.is_open())
        {
            cout << "<executing " << argv[i] << ">" << endl;

            int size = file.tellg();
            //unsigned char bytecode[size];
            vector <unsigned char> bytecode;

            file.seekg(0);

            char c;
            int i = 0;
            while (file.get(c))
                //bytecode[i++] = (unsigned char)c;
                bytecode.push_back((unsigned char)c);

            //vm.run(bytecode, size);
            unsigned char* program = bytecode.data();
            vm.run(program, size);

            file.close();
            cout << "<execution finished>" << endl;
        }
    }

    return 0;
}
