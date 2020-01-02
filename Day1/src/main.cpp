#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string line;
    vector<int> numbers;
    ifstream file("src/input.txt");
    if (file.is_open()){
        while (getline(file,line)){
            numbers.push_back(stoi(line));
        }
        file.close();
    } else {
        cout << "Could not open the file";
    }

    int sum = 0;
    int sumRec = 0;
    for (int z = 0; z < (int)numbers.size(); z++){
        int fuelReq = (numbers[z] / 3) - 2;
        //Part 1
        sum += fuelReq;
        //Part 2
        int fuelLeft = fuelReq;
        while (fuelLeft > 0){
            sumRec += fuelLeft;
            fuelLeft = (fuelLeft / 3) - 2;
        }
    }

    cout << "Part 1 Sum: " << sum << endl;
    cout << "Part 2 Sum: " << sumRec << endl;

    return 0;
}