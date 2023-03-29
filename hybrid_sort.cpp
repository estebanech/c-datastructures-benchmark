#include <vector>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;



void insertionSort(int array[], int initial_pos,int size) {
  for (int step = initial_pos + 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= initial_pos) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r, int min_size) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    if(r - l <= min_size){
        insertionSort(arr,l,r+1);
    }
    else {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m,min_size);
        mergeSort(arr, m + 1, r,min_size);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
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
        mergeSort(array,0,atoi(argv[2])-1,atoi(argv[3]));
        //insertionSort(array,5,atoi(argv[2]));
        std::clock_t tot_time = std::clock() - start_time;
        std::cout << "Time: "
                  << ((double) tot_time) / (double) CLOCKS_PER_SEC
                  << " seconds" << std::endl;    
        //printArray(array,atoi(argv[2]));
    }

    else cout << "Unable to open file"; 

    return 0;
}