#include<iostream>
#include<fstream>
#include<concepts>
#include <bits/stdc++.h>
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <map>
#include<ranges>
using namespace std;
using namespace std::chrono;

void hist(vector<int> vec, int n) {
std::map<int,int> histogram;
for (const auto& e : vec) ++histogram[e];

for (const auto &entry: histogram) {
        std::cout << "{" << entry.first << ", " << entry.second << "}" << std::endl;
    } 
}
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

template <typename T, std::predicate<const T&> Pred>
auto FilterCopyIfConcepts(const std::vector<T>& vec, Pred p) {
	std::vector<T> out;
	std::copy_if(begin(vec), end(vec), std::back_inserter(out), p);
	return out;
}

template <typename T, typename Pred>
auto FilterRemoveCopyIf(const std::vector<T>& vec, Pred p) {
	std::vector<T> out;
	std::remove_copy_if(begin(vec), end(vec), std::back_inserter(out), std::not_fn(p));
	return out;
}

template <typename T, typename Pred>
auto FilterRemoveErase(const std::vector<T>& vec, Pred p) {
	auto out = vec;
	out.erase(std::remove_if(begin(out), end(out), std::not_fn(p)), end(out));
	return out;
}

template <typename T, typename Pred>
auto FilterEraseIf(const std::vector<T>& vec, Pred p) {
	auto out = vec;
	std::erase_if(out, std::not_fn(p));
	return out;
}

template <typename TCont, typename Pred>
auto FilterEraseIfGen(const TCont& cont, Pred p) {
	auto out = cont;
	std::erase_if(out, std::not_fn(p));
	return out;
}


template <typename T, typename Pred>
auto FilterRangesCopyIf(const std::vector<T>& vec, Pred p) {
	std::vector<T> out;
	std::ranges::copy_if(vec, std::back_inserter(out), p);
	return out;
}

template <typename TCont, typename Pred>
auto FilterRangesCopyIfGen(const TCont& vec, Pred p) {
	TCont out;
	std::ranges::copy_if(vec, std::back_inserter(out), p);
	return out;
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
   ///auto filtered = FilterRaw(a1, [](auto& elem) { return elem>=3; });     //
   ///auto filtered = FilterRawOld(a1, [](auto& elem) { return elem>=3; });
 ///auto filtered = FilterCopyIf(a1, [](auto& elem) { return elem>=3; });
 /// auto filtered = FilterCopyIfConcepts(a1, [](auto& elem) { return elem>=3; });  //
///     auto filtered = FilterRemoveCopyIf(a1, [](auto& elem) { return elem>=3; });
///        auto filtered = FilterRemoveErase(a1, [](auto& elem) { return elem>=3; });
///       auto filtered= FilterEraseIf(a1, [](auto& elem) { return elem>=3; });
///         auto filtered = FilterEraseIfGen(a1, [](auto& elem) { return elem>=3; });
hist(a1,n);
 auto filtered = FilterRangesCopyIf(a1, [](auto& elem) { return elem>=3; });     //
/// auto filtered = FilterRangesCopyIfGen(a1, [](auto& elem) { return elem>=3; });     //


   cout<<filtered.size();
      
    
    auto end = chrono::steady_clock::now();
auto diff = end - start;
cout <<"time duration "<< chrono::duration <double, milli> (diff).count() << " ms" << endl;

    return 0;
}




