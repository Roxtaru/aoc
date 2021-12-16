#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

void addLine(vector<vector<int>>&, int, int, int, int, bool);
void parseString(string, int&, int&, int&, int&);
int overLap(vector<vector<int>>);
void printVector(vector<vector<int>>, int);

int main(){

   int locx = 0;
   int locy = 0;
   int locx2 = 0;
   int locy2 = 0;
   int oceanSize = 1000;
   vector<vector<int>> ocean(oceanSize, vector<int>(oceanSize, 0));
   string line = "";

   ifstream myfile("input.txt");

    while(!myfile.eof()){
        getline(myfile, line);

        parseString(line, locx, locx2, locy, locy2);
        addLine(ocean, locx, locy, locx2, locy2, true);

    }

    //printVector(ocean, 10);
    //cout << endl;
    cout << overLap(ocean) << endl;

    return 0;
}

void addLine(vector<vector<int>>& v, int x, int y, int x2, int y2, bool diag){
    int tmp = 0;
    int tmp2 = 0;
    int tmpxHi = 0;
    int tmpyHi = 0;
    int counter = 0;

    if(x == x2 ){
        if(y < y2){
            for(int i = y; i<=y2; i++){
                tmp = v[i][x];
                ++tmp;
                v[i][x] = tmp;
            }
        }
        if(y2 < y){
            for(int i = y2; i<=y; i++){
                tmp = v[i][x];
                ++tmp;
                v[i][x] = tmp;
            }
        }
    }
    if(y == y2 ){
        if(x < x2){
            for(int i = x; i<=x2; i++){
                tmp = v[y][i];
                ++tmp;
                v[y][i] = tmp;
            }
        }
        if(x2 < x){
            for(int i = x2; i<=x; i++){
                tmp = v[y][i];
                ++tmp;
                v[y][i] = tmp;
            }
        }
    }
    if(diag == true){
        if(y != y2 && x != x2){
            if(x > x2){
                tmpxHi = x;
                x = x2;
                x2 = tmpxHi;
                tmpyHi = y;
                y = y2;
                y2 = tmpyHi;
            }        
            if(x < x2){
                for(x; x <= x2; ++x ){
                    if(y < y2){
                        tmp = v[y][x];
                        ++tmp;
                        v[y][x] = tmp;
                        ++y;
                    }      
                    if(y > y2){
                        tmp = v[y][x];
                        ++tmp;
                        v[y][x] = tmp;
                        --y;
                    }
                }     
            }
            tmp = v[y2][x2];
            ++tmp;
            v[y2][x2] = tmp;
        }
    }
}

void parseString(string str, int& x, int& x1, int& y, int& y1){
    string tmp = " ";
    int counter = 0;

    for(int i = 0; i < str.length(); i++){
        if( str[i] >= '0' && str[i] <= '9'){
            tmp += str[i];
        }
        if(str[i] == ','){
            if(counter == 0){
                x = stoi(tmp);
                ++counter;
                tmp = " ";
            }
            if(counter == 2){
               x1 = stoi(tmp);
                ++counter;
                tmp = " ";
            }
        }if(str[i] == '>'){
            y = stoi(tmp);
            ++counter;
            tmp = " ";
        }if(i == str.length() - 1){
            y1 = stoi(tmp);
        }
    }

}

int overLap(vector<vector<int>> v){
    int tmp = 0;

    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v.size(); j++){
            if(v[i][j] > 1){
                ++tmp;
            }
        }
    }
    
    return tmp;
}

void printVector(vector<vector<int>> v, int sizeVec){
    for(int i = 0; i<sizeVec; i++){
        for(int j = 0; j<sizeVec; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
