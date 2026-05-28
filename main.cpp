#include <iostream>
#include <string>
using namespace std;
 
struct Customer{
    string name;
    string  id;
    string address;
    string meter_no;
    int used_units;
    double total_bill;
    double amount_paid;
    double outstanding_balance;

};
 void addCoustomer(Customer customer[], int &customerCount){
        string name,address,meter_no,id;
        int used_units;
        cout<<"Enter the Name:"<<"\n";
        cin>>customer[customerCount].name;
        cout<<"Enter the Address :"<<"\n";
        cin.ignore();
        getline(cin,customer[customerCount].address );
        cout<<"Enter the Meter-No:"<<"\n";
         cin>>customer[customerCount].meter_no;
        cout<<"Enter the Used Units:"<<"\n";
         cin>>customer[customerCount].used_units;
         customer[customerCount].id = "C00" + to_string(customerCount + 1);
         cout<<"Customer added successfully! (ID: "<< customer[customerCount].id << ")\n";
         customerCount++;
            }
int main(){
     Customer customer[50];
     int customerCount = 0;
      addCoustomer(customer, customerCount);

}