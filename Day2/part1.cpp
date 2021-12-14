#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    int horizontal = 0;
    int depth = 0;
    int numDir = 0;
    string direction = "";


    ifstream infile;

    infile.open("input.txt");

    while(!infile.eof()){
        infile >> direction;
        infile >> numDir;

        if(direction == "forward"){
            horizontal += numDir;
        }
        if(direction == "down"){
            depth += numDir;
        }
        if(direction == "up"){
            depth -= numDir;
        }
    }

    cout << depth * horizontal << endl;

    return 0;
}
