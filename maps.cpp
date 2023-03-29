#include <vector>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

int main(int argc, char* argv[]) {
    std::fstream file;
    file.open(argv[1],std::fstream::app);
    file<<",multimap,unordered_multimap"<<std::endl;
    //100000000
    for (int i = 10; i <= atoi(argv[2]);) {
        multimap<int, int> multi;
        unordered_multimap<int, int> u_multi;
        std::clock_t multi_start_time = std::clock();
        for(int j = 0; j < i;j++){
            multi.insert(pair<int, int>(j, i));
        } 
        std::clock_t multi_time = std::clock() - multi_start_time;
        std::clock_t u_multi_start_time = std::clock();
        for(int j = 0; j < i;j++){
            u_multi.insert(pair<int, int>(j, i));
        } 
        std::clock_t u_multi_time = std::clock() - u_multi_start_time;
        file << i << "," << ((double) multi_time) / (double) CLOCKS_PER_SEC <<"," << ((double) u_multi_time) / (double) CLOCKS_PER_SEC << endl;
        i = i * 10;
    }
    file.close();
}