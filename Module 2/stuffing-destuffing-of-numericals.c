#include <iostream>
#include <vector>
using namespace std;

// Function to perform bit stuffing
vector<int> bitStuffing(vector<int> data) {
    vector<int> stuffedData;
    int count = 0;

    for (int bit : data) {
        if (bit == 1) {
            count++;
        } else {
            count = 0;
        }
        stuffedData.push_back(bit);
        if (count == 5) {
            stuffedData.push_back(0);
            count = 0;
        }
    }
    return stuffedData;
}

// Function to perform bit destuffing
vector<int> bitDestuffing(vector<int> data) {
    vector<int> destuffedData;
    int count = 0;

    for (int bit : data) {
        if (bit == 1) {
            count++;
        } else {
            count = 0;
        }
        destuffedData.push_back(bit);
        if (count == 5) {
            if (data.size() > destuffedData.size() && data[destuffedData.size()] == 0) {
                destuffedData.pop_back();
                count = 0;
            }
        }
    }
    return destuffedData;
}

int main() {
    vector<int> data = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0};
    cout << "Original Data: ";
    for (int bit : data) {
        cout << bit;
    }
    cout << endl;

    vector<int> stuffedData = bitStuffing(data);
    cout << "Stuffed Data: ";
    for (int bit : stuffedData) {
        cout << bit;
    }
    cout << endl;

    vector<int> destuffedData = bitDestuffing(stuffedData);
    cout << "Destuffed Data: ";
    for (int bit : destuffedData) {
        cout << bit;
    }
    cout << endl;

    return 0;
}
