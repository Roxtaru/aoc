#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

void parseString(string, vector<int>&);

struct bingoBoard{
    int bingo[5][5] = {0};
    bool bingoLoc[5][5] = {0};

    //place number in board
    void placeNum(int num, int locx, int locy){ 
        bingo[locx][locy] = num;
    }
    //check for bingo
    bool checkbingoAcross(){
        bool tmp = false;
        int counter = 0, counter2 = 0;

        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(bingoLoc[i][j] == false){
                    tmp = false;
                } 
                if(bingoLoc[i][j] == true){
                    counter++;
                }

            }
            if (counter == 5){
                return true;
            }
            counter = 0;
        }
        return tmp;
    }
    bool checkbingoDown(){
        bool tmp = false;
        int counter = 0, counter2 = 0;

        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(bingoLoc[j][i] == false){
                    tmp = false;
                } 
                if(bingoLoc[j][i] == true){
                    counter++;
                }

            }
            if (counter == 5){
                return true;
            }
            counter = 0;
        }
        return tmp;
    }
    //bool change
    void changeBool(int locx, int locy){
        bingoLoc[locx][locy] = true;
    }
    bool checkNum(int num){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(bingo[i][j] == num){
                    changeBool(i,j);
                    return true;
                }
            }
        }
        return false;
    }
    //print board
    void printBoard(){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                cout << bingo[i][j] << " ";
            }
            cout << endl;
        }
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                cout << bingoLoc[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

    }
    int sum(){
        int sumed = 0;

        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(bingoLoc[i][j] == false){
                    sumed += bingo[i][j];
                }
            }
        }
        return sumed;
    }
};

int main(){
    
    string randNums;
    int nums;
    int winningBoard;
    int winningNum;
    int total = 0;
    int count = 0;
    int counter = 0;
    vector<int> bingoNums;
    vector<bingoBoard> bingoBoards;
    vector<int>::iterator it;
    bool checkBool = false;
    bool checkBool2 = false;

    ifstream myfile("input.txt");

    getline(myfile, randNums);

    parseString(randNums, bingoNums);
    
    bingoBoard tmpBoard;

    while(!myfile.eof()){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                myfile >> nums;
                tmpBoard.placeNum(nums, i, j);
            }
        }
        bingoBoards.push_back(tmpBoard);

    }
for(int j = 0; j < bingoNums.size(); j++){
        for(int i = 0; i < bingoBoards.size(); i++){
                bingoBoards[i].checkNum(bingoNums[j]);
                checkBool = bingoBoards[i].checkbingoAcross();
                checkBool2 = bingoBoards[i].checkbingoDown();
                if(checkBool == true || checkBool2 == true){
                    counter++;
                }
            
                checkBool = false;
                checkBool2 = false;
        }
        if(counter == bingoBoards.size() - 1){
            for(int i = 0; i < bingoBoards.size(); i++){
                checkBool = bingoBoards[i].checkbingoAcross();
                checkBool2 = bingoBoards[i].checkbingoDown();
    
                if(checkBool == false && checkBool2 == false){
                    winningBoard = i;
                }
                checkBool = false;
                checkBool2 = false;
            }
                bingoBoards[winningBoard].printBoard();
        }
        if(counter == bingoBoards.size()){
            winningNum = j;
            j = bingoNums.size() + 1;
        }
        
        counter = 0;
}
    bingoBoards[winningBoard].printBoard();

    total = bingoBoards[winningBoard].sum();
    cout << "total: " << total << endl;
    cout << "winning board: " << winningBoard << endl;
    cout << "winning num: " << bingoNums[winningNum] << endl;
    cout << "answer: " << total * bingoNums[winningNum] << endl;


    return 0;
}

void parseString(string s, vector<int>& v){
    string tmp = "";
    char tmpChar;
    int counter = 0;

    for(int i = 0; i < s.length(); ++i){
        tmpChar = s[i];
        if(tmpChar == ','){
            v.push_back(stoi(tmp));
            tmp = "";
        }
        if(tmpChar != ','){
            tmp += tmpChar;
            if(i == s.length() - 1){
                v.push_back(stoi(tmp));
            }
        }

    }

}

int check4Bingo(vector<bingoBoard>& boards){
    bingoBoard tmpBoard;
    bool tmpBool = false;

    for(int i = 0; i < boards.size(); i++){
        tmpBoard = boards[i];

        tmpBool = tmpBoard.checkbingoAcross();
        if(tmpBool == true){
            return i;
        }
    }
        return -1;
}
