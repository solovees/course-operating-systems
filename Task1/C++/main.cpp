#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iterator>
#include <cstdio>
using namespace std;

bool isNumberNotInList(list<int> lst, int num){
	bool res = true;
	for(list<int>::iterator v = lst.begin(); v != lst.end(); v++){
		if(*v == num){
			res = false;
			break;
		}
	}
	return res;
}

list <int> getMissingNumbers(int minValue, int maxValue, list<int> lst){
    list <int> result;
    for(int i = minValue; i < maxValue; i++){
    	if(isNumberNotInList(lst,i)){
    		result.push_back(i);	
		}
	}
	return result;	
}
    
void handleSequence(){ 
	ifstream fout("input.txt");
	list <int> currentList;
    int minValue = 32000;
    int maxValue = 0;
    int linN;
    while(fout>>linN){
        currentList.push_back(linN);
        if(linN > maxValue){
        	maxValue = linN;
		}
        if(linN < minValue){
        	minValue = linN;	
		}
        cout<<"Последовательность: ";
        for (list<int>::iterator v = currentList.begin(); v != currentList.end(); v++){
        	cout << *v << ", ";	
		}
        cout<<"Для полноты не хватает: ";
        list<int> lst = getMissingNumbers(minValue, maxValue, currentList);
        for (list<int>::iterator v = lst.begin(); v != lst.end(); v++){
        	cout << *v << ", ";	
		}
		cout<<"\r\n";
    }
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	handleSequence();
	return 0;
}
