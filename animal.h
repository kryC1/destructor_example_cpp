#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <new>

using namespace std;

class Animal{
	private:
		string name;
		int age;
		double weight;
		bool isPet;
		
	public:
		Animal(string name, int age, double weight, bool isPet){
			this->name = name;
			this->age = age;
			this->weight = weight;
			this->isPet = isPet;
		}
		
		Animal(){
			
		}
		
		~Animal(){
			cout << "Destructor is called(Animal)" << endl;
		}
		
		void setName(string name){
			this->name = name;
		}
		
		void setAge(int age){
			this->age = age;
		}
		
		void setWeight(double weight){
			this->weight = weight;
		}
		
		void setIsPet(bool isPet){
			this->isPet = isPet;
		}
		
		string getName(){
			return name;
		}
		
		int getAge(){
			return age;
		}
		
		double getWeight(){
			return weight;
		}
		
		string getIsPet(){
			if (isPet)
				return "Yes";
			else
				return "No";
		}
		
		
};

class Dragon : public Animal{
	private:
		string type, anName;
		int anAge;
		double anWeight;
	
	public:
		Dragon(string type, string name, int age, double weight, bool isPet) : Animal(name, age, weight, isPet){
			this->type = type;
		}
		
		Dragon() : Animal(){
			
		}
		
		~Dragon(){
			cout << "Destructor is called(Dragon)" << endl;
		}
		
		void setAnName(string name){
			this->anName = name;
		}
		
		void setAnAge(int age){
			this->anAge = age;
		}
		
		void setAnWeight(double weight){
			this->anWeight = weight;
		}
		
		void setType(string type){
			this->type = type;
		}
		
		double getAnWeight(){
			return anWeight;
		}
		
		int getAnAge(){
			return anAge;
		}
		
		string getType(){
			return type;
		}
		
		void printDetails(){
			cout << "Type: " << type << "\nName: " << getName() << "\nAge: " << getAge() << "\nWeight: " << getWeight() << "\nIs it pet? " << getIsPet();
		}
		
		bool operator < (const Dragon& dr) const{
			return (anName < dr.anName);
		}
		
		Dragon operator+(const Dragon& dr){
			Dragon drg;
			
			drg.anWeight = this->anWeight + dr.anWeight;
			
			return drg;
		}
		
		Dragon operator-(const Dragon& dr){
			Dragon drg;
			
			drg.anAge = this->anAge - dr.anAge;
			
			return drg;
		}
};


inline vector <Dragon> readFile(){
	string tType, tName, line;
	int tAge;
	double tWeight;
	bool tIsPet;
	
	vector <Dragon> v;
	Dragon temp("", "", 0, 0, false);
	
	ifstream fin;
	fin.open("input.txt");
		while(getline(fin, line)){
			if(fin.is_open()){
				fin >> tType;
				fin >> tName;
				fin >> tAge;
				fin >> tWeight;
				fin >> tIsPet;
			
				temp.setType(tType);
				temp.setName(tName);
				temp.setAge(tAge);
				temp.setWeight(tWeight);
				temp.setIsPet(tIsPet);
				
				temp.setAnName(tName);
				temp.setAnAge(tAge);
				temp.setAnWeight(tWeight);
			
				v.push_back(temp);
			}
		}
		fin.close();
	
	return v;
}
