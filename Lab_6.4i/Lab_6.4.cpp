#include <iostream>

using namespace std;

void InputArray(int* a, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void PrintArray(const int* a, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "a[" << i << "] = " << a[i] << "; ";
    }
    cout << endl;
}

int GetProductOfEvenIndex(const int* a, int size) {
    int product = 1;
    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            product *= a[i];
        }
    }
    return product;
}

int GetSumBetweenZeros(const int* a, int size) {
    int firstZero = -1, lastZero = -1;
    for (int i = 0; i < size; ++i) {
        if (a[i] == 0) {
            if (firstZero == -1) {
                firstZero = i;
            }
            lastZero = i;
        }
    }

    if (firstZero == -1 || lastZero == -1 || firstZero == lastZero) {
        return 0;
    }

    int sum = 0;
    for (int i = firstZero + 1; i < lastZero; ++i) {
        sum += a[i];
    }
    return sum;
}

void TransformArray(int* a, int size) {
    int* positives = new int[size];
    int* negatives = new int[size];
    int posCount = 0, negCount = 0;

    for (int i = 0; i < size; ++i) {
        if (a[i] >= 0) {
            positives[posCount++] = a[i];
        }
        else {
            negatives[negCount++] = a[i];
        }
    }

    int index = 0;
    for (int i = 0; i < posCount; ++i) {
        a[index++] = positives[i];
    }
    for (int i = 0; i < negCount; ++i) {
        a[index++] = negatives[i];
    }

    delete[] positives;
    delete[] negatives;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size!" << endl;
        return 1;
    }

    int* a = new int[n];
    cout << "Enter the elements of the array:" << endl;
    InputArray(a, n);

    cout << "\nOriginal array:" << endl;
    PrintArray(a, n);

    // 1.1
    int product = GetProductOfEvenIndex(a, n);
    cout << "\n1.1. Product of elements with even indices: " << product << endl;

    // 1.2
    int sum = GetSumBetweenZeros(a, n);
    cout << "1.2. Sum of elements between first and last zero: " << sum << endl;

    // 2
    TransformArray(a, n);
    cout << "\n2. Transformed array:" << endl;
    PrintArray(a, n);

    delete[] a;

    return 0;
}

