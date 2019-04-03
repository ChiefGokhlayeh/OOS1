#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int num = 0;
    cout << "Enter how many numbers you would like to store: ";
    cin >> num;

    if (!cin.good()) {
        cerr << "Invalid input!" << endl;
        return 1;
    }

    vector<int> numbers;
    int entered = 0;
    do {
        int input = 0;
        cout << "Enter number [" << entered+1 << "/" << num << "]: ";
        cin >> input;
        if (cin.good()) {
            numbers.push_back(input);
            entered++;
        } else {
            cerr << "Invalid input, try again!" << endl;
        }
    } while (entered < num);
    ofstream output;
    output.open("output.txt");
    int sum = 0;
    for (auto val : numbers) {
        sum += val;
        cout << "Entered: " << val << endl;
        output << val << endl;
    }
    output.close();

    cout << "Average: " << sum / numbers.size() << endl;

    return 0;
}
