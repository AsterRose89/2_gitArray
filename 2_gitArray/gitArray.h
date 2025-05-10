#ifndef GITARRAY_H_INCLUDED
#define GITARRAY_H_INCLUDED

#include <string>
#include <vector>
#include <unordered_map>
#include <map>

class GitArray {
private:
    // add member functions/variables here
    std:: vector<int> data;
    std::vector<std::vector<int>> versionHistory;
    int currentVersionIndex;
    std::unordered_map<std::string, std::vector<std::vector<int>>> branches;
    std::string currentBranch;
public:
    GitArray(int length);

    std::string toString();

    void set(int index, int value);
    int get(int index, int version);

    void undo();
    void redo();

    void branch(const std::string& old_branch_name, const std::string& new_branch_name);
    void checkout(const std::string& branch_name);
    std::string getCurrentBranch();
};


#endif // GITARRAY_H_INCLUDED
