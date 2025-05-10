#include <vector>
#include <iostream>

using namespace std;

int findString(const vector<char>& str, const vector<char>& sub){
    for (int i = 0; i < str.size() - sub.size() - 1; i++){
        bool found = true;
        for (int j = 0; j < sub.size() - 1; j++){
            if (sub[j]!= str[i + j]){
                found = false;
                break;
            }
        }
    if (found){
        return i;
    }    
    }
    return -1;

}


int findString(const vector<char>& str, const vector<char>& sub){
    for (int i = str.size() - sub.size()- 1; i > 0 ; i--){
        bool found = true;
        for (int j = sub.size() - 1; j > 0; j--){
            if (sub[j]!= str[i + j]){
                found = false;
                break;
            }
        }
    if (found){
        return i;
    }    
    }
    return -1;

}
