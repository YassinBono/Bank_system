#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<Windows.h>
using namespace std;
struct client
{
    char name[50];
    int age, account, password; //To enter customer data
    long long deposit;
    string phone;
    string city;
};
struct node
{
    client data;        //pointer 
    node* next;
};
node* current = NULL;
node* head = NULL;
node* tail = NULL;

void account();     //creat account
void addacc();     //add account
void search();     //print infromation account
void deleteacc();  //delete account
void update();      //update infromation account

void account()
{
    node* current = new node;
    cout << "Enter Your Name: ";
    cin.ignore();
    cin.getline(current->data.name, 50); //To enter the full name and calculate the distance
    cout << "Enter Your Age: ";
    cin >> current->data.age;
    cout << "Enter Your City: ";
    cin >> current->data.city;
    int x = 0;       
    while (x != 1) { // To prevent the entry of letters or more than 11 digits or less than 11 digits

        cout << "Enter Your Mobile Number: ";
        cin >> current->data.phone;
        if (current->data.phone.length() == 11)
        {
            for (int i = 0; i < current->data.phone.length(); i++)
            {
                if (current->data.phone[i] >= '0' && current->data.phone[i] <= '9')
                {
                    x = 1;
                }

            }
            if (x == 0)
                cout << "error" << endl;
        }
    }
    cout << "Account Number: ";
    cin >> current->data.account;
    cout << "Enter password:  ";
    cin >> current->data.password;
    cout << "Enter Deposit: ";
    cin >> current->data.deposit;
    if (current->data.deposit >= 1000000)
    {
        cout << "YOU ARE NOW VIP CLIENT\n";
    }
    else if (current->data.deposit < 1000000)  //If the customer entered the money of one million pounds or more
    {
        cout << "YOU ARE NOW CLIENT IN OUR BANK\n";
    }
    current->next = NULL;  //Then we make the pointer on NULL
    if (head == NULL)
    {
        head = current;   //Let's check if it's the first account or not
    }
    else
    {
        node* tail = new node();
        tail = head;
        while (tail->next != NULL) {
            tail = tail->next;          //If there are other accounts in the past
        }
        tail->next = current;
    }
    cout << "\t\t\t  Bank Account Successfully Added !!!! \n";//Successfully
}
void addacc()
{
    node* current = new node;
    cout << "Enter Your Name: ";
    cin.ignore();
    cin.getline(current->data.name, 50); //To enter the full name and calculate the distance
    cout << "Enter Your Age: ";
    cin >> current->data.age;
    cout << "Enter Your City: ";
    cin >> current->data.city;
    int x = 0;
    while (x != 1) {
        // To prevent the entry of letters or more than 11 digits or less than 11 digits
        cout << "Enter Your Mobile Number: ";
        cin >> current->data.phone;
        if (current->data.phone.length() == 11)
        {
            for (int i = 0; i < current->data.phone.length(); i++)
            {
                if (current->data.phone[i] >= '0' && current->data.phone[i] <= '9')
                {
                    x = 1;
                }

            }
            if (x == 0)
                cout << "error" << endl;
        }
    }
    cout << "Account Number: ";
    cin >> current->data.account;
    cout << "Enter password:  ";
    cin >> current->data.password;
    cout << "Enter Deposit: ";
    cin >> current->data.deposit;
    if (current->data.deposit >= 1000000)
    {
        cout << "YOU ARE NOW VIP CLIENT\n";//If the customer entered the money of one million pounds or more
    }
    else if (current->data.deposit < 1000000)
    {
        cout << "YOU ARE NOW CLIENT IN OUR BANK\n";
    }
    current->next = head;
    head = current;
    cout << "\t\t\t  Bank Account Successfully Added !!!! \n";
}
void search()
{
    ofstream pro;
    pro.open("THE PROJECT.txt");
    pro << " BANK ACCOUNT\n";   
    node* current = new node;     //search in file steram
    if (head == NULL)
    {
        cout << "No Found Account\n";  
        return;
    }
    int acc, pass;
    cout << "Enter Account Number: "; 
    cin >> acc;
    cout << "Enter your password: ";
    cin >> pass;
    current = head;
    while (current != NULL)  
    {

        if (current->data.account == acc && current->data.password == pass)
        {
            cout << "\n\n\n";
            cout << "\t\t\t\t__________________\n";
            cout << "\t\t\t\tNAME:             " << current->data.name << endl;
            pro << "\t\t\t\tNAME:             " << current->data.name << endl;  //call who file stream
            cout << "\t\t\t\tACCOUNT NUMBER:   " << current->data.account << endl;
            pro << "\t\t\t\tACCOUNT NUMBER:   " << current->data.account << endl; //call who file stream
            cout << "\t\t\t\tAGE:              " << current->data.age << " Years" << endl;
            pro << "\t\t\t\tAGE:              " << current->data.age << " Years" << endl; //call who file stream
            cout << "\t\t\t\tCITY:             " << current->data.city << endl;
            pro << "\t\t\t\tCITY:             " << current->data.city << endl; //call who file stream
            cout << "\t\t\t\tMOBILE NUMBER:    " << current->data.phone << endl;
            pro << "\t\t\t\tMOBILE NUMBER:    " << current->data.phone << endl; //call who file stream
            cout << "\t\t\t\tDEPOSITE:         " << current->data.deposit << "$" << endl;
            cout << "\t\t\t\t__________________\n";

            if (current->data.deposit >= 1000000)
            {
                cout << "\n\t\t\t\t\t\t VIP CLIENT\n\n";
                cout << "\t\t\t\t*******\n";
            }
            pro << "\t\t\t\tDEPOSITE:        " << current->data.deposit << "$" << endl;
            return;
        }
        current = current->next;


    }
}
void deleteacc()
{
    int accn, pas;
    node* current = new node();
    if (head != NULL)
    {
        current = head;
        cout << "Account Number:  ";
        cin >> accn;
        cout << "Enter password : ";
        cin >> pas;
        if (current->data.account == accn && current->data.password == pas)
        {//You must enter the account number and password
            head = head->next;
            cout << "\t\t    BANK ACCOUNT SUCCESSFULLY CLOSED !!!\n\n";
            delete current;
        }
        else
        {
            while (current != NULL)
            {
                if ((current->next)->data.account == accn)
                {//See if it is equal to the existing information or not
                    (current->next) = (current->next)->next;
                    cout << "\t\t    BANK ACCOUNT SUCCESSFULLY CLOSED !!!\n\n";
                    break;
                }
                else
                {
                    current = current->next;
                }

            }
        }
    }
    else
    {
        cout << "No Found data or The password is wrong\n";
    }
}
void update()
{
    int acct, pass;
    int sol;
    node* current = new node;
    if (head == NULL)
    {
        cout << "No found account\n";
    }
    cout << "Enter Your Account Number: ";
    cin >> acct;
    cout << "Enter your password: ";
    cin >> pass;
    current = head;
    while (current != NULL)
    {
        if (current->data.account == acct && current->data.password == pass)
        { //You must enter the account number and password
            system("Cls");
            cout << "\n\n\n\n";
            cout << "\t\t\t\t******\n";
            cout << "\t\t\t\t1-NAME:              " << current->data.name << endl;
            cout << "\t\t\t\t2-ACCOUNT NUMBER:    " << current->data.account << endl;
            cout << "\t\t\t\t3-PASSWORD :         " << current->data.password << endl;
            cout << "\t\t\t\t4-AGE:               " << current->data.age << " Years" << endl;
            cout << "\t\t\t\t5-CITY:              " << current->data.city << endl;
            cout << "\t\t\t\t6-MOBILE NUMBER:     " << current->data.phone << endl;
            cout << "\t\t\t\t7-DEPOSITE:          " << current->data.deposit << "$" << endl;
            cout << "\t\t\t\t*****\n\n";
            cout << "\t\t\t\t  ^^   Which option you want abdate?  ^^\n";
            cin >> sol;
            switch (sol)
            {
            case 1:
                cout << "\n\t\tEnter New Name: ";
                cin.ignore();
                cin.getline(current->data.name, 50);
                break;
            case 2:
                cout << "\n\t\tEnter New Account Number: ";
                cin >> current->data.account;
                break;
            case 3:
                cout << "\n\t\tEnter New Pasword: ";
                cin >> current->data.password;
                break;
            case 4:
                cout << "\n\t\tEnter New Age: ";
                cin >> current->data.age;
                break;
            case 5:
                cout << "\n\t\tEnter New City: ";
                cin >> current->data.city;
                break;
            case 6:
                cout << "\n\t\t Enter New Mobile number: ";
                cin >> current->data.phone;
                break;
            case 7:
                cout << "\n\t\tEnter New Deposite: ";
                cin >> current->data.deposit;
                if (current->data.deposit >= 1000000)
                {
                    cout << "YOU BECAME VIP CLIENT\n";
                }
            default:
                cout << "\n\t\tThere is Wrong\n"; //If you don't enter any correct number
            }
            char o;
            cout << "\n\t\t\t  UPDATED SUCCESFULLY !!!! \n";
            cout << "\t\t\t\Do you want chang other option (y/n)\n";
            cin >> o;
            if (o == 'y')
            {
                update();
            }
            else
            {
                return;
            }
        }
        current = current->next;
    }
}
void displayAll() //Admin only
{
    int c, pass;
    node* current = new node;
    cout << "Are You   1-Client \t 2-Admin\n";
    cin >> c;
    if (c == 1)
    {
        cout << "Non Available\n";
    }
    else if (c == 2)
    {
        cout << "Enter a password\n";
        cin >> pass;
        if (pass != 123)
            cout << "password error\n";
        else
        {
            if (head != NULL)
            {
                current = head;
                while (current != NULL)
                {
                    cout << "\n\n\n";
                    cout << "\t\t\t\t__________________\n";
                    cout << "\t\t\t\tNAME:             " << current->data.name << endl;
                    cout << "\t\t\t\tACCOUNT NUMBER:   " << current->data.account << endl;
                    cout << "\t\t\t\tAGE:              " << current->data.age << " Years" << endl;
                    cout << "\t\t\t\tCITY:             " << current->data.city << endl;
                    cout << "\t\t\t\tMOBILE NUMBER:    " << current->data.phone << endl;
                    cout << "\t\t\t\tDEPOSITE:         " << current->data.deposit << "$" << endl;
                    if (current->data.deposit >= 1000000)
                    {
                        cout << "                        VIP CLIENT\n";
                    }
                    cout << "\t\t\t\t__________________\n";
                    current = current->next;
                }
            }
            else
                cout << "no found data\n";
        }
    }

}
int main()
{
    int ch;
    system("Cls");
    system("color 90");
    cout << "\n\n\n";
    cout << "\t\t\t\t|_________________________________________________________|\n";
    cout << "\t\t\t\t|    ^^ ^^      [WELCOME TO OUR BANK]   ^^ ^^             | \n";
    cout << "\t\t\t\t|_________________________________________________________|\n";
    cout << "\t\t\t\t| PROJECT  BY ||     A7MED 3TEF & YASSIN SA3D & NABIL HANY|\n";
    cout << "\t\t\t\t|_________________________________________________________|\n";
    cout << "\t\t\t\t|    PRESS ENTER TO CONTINUE....                          |\n";
    cout << "\t\t\t\t|_________________________________________________________|\n";
    cin.get();
    cout << "\n\t\t\t\t  loading \t\t\t\t\t\n";
    char lod = 219;
    for (int i = 0; i < 35; i++) {
        cout << lod;
        if (i < 10)
            Sleep(65);
        if (i >= 10 && i < 20)
            Sleep(45);
        if (i >= 10)
            Sleep(25);
    }
    do {
        system("Cls");
        cout << "\n\n\n\n\n\n\n";
        cout << "\t\t\t\t | ACCOUNT REGISTRATION AND OTHER SERVICES  |\n";
        cout << "\t\t\t\t |------------------------------------------|\n";
        cout << "\t\t\t\t | [1] CREATE NEW ACCOUNT                   |\n";
        cout << "\t\t\t\t |------------------------------------------|\n";
        cout << "\t\t\t\t | [2] ADD ACCOUNT                          |\n";
        cout << "\t\t\t\t |------------------------------------------|\n";
        cout << "\t\t\t\t | [3] DELETE ACCOUNT                       |\n";
        cout << "\t\t\t\t |------------------------------------------|\n";
        cout << "\t\t\t\t | [4] SEARCH ACCOUNT                       |\n";
        cout << "\t\t\t\t |------------------------------------------|\n";
        cout << "\t\t\t\t | [5] UPDATE ACCOUNT                       |\n";
        cout << "\t\t\t\t |------------------------------------------|\n";
        cout << "\t\t\t\t | [6] DISPLAYALL ACCOUNT                   |\n";
        cout << "\t\t\t\t |------------------------------------------|\n";
        cout << "\t\t\t\t | [7] EXIT                                 |\n";
        cout << "\t\t\t\t |------------------------------------------|\n";
        cout << "\t\t\t\t |SELECT OPTION BETWEEN |1-6|** |\n";
        cout << "\t\t\t\t |------------------------------------------|\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            system("Cls");
            cout << "\t\t\t  CREATE ACCOUNT\n\n";
            account();
            break;
        case 2:
            system("Cls");
            cout << "\t\t\t   ADD ACCOUNT\n\n";
            addacc();
            break;
        case 3:
            system("Cls");
            cout << "\t\t\t  Delete ACCOUNT\n\n";
            deleteacc();
            break;
        case 4:
            system("Cls");
            cout << "\t\t\t SEARCH ACCOUNT\n\n";
            search();
            break;
        case 5:
            system("Cls");
            cout << "\t\t\t UPDATE ACCOUNT\n\n";
            update();
            break;
        case 6:
            system("Cls");
            cout << "\t\t\t DISPLAYALL ACCOUNT\n\n";
            displayAll();
            break;

        }
        cout << "\n\t\t PRESS ENTER TO CONTINUE.... ";
        cin.ignore();
        cin.get();
    } while (ch != 6);
    system("Cls");
    cout << "\n\n\n\t\t\tTHANK YOU FOR USING OUR BANK. \n\n\n\n ";
}