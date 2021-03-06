/******************************************************************
   C++ program to illustrate the 
  various  functions in Unorderd_MULTIMAP class of Assosiative container
  Author : Md Shakil Ansari date -20-mar-2020 
 ******************************************************************/ 

#include <iostream> 
#include <unordered_map> 
using namespace std; 

int main() 
{ 
	
	unordered_multimap<string, int> umap; 

	// inserting values by using [] operator 
	umap.insert(pair <string ,int> ("shakil",416)); 
    umap.insert(pair <string ,int> ("naveen",421)); 
    umap.insert(pair <string ,int> ("khwaja",421)); 
    umap.insert(pair <string ,int> ("rohit",450)); 
    umap.insert(pair <string ,int> ("shahkar",418));
    umap.insert(pair <string ,int> ("shubham",434)); 
	cout<<"the size of the map_list is "<<umap.size()<<endl;

	// inserting value by insert function 
	umap.insert(make_pair("shubham", 434)); //multimap will consider dupilicate elemnts
    cout<<"After inserting a dupilicate element ,the size of the map_list is "<<umap.size()<<endl;
	string key = "shakil"; 

	// If key not found in map iterator to end is returned 
	if (umap.find(key) == umap.end()) 
		cout << key << " not found\n\n"; 

	// If key found then iterator to that key is returned 
	else
		cout << "Found " << key << "\n\n"; 

	
	// iterating over all value of umap 
	unordered_map<string, int>:: iterator itr; 
	cout << "\nAll Elements : \n";
	cout<<"\nKEY\tELEMENT"<<endl ; 
	for (itr = umap.begin(); itr != umap.end(); itr++) 
	{ 
			cout<<itr->first<<"\t"<< itr->second<<endl ; 
	} 
} 

