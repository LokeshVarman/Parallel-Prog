#include <stdio.h>
#include <math.h>
#include<iostream>
#include <omp.h>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void hist(vector<int> arr, int length) {
int* fr=new int[length];  
int visited = -1;  
//#pragma omp parallel for 
    for(int i = 0; i < length; i++){  
        int count = 1;  
        for(int j = i+1; j < length; j++){  
            if(arr[i] == arr[j]){  
                count++; 
                fr[j] = visited;  
            }  
        }  
        if(fr[i] != visited)  
            fr[i] = count;  
    }  
      
   
    cout<<"---------------------"<<endl;  
    cout<<" Element | Frequency"<<endl;  
    cout<<"---------------------"<<endl;  
  //  #pragma omp parallel for
    for(int i = 0; i < length; i++){  
        if(fr[i] != visited){  
            cout<< arr[i];  
            cout<<"    |  ";  
            cout<< fr[i]<<endl;  
        }  
    } 
   
}
int main() {
    
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

    
      
    
    int length = n; 
   hist(a1,length);
   hist(a2,length);
   hist(a3,length);
   hist(a4,length);
   hist(a5,length);
 auto end = chrono::steady_clock::now();
auto diff = end - start;
cout <<"time duration "<< chrono::duration <double, milli> (diff).count() << " ms" << endl;
  

  
}


//without parallel time duration 25673.5 ms
//with parallel time duration 11512.2 ms

