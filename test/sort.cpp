#include <array>
#include <fstream>
#include<iostream>

using namespace std;

int main(){

int numbers;


cout << "how many numbers do you want to enter?"<< endl;

cin >> numbers;

int size=numbers-1;

int aray[numbers];


for(int i = 0;i< numbers; i++){    //n
cout << "enter a number" << endl;       //1
cin >> aray[i];       //1 
}                                  //n(1+1)  ~= n

//cout<< "element 1 is " << aray[0] << endl;


int temp;
for(int i = 0; i< numbers; i++){   //n

for(int j =0; j< numbers-1;j++){   //n 
    if(aray[j] > aray[j+1]){   //theta?
    temp = aray[j];          //+3 
    aray[j] = aray[j+1];
    aray[j+1] = temp; 
    }
                      //n(n(3)   ~=n^2       T(n)= theta(n) = n + (n^2)= n^2 
}
}

cout<< "final array is:" << endl;

for(int i=0; i<numbers; i++){
cout<< aray[i]<< endl;
}











}











