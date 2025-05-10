#include <iostream>
#include "gitArray.h"
#include <string>
#include <sstream>

using namespace std;

int main()
{
	// The gitarray
	GitArray arr(0);
	
	int num;
	cin >> num;
	GitArray gitArray(num);

    string inputLine;
    while (getline(cin, inputLine)) {
        istringstream iss(inputLine);
        string command;
        iss >> command;	

	if (command == "set"){
        int index, value;
        iss >> index >> value;
		gitArray.set(index, value); 
	}

	else if (command == "get") {
            int index, version;
            iss >> index >> version;
            cout << gitArray.get(index, version) << endl;
        }

	else if (command == "undo"){
		gitArray.undo();
	}

	else if (command == "redo"){
		gitArray.redo();
	}

	else if (command == "branch"){
		string new_branch_name, old_branch_name;
		iss >> new_branch_name;
		old_branch_name = gitArray.getCurrentBranch();
		gitArray.branch(old_branch_name, new_branch_name);
	}

	else if (command == "checkout"){
		string branch_name;
		iss >> branch_name;
		gitArray.checkout(branch_name);
	}

	else if (command == "print"){
		cout << gitArray.toString() << endl;
	}
	
}
	return 0;
}