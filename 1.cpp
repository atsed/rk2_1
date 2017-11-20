#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
bool myCompare(T i, T j) {
return (i < j);
}

template <typename Iterator, typename arrType>
void merge_sort(Iterator first, Iterator last) {
sort(first, last, myCompare<arrType>);
}

template <typename Iterator1, typename Iterator2>
auto merge(Iterator1 first1, Iterator1 last1, Iterator1 first2, Iterator1 last2, Iterator2 output) {
while(true) {
if (first1 == last1)
return copy(first2, last2, output);

if (first2 == last2)
return copy(first1, last1, output);

*output++ = (*first2 < *first1)? *first2++ : *first1++;
}
}

int main() {
vector<int> v = {0, 2, 7, 6};
vector<int> b = {6, 6, 7, 9};

cout « "------------------------------------------------" « endl;
cout « "Первый вектор:" « endl;
for(int i = 0; i < v.size(); i++)
cout « v[i] « ' ';

cout « endl;

cout « "Второй вектор:" « endl;
for(int i = 0; i < b.size(); i++)
cout « b[i] « ' ';

cout « endl;

merge_sort<vector<int>::iterator, int>(v.begin(), v.end());
merge_sort<vector<int>::iterator, int>(b.begin(), b.end());

vector<int> c(v.size() + b.size());

merge<vector<int>::iterator, vector<int>::iterator, vector<int>::iterator>(v.begin(), v.end(), b.begin(), b.end(), c.begin());

cout « "Итоговый вектор:" « endl;
for(int i = 0; i < c.size(); i++)
cout « c[i] « ' ';

cout « endl;
cout « "------------------------------------------------" « endl;
return 0;
}
