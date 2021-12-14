#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    vector<int> list;
    vector<int> list2;
    int greaterThan = 0;
    int listNum = 0;
    int compareNum = 0;
    int compareNum2 = 0;

    ifstream infile;

    infile.open("input.txt");

    infile >> listNum;
    list.push_back(listNum);
    infile >> listNum;
    list.push_back(listNum);
    infile >> listNum;
    list.push_back(listNum);

   while(!infile.eof()){
        infile >> listNum;
        list.push_back(listNum);
        
        compareNum = list[0] + list[1] + list[2];
        compareNum2 = list[1] + list[2] + list[3];

        if(list.size() % 4 == 0){
            if(compareNum < compareNum2){
                greaterThan++;
            }
        }

        list.erase(list.begin());
        
   }

   cout << greaterThan << endl;

    



    return 0;
}
