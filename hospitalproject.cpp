/////////////////////////////////////// Hospital Management System ///////////////////////////////////////
/////////////////////////////////////// Header Files ///////////////////////////////////////
#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<windows.h>
#define r 9999

/////////////////////////////////////// Function Declaration ///////////////////////////////////////

void menu();
void reset();
void pas_code();
void change_pas_code();
void patient_info_show();
void call_dr();
void continue_patient_info_show();
void continue_call_dr();
void call_staff_info();
void show_staff_info();
void continue_show_staff_info();
void really_change_pas_code();


using namespace std;


/////////////////////////////////////// Class Base ///////////////////////////////////////

class base
{
public:
    virtual void get()=0;
    virtual void show()=0;

};

/////////////////////////////////////// Class Patient Information ///////////////////////////////////////

class info:public base
{
public:
    char name[50], time[50];
    int num, age;
    void get()
    {
        system("cls");
        cin.sync();
        cout<<"\n\t Enter the patient name : ";
        cin.getline(name, 50);
        cout<<"\n\t Enter the Appointment Time : ";
        cin.getline(time, 50);
        cout<<"\n\t Enter the patient age : ";
        cin>>age;
        cout<<"\n\t Enter Appointment number : ";
        cin>>num;
    }
    void show()
    {   cout<<"\n\n\t\t !!! Patient Information !!!"<<endl;
        cout<<"\n\t\tName : "<<name;
        cout<<"\n\t\tAge : "<<age;
        cout<<"\n\t\tNumber : "<<num;
        cout<<"\n\t\tTime : "<<time<<endl;
    }
};

/////////////////////////////////////// Class Dr.Rana ///////////////////////////////////////

class rana:public info
{
public:
    info a1;
    void get()
    {
        system("cls");
        ofstream out("Rana.txt", ios::app|ios::binary);
        a1.get();
        out.write((char*)&a1,sizeof(a1));
        out.close();
        cout<<"\n\t\tYour Entry Has Been Saved !";
        continue_call_dr();
    }
    void show()
    {
        ifstream inx("rana.txt");
        if(inx==NULL)
        {
            cout<<"\n\n\t\tNo Data In The File ";
            continue_patient_info_show();
        }
        else
        {
             while(inx.read((char*)&a1,sizeof(info)))
            {
                a1.show();
            }
            continue_patient_info_show();
            inx.close();

        }
    }
};

/////////////////////////////////////// Class Dr.Waqar ///////////////////////////////////////

class waqar:public info
{
public:
    info a1;
    void get()
    {
        system("cls");
        ofstream out("waqar.txt", ios::app|ios::binary);
        a1.get();
        out.write((char*)&a1,sizeof(a1));
        out.close();
        cout<<"\n\t\tYour Entry Has Been Saved !";
        continue_call_dr();
    }
    void show()
    {
        ifstream inx("waqar.txt");
        if(inx==NULL)
        {
            cout<<"\n\n\t\tNo Data In The File ";
            continue_patient_info_show();
        }
        else
        {
            while(inx.read((char*)&a1,sizeof(info)))
            {
                a1.show();
            }
            continue_patient_info_show();
            inx.close();

        }
    }
};


///////////////////////////////////////  Class Dr.Ahmed ///////////////////////////////////////
class ahmed:public info
{
public:
    info a1;
    void get()
    {
        system("cls");
        ofstream out("ahmed.txt", ios::app|ios::binary);
        a1.get();
        out.write((char*)&a1,sizeof(a1));
        out.close();
        cout<<"\n\t\tYour Entry Has Been Saved !";
        continue_call_dr();
    }
    void show()
    {
        ifstream inx("ahmed.txt");
        if(inx==NULL)
        {
            cout<<"\n\n\t\tNo Data In The File ";
            continue_patient_info_show();
        }
        else
        {
             while(inx.read((char*)&a1,sizeof(a1)))
            {
                a1.show();
            }
            continue_patient_info_show();
            inx.close();

        }
    }
};



//////////////////////////////////////// Class Staff ////////////////////////////////////////

class staff:public base
{
public:

    char all[r];
    char name[50],age[20],sal[30],pos[20];
    void get()
    {
        ofstream out("staff.txt",ios::app | ios::binary);
        {
            system("cls");
            cin.sync();
            cout<<"\n\tEnter Name : ";
            cin.getline(name, 50);
            cout<<"\n\tEnter Age : ";
            cin.getline(age,20);
            cout<<"\n\tEnter Salary : ";
            cin.getline(sal, 30);
            cout<<"\n\tEnter Working Position : ";
            cin.getline(pos,20);


        }
        out<<"\n\t\tName : "<<name<<"\n\t\tAge : "<<age<<"\n\t\tSalary : "<<sal<<"\n\t\tWorking Position :"<<pos<<endl;
        out.close();
        cout<<"\n\n\t\tYour Information Has Been Saved !";
        cout<<"\n\n\t\tDo You Want To Stored More Staff Information ?"<<endl;
        cout<<"\n\t\t\tPress 1 for Yes\n\t\t\tPress 2 for No"<<endl;
        cout<<"\n\t\tPlease Enter Your Choice :" ;
        int x;
        cin>>x;
        while(x>2 || x<1)
        {
            cout<<"\n\t\tSorry Invalid Choice ";
            cout<<"\n\n\t\tPlease Enter Valid Choice :";
            cin>>x;
        }
        if (x==1)
           get();
        else
           menu();
    }
    void show()
    {
        ifstream inx("staff.txt");
        if(inx==NULL)
        {
            cout<<"\n\n\t\tNo Data In The File ";
            continue_show_staff_info();
        }
        else if(!inx)
        {
            cout<<"\n\t\tFile open Error !!!";
            continue_show_staff_info();
        }
        cout<<"\n\n\t\t !!! Staff Information !!!"<<endl;
        while(!(inx.eof()))
        {
            inx.getline(all,999);
            cout<<all<<endl;
        }
        continue_show_staff_info();
        inx.close();
    }
};

//////////////////////////////////////// Class Information ////////////////////////////////////////
class information
{
public:
    void drinfo()
    {
        system("cls");
        //system("background color F3");
        system("color E4");
        cout<<"\n=====================================================================================\n";
        cout<<"\n\n\t\t(Three Doctors Available) \n\n \t\t[Information And Timing Are Given Below]\n";
        cout<<"\n-------------------------------------------------------------------------------------\n";
        cout<<"\nDr Available in hospital:\n";
        cout<<"\t1.\tDr. Rana (Skin Specialist)\n\n";
        cout<<"\t\t\t  [[Timing]] : \n\n";
        cout<<"\tMonday To Friday\t\t 9AM To 5PM\n";
        cout<<"\tSaturday        \t\t 9AM To 1PM\n";
        cout<<"\tSunday          \t\t OFF\n";
        cout<<"\n-------------------------------------------------------------------------------------\n";
        cout<<"\t2.\tDr. Waqar (Child Specialist)\n\n";
        cout<<"\t\t\t  [[Timing]] : \n\n";
        cout<<"\tMonday To Friday\t\t 2PM To 10PM\n";
        cout<<"\tSaturday        \t\t 8AM To 1PM\n";
        cout<<"\tSunday          \t\t 12PM To 9PM\n";
        cout<<"\n-------------------------------------------------------------------------------------\n";
        cout<<"\t3.\tDr. Ahmed (DVM)\n\n";
        cout<<"\t\t\t  [[Timing]] : \n\n";
        cout<<"\tMonday To Friday\t\t 8AM To 5PM\n";
        cout<<"\tSaturday        \t\t 10AM To 1PM\n";
        cout<<"\tSunday          \t\t OFF\n";
        cout<<"\n-------------------------------------------------------------------------------------\n";
        cout<<"\nPress Any Key For Continue ! ";
        getch();
        menu();

    }
};
void call_staff_info()
{
    system("cls");
    int choice;
    cout<<"\n\n\n\t\tPress 1 Store Staff Information\n\n\t\tPress 2 Go Back\n\n\t\t\t ";
    cout<<"\n\t\tPlease Enter Your Choice :" ;
    cin>>choice;

    base *ptr;
   staff st;
     while(choice>2 || choice<1){

            cout<<"\n\t\tSorry Invalid Choice ";
            cout<<"\n\n\t\tPlease Enter Valid Choice :";
            cin>>choice;
    }
    if(choice==1)
    {
        ptr=&st;
        ptr->get();

    }
    else if(choice==2)
    {
       menu();
    }

    else
    {
        cout<<"\n\t\tSorry Invalid Choice :";
        getch();
        menu();
    }

}

void show_staff_info()
{
    system("cls");
    int choice;
    cout<<"\n\n\n\t\tPress 1 Staff Information\n\n\t\tPress 2 Go Back\n\n\t\t\t ";
    cout<<"\n\t\tPlease Enter Your Choice :" ;
    cin>>choice;

    base *ptr;
   staff st;
     while(choice>2 || choice<1){

            cout<<"\n\t\tSorry Invalid Choice ";
            cout<<"\n\n\t\tPlease Enter Valid Choice :";
            cin>>choice;
    }
    if(choice==1)
    {
        ptr=&st;
        ptr->show();

    }
    else if(choice==2)
    {
       menu();
    }

    else
    {
        cout<<"\n\t\tSorry Invalid Choice :";
        getch();
        menu();
    }

}

void continue_show_staff_info()
{
    staff a;
    cout<<"\n\n\t\tDo You Want To Continue ?"<<endl;
        cout<<"\n\t\t\tPress 1 for Yes\n\t\t\tPress 2 for No"<<endl;
        cout<<"\n\t\tPlease Enter Your Choice :" ;
        int x;
        cin>>x;
        while(x>2 || x<1)
        {
            cout<<"\n\t\tSorry Invalid Choice ";
            cout<<"\n\n\t\tPlease Enter Valid Choice :";
            cin>>x;
        }
        if (x==1)
           a.show();
        else
           menu();
}

void call_dr()
{
    system("cls");
    int choice;
    cout<<"\n\n\n\t\tPress 1 for Dr. Rana\n\n\t\tPress 2 for Dr. Waqar\n\n\t\tPress 3 for Dr. Ahmed\n\n\t\tPress 4 Go Back\n\n\t\t\t ";
    cout<<"\n\t\tPlease Enter Your Choice :" ;
    cin>>choice;

    base *ptr;
    rana ra;
    waqar wa;
    ahmed ah;
     while(choice>4 || choice<1){

            cout<<"\n\t\tSorry Invalid Choice ";
            cout<<"\n\n\t\tPlease Enter Valid Choice :";
            cin>>choice;
    }
    if(choice==1)
    {
        ptr=&ra;
        ptr->get();

    }
    else if(choice==2)
    {
        ptr=&wa;
        ptr->get();


    }
    else if(choice==3)
    {
        ptr=&ah;
        ptr->get();

    }
     else if(choice==4)
    {
       menu();
    }

    else
    {
        cout<<"\n\t\tSorry Invalid Choice :";
        getch();
        menu();
    }

}

void patient_info_show()
{
    system("cls");
    int choice;
    cout<<"\n\n\n\t\tPress 1 for Dr. Rana\n\n\t\tPress 2 for Dr. Waqar\n\n\t\tPress 3 for Dr. Ahmed \n\n\t\tPress 4 Go Back\n\n\t\t\t";
    cout<<"\n\t\tPlease Enter Your Choice :" ;
    cin>>choice;
    base *ptr;
    rana ra;
    waqar wa;
    ahmed ah;
     while(choice>4 || choice<1){

            cout<<"\n\t\tSorry Invalid Choice ";
            cout<<"\n\n\t\tPlease Enter Valid Choice :";
            cin>>choice;
    }
    if(choice==1)
    {
        ptr=&ra;
        ptr->show();
    }
    else if(choice==2)
    {
        ptr=&wa;
        ptr->show();
    }
    else if(choice==3)
    {
        ptr=&ah;
        ptr->show();
    }
    else if(choice==4)
    {
      menu();
    }
    else
    {
        cout<<"\n\t\tSorry Invalid Choice ";
        getch();
        menu();

    }

}
void continue_call_dr()
{
    cout<<"\n\n\t\tDo You Want To Continue?"<<endl;
    cout<<"\n\t\t\tPress 1 for Yes\n\t\t\tPress 2 for No"<<endl;
    cout<<"\n\t\tPlease Enter Your Choice :" ;
    int x;
    cin>>x;

   while(x>2 || x<1)
    {
        cout<<"\n\t\tSorry Invalid Choice ";
        cout<<"\n\n\t\tPlease Enter Valid Choice :";
        cin>>x;
    }
   if (x==1)
   {
       call_dr();
   }
   else
   {
       menu();
   }
}

void continue_patient_info_show()
{
    cout<<"\n\n\t\tDo You Want To Continue?"<<endl;
    cout<<"\n\t\t\tPress 1 for Yes\n\t\t\tPress 2 for No"<<endl;
    cout<<"\n\t\tPlease Enter Your Choice :" ;
    int x;
    cin>>x;
    while(x>2 || x<1)
    {
        cout<<"\n\t\tSorry Invalid Choice ";
        cout<<"\n\n\t\tPlease Enter Valid Choice :";
        cin>>x;
    }
    if (x==1)
    {
        patient_info_show();
    }
    else
    {
        menu();
    }

}
void menu()
{

    system("cls");
    system("color E4");

    cout<<"\n";
    cout<<"\n";

    cout<<"\t\t    |     ************  MAIN MENU  ************     |   \n";
    cout<<"\t\t    |           Hospital Management System          |   \n";
    cout<<"\t\t    |  ===========================================  |   \n";

    cout<<"\n-------------------------------------------------------------------------------------\n";
    cout<<"\t\t         Please Select Any Option                \n";

    cout<<"\n\n\t1-\t\tPress 1 For Available Doctor Information \n\n";
    cout<<"\t2-\t\tPress 2 For Doctor Appointment \n\n";
    cout<<"\t3-\t\tPress 3 For Saving Staff Information \n\n";
    cout<<"\t4-\t\tPress 4 For Checking Patient Appointment Menu : \n\n";
    cout<<"\t5-\t\tPress 5 For Checking Staff Information Menu : \n\n";
    cout<<"\t6-\t\tPress 6 For Change Password OR Create Password : \n\n";
    cout<<"\t7-\t\t[     Press 7 For Logout     ]\n\n";
    cout<<"\t8-\t\t[     Press 8 For System Reset    ]\n\n";
    cout<<"\t9-\t\t[     Press 9 For Exit Without Logout   ]\n";

    cout<<"\n=====================================================================================\n";
    cout<<"\n\n\t\tPlease Enter Your Choice : ";
    information a1;
    int a;
    cin>>a;
     while(a>9 || a<1){

            cout<<"\n\t\tSorry Invalid Choice ";
            cout<<"\n\n\t\tPlease Enter Valid Choice :";
            cin>>a;
    }
    if(a==1)
    {
        a1.drinfo();
    }
    else if(a==2)
    {
        call_dr();
    }
    else if(a==3)
    {
       call_staff_info();
    }
    else if(a==4)
    {
        patient_info_show();
    }
    else if(a==5)
    {
       show_staff_info();
    }
    else if(a==6)
    {
        really_change_pas_code();
    }
    else if(a==7)
    {
        pas_code();
    }
   else if(a==8)
    {
        reset();
    }
    else if(a==9)
    {
        exit(0);
    }
    else
    {
        cout<<"\n\t\tSorry Invalid Choice :";
    }
}
void reset()
{
      system("cls");
      system("color 80");
      remove("ahmed.txt");
      remove("rana.txt");
      remove("waqar.txt");
      remove("staff.txt");
      cout<<"\n\n\n\n\n\n\n\n\n\t\t\tSystem Reset Successfully"<<endl;
      cout<<"\n\n\t\t\tPress Any Key To Continue !";
    getch();
    menu();

}
void pas_code()
{
    system("cls");
    char p1[50],p2[50],p3[50];
    system("color 80");
    ifstream in("password.txt");
    {
        cin.sync();
        cout<<"\n\n\n\n\n\n\n\t\tEnter The Password:";
        cin.getline(p1,50);
        in.getline(p2,50);
        if(strcmp(p2,p1)==0)
        {
            menu();
        }
        else
        {

            cout<<"\n\n\t\t\tIncorrect Passcode Please Try Again \n";
            pas_code();
        }
    }
    in.close();


}
void really_change_pas_code()
{
    cout<<"\n\n\t\tDo You Want To Really Change Your Password?"<<endl;
    cout<<"\n\t\t\tPress 1 for Yes\n\t\t\tPress 2 for No"<<endl;
    cout<<"\n\t\tPlease Enter Your Choice :" ;
    int x;
    cin>>x;
    while(x>2 || x<1)
    {
        cout<<"\n\t\tSorry Invalid Choice ";
        cout<<"\n\n\t\tPlease Enter Valid Choice :";
        cin>>x;
    }
    if (x==1)
    {
       change_pas_code();
    }
    else
    {
        menu();
    }

}
void change_pas_code()
{
    char n[50];
    system("cls");
    system("color E4");
    ofstream out("password.txt");
    {
        cin.sync();
        cout<<"\n\n\n\n\t\t\tEnter The New Password : ";
        cin.getline(n,50);
        out<<n;
    }
    out.close();
    cout<<"\n\n\t\t\tYour Password Has Been Saved !";
    getch();
    menu();

}
int main()
{
    pas_code();
    system("pause");
}
