#include <iostream>
#include <string>


std::string without_string(std::string, std::string);
int main() {
    std::string str = without_string("xxx", "xx");
    std::cout << str << std::endl;
}

std::string without_string(std::string string, std::string substring) {
    int substr_i = 0;

    // string.size() changes on fly...hmm
    // we shouldn't increment i when we erase because the positions of the characters
    // change
    for(int i = 0; i < string.size();) {
        if(string[i] != substring[substr_i]) {
            i++;
            continue;
        }
        // If str.erase() is O(n), is the worst-case for without string O(n^2)?
        string.erase(string.begin() + i);     // deletes character at i
        substr_i++;
    }
    return string;
}
