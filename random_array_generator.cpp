#include <vector>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>

int next_rand(){
    return 1 + (std::rand() % 100);
}

int main(int argc, char* argv[]) {
    // argv[1] file name
    // argv[2] vector size
    std::srand(unsigned(std::time(nullptr)));
    std::vector<int> v(atoi(argv[2]));
    std::generate(v.begin(), v.end(), next_rand);
    std::fstream file;
    file.open(argv[1],std::fstream::app);
 
    for(int i=0;i<v.size();i++)
    {
        if (i == v.size() -1) {
            file<<v[i];
        }
        else {
            file<<v[i]<<std::endl;
        }
        
    }
 
    file.close();
}