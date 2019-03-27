#include <iostream>
#include <array>

using namespace std;

int main(void) {
    array<int, 5> numbers;
    int sum = 0;
    for (int i = 0; i < numbers.size(); i++) {
        cout << "Enter number " << i+1 << "/" << numbers.size() << ": ";
        cin >> numbers[i];
        if (!cin.good()) {
            cerr << "Invalid input!" << endl;
            return 1;
        }
    }

    for (int i = 0; i < numbers.size(); i++) {
        cout << "Number " << i+1 << "/" << numbers.size() << ": " << numbers[i] << endl;
        sum += numbers[i];
    }

    cout << "Average: " << static_cast<float>(sum) / numbers.size() << endl;

    for (int i = 0; i < numbers.size() - 1; i++) {
        cout << "Difference between [" << i+1 << "] " << numbers[i] << " and [" << i+2 << "] " << numbers[i+1] << ": " << numbers[i] - numbers[i+1] << endl;
    }

    return 0;
}