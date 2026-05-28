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



void calculateBill(Customer customer[], int &customerCount){
    double bill;
    string id;
    cout<<"Enter the Customer ID:"<<"\n";
    cin>>id;
      for(int i=0; i<customerCount; i++){
         if(customer[i].id==id){
            int units = customer[i].used_units;
            cout<<"Used Units:"<<units<<"\n";
            if(units<=100){
                bill= units*5;
            }else if(units<=200){
                bill=(100*5)+(units-100)*8;
            }else if(units<=300){
                 bill=(100*5)+(100*8)+(units-200)*12;
            }else if(units<=400){
                 bill=(100*5)+(100*8)+(100*12)+(units-300)*15;
            }
            bill = bill+50+100;  //fixed charges
            bill = bill+(bill*0.17); //GST 17%
             cout<<"Bill:"<<bill<<" Rs"<<"\n";
             customer[i].total_bill = bill;
             customer[i].outstanding_balance = bill;
         }}
        
}

void payBill(Customer customer[], int &customerCount){
    double bill;
    string id;
    cout<<"Enter the Customer ID to pay bill:"<<"\n";
    cin>>id;
     for(int i=0; i<customerCount; i++){
         if(customer[i].id==id){
            cout<<"Total Bill: "<< customer[i].total_bill<<"\n";
            cout<<"How much you want to pay?"<<"\n";
            cin>>bill;
            if(bill>customer[i].outstanding_balance){
                cout<<"Amount exceeds balance!"<<"\n";
            }else{
            customer[i].amount_paid += bill;
            customer[i].outstanding_balance -= bill;
            cout<<"Paid bill:"<< bill<<"\n";
            cout<<"Remaining Bill Amount:"<< customer[i].outstanding_balance<<"\n";
            cout<<"Thanks!"<<"\n";
            }
         }}
}

void overDue(Customer customer[], int &customerCount){
    cout<<"\n === Overdue Customers === \n"
    for(int i=0; i<customerCount; i++){
        if(customer[i].outstanding_balance>0){
            cout<<"ID: "<< customer[i].id<<"\n";
            cout<<"Name: "<< customer[i].name<<"\n";
            cout<<"Balance: "<< customer[i].outstanding_balance<<"\n";
        }
    }
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
            case 3:  calculateBill (customer, customerCount); break;
            case 4:  payBill  (customer, customerCount); break;
            case 5:  viewOverdue (customer, customerCount); break;
            case 6: cout << "Goodbye!\n"; return;
            default: cout << "Invalid choice!\n";
        }
    }
}  

int main(){
     Customer customer[50];
     int customerCount = 0;
    showMenu(customer, customerCount);

}