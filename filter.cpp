#include<iostream>
#include<fstream>

#include <bits/stdc++.h>
#include <vector>
#include <functional>
#include <algorithm>
#include <execution>
//#include<tbb/task.h>
#include <unordered_map>
#include <omp.h>
#include <map>
#include<ranges>
using namespace std;
using namespace std::chrono;
template <typename T, typename Pred>
auto FilterRaw(const std::vector<T>& vec, Pred p) {
	std::vector<T> out;
	for (auto&& elem : vec)
		if (p(elem))
			out.push_back(elem);
	return out;
}

template <typename T, typename Pred>
auto FilterRawOld(const std::vector<T>& vec, Pred p) {
	std::vector<T> out;
	for (typename std::vector<T>::const_iterator it = begin(vec); it != end(vec); ++it)
		if (p(*it))
			out.push_back(*it);
	return out;
}

template <typename T, typename Pred>
auto FilterCopyIf(const std::vector<T>& vec, Pred p) {
	std::vector<T> out;
	std::copy_if(begin(vec), end(vec), std::back_inserter(out), p);
	return out;
}

void fil(vector<int> vec, int n) {
//std::map<int,int> histogram;
//for (const auto& e : vec) ++histogram[e];



//filter using map while calculating histogram 

/*for (const auto& e : vec) {
if(e>=3){
	++histogram[e];
}
}*/

//filter using copy_if

/*std::vector<int> filt;
    std::copy_if(vec.begin(), vec.end(), std::back_inserter(filt), [](int i) {
        return i>=3;
    });
 
  
    std::cout << filt.size() << ' ';*/





    
    
    
//filter using ranges

/*auto filt = vec | std::ranges::views::filter([](int &i) {
        return i>=3;
    });
    int count=0;

    for (int &i: filt) {
                count++;
    }
cout<<count;
//for (const auto& x : histogram) std::cout << x.first << " " << x.second <<"\n";
*/


// filter using erase-remove idiom

/*vec.erase(std::remove_if(vec.begin(), vec.end(), [&](const int& i) {
        return i<3;
    }), vec.end());
 
    
 std::cout << vec.size()<< ' '; */


// filter using par copy_if

std::vector<int> filt;
    std::copy_if(std::execution::par,vec.begin(), vec.end(), std::back_inserter(filt), [](int i) {
        return i>=3;
    });
 
  
    std::cout << filt.size() << ' ';


cout<<"-------------"<<endl;


//filter after cal histogram

 /* auto it = histogram.begin();
    while (it != histogram.end())
    {
        if (it->first >=3) {
            ++it;       
        } else {
            histogram.erase(it++); 
            
        }
    }
 
    for (const auto &entry: histogram) {
        std::cout << "{" << entry.first << ", " << entry.second << "}" << std::endl;
    }   */
 
   
}


int  main() {
auto start = chrono::steady_clock::now();
vector<int> a1,a2,a3,a4,a5,a6,a7;
int v1, v2,v3,v4,v5,v6,v7;


ifstream inputFile("1Mdata.txt");

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
   //auto filtered = FilterRaw(a1, [](auto& elem) { return elem>=3; });
   auto filtered = FilterRawOld(a1, [](auto& elem) { return elem>=3; });
   
   cout<<filtered.size();
        //#pragma omp task shared(a1,n)
        //std::cout<<"a1"<<endl;
        //fil(a1,n);
	//filter(a1,n);
        //#pragma omp task shared(a2,n)
        //std::cout<<"a2"<<endl;
        //hist(a2,n);
	
        //#pragma omp task shared(a3,n)
        //std::cout<<"a3"<<endl;
       // hist(a3,n);
        
        //#pragma omp task shared(a4,n)
        //std::cout<<"a4"<<endl;
        //hist(a4,n);
        
        //#pragma omp task shared(a5,n)
        //std::cout<<"a5"<<endl;
      //  hist(a5,n);
	
        //#pragma omp taskwait
        
    fil(a1,n);
    auto end = chrono::steady_clock::now();
auto diff = end - start;
cout <<"time duration "<< chrono::duration <double, milli> (diff).count() << " ms" << endl;

    return 0;
}


// time duration 36.2906 ms

