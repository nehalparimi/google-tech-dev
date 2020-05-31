#include <iostream>
#include <vector>

bool can_balance(std::vector<int> v) {
    int l_sum = 0;
    int r_sum = 0;

    std::vector<int>::iterator l = v.begin();
    std::vector<int>::iterator r = v.end() - 1;

    int hangman = 0;

    while(hangman != v.size()) {
        if (r_sum > l_sum) {
            l_sum += *l;
            l++;
            hangman++;
        }


        else if (l_sum > r_sum) {
            r_sum += *r;
            r--;
            hangman++;
        }


        else if (l_sum == r_sum && l_sum == 0) {
            l_sum += *l;
            r_sum += *r;
            l++;
            r--;
            hangman += 2;
        }

        else {
            // need to keep it moving;
            // don't change the sums
            // this just gets us towards terminating the loop
            // also, if there is no point to split the array at
            // add something to one of the sums so they don't remain after the loop
            l_sum += *l;
            hangman++;
        }

        std::cout << "l_sum " << l_sum << std::endl;
        std::cout << "r_sum " << r_sum << std::endl;
        std::cout << hangman << std::endl;



    }
    if (l_sum == r_sum && l_sum != 0) return true;
    return false;
}
int main() {
    std::vector<int> v;
    v.push_back(110);
    v.push_back(90);
    v.push_back(50);
    v.push_back(50);
    v.push_back(50);
    v.push_back(50);
    bool value = can_balance(v);

    std::cout << std::boolalpha << value << std::endl;
}
