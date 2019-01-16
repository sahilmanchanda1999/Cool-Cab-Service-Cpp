#include<iostream>
#include<conio.h>
#include<windows.h>


#include<fstream>


using namespace std;

void loginpage();
void login();
void registr();
void forgot();
void afterlogin();
void bookingfromjalandhartoamritsar();
void bookingfromjalandhartodelhi();
void bookingfromjalandhartomanali();
void bookingfromjalandhartochandigarh();
void rentcard();
void adminlogin();
void gotoxy(int x,int y)
{
COORD c;
    c.X=x;
    c.Y=y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
main()
{
    system("COLOR cF");
    gotoxy(38,5);
    cout<<"----------------*********-----------------\n";
    gotoxy(38,6);cout<<"\t\tWELCOME TO HEXI CAB SERVICE\n";
    gotoxy(38,7);cout<<"----------------*********-----------------\n";
     gotoxy(40,12);
    cout<<"Loading......";
    int x=0;
    for(int i=1;i<=10;i++)
    {


        gotoxy(40+x,13);
        Sleep(500);
        cout<<"||||||||||||";
        x=x+1;
        gotoxy(62,13);
        cout<<i<<"0%";
    }
    gotoxy(45,14);
    cout<<"complete";
    Sleep(200);
    cout<<"!";
    Sleep(200);
    cout<<"!";
    Sleep(300);
    gotoxy(55,21);
    cout<<"Press Enter to Continue";
    getch();
    system("cls");
    loginpage();

}

void loginpage()
{system("cls");
loginpage:
        int choice;

        cout<<"                      Welcome to login page                               \n\n";
        cout<<"*******************        MENU        *******************************\n\n";
        cout<<"1.ADMIN LOGIN\n"<<endl;
        cout<<"2.LOGIN\n"<<endl;
        cout<<"3.REGISTER\n"<<endl;
        cout<<"4.FORGOT PASSWORD (or) USERNAME\n"<<endl;
        cout<<"5.Exit\n"<<endl;
        cout<<"\nEnter your choice :";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
        case 2:
            {
                login();
                break;
            }
        case 3:
            registr();
            break;
        case 4:
            forgot();
            break;
        case 5:
            {
            cout<<"\n\n\n\t\t\tThank you";

            exit(0);
            }

        case 1:
        {
            adminlogin();
            break;
        }
        default:
            {


            system("cls");
                        cout<<"You've made a mistake , give it a try again\n"<<endl;
                        goto loginpage;

            }
        }
}

void registr()
{
    string reguser,regpass,ru,rp;
    system("cls");
        cout<<"Enter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;
        ofstream reg("looooogin.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\nRegistration Sucessful\n";
        getch();
        system("cls");
        loginpage();

}

void login()
{
        loginn:
    int count;
        string user,pass,u,p;
        system("cls");
        cout<<"please enter the following details"<<endl;
        cout<<"USERNAME :";
        cin>>user;
        cout<<"PASSWORD :";
        cin>>pass;
        ifstream input("looooogin.txt");
        while(input>>u>>p)
        {
            if(u==user && p==pass)

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
            cout<<"\nHello "<<user<<"\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n";
                getch();
                afterlogin();
        }
        else{
            cout<<"\nLOGIN ERROR\nPlease check your username and password\n";

            cout<<"\t\tRetry(y/n): ";
            char ret;
            cin>>ret;
            if(ret=='y' || ret=='Y')
            {
                goto loginn;

            }
            else
            {
                system("cls");
                loginpage();
            }


        }

}

void forgot()
{

    int ch;
        system("cls");
        cout<<"Forgotten ? We're here for help\n";
        cout<<"1.Search your id by username"<<endl;
        cout<<"2.Search your id by password"<<endl;
        cout<<"3.Main menu"<<endl;
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch)
        {
            case 1:
            	{
            		int count=0;
                        string searchuser,su,sp;
                        cout<<"\nEnter your remembered username :";
                        cin>>searchuser;

                        ifstream searchu("looooogin.txt");
                        searchu.seekg(0);
                        while(!searchu.eof())
                        {	searchu>>su>>sp;
                                if(su==searchuser)
                                {
                                        count=1;
                                        break;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                            cout<<"\n\nHurray, account found\n";
                                cout<<"\nYour password is "<<sp;
                                getch();
                                system("cls");
                                loginpage();
                        }
                        else
                        {
                                cout<<"\nSorry, Your userID is not found in our database\n";
                                cout<<"\nPlease kindly contact your system administrator for more details \n";
                                getch();
loginpage();
                        }
                        break;

				}

        case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\nEnter the remembered password :";
                        cin>>searchpass;

                        ifstream searchp("looooogin.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                        break;
                                }
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\nYour password is found in the database \n";
                                cout<<"\nYour Id is : "<<su2;
                                getch();

                                system("cls");
                                loginpage();
                        }
                        else
                        {
                                cout<<"Sorry, We cannot found your password in our database \n";
                                cout<<"\nkindly contact your administrator for more information\n";
                                getch();
								loginpage();
                        }

                        break;
                }
            case 3:
                {
                        getch();
                        loginpage();
                }
                default:
                        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
                        forgot();
        }}

  void afterlogin()
  {
      int choice;
afterlogin:
system("CLS");
 cout<<"\t********************"<<endl;
 cout<<"\t*    Customer        *"<<endl;
 cout<<"\t********************"<<endl;
 cout<<endl;
 cout<<endl;
    cout<<"<1> Booking"<<endl;
 cout<<endl;
 cout<<"<2> Rent Card    "<<endl;
 cout<<endl;
 cout<<"<3> To LogOut         "<<endl;
    cout<<endl;
    cout<<"Select:";
       cin>>choice;
       switch(choice)
       {
       case 1:                                          //***********booking***********
        {    x:
            system("cls");
             char Wish;
                  int Choice;
               cout<<"\t********************"<<endl;
               cout<<"\t*    Booking        *"<<endl;
               cout<<"\t********************"<<endl;
               cout<<endl;
                  cout<<endl;
                  cout<<"<1> To Book Cab From Jalandhar To Delhi"<<endl;
               cout<<endl;
               cout<<"<2> To Book Cab From Jalandhar To Amritsar"<<endl;
               cout<<endl;
               cout<<"<3> To Book Cab From Jalandhar To Manali"<<endl;
               cout<<endl;
               cout<<"<4> To Book Cab From jalandhar To Chandigarh"<<endl;
               cout<<endl;
               cout<<"<5> To Go Back to Previous Menu"<<endl;
               cout<<endl;
                  cout<<"Select :";
                  cin>>choice;
                  switch(choice)
                  {
                  case 1:
                        {


                        bookingfromjalandhartodelhi();
                        getch();
                        goto afterlogin;
                        break;
                        }
                  case 2:
                    {
                        bookingfromjalandhartoamritsar();
                       getch();
                        goto afterlogin;
                         break;
                    }
                  case 3:
                    {
                        bookingfromjalandhartomanali();
                        getch();
                        goto afterlogin;
                        break;
                    }
                  case 4:
                    {
                        bookingfromjalandhartochandigarh();
                    getch();
                        goto afterlogin;
                    break;
                    }
                  case 5:
                                 {
                        system("cls");
                        goto afterlogin;
                    }

                  }

        }
                  case 2:
                      {
                          rentcard();
                          getch();

                      }
                  case 3:
                    {
                        system("cls");
                        loginpage();
                    }


       }

  }

void bookingfromjalandhartodelhi()
    {
        ofstream CustRec;
        CustRec.open("Customer Record.txt",ios::app);
        ofstream CanceledRec;
        CanceledRec.open("canceled Record.txt",ios::app);
system("cls");
string Name;
float Charges,Distance,ChargesPerKm;
int choo,timecharge;
cout<<"\t\t\tjalandhar to delhi";
cout<<"--------------------------------------"<<endl;
    cout<<"|GuIdE LiNes WhIlE FiLlInG The fOrM: |"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<endl;
    cout<<"After Entering Your Name Put FullStop After Ending The NAme.\n";
    cout<<"Your Must Put Fullstop at The End If You Didn't So Program \n";
    cout<<"Will Not Go Further.\n\n";
    cout << "What is your NAme : ";
    getline(cin,Name,'.');

    cout <<"\nDrop:Delhi";
 cout <<"\nDistance: 386Km";
 cout<<"\nchoose category of your car: ";
 choose:
 cout<<"\n1.Micro\n2.Mini\n3.Prime Sedan\n";
 cin>>choo;
 switch(choo)
 {
 case 1:
    {

        Distance=386;
        ChargesPerKm=6;
        timecharge=2*Distance;
      cout<<"\n\nYou have selected Micro Car\n\n";
      Charges=Distance*ChargesPerKm+timecharge;
       cout <<"\n\nCharges: Rs"<< Charges<<"\n\n";
       char PaidCharges;
 cout<<"Did You PAy The Charges(Y/N) :- ";
 PaidCharges=getch();
 if(PaidCharges=='y' || PaidCharges=='Y')
    {

   cout<<"\n\nYour Booking Has Been Done\n";
   CustRec<<"\n\t\tCustomer Record\n";
   CustRec<<"\nNAme : "<<Name;
   CustRec<<"\nPick : Jalandhar";
   CustRec<<"\nDrop:Delhi";
   CustRec<<"\nDistance: 386Km";
   CustRec<<"\nBy Micro Car";
   CustRec<<"\nCharges: Rs"<< Charges<<"\n\n";
   CustRec.close();
   break;

    }
else
{
cout<<"Your Booking HAs BEen Canceled Due to Unpaid Charge. \n";
  CanceledRec<<"\n\t\tBooking Canceled\n";
  CanceledRec<< "\nNAme : "<< Name;
  CanceledRec<<"\nPick : Jalandhar";
  CanceledRec<<"\nDrop:Delhi";
  CanceledRec<<"\nDistance: 386Km";
  CanceledRec<<"\nBy Micro Car";
  CanceledRec<<"\nCharges: Rs"<< Charges<<"\n\n";
  CanceledRec.close();
break;}


    }
 case 2:
    {
        Distance=386;
        ChargesPerKm=14;
        timecharge=2*Distance;
      cout<<"By Mini\n\n";
      Charges=Distance*ChargesPerKm+timecharge;
       cout <<"\n\nCharges: Rs"<< Charges<<"\n\n";
       char PaidCharges;
 cout<<"Did You PAy The Charges(Y/N) :- ";
 PaidCharges=getch();
 if(PaidCharges=='y' || PaidCharges=='Y')
    {

   cout<<"\n\nYour Booking Has Been Done\n";
   CustRec<<"\n\t\tCustomer Record\n";
   CustRec<<"\nNAme : "<<Name;
   CustRec<<"\nPick : Jalandhar";
   CustRec<<"\nDrop:Delhi";
   CustRec<<"\nDistance: 386Km";
   CustRec<<"\nBy Mini Car";
   CustRec<<"\nCharges: Rs"<< Charges<<"\n\n";
   CustRec.close();
break;
    }
else
{
cout<<"Your Booking HAs BEen Canceled Due to Unpaid Charge. \n";
  CanceledRec<<"\n\t\tBooking Canceled\n";
  CanceledRec<< "\nNAme : "<< Name;
  CanceledRec<<"\nPick : Jalandhar";
  CanceledRec<<"\nDrop:Delhi";
  CanceledRec<<"\nDistance: 386Km";
  CanceledRec<<"\nBy Mini Car";
  CanceledRec<<"\nCharges: Rs"<< Charges<<"\n\n";
  CanceledRec.close();
break;}
    }
 case 3:
    {
        Distance=386;
        ChargesPerKm=16;
        timecharge=2*Distance;
      cout<<"By Prime\n\n";
      Charges=Distance*ChargesPerKm+timecharge;
       cout <<"\n\nCharges: Rs"<< Charges<<"\n\n";
       char PaidCharges;
 cout<<"Did You PAy The Charges(Y/N) :- ";
 PaidCharges=getch();
 if(PaidCharges=='y' || PaidCharges=='Y')
    {

   cout<<"\n\nYour Booking Has Been Done\n";
   CustRec<<"\n\t\tCustomer Record\n";
   CustRec<<"\nNAme : "<<Name;
   CustRec<<"\nPick : Jalandhar";
   CustRec<<"\nDrop:Delhi";
   CustRec<<"\nDistance: 386Km";
   CustRec<<"\nBy Prime Car";
   CustRec<<"\nCharges: Rs"<< Charges<<"\n\n";
   CustRec.close();
break;
    }
else
{
cout<<"Your Booking HAs BEen Canceled Due to Unpaid Charge. \n";
  CanceledRec<<"\n\t\tBooking Canceled\n";
  CanceledRec<< "\nNAme : "<< Name;
  CanceledRec<<"\nPick : Jalandhar";
  CanceledRec<<"\nDrop:Delhi";
  CanceledRec<<"\nDistance: 386Km";
  CanceledRec<<"\nBy Prime Car";
  CanceledRec<<"\nCharges: Rs"<< Charges<<"\n\n";
  CanceledRec.close();
break;}

    }
 default:
    {
        cout<<"please choose correct option: \n";
        getch();
        system("cls");
        goto choose;
    }
 }




    }

    void bookingfromjalandhartoamritsar()
    {
         ofstream CustRec;
        CustRec.open("Customer Record.txt",ios::app);
        ofstream CanceledRec;
        CanceledRec.open("canceled Record.txt",ios::app);
system("cls");
string Name;
float Charges,Distance,ChargesPerKm;
int choo,timecharge;
cout<<"\t\t\tjalandhar to Amritsar";
cout<<"--------------------------------------"<<endl;
    cout<<"|GuIdE LiNes WhIlE FiLlInG The fOrM: |"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<endl;
    cout<<"After Entering Your Name Put FullStop After Ending The NAme.\n";
    cout<<"Your Must Put Fullstop at The End If You Didn't So Program \n";
    cout<<"Will Not Go Further.\n";
    cout << "What is your NAme : ";
    getline(cin,Name,'.');

    cout <<"\nDrop:Amritsar";
 cout <<"\nDistance: 82Km";
 cout<<"choose category of your car: \n";
 choose:
 cout<<"1.Micro\n2.Mini\n3.Prime Sedan\n";
 cin>>choo;
 switch(choo)
 {
 case 1:
    {

        Distance=82;
        ChargesPerKm=6;
        timecharge=2*Distance;
      cout<<"By Micro\n\n";
      Charges=Distance*ChargesPerKm+timecharge;
       cout <<"\n\nCharges: Rs"<< Charges<<"\n\n";
       char PaidCharges;
 cout<<"Did You PAy The Charges(Y/N) :- ";
 PaidCharges=getch();
 if(PaidCharges=='y' || PaidCharges=='Y')
    {

   cout<<"\n\nYour Booking Has Been Done\n";
   CustRec<<"\n\t\tCustomer Record\n";
   CustRec<<"\nNAme : "<<Name;
   CustRec<<"\nPick : Jalandhar";
   CustRec<<"\nDrop:Amritsar";
   CustRec<<"\nDistance: 82Km";
   CustRec<<"\nBy Micro Car";
   CustRec<<"\nCharges: Rs"<< Charges<<"\n\n";
   CustRec.close();
   break;

    }
else
{
cout<<"Your Booking HAs BEen Canceled Due to Unpaid Charge. \n";
  CanceledRec<<"\n\t\tBooking Canceled\n";
  CanceledRec<< "\nNAme : "<< Name;
  CanceledRec<<"\nPick : Jalandhar";
  CanceledRec<<"\nDrop:Amritsar";
  CanceledRec<<"\nDistance: 82Km";
  CanceledRec<<"\nBy Micro Car";
  CanceledRec<<"\nCharges: Rs"<< Charges<<"\n\n";
  CanceledRec.close();
break;}


    }
 case 2:
    {
        Distance=82;
        ChargesPerKm=14;
        timecharge=2*Distance;
      cout<<"By Mini\n\n";
      Charges=Distance*ChargesPerKm+timecharge;
       cout <<"\n\nCharges: Rs"<< Charges<<"\n\n";
       char PaidCharges;
 cout<<"Did You PAy The Charges(Y/N) :- ";
 PaidCharges=getch();
 if(PaidCharges=='y' || PaidCharges=='Y')
    {

   cout<<"\n\nYour Booking Has Been Done\n";
   CustRec<<"\n\t\tCustomer Record\n";
   CustRec<<"\nNAme : "<<Name;
   CustRec<<"\nPick : Jalandhar";
   CustRec<<"\nDrop:Amritsar";
   CustRec<<"\nDistance: 82Km";
   CustRec<<"\nBy Mini Car";
   CustRec<<"\nCharges: Rs"<< Charges<<"\n\n";
   CustRec.close();
break;
    }
else
{
cout<<"Your Booking HAs BEen Canceled Due to Unpaid Charge. \n";
  CanceledRec<<"\n\t\tBooking Canceled\n";
  CanceledRec<< "\nNAme : "<< Name;
  CanceledRec<<"\nPick : Jalandhar";
  CanceledRec<<"\nDrop:Amritsar";
  CanceledRec<<"\nDistance: 82Km";
  CanceledRec<<"\nBy Mini Car";
  CanceledRec<<"\nCharges: Rs"<< Charges<<"\n\n";
  CanceledRec.close();
break;}
    }
 case 3:
    {
        Distance=82;
        ChargesPerKm=16;
        timecharge=2*Distance;
      cout<<"By Prime\n\n";
      Charges=Distance*ChargesPerKm+timecharge;
       cout <<"\n\nCharges: Rs"<< Charges<<"\n\n";
       char PaidCharges;
 cout<<"Did You PAy The Charges(Y/N) :- ";
 PaidCharges=getch();
 if(PaidCharges=='y' || PaidCharges=='Y')
    {

   cout<<"\n\nYour Booking Has Been Done\n";
   CustRec<<"\n\t\tCustomer Record\n";
   CustRec<<"\nNAme : "<<Name;
   CustRec<<"\nPick : Jalandhar";
   CustRec<<"\nDrop:Amritsar";
   CustRec<<"\nDistance: 82Km";
   CustRec<<"\nBy Prime Car";
   CustRec<<"\nCharges: Rs"<< Charges<<"\n\n";
   CustRec.close();
break;
    }
else
{
cout<<"Your Booking HAs BEen Canceled Due to Unpaid Charge. \n";
  CanceledRec<<"\n\t\tBooking Canceled\n";
  CanceledRec<< "\nNAme : "<< Name;
  CanceledRec<<"\nPick : Jalandhar";
  CanceledRec<<"\nDrop:Amritsar";
  CanceledRec<<"\nDistance: 82Km";
  CanceledRec<<"\nBy Prime Car";
  CanceledRec<<"\nCharges: Rs"<< Charges<<"\n\n";
  CanceledRec.close();
break;}

    }
 default:
    {
        cout<<"please choose correct option: \n";
        getch();
        system("cls");
        goto choose;
    }
 }


 }



    void bookingfromjalandhartomanali()
    {
ofstream CustRec;
        CustRec.open("Customer Record.txt",ios::app);
        ofstream CanceledRec;
        CanceledRec.open("canceled Record.txt",ios::app);
system("cls");
string Name;
float Charges,Distance,ChargesPerKm;
int choo,timecharge;
cout<<"\t\t\tjalandhar to Manali";
cout<<"--------------------------------------"<<endl;
    cout<<"|GuIdE LiNes WhIlE FiLlInG The fOrM: |"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<endl;
    cout<<"After Entering Your Name Put FullStop After Ending The NAme.\n";
    cout<<"Your Must Put Fullstop at The End If You Didn't So Program \n";
    cout<<"Will Not Go Further.\n";
    cout << "What is your NAme : ";
    getline(cin,Name,'.');

    cout <<"\nDrop:Manali";
 cout <<"\nDistance: 368.1Km";
 cout<<"choose category of your car: \n";
 choose:
 cout<<"1.Micro\n2.Mini\n3.Prime Sedan\n";
 cin>>choo;
 switch(choo)
 {
 case 1:
    {

        Distance=368;
        ChargesPerKm=6;
        timecharge=2*Distance;
      cout<<"By Micro\n\n";
      Charges=Distance*ChargesPerKm+timecharge;
       cout <<"\n\nCharges: Rs"<< Charges<<"\n\n";
       char PaidCharges;
 cout<<"Did You PAy The Charges(Y/N) :- ";
 PaidCharges=getch();
 if(PaidCharges=='y' || PaidCharges=='Y')
    {

   cout<<"\n\nYour Booking Has Been Done\n";
   CustRec<<"\n\t\tCustomer Record\n";
   CustRec<<"\nNAme : "<<Name;
   CustRec<<"\nPick : Jalandhar";
   CustRec<<"\nDrop:Manali";
   CustRec<<"\nDistance: 368Km";
   CustRec<<"\nBy Micro Car";
   CustRec<<"\nCharges: Rs"<< Charges<<"\n\n";
   CustRec.close();
   break;

    }
else
{
cout<<"Your Booking HAs BEen Canceled Due to Unpaid Charge. \n";
  CanceledRec<<"\n\t\tBooking Canceled\n";
  CanceledRec<< "\nNAme : "<< Name;
  CanceledRec<<"\nPick : Jalandhar";
  CanceledRec<<"\nDrop:Manali";
  CanceledRec<<"\nDistance: 368Km";
  CanceledRec<<"\nBy Micro Car";
  CanceledRec<<"\nCharges: Rs"<< Charges<<"\n\n";
  CanceledRec.close();
break;}


    }
 case 2:
    {
        Distance=398;
        ChargesPerKm=14;
        timecharge=2*Distance;
      cout<<"By Mini\n\n";
      Charges=Distance*ChargesPerKm+timecharge;
       cout <<"\n\nCharges: Rs"<< Charges<<"\n\n";
       char PaidCharges;
 cout<<"Did You PAy The Charges(Y/N) :- ";
 PaidCharges=getch();
 if(PaidCharges=='y' || PaidCharges=='Y')
    {

   cout<<"\n\nYour Booking Has Been Done\n";
   CustRec<<"\n\t\tCustomer Record\n";
   CustRec<<"\nNAme : "<<Name;
   CustRec<<"\nPick : Jalandhar";
   CustRec<<"\nDrop:Manali";
   CustRec<<"\nDistance: 368Km";
   CustRec<<"\nBy Mini Car";
   CustRec<<"\nCharges: Rs"<< Charges<<"\n\n";
   CustRec.close();
break;
    }
else
{
cout<<"Your Booking HAs BEen Canceled Due to Unpaid Charge. \n";
  CanceledRec<<"\n\t\tBooking Canceled\n";
  CanceledRec<< "\nNAme : "<< Name;
  CanceledRec<<"\nPick : Jalandhar";
  CanceledRec<<"\nDrop:Manali";
  CanceledRec<<"\nDistance: 368Km";
  CanceledRec<<"\nBy Mini Car";
  CanceledRec<<"\nCharges: Rs"<< Charges<<"\n\n";
  CanceledRec.close();
break;}
    }
 case 3:
    {
        Distance=368;
        ChargesPerKm=16;
        timecharge=2*Distance;
      cout<<"By Prime\n\n";
      Charges=Distance*ChargesPerKm+timecharge;
       cout <<"\n\nCharges: Rs"<< Charges<<"\n\n";
       char PaidCharges;
 cout<<"Did You PAy The Charges(Y/N) :- ";
 PaidCharges=getch();
 if(PaidCharges=='y' || PaidCharges=='Y')
    {

   cout<<"\n\nYour Booking Has Been Done\n";
   CustRec<<"\n\t\tCustomer Record\n";
   CustRec<<"\nNAme : "<<Name;
   CustRec<<"\nPick : Jalandhar";
   CustRec<<"\nDrop:Manali";
   CustRec<<"\nDistance: 368Km";
   CustRec<<"\nBy Prime Car";
   CustRec<<"\nCharges: Rs"<< Charges<<"\n\n";
   CustRec.close();
break;
    }
else
{
cout<<"Your Booking HAs BEen Canceled Due to Unpaid Charge. \n";
  CanceledRec<<"\n\t\tBooking Canceled\n";
  CanceledRec<< "\nNAme : "<< Name;
  CanceledRec<<"\nPick : Jalandhar";
  CanceledRec<<"\nDrop:Manali";
  CanceledRec<<"\nDistance: 368Km";
  CanceledRec<<"\nBy Prime Car";
  CanceledRec<<"\nCharges: Rs"<< Charges<<"\n\n";
  CanceledRec.close();
break;}

    }
 default:
    {
        cout<<"please choose correct option: \n";
        getch();
        system("cls");
        goto choose;
    }
 }




    }
    void bookingfromjalandhartochandigarh()
    {


ofstream CustRec;
        CustRec.open("Customer Record.txt",ios::app);
        ofstream CanceledRec;
        CanceledRec.open("canceled Record.txt",ios::app);
system("cls");
string Name;
float Charges,Distance,ChargesPerKm;
int choo,timecharge;
cout<<"\t\t\tjalandhar to Chandigarh";
cout<<"--------------------------------------"<<endl;
    cout<<"|GuIdE LiNes WhIlE FiLlInG The fOrM: |"<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<endl;
    cout<<"After Entering Your Name Put FullStop After Ending The NAme.\n";
    cout<<"Your Must Put Fullstop at The End If You Didn't So Program \n";
    cout<<"Will Not Go Further.\n";
    cout << "What is your NAme : ";
    getline(cin,Name,'.');

    cout <<"\nDrop:Manali";
 cout <<"\nDistance: 148Km";
 cout<<"choose category of your car: \n";
 choose:
 cout<<"1.Micro\n2.Mini\n3.Prime Sedan\n";
 cin>>choo;
 switch(choo)
 {
 case 1:
    {

        Distance=148;
        ChargesPerKm=6;
        timecharge=2*Distance;
      cout<<"By Micro\n\n";
      Charges=Distance*ChargesPerKm+timecharge;
       cout <<"\n\nCharges: Rs"<< Charges<<"\n\n";
       char PaidCharges;
 cout<<"Did You PAy The Charges(Y/N) :- ";
 PaidCharges=getch();
 if(PaidCharges=='y' || PaidCharges=='Y')
    {

   cout<<"\n\nYour Booking Has Been Done\n";
   CustRec<<"\n\t\tCustomer Record\n";
   CustRec<<"\nNAme : "<<Name;
   CustRec<<"\nPick : Jalandhar";
   CustRec<<"\nDrop:Chandigarh";
   CustRec<<"\nDistance: 148Km";
   CustRec<<"\nBy Micro Car";
   CustRec<<"\nCharges: Rs"<< Charges<<"\n\n";
   CustRec.close();
   break;

    }
else
{
cout<<"Your Booking HAs BEen Canceled Due to Unpaid Charge. \n";
  CanceledRec<<"\n\t\tBooking Canceled\n";
  CanceledRec<< "\nNAme : "<< Name;
  CanceledRec<<"\nPick : Jalandhar";
  CanceledRec<<"\nDrop:Chandigarh";
  CanceledRec<<"\nDistance: 148Km";
  CanceledRec<<"\nBy Micro Car";
  CanceledRec<<"\nCharges: Rs"<< Charges<<"\n\n";
  CanceledRec.close();
break;}


    }
 case 2:
    {
        Distance=148;
        ChargesPerKm=14;
        timecharge=2*Distance;
      cout<<"By Mini\n\n";
      Charges=Distance*ChargesPerKm+timecharge;
       cout <<"\n\nCharges: Rs"<< Charges<<"\n\n";
       char PaidCharges;
 cout<<"Did You PAy The Charges(Y/N) :- ";
 PaidCharges=getch();
 if(PaidCharges=='y' || PaidCharges=='Y')
    {

   cout<<"\n\nYour Booking Has Been Done\n";
   CustRec<<"\n\t\tCustomer Record\n";
   CustRec<<"\nNAme : "<<Name;
   CustRec<<"\nPick : Jalandhar";
   CustRec<<"\nDrop:Chandigarh";
   CustRec<<"\nDistance: 148Km";
   CustRec<<"\nBy Mini Car";
   CustRec<<"\nCharges: Rs"<< Charges<<"\n\n";
   CustRec.close();
break;
    }
else
{
cout<<"Your Booking HAs BEen Canceled Due to Unpaid Charge. \n";
  CanceledRec<<"\n\t\tBooking Canceled\n";
  CanceledRec<< "\nNAme : "<< Name;
  CanceledRec<<"\nPick : Jalandhar";
  CanceledRec<<"\nDrop:Chandigarh";
  CanceledRec<<"\nDistance: 148Km";
  CanceledRec<<"\nBy Mini Car";
  CanceledRec<<"\nCharges: Rs"<< Charges<<"\n\n";
  CanceledRec.close();
break;}
    }
 case 3:
    {
        Distance=148;
        ChargesPerKm=16;
        timecharge=2*Distance;
      cout<<"By Prime\n\n";
      Charges=Distance*ChargesPerKm+timecharge;
       cout <<"\n\nCharges: Rs"<< Charges<<"\n\n";
       char PaidCharges;
 cout<<"Did You PAy The Charges(Y/N) :- ";
 PaidCharges=getch();
 if(PaidCharges=='y' || PaidCharges=='Y')
    {

   cout<<"\n\nYour Booking Has Been Done\n";
   CustRec<<"\n\t\tCustomer Record\n";
   CustRec<<"\nNAme : "<<Name;
   CustRec<<"\nPick : Jalandhar";
   CustRec<<"\nDrop:Chandigarh";
   CustRec<<"\nDistance: 148Km";
   CustRec<<"\nBy Prime Car";
   CustRec<<"\nCharges: Rs"<< Charges<<"\n\n";
   CustRec.close();
break;
    }
else
{
cout<<"Your Booking HAs BEen Canceled Due to Unpaid Charge. \n";
  CanceledRec<<"\n\t\tBooking Canceled\n";
  CanceledRec<< "\nNAme : "<< Name;
  CanceledRec<<"\nPick : Jalandhar";
  CanceledRec<<"\nDrop:Chandigarh";
  CanceledRec<<"\nDistance: 148Km";
  CanceledRec<<"\nBy Prime Car";
  CanceledRec<<"\nCharges: Rs"<< Charges<<"\n\n";
  CanceledRec.close();
break;}

    }
 default:
    {
        cout<<"please choose correct option: \n";
        getch();
        system("cls");
        goto choose;
    }
 }
     }

void rentcard()
{rateclass:
    system("cls");
    int choice;
    cout<<"\t\t\t\t\t\tRate Card";
    cout<<endl;

    cout<<"Choose your category of your Car:\n\n";
    cout<<"1.Micro\n2.Mini\n3.Prime Sedan\n4.Rental\n5.Previous screen";
    cout<<"Your Choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        {   system("cls");

            cout<<"\n\n";
            gotoxy(23,4);cout<<"\t\t³ þþþþþþ Details of micro car þþþþþþ ³";

            gotoxy(23,5);cout<<"ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿";
            gotoxy(23,6);cout<<"³\t\t  Standard Rate                ³";
            gotoxy(23,7);cout<<"³  First 0 km:                             Rs.35³";
            gotoxy(23,8);cout<<"³  0-10km:                          Rs. 6 per km³";
            gotoxy(23,9);cout<<"³  After 10km:                      Rs. 6 per km³";
            gotoxy(23,10);cout<<"³  Ride Time Charges:               Rs. 2 per km³";
            gotoxy(23,11);cout<<"ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ";
            getch();
            system("cls");
           goto rateclass;
            break;
        }
    case 2:
        {
            system("cls");

            cout<<"\n\n";
            gotoxy(23,4);cout<<"\t\t³ þþþþþþ Details of MINI car þþþþþþ ³";

            gotoxy(23,5);cout<<"ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿";
            gotoxy(23,6);cout<<"³\t\t  Standard Rate                ³";
            gotoxy(23,7);cout<<"³  First 0 km:                             Rs.40³";
            gotoxy(23,8);cout<<"³  0-10km:                         Rs. 8 per km³";
            gotoxy(23,9);cout<<"³  After 10km:                     Rs. 14 per km³";
            gotoxy(23,10);cout<<"³  Ride Time Charges:               Rs. 2 per km³";
            gotoxy(23,11);cout<<"ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ";
            getch();
            system("cls");
            goto rateclass;
            break;
        }
    case 3:
        {
               system("cls");

            cout<<"\n\n";
            gotoxy(23,4);cout<<"\t\t³ þþþþþþ Details of Prime car þþþþþþ ³";

            gotoxy(23,5);cout<<"ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿";
            gotoxy(23,6);cout<<"³\t\t  Standard Rate                ³";
            gotoxy(23,7);cout<<"³  First 0 km:                             Rs.45³";
            gotoxy(23,8);cout<<"³  0-10km:                         Rs. 10 per km³";
            gotoxy(23,9);cout<<"³  After 10km:                     Rs. 16 per km³";
            gotoxy(23,10);cout<<"³  Ride Time Charges:               Rs. 2 per km³";
            gotoxy(23,11);cout<<"ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ";
            getch();
            system("cls");
            goto rateclass;
            break;
        }
    case 4:
        {
            int c;
        system("cls");
            rent:
            gotoxy(13,2);cout<<"1.Prime\t\t2.Mini\n";
            gotoxy(13,3);cout<<"Your choice: ";
            cin>>c;
            switch(c)
            {
            case 1:
                {

               system("cls");

            cout<<"\n\n";
            gotoxy(23,4);cout<<"\t\t³ þþþþþþ Rental Details of Rental car þþþþþþ ³";

            gotoxy(23,5);cout<<"ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿";
            gotoxy(23,6);cout<<"³\t\t  Standard Rate                                 ³";
            gotoxy(23,7);cout<<"³  Base fare:                             Rs. 349 for 15km & 1hr.³";
            gotoxy(23,8);cout<<"³  Additional km fare:                              Rs. 12 per km³";
            gotoxy(23,9);cout<<"³  Additional Time fare:                         Rs. 1.6 per min.³";

            gotoxy(23,10);cout<<"ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ";
            getch();
            system("cls");
            goto rateclass;
break;
                }
            case 2:
                {
                    system("cls");

            cout<<"\n\n";
            gotoxy(23,4);cout<<"\t\t³ þþþþþþ Rental Details of Mini car þþþþþþ ³";

            gotoxy(23,5);cout<<"ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿";
            gotoxy(23,6);cout<<"³\t\t  Standard Rate                                 ³";
            gotoxy(23,7);cout<<"³  Base fare:                             Rs. 249 for 15km & 1hr.³";
            gotoxy(23,8);cout<<"³  Additional km fare:                              Rs. 09 per km³";
            gotoxy(23,9);cout<<"³  Additional Time fare:                         Rs. 1.7 per min.³";

            gotoxy(23,10);cout<<"ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ";
            getch();
            system("cls");
            goto rateclass;
break;
            default:
                {
                    cout<<"you entered the wrong choice...";
                    getch();
                    system("cls");
                        goto rent;
                }

                }
            }

        }
            case 5:
                {
                    system("cls");
                    afterlogin();;

                }
            default:
                {


                    cout<<"you entered the wrong choice...";
                    getch();
                    system("cls");
                    goto rateclass;
                }

        }
}

void adminlogin()
{
system("cls");
    int choice;
    string adminuser,adminpass;

    cout<<"enter your login details:\n\n";
    cout<<"UserName: ";
    cin>>adminuser;
    cout<<"password: ";
    cin>>adminpass;

    if(adminuser=="admin" && adminpass=="admin")
    {

admin:


    system("cls");
   cout<<"                      Welcome to admin page                               \n\n";
        cout<<"*******************        MENU        *******************************\n\n";
        cout<<"1.Booking details"<<endl;
        cout<<"2.Canceled Details"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"\nEnter your choice :";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {

        case 1:
            {

system("cls");
            ifstream CustRec;
        CustRec.open("Customer Record.txt",ios::in);

          char ch;
          ch=CustRec.get();
          while(!CustRec.eof())
          {
              cout<<ch;
              ch=CustRec.get();
          }
          CustRec.close();
          cout<<"\n\n\n\n\nPress enter to go back";
          getch();
            goto admin;

        }
        case 2:
            {   system("cls");
                ifstream CancelRec;
        CancelRec.open("canceled Record.txt",ios::in);
        char ch;
        ch=CancelRec.get();
        while(!CancelRec.eof())
        {
            cout<<ch;
            ch=CancelRec.get();

        }
        CancelRec.close();
         cout<<"\n\n\n\n\nPress enter to go back";
         getch();
        goto admin;

            }
        case 3:
            {
                loginpage();
                break;
            }
        default:
            {

                goto admin;
            }


        }}
        else{
                cout<<"\n\nYou have entered wrong username and password!!!";
                getch();
            loginpage();
        }


}

