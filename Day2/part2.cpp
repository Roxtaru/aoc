#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    int horizontal = 0;
    int depth = 0;
    int aim = 0;
    int numDir = 0;
    int holder = 0;
    string direction = "";


    ifstream infile;

    infile.open("input.txt");

    while(!infile.eof()){
        infile >> direction;
        infile >> numDir;

        if(direction == "forward"){
            horizontal += numDir;
            holder = aim * numDir;
            depth = depth + holder;
            holder = 0;
        }
        if(direction == "down"){
            aim += numDir;
        }
        if(direction == "up"){
            aim -= numDir;
        }
    }

    cout << horizontal * depth << endl;

    return 0;
}
