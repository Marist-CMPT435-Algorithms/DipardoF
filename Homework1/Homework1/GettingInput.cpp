#include <iostream>
#include <fstream>  // For file handling
#include <vector>
using namespace std;

// Function to read numbers from a file and store them in a vector
vector<int> readInput(const string& filename) {
    vector<int> numbers;
    ifstream inputFile(filename);  // Opens the file

    if (!inputFile) {  // Check if the file opened successfully
        cerr << "Error: Could not open file " << filename << endl;
        return numbers; // Return empty vector
    }

    int num;
    while (inputFile >> num) {  // Read integers from file
        numbers.push_back(num);
    }

    inputFile.close();  // Close the file
    return numbers;
}

int main() {
    string filename = "input-numbers.txt";  // Specify the file name
    vector<int> numbers = readInput(filename);  // Call function to read file

    cout << "Here's a list of numbers: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
