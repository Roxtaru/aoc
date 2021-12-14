#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

char findBit(vector<string>, int, string);
void deleteBits(vector<string>&, int, char);

int main(){
    vector<string> list;
    vector<string> list2;
    int oxygenInt;
    int c02Int;
    char oxygen;
    char c02;
    string temp;

    ifstream myFile("input.txt");

    while(!myFile.eof()){
        myFile >> temp;
        list.push_back(temp);
        list2.push_back(temp);
    }

    for(int i = 0; i < 12; i++){
        oxygen = findBit(list, i, "most");
        c02 = findBit(list2, i, "least");
        
        if(list.size() > 1){
            deleteBits(list, i, oxygen);
        }
        if(list2.size() > 1){
            deleteBits(list2, i, c02);
        }

    }
    oxygenInt = stoi(list[0], nullptr, 2);
    c02Int = stoi(list2[0], nullptr, 2);

    cout << "Oxygen: " << oxygenInt << " C02: " << c02Int << endl;
    cout << "Oxygen x c02: " << oxygenInt * c02Int << endl;
    return 0;
}


char findBit(vector<string> v, int binPosit, string common){
    int zeros = 0;
    int ones = 0;
    string tmp = "";

    for(int i = 0; i < v.size(); i++){
        tmp = v[i];
        if( tmp[binPosit] == '0'){
           zeros++;
        }
        else{
            ones++;
        }
        
    }
    if(common == "most"){
        if(zeros > ones){
            return '0';
        }
        if (zeros == ones){
            return '1';
        }
        else{
            return '1';
        }
    }
    if(common == "least"){
        if(zeros < ones){
            return '0';
        }if(zeros == ones){
            return '0';
        }
        else{
            return '1';
        }
    }
    
    
    cout << "Error" << endl;
    return '0';
}

void deleteBits(vector<string>& v, int bitLoc, char wntedBit){
    int counter = 0;
    string tmp = "";

    for(int i = 0; i < v.size(); i++){
        tmp = v[i];

        if(tmp[bitLoc] == wntedBit){
            v[counter] = tmp;
            counter++;
        }
    }
    v.resize(counter);
    v.shrink_to_fit();



}
