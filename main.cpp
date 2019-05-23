double balance = 0.00;
double saving = 0.00;

#include <iostream>
using namespace std;


void menu(){
  cout << "***WELCOME TO THE ONLINE BANKING SYSTEM***" << endl;
  cout << "Current balance: " << balance << endl;
  cout << "Current savings: " <<saving << endl; 
  cout << "     " << endl;
  cout << "What would you like to do in this session?" << endl;

}

void options()
{
  cout << "01. Deposit" << endl;
  cout << "02. withdrawal" << endl;
  cout << "03. Transfer" << endl;
  cout << "Enter an option: " << flush;
}


int deposit(double x)
{
  int deposit = x;
  balance = balance + deposit;
  return balance;
}

int withdraw(double x){
  int withdraw = x;
  balance = balance - withdraw;
  return balance;
}

int transfer(double x){
  char ans;
  cout << "Would you like to transfer from your savings? y/n" << endl;
  cin >> ans;
  if (ans == 'n'){
    cout << "How much would you like to take out of your checkings to your savings?: " << flush;
    cin >> x;
    balance = balance - x;
    saving = saving + x;
    
    return saving;
    
  }else{
    cout << "How much would you like to take from your savings to checking : " << flush;
    cin >> x;
    saving = saving - x;
    balance = balance + x;

    return balance;

  }


}

void overdraft(){
  double newbalance;
  double newsaving;
  double newtotalbalance;
  double newtotalsaving;

  if (balance < 0){
    cout << "OVERDRAFT FEE: 25%!!!" << endl;
    newbalance = balance + (balance * .25);
    cout << "Your new balance is now: " << newbalance << endl;


  }else if(saving < 0) {
    cout << "OVERDRAFT FEE: 25%!!!" << endl;
    newsaving = saving + (saving * .25);
    
    cout << "Your new saving is now: " << newsaving<< endl;
  }
  else{
    cout << "No overdraft fee" << endl;
  }
}


int main()
{
  int ans;
  int addMoney;
  int takeout;
  int trans;

  menu();
  options();
  cout << ans << flush;
  cin >> ans;
  
  

  switch (ans){
    case 1:
    cout << "How much would you like to deposit: " << flush;
    cin >> addMoney;
    deposit(addMoney);
    cout << "Your balance is now: $" << balance << endl;
    break;

    case 2:
    cout << "How much would you like to withdraw: " << flush;
    cin >> takeout;
    withdraw(takeout);
    cout << "Your balance is now: $" << balance << endl;
    break;

    case 3:
    cout << "How much would you like to transfer: " << flush;
    transfer(trans);
    cout << "Your balance is now: $" << balance << endl; 
    cout << "Your saving is now: $" << saving << endl;
    break;

    default:
    cout << "Not a valid option" << endl;
    break;

  
  }
  overdraft();

} 


