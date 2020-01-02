#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
    string line;
    vector<int> commands;
    ifstream file("src/input.txt");
    if (file.is_open()){
        while (getline(file,line)){
            istringstream ss(line);
            string token;
            while (getline(ss, token, ',')){
                commands.push_back(stoi(token));
            }
        }
        file.close();
    } else {
        cout << "Could not open the file";
    }

    //Command Structure
    // a, b, c, d
    // a: opcode { 1 : addition, 2 : multiplication, 99 : end program }
    // b: location of first input
    // c: location of second input
    // d: location of output

    int pc = 0; // must be 4n
    
    commands[1] = 12;
    commands[2] = 2;

    while (commands[pc] != 99){
        //get arguments
        int inputOneVal = commands[commands[pc+1]];
        int inputTwoVal = commands[commands[pc+2]];
        int outputLoc = commands[pc+3];
        //service commands
        if (commands[pc] == 1){
            commands[outputLoc] = inputOneVal + inputTwoVal;
        } else if (commands[pc] == 2){
            commands[outputLoc] = inputOneVal * inputTwoVal;
        }
        //next command
        pc += 4;
    }

    for (int z = 0; z < (int)commands.size(); z++){
        cout << "command #" << z << ": " << commands[z] << endl;
    }

    return 0;
}