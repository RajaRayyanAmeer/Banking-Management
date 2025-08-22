#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
using namespace std;
//Constants
const long long int MIN_IBAN = 1000000000000000;
const long long int MAX_IBAN = 9999999999999999;
class Bank_Account
{
 private:
        long long int CNIC;
        long long int IBAN;
        int PIN;
        float Balance;
        string formatted_time;
 public:
        string First_Name;
        string Last_Name;
        int age;	
        Bank_Account ()
        {
         set_formatted_time ();
		}
		//setter
		void set_formatted_time ()
		{
		 //Current Time
         time_t now = time (0);
		 formatted_time = string (ctime (&now));
		}
		//getter
		string get_formatted_time ()
		{
		 return formatted_time;
		}
		//setter
        void set_CNIC(long long int cnic)
        {
         CNIC = cnic;
		}
		//getter
		long long int get_CNIC()
		{
		 return CNIC;
		}
		//setter
        void set_IBAN (long long int iban)
        {
         // Generate a random IBAN
         srand(time(0));    
         iban = MIN_IBAN + (rand() % (MAX_IBAN - MIN_IBAN + 1));
         IBAN = iban;
		}
		//getter
		long long int get_IBAN()
		{
		 return IBAN;
		}
		//setter
        void set_PIN(int pin)
        {
         PIN = pin;
		}
		//getter
		int get_PIN ()
		{
		 return PIN;
		}
		//setter
        void set_Balance (float amount)
        {
         Balance = amount;
		}
		//getter
		float get_Balance ()
		{
		 return Balance;
		}
};
int main ()
{
 // Create a vector to store multiple bank accounts
 vector <Bank_Account> accounts;
 Bank_Account account;
 int option;
 cout<<"\n\n\n\n\t\t\t\t\t\t\t\tBank Management: \n";
 // Menu loop
 while (true)
       {   
	    cout<<endl;   
        cout<<"\n\t\t\t\t1. New Account ";
        cout<<"\n\t\t\t\t2. Deposit Money";
        cout<<"\n\t\t\t\t3. Withdraw Money";
        cout<<"\n\t\t\t\t4. Current Balance";
        cout<<"\n\t\t\t\t5. Get Account Details";
        cout<<"\n\t\t\t\t6. Exit";
        cout<<"\n\n\t\t\t\t\t\tWelcome to our Banking Site! Choose an Option, For what You Want!  ";
        cin>>option;
        cout<<endl;
        switch (option)
               {
                case 1:
                      {
                       float Initial_Balance;
                       int pin;
                       long long int cnic;
                       cout<<"\n\n\t\t\t\t\t\tInformation Needed for Your Account Creation! "<<endl;
                       cout<<"\n\t\t\t\tEnter Your First Name: ";
                       cin>>account.First_Name;
                       cout<<"\n\t\t\t\tEnter Your Last Name: ";
                       cin>>account.Last_Name;
                       cout<<"\n\t\t\t\tEnter Your Age: ";
                       cin>>account.age;
                       if (account.age >= 18)
                          {    
                           cout<<"\n\t\t\t\tEnter Your CNIC Number (Enter 13 Digits of CNIC in Numerical Form, Without Hyphen): ";
                           cin>>cnic;
                           account.set_CNIC(cnic);
                           cout<<"\n\t\t\t\tCreate 4 Digits PIN for Your Account Safety (Remember! Don't share your PIN with anyone): ";
                           cin>>pin;
                           account.set_PIN(pin);
                           // Generate IBAN here
                           account.set_IBAN(0); 
                           // Call set_formatted_time()
                           account.set_formatted_time();
                           cout<<"\n\t\t\t\tYour IBAN (Digital Account Number; Remember Don't share it with anyone): BANK"<<account.get_IBAN();
                           cout<<"\n\n\t\t\t\t\t\tCONGRATULATIONS! Your Account Created on "<<account.get_formatted_time();
                           cout<<"\n\t\t\t\tHow much Money You want to Enter for the First Time In Your Account: $";
                           cin>>Initial_Balance;
                           account.set_Balance(Initial_Balance);
                           cout<<endl;
                          }
                       else if (account.age < 18)
                               {
                                cout<<"\n\t\t\t\t\t\tOnly those persons are allowed who are offically 18 or 18+ age...";
                                exit(0);
                               }
                       accounts.push_back(account);
                       break;
                      } 
                case 2:
                      {
                       float Deposit;
                       int pin;
                       long long int cnic;
                       cout<<"\n\t\t\t\tEnter Your CNIC: ";
                       cin>>cnic;
                       bool found = false;
                       for (auto &acc : accounts)
                           {
                            if (cnic == acc.get_CNIC())
                               {
                                found = true;
                                cout<<"\n\t\t\t\tAccount Found "<<acc.First_Name<<" "<<acc.Last_Name<<".";
                                cout<<"\n\t\t\t\tEnter Your PIN: ";
                                cin>>pin;
                                if (pin == acc.get_PIN())
                                   {
                                    cout<<"\n\t\t\t\tHow Much Money You Want to Deposit? $";
                                    cin>>Deposit;
                                    acc.set_Balance(acc.get_Balance() + Deposit);
                                    cout<<"\n\t\t\t\tYour Total Balance: "<<acc.get_Balance()<<" $";
                                   }
                                else
                                    {
                                     cout<<"\n\n\t\t\t\t\t\tERROR... TRY AGAIN... ";
                                    }
                                break;
                               }
                           }
                       if (!found)
                          {
                           cout<<"\n\n\t\t\t\t\t\tERROR... CNIC NOT FOUND... ";
                          }
                       break;
                      } 
                case 3:
                      {
                       float Withdraw;
                       int pin;
                       long long int cnic;
                       cout<<"\n\t\t\t\tEnter Your CNIC: ";
                       cin>>cnic;
                       bool found = false;
                       for (auto &acc : accounts)
                           {
                            if (cnic == acc.get_CNIC())
                               {
                                found = true;
                                cout<<"\n\t\t\t\tAccount Found "<<acc.First_Name<<" "<<acc.Last_Name<<".";
                                cout<<"\n\t\t\t\tEnter Your PIN: ";
                                cin>>pin;
                                if (pin == acc.get_PIN())
                                   {
                                    cout<<"\n\t\t\t\tHow Much Money You Want to Withdraw? $";
                                    cin>>Withdraw;
                                    if (acc.get_Balance() >= Withdraw)
                                       {
                                        acc.set_Balance(acc.get_Balance() - Withdraw);
                                        cout<<"\n\t\t\t\tTotal Balance: "<<acc.get_Balance()<<" $";
                                       }
                                    else
                                        {
                                         cout<<"\n\n\t\t\t\t\t\tInsufficient Balance!";
                                        }
                                    }
                                else
                                    {
                                     cout<<"\n\n\t\t\t\t\t\tERROR... TRY AGAIN... ";
                                    }
                                break;
                               }
                           }
                       if (!found)
                          {
                           cout<<"\n\n\t\t\t\t\t\tERROR... CNIC NOT FOUND... ";
                          }
                       break;
                      } 
			    case 4:
                      {
                       int pin;
                       long long int cnic;
                       cout<<"\n\t\t\t\tEnter Your CNIC: ";
                       cin>>cnic;
                       bool found = false;
                       for (auto &acc : accounts)
                           {
                            if (cnic == acc.get_CNIC())
                               {
                                found = true;
                                cout<<"\n\t\t\t\tAccount Found "<<acc.First_Name<<" "<<acc.Last_Name<<".";
                                cout<<"\n\t\t\t\tEnter Your PIN: ";
                                cin>>pin;
                                if (pin == acc.get_PIN())
                                   {
                                    cout<<"\n\t\t\t\tTotal Balance: "<<acc.get_Balance()<<" $";
                                   }
                                else
                                    {
                                     cout<<"\n\n\t\t\t\t\t\tERROR... TRY AGAIN... ";
                                    }
                                break;
                               }
                           }
                       if (!found)
                          {
                           cout<<"\n\n\t\t\t\t\t\tERROR... CNIC NOT FOUND... ";
                          }
                       break;
                      }
                case 5:
                      {
                       long long int cnic;
                       cout<<"\n\t\t\t\tEnter Your CNIC: ";
                       cin>>cnic;
                       bool found = false;
                       for (auto &acc : accounts)
                           {
                            if (cnic == acc.get_CNIC())
                               {
                                found = true;
                                cout<<"\n\t\t\t\tName: "<<acc.First_Name<<" "<<acc.Last_Name;
                                cout<<"\n\t\t\t\tIBAN: BANK"<<acc.get_IBAN();
                                cout<<"\n\t\t\t\tBalance: $"<<acc.get_Balance();
                                cout<<"\n\t\t\t\tYour Account Was Created on "<<acc.get_formatted_time();
                                break;
                               }
                           }
                       if (!found)
                          {
                           cout<<"\n\n\t\t\t\t\t\tERROR... CNIC NOT FOUND... ";
                          }
                       break;
                      }
				case 6:
				      {
				       cout<<"\n\n\t\t\t\t\t\tEXITING ... ";
					   return 0;	
					  }
				default:
				       cout<<"\n\n\t\t\t\t\t\tERROR ... ";          
		       }
       }
 return 0;
}    