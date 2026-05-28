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
 void addCustomer(Customer customer[], int &customerCount){
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
         customer[customerCount].total_bill = 0;
         customer[customerCount].amount_paid = 0;
         customer[customerCount].outstanding_balance = 0;
         cout<<"Customer added successfully! (ID: "<< customer[customerCount].id << ")\n";
         customerCount++;
            }

 void displayCustomer(Customer customer[], int customerCount){
        string id;
        cout<<"Enter the Customer ID:"<<"\n";
        cin>>id;

         for(int i=0; i<customerCount; i++){
         if(customer[i].id==id){
           cout << "Name: " << customer[i].name << "\n";
           cout << "Address: " << customer[i].address << "\n";
           cout << "Meter No: " << customer[i].meter_no << "\n";
           cout << "Units Used: " << customer[i].used_units << "\n";
           cout << "Total Bill: " << customer[i].total_bill << "\n";
           cout << "Amount Paid: " << customer[i].amount_paid << "\n";
           cout << "Outstanding Balance: " << customer[i].outstanding_balance << "\n";
            return ;
         }
           
         }
          cout<<"Customer not found!\n";
            }

void showMenu(Customer customer[], int &customerCount)  {
    int choice;
     while(true){
        cout << "\n=== Electricity Bill Management ===\n";
        cout << "1. Add Customer\n";
        cout << "2. Display Customer\n";
        cout << "3. Calculate Bill\n";
        cout << "4. Pay Bill\n";
        cout << "5. View Overdue\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1: addCustomer(customer, customerCount); break;
            case 2: displayCustomer(customer, customerCount); break;
            case 3: // calculateBill later
            case 4: // payBill later
            case 5: // viewOverdue later
            case 6: cout << "Goodbye!\n"; return;
            default: cout << "Invalid choice!\n";
        }
    }
}       
int main(){
     Customer customer[50];
     int customerCount = 0;
    //   addCoustomer(customer, customerCount);
    // displayCustomer(customer, customerCount);
    showMenu(customer, customerCount);

}