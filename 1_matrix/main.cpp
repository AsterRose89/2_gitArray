#include <iostream>
#include <map>
#include <string>
#include "matrix.h"

using namespace std;

string printErrorCode(ErrorCode errorCode){
	if (errorCode == NoError){
		cout << "No Error";
}
	else if (errorCode == IndexOutOfRange){
		cout << "Index out of Range";
}
	if (errorCode == DimensionMismatch){
		cout << "Dimension Mismatch";
}
	if (errorCode == InvalidDimension){
		cout << "Invalid Dimension";
}
}

int main() {
    map<string, Matrix> matrices;
    string inputLine;
    while (getline(cin, inputLine)) {
        istringstream iss(inputLine);
        string command;
        iss >> command;

        if (command == "new") {
            string name;
            int row, col;
            iss >> name >> row >> col;
            matrices[name] = Matrix(row, col);
            // cout << printErrorCode(matrices[name].getErrorCode()) << endl;
        }
        else if (command == "set") {
            string name;
            int row, col;
            double val;
            iss >> name >> row >> col >> val;
            if (matrices.find(name) != matrices.end()) {
                matrices[name].set(row, col, val);
                // cout << printErrorCode(matrices[name].getErrorCode()) << endl;
            }
            // else {
                // cout << "Matrix not found" << endl;
            // }
        }
        else if (command == "get") {
            string name;
            int row, col;
            iss >> name >> row >> col;
            if (matrices.find(name) != matrices.end()) {
                double element = matrices[name].get(row, col);
                // cout << printErrorCode(matrices[name].getErrorCode()) << endl;
                if (matrices[name].getErrorCode() == NoError) {
                    cout << element << endl;
                }
            }
            // else {
            //     cout << "Matrix not found" << endl;
            // }
        }
        else if (command == "add") {
            string aName, bName, cName;
            iss >> aName >> bName >> cName;
            if (matrices.find(aName) != matrices.end() && matrices.find(bName) != matrices.end()) {
                matrices[cName] = matrices[aName] + matrices[bName];
                // cout << printErrorCode(matrices[cName].getErrorCode()) << endl;
            }
            // else {
            //     cout << "One or more matrices not found" << endl;
            // }
        }
        else if (command == "mul") {
            string aName, bName, cName;
            iss >> aName >> bName >> cName;
            if (matrices.find(aName) != matrices.end() && matrices.find(bName) != matrices.end()) {
                matrices[cName] = matrices[aName] * matrices[bName];
                // cout << printErrorCode(matrices[cName].getErrorCode()) << endl;
            }
            // else {
            //     cout << "One or more matrices not found" << endl;
            // }
        }
        else if (command == "print") {
            string name;
            iss >> name;
            if (matrices.find(name) != matrices.end()) {
                cout << matrices[name];
                // cout << printErrorCode(matrices[name].getErrorCode()) << endl;
            }
            // else {
            //     cout << "Matrix not found" << endl;
            // }
        }
        else if (command == "error") {
            string name;
            iss >> name;
            if (matrices.find(name) != matrices.end()) {
                cout << printErrorCode(matrices[name].getErrorCode()) << endl;
            }
            // else {
            //     cout << "Matrix not found" << endl;
            // }
        }
    }
    return 0;
}