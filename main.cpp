#include "animal.h"

int main(){
	int num;
	vector <Dragon> dg;
	
	ifstream fin;
	fin.exceptions(ifstream::failbit | ifstream::badbit);
	try{
		fin.open("input.txt");	//input file also must be changed in readFile() function (line 153)
		fin.close();
	}
	catch(const ifstream::failure& e){
		cout << "File is not found!\n\n";
		return 0;
	} 
	dg = readFile();
	
	cout << "Please enter a number (for dynmaic memory allocation):";
	cin >> num;
	
	Dragon* ptr = new Dragon[num];
	
	cout << "before sorting\n";
	for(int i = 0; i < num; i++){
		dg[i].printDetails();
		cout << "\n\n";
	}
	
	sort(dg.begin(), dg.end());
	
	cout << "\n\nafter sorting\n";
	for(int i = 0; i < num; i++){
		dg[i].printDetails();
		cout << "\n\n";
	}
		
	cout << "\n\noverloaded +\n";
	Dragon temp1 = dg[0] + dg[1];
	cout << temp1.getAnWeight();
	
	cout << "\n\noverloaded -\n";
	Dragon temp2 = dg[0] - dg[1];
	cout << temp2.getAnAge() << "\n\n";
	
	return 0;
}	
