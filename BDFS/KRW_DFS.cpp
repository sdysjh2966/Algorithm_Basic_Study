#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class PIXEL {
public:
    PIXEL(){}
    PIXEL(bool color): color(color){}
    void checking() {
        this->check = 1;
    }
    bool retColor() {
        return this->color;
    }
    bool retCheck() {
        return this->check;
    }
private:
    bool color;
    bool check = false;
};

int main() {
    int column, row;
    cin >> row >> column;
    PIXEL** arr = new PIXEL*[column];
    for (int i = 0; i < column; i++) {
        arr[i] = new PIXEL[row];
    }
    for (int i=0; i < row; i++) {
        for (int j=0; j<column; j++) {
            bool color;
            cin >> color;
            PIXEL info = PIXEL(color);
            arr[j][i] = info;
        }
    }
    stack<int> search;
    vector<int> size;
    int numberOfPicture=0;
    for (int i=0; i<row; i++) {
        for (int j=0; j<column; j++) {
            if (arr[j][i].retColor()==1 && arr[j][i].retCheck()==0) {
                int count=1;
                arr[j][i].checking();
                search.push(i);
                search.push(j);
                while(!search.empty()) {
                    int checkColumn = search.top();
                    search.pop();
                    int checkRow = search.top();
                    search.pop();
                    if (checkColumn-1>=0) {
                        if (arr[checkColumn-1][checkRow].retColor()==1 && arr[checkColumn-1][checkRow].retCheck()==0)
                        {
                            arr[checkColumn-1][checkRow].checking();
                            search.push(checkRow);
                            search.push(checkColumn-1);
                            count++;
                        }
                    }
                    if (checkRow-1>=0) {
                        if (arr[checkColumn][checkRow-1].retColor()==1 && arr[checkColumn][checkRow-1].retCheck()==0)
                        {
                            arr[checkColumn][checkRow-1].checking();
                            search.push(checkRow-1);
                            search.push(checkColumn);
                            count++;
                        }
                    }
                    if (checkColumn+1<column){
                        if (arr[checkColumn+1][checkRow].retColor()==1 && arr[checkColumn+1][checkRow].retCheck()==0)
                         {
                            arr[checkColumn+1][checkRow].checking();
                            search.push(checkRow);
                            search.push(checkColumn+1);
                            count++;
                        }
                    }
                    if (checkRow+1<row){
                        if (arr[checkColumn][checkRow+1].retColor()==1 && arr[checkColumn][checkRow+1].retCheck()==0) {
                            arr[checkColumn][checkRow+1].checking();
                            search.push(checkRow+1);
                            search.push(checkColumn);
                            count++;
                        }
                    }
                }
                size.push_back(count);
                numberOfPicture++;
            }
        }
    }
    int max;
    if (!size.empty()) {
        max=*max_element(size.begin(), size.end());
    }
    for (int i = 0; i < column; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    if (!size.empty()) {
        cout << numberOfPicture << endl;
        cout << max << endl;
    }
    else {
        cout << "0\n" << "0";
    }
    return 0;
}
