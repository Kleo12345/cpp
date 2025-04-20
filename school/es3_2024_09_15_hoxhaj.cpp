#include <iostream>
using namespace std;

int* apply_all(const int* arr1, int size1, const int* arr2, int size2) {
    int* result = new int[size1 * size2];  
    int index = 0;

    for (int i = 0; i < size2; ++i) {
        for (int j = 0; j < size1; ++j) {
            result[index++] = arr2[i] * arr1[j];
        }
    }

    return result;  
}

void print(const int* arr, int size) {
    cout << "[ ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {10, 20, 30};

    cout << "Array 1: ";
    print(array1, 5);

    cout << "Array 2: ";
    print(array2, 3);

    int* results = apply_all(array1, 5, array2, 3);
    
    cout << "Result: ";
    print(results, 15);

    delete[] results;

    return 0;
}
