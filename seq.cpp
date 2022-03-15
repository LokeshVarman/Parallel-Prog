#include<iostream>
#include<fstream>
#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>

using namespace std;
using namespace std::chrono;
void countFreq(vector<int> vec, int n)
{
std::map<int,int> histogram;

for (const auto& e : vec) ++histogram[e];

for (const auto& x : histogram) std::cout << x.first << " " << x.second <<"\n";
    cout<<"---------------"<<endl;
}
 
int main(){
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
int noe=a1.size();
cout<<noe<<"values present"<<endl;

countFreq(a1,noe);

countFreq(a2,noe);

countFreq(a3,noe);

countFreq(a4,noe);

countFreq(a5,noe);
auto end = chrono::steady_clock::now();
auto diff = end - start;
cout <<"time duration "<< chrono::duration <double, milli> (diff).count() << " ms" << endl;
return 0;
}


//time duration 37.115 ms


