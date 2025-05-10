#include "gitArray.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

GitArray::GitArray(int length) {
    data.resize(length, 0);
    versionHistory.push_back(data);
    currentVersionIndex = 0;
    currentBranch = "main";
    branches[currentBranch] = versionHistory;
}

string GitArray::getCurrentBranch() {
    return currentBranch;
}

string GitArray::toString() {
    string result = "(";
    for (int i = 0; i < data.size(); i++) {
        if (i != 0) {
            result += ",";
        }
        result += to_string(data[i]); // 将 int 转换为 string
    }
    result += ")";
    return result;
}

void GitArray::set(int index, int value){
    data[index] = value;
    versionHistory.push_back(data);
    currentVersionIndex++;
}

int GitArray::get(int index, int version) {
    int targetVersionIndex = currentVersionIndex + version;
    if (targetVersionIndex >= 0 && targetVersionIndex < static_cast<int>(versionHistory.size())) {
        const vector<int>& targetVersionData = versionHistory[targetVersionIndex];
        if (index >= 0 && index < static_cast<int>(targetVersionData.size())) {
            return targetVersionData[index];
        }
    }
    return 0; 
}

void GitArray::undo() {
    if (currentVersionIndex > 0) {
        currentVersionIndex--;
        data = versionHistory[currentVersionIndex];
    } else {
        cout << "No Previous Version to Undo" << endl;
    }
}

void GitArray::redo(){
    if (currentVersionIndex < static_cast<int>(versionHistory.size()) - 1) {
        currentVersionIndex++;
        data = versionHistory[currentVersionIndex];
    } else {
        cout << "No Next Version to Redo" << endl;
    }   
}

void GitArray::branch(const std::string& old_branch_name, const std::string& new_branch_name) {
    std::vector<std::vector<int>> oldBranchHistory;
    std::vector<std::vector<int>> newBranchHistory;
    for (int i = 0; i <= currentVersionIndex; ++i) {
        oldBranchHistory.push_back(versionHistory[i]);
        newBranchHistory.push_back(versionHistory[i]);
    }
    branches[old_branch_name] = oldBranchHistory;
    branches[new_branch_name] = newBranchHistory;
}

void GitArray::checkout(const std::string& branch_name) {
    if (branches.find(branch_name) != branches.end()) {
        currentBranch = branch_name;
        versionHistory = branches[branch_name]; 
        currentVersionIndex = versionHistory.size() - 1;
        data = versionHistory[currentVersionIndex];
        
    } else {
            cout << "Branch not found" << endl;
    }
}


