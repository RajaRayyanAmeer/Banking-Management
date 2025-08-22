#include<iostream>
#include<fstream>
using namespace std;
struct bank
{
 int new_user();
 int display();
 int check_balance();
 int withdraw_money();
 int transfer();
};
int main()
{
 struct bank m;
 int a;
 for(int i=1;i<=10;i++)
    {
     if(i>1 && i<=10);
     system("cls");
     m.display();
     cout<<"\n\n (ENTER -1 Turn off \nBMS)";
     cout<<endl;
     cout<<"\nENTER OPTION : ";
     cin>>a;
     cout<<"\a";
     if(a == -1)
        break;
     if(i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9 || i == 10);
     cout<<"\nWELCOME AGAIN\n\n";
     switch(a)
           {
            case 1:
            {
             m.new_user();
             break;
            }
            case 2:
            {
             m.check_balance();
             break;
            }
            case 3:
            {
             m.withdraw_money();
             break;
            }
            case 4:
            {
             m.transfer();
             break;
            }
           }
    }
     system("cls");
     cout<<"\nTHANK YOU FOR CHOOSING STUDENTS BMS\n";
     cout<<"HAVE A NICE DAY !";
}
int bank::display()
{
 cout<<"\t\t\t\t"<<endl;
 cout<<"\t\t\t\t\t"<<endl;
 cout<<"\t\t\t\t\tBANK MANAGEMENT SYSTEM"<<endl;
 cout<<"\t\t\t\t\t"<<endl;
 cout<<"\t\t\t\t"<<endl;
 cout<<"\n\n\t\t\t[1] New user ";
 cout<<"\n\n\t\t\t[2] Check Balance ";
 cout<<"\n\n\t\t\t[3] Withraw Balance ";
 cout<<"\n\n\t\t\t[4] Transfering money";
}
int bank::new_user()
{
 system("cls");
 fstream file;
 long long pass, cn, iban, amount;
 cout<<"\n\n\t\t\t ADD new account";
 cout<<"\n WELCOME NEW USER\n";
 cout<<"\n\n Enter Your FOUR Digit passward:";
 cin>>pass;
 cout<<"\a";
 cout<<"\n\n Enter Your CNIC Number:";
 cin>>cn;
 cout<<"\a";
 cout<<"\n\n Enter Your Sixteen Digit IBAN Provided By Bank:";
 cin>>iban;
 cout<<"\a";
 cout<<"\n\n Enter Your Amount:";
 cin>>amount;
 cout<<"\a";
 file.open("hbl.txt",ios::out|ios::app);
 file<<" "<<pass<<" "<<cn<<" "<<iban<<" "<<amount<<endl;
 file.close();
 cout<<endl;
 system("pause");
}
int bank::check_balance()
{
 system("cls");
 fstream file;
 long long amount,count=0;
 long long pass,cn,iban,pass1;
 cout<<"\n\n\t\t\t\tCheck Balance";
 file.open("hbl.txt",ios::in);
 if(!file)
    cout << "\n\n File Opening Error...";
 else
     {
      cout<<"\n\n Enter FOUR Digit PIN Code:";
      cin>>pass1;
      cout<<"\a";
      while(file>>pass>>cn>>iban>>amount)
           {
            if(pass1 == pass)
              {
               system("cls");
               cout<<"\n\n\t\t\t\tCheck Balance:";
               cout<<"\n\n\t\t\tYour Current Balance is:"<<amount;
               count++;
               break;
              }
           }
       file.close();
       if (count == 0)
          cout << "\n\n  Your account not found contact concern authorities...";
     }
      cout << endl;
      system("pause");
}
int bank::withdraw_money()
{
 system("cls");
 fstream file,tempFile;
 long long amount,count=0;
 long long pass1,cn,iban,pass;
 long long withdraw;
 cout<<"\n\n\t\t\t\tWithdraw Balance";
 file.open("hbl.txt",ios::in|ios::out);
 tempFile.open("temp.txt",ios::out);
 if(!file||!tempFile)
    {
     cout << "\n\n File Opening Error...";
    }
 else
     {
      cout<<"\n\n Enter FOUR Digit PIN Code:";
      cin>>pass;
      cout<<"\a";
      while(file >> pass1 >> cn >> iban >> amount)
        {
         if(pass == pass1)
            {
             system("cls");
             cout<<"\n\n\t\t\t\tWithdraw Balance:";
             cout<<"\n\nYour withdraw Amount is";
             cin>>withdraw;
             cout<<"\a";
             amount=amount-withdraw;
             cout<<"\n\n\t\t\tYour Current Balance is:"<<amount;
             tempFile<<pass1<<" "<<cn<<" "<<iban<<" "<<amount<<"\n";
             count++;
            }
         else
             {
              tempFile<<pass1<<" " <<cn<<" "<<iban<<" "<<amount<<"\n";
            }
        }
        file.close();
        tempFile.close();
        remove("hbl.txt");
        rename("temp.txt","hbl.txt");
        if(count==0)
           cout<<"\n\n Your account not found contact concern authorities...";
     }
      cout<<endl;
      system("pause");
}
int bank::transfer()
{
 system("cls");
 fstream file,tempFile;
 long long amount,count=0;
 long long pass1,cn,iban,pass;
 long long transfer;
 cout<<"\n\n\t\t\t\tTransfer Balance";
 file.open("hbl.txt",ios::in|ios::out);
 tempFile.open("temp.txt",ios::out);
 if(!file||!tempFile)
    {
     cout<<"\n\n File Opening Error...";
    }
 else
     {
      cout<<"\n\n Enter FOUR Digit PIN Code:";
      cin>>pass;
      cout<<"\a";
      while(file >> pass1 >> cn >> iban >> amount)
           {
            if(pass == pass1)
              {
               system("cls");
               cout<<"\n\n\t\t\t\tTransfer Balance:";
               cout<<"\n\nYour Transfer Amount is";
               cin>>transfer;
               cout<<"\a";
               amount=amount-transfer;
               cout<<"\n\n\t\t\tYour Current Balance is:"<<amount;
               tempFile<<pass1<<" "<<cn<<" "<<iban<<" "<<amount<<"\n";
               count++;
              }
            else
               {
                tempFile<<pass1<<" "<<cn<<" "<<iban<<" "<<amount<<"\n";
               }
           }
    file.close();
    tempFile.close();
    remove("hbl.txt");
    rename("temp.txt", "hbl.txt");
    if(count == 0)
       cout<<"\n\n Your account not found contact concern authorities...";
    }
     cout<<endl;
     system("pause");
}                     