#include<iostream>
#include<fstream>
#include<string>
#include<vector>


using namespace std;

int main(){
    
    int zeros = 0;
    int ones = 0;
    int binSize = 12;
    int gammaNum = 0;
    int epsilonNum = 0;
    vector<string> list;
    string holder = "";
    string checker = "";
    string gammaStr = "";
    string epsilonStr = "";


    ifstream infile;
    infile.open("input.txt");

    while(!infile.eof()){
        
        infile >> holder;
        list.push_back(holder);

    }


    for(int i = 0; i < binSize; i++){
        for(int j = 0; j < list.size(); j++){
            holder = list[j];

            if(holder[i] == '0'){
                zeros++;
            }
            else{
                ones++;
            }
        }
        if(zeros > ones){
            gammaStr += '0';
            epsilonStr += '1';
        }
        else{
            gammaStr += '1';
            epsilonStr += '0';
        }
        zeros = 0;
        ones = 0;
    }

    gammaNum = stoi(gammaStr, nullptr, 2);
    epsilonNum = stoi(epsilonStr, nullptr, 2);

    cout << "Power Cunsumtion: " << gammaNum * epsilonNum << endl;

    return 0;

}
