#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <stdlib.h>

// hash function that converts all letters to 0...
// maybe that can be constant?

bool is_int(char c) {
    // O(1)
    if(static_cast<int>(c) >= 48 && static_cast<int>(c) <= 57) {
        return true;
    }
    return false;
}

int sum_numbers(std::string str) {
    // Initialize vector O(1)
    std::vector<int> num_holder;
    int sum = 0;
    int x = 0;

    // Iterate over string O(n)
    for(int i = 0; i < str.size(); i++) {
        // is_int calls: O(1)
        if(is_int(str[i])) {
            // std::cout << str[i] << std::endl;
            if(i == 0 || !is_int(str[i - 1])) {
                // std::cout << "1 " << str[i] << std::endl;
                // std::cout << str[i] << std::endl;
                x += (str[i] - 48);
                continue;
            }
            if(is_int(str[i - 1])) {
                // std::cout << "3 " << str[i] << std::endl;
                x *= 10;
                x += (str[i] - 48);
                continue;
            }
        }
        else {
            // If a letter and not an int
            // push_back O(1)
            if(x > 0) {
                num_holder.push_back(x);
                x = 0;
            }
        }

    }
    // Any carry number at the end of the loop:
    if(x > 0) {
        num_holder.push_back(x);
        x = 0;
    }

    // Iterating over vector?
    for(int q : num_holder) {
        sum += q;
    }
    return sum;

    // Total running time = O(n + v) ?
    // Learn about combining asymptotic running times
}

int main() {
    std::cout << sum_numbers("7 11") << std::endl;
}
