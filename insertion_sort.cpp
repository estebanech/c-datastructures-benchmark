#include <vector>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>

// insertion sort code taken from https://www.programiz.com/dsa/insertion-sort

using namespace std;

void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main(int argc, char* argv[]) {
    // argv[1] file name
    // argv[2] vector size
    //std::vector<int> v(atoi(argv[2]));
    int array[atoi(argv[2])];
    string line;
    ifstream myfile (argv[1]);
    if (myfile.is_open())
    {
        int i = 0;
        while ( getline (myfile,line) )
        {
            array[i] = stoi(line);
            i += 1;
        }
        myfile.close();
        
        std::clock_t start_time = std::clock();
        insertionSort(array,atoi(argv[2]));
        std::clock_t tot_time = std::clock() - start_time;
        std::cout << "Time: "
                  << ((double) tot_time) / (double) CLOCKS_PER_SEC
                  << " seconds" << std::endl; 
        //printArray(array,atoi(argv[2]));
    }

    else cout << "Unable to open file"; 

    return 0;
}