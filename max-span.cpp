#include <iostream>

int max_span(int arr[], int size) {
    // O(n^2)
    // Problem mentioned efficiency as being secondary to solution
    // Worth thinking about how to make this run faster
    int curr;
    int span = 0;
    for(int i = 0; i < size; i++) {
        curr = arr[i];
        for(int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                span = ((i - j + 1) > span) ? (i - j + 1) : span;
            }
        }
    }
    return span;
}
int main() {
    int arr[10] = {1, 4, 2, 1, 4, 1, 4};
    int span = max_span(arr, 7);
    std::cout << span << std::endl;
}
