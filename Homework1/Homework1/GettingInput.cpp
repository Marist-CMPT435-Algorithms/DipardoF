#include <iostream>
#include <fstream>  
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

// Function to perform linear search
int linearSearch(const vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found
}

// Function to find the minimum element in the array
int findMinimum(const vector<int>& arr) {
    if (arr.empty()) return -1;  // Edge case: empty array

    int min_value = arr[0];  // Initialize min_value to first element
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < min_value) {
            min_value = arr[i];  // Update min_value if a smaller element is found
        }
    }
    return min_value;
}

// Selection Sort in Ascending Order
void ascendingSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[k]) {  // Find the smallest element
                k = j;
            }
        }
        swap(arr[i], arr[k]);  // Swap found minimum with current position
    }
}

// Selection Sort in Descending Order
void descendingSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[k]) {  // Find the largest element
                k = j;
            }
        }
        swap(arr[i], arr[k]);  // Swap found maximum with current position
    }
}

int main() {
    string filename = "input-numbers.txt";  // Specify the file name
    vector<int> numbers = readInput(filename);  // Call function to read file

    if (numbers.empty()) {
        cout << "No numbers found in file or file could not be read." << endl;
        return 1; // Exit with error
    }

    // Display numbers from the file
    cout << "Here's a list of numbers: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Ask the user for a number to search
    int key;
    cout << "Enter a number to search for: ";
    cin >> key;

    // Perform linear search
    int result = linearSearch(numbers, key);

    // Display search result
    if (result != -1) {
        cout << "Number " << key << " found at index " << result << "." << endl;
    }
    else {
        cout << "Number " << key << " not found in the list." << endl;
    }

    // Find and display the minimum value in the array
    int min_value = findMinimum(numbers);
    cout << "The minimum value in the array is: " << min_value << endl;

    // Sort the array in ascending order
    ascendingSort(numbers);
    cout << "Sorted in Ascending Order: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Sort the array in descending order
    descendingSort(numbers);
    cout << "Sorted in Descending Order: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
