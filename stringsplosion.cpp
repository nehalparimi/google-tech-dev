#include <iostream>
#include <string>


char* string_splosion(char *str) {
    while(*str) {
        std::cout << *str << std::endl;
        str++;
    }
    return str;
}

int main() {
    char *s = string_splosion("Code");
}
