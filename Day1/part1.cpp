#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    vector<int> list;
    int greaterThan = 0;
    int listNum = 0;
    int compareNum = 0;
    int compareNum2 = 0;

    ifstream infile;

    infile.open("input.txt");

    infile >> listNum;
    list.push_back(listNum);


   while(!infile.eof()){
        infile >> listNum;
        list.push_back(listNum);
        
        compareNum = list[0];
        compareNum2 = list[1];

        if(compareNum < compareNum2){
            greaterThan++;
        }

        list.erase(list.begin());
        
   }

   cout << greaterThan << endl;

    



    return 0;
}
