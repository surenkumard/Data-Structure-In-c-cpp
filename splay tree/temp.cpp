#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;

int main()
{
    ifstream file("check.txt");
    string line;
    if(file.is_open())
    {
        while(getline(file,line)){
        stringstream ss(line);
        string name;
        int num1,num2;
        ss>>name>>num1>>num2;
        // t1.insert(num1);
       cout<<"name "<<name<<"   num "<<num1<<"  "<<num2<<endl;
        }
    }
}