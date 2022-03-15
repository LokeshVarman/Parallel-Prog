#include<iostream>
#include<fstream>
#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <omp.h>
using namespace std;
using namespace std::chrono;
void hist(vector<int> vec, int n) {
std::map<int,int> histogram;
for (const auto& e : vec) ++histogram[e];

for (const auto& x : histogram) std::cout << x.first << " " << x.second <<"\n";
//int tid = omp_get_thread_num();
   // printf("Thread %d in hist: \n", tid);
cout<<"-------------"<<endl;
   
}



int  main() {
auto start = chrono::steady_clock::now();
vector<int> a1,a2,a3,a4,a5,a6,a7;
int v1, v2,v3,v4,v5,v6,v7;


ifstream inputFile("50kdata.txt");

while (inputFile >> v1 >> v2 >> v3 >> v4 >> v5 >> v6 >> v7)
{
    a1.push_back(v1);
    a2.push_back(v2);
    a3.push_back(v3);
    a4.push_back(v4);
    a5.push_back(v5);
    a6.push_back(v6);
    a7.push_back(v7);
    
}
int n=a1.size();
cout<<n<<"values present"<<endl;
   
        #pragma omp task shared(a1,n)
        //std::cout<<"a1"<<endl;
        hist(a1,n);
	
        #pragma omp task shared(a2,n)
        //std::cout<<"a2"<<endl;
        hist(a2,n);
	
        #pragma omp task shared(a3,n)
        //std::cout<<"a3"<<endl;
        hist(a3,n);
        
        #pragma omp task shared(a4,n)
        //std::cout<<"a4"<<endl;
        hist(a4,n);
        
        #pragma omp task shared(a5,n)
        //std::cout<<"a5"<<endl;
        hist(a5,n);
	
        //#pragma omp taskwait
        
    
    auto end = chrono::steady_clock::now();
auto diff = end - start;
cout <<"time duration "<< chrono::duration <double, milli> (diff).count() << " ms" << endl;

    return 0;
}


// time duration 36.2906 ms

