#include <iostream>
using namespace std;

int find_max_element(int* arr, int size) {
    int max_element = *arr;
    for (int* ptr = arr + 1; ptr < arr + size; ++ptr) {
        if (*ptr > max_element) {
            max_element = *ptr;
        }
    }

    return max_element;
}

int main() {
    int arr[] = {3, 7, 10, 9, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    int max_value = find_max_element(arr, size);
    cout << "The maximum element is: " << max_value << endl;

    return 0;
}
