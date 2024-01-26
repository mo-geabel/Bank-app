#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

void line();
void welcome();
void operation();
void please(string a);
void information(string& Name, string& lastName, string& Adress, int& pass, int& tel, int& year, int& month, int& day, int& ID);
void login(int& pass1, int& ID1);
int age(int year);
void page();
void customer(int& mon, int& plus, int& sub);
void save(string& Name, string& lastName, string& Adress, int& pass, int& tel, int& year, int& month, int& day, int& ID);
void secret(int& ID, int& pass); 
void paper(int& mon);
void paper2(int& mon, string &iban);
pair<int, int> resecret();

int main() {
    string Name, lastName, Adress;
    int tel, year, month, day, ID, pass, mon = 0, plus = 0, sub = 0;
    int first;
    welcome();
    do 
    {
        operation();
        cin >> first;

        if (first == 1) 
        {
            pair<int, int> secretInfo = resecret();
            login(secretInfo.second, secretInfo.first);
        } 
        else if (first == 2) 
        {
            information(Name, lastName, Adress, pass, tel, year, month, day, ID);
            if (age(year) <= 17) 
            {
                cout << "Sorry, your age is not allowed to open a bank account" << endl;
                break;
            }
            save(Name, lastName, Adress, pass, tel, year, month, day, ID);
            secret(ID, pass);
            cout << "Your account has been created successfully." << endl;
            customer(mon,plus,sub);
        } 
        else if (first == 3) 
        {
            break;
        }
    } while (first != 1 && first != 2 && first != 3);

    return 0;
}

void welcome() {
    line();
    cout << "WELCOME TO OUR BANK. YOUR MONEY IS IN GOOD HANDS." << endl;
    line();
}

void line() {
    cout << "_________________________________________________________________" << endl;
    cout << endl;
}

void operation() {
    cout << "\n 1. LOGIN  \n 2. OPEN AN ACCOUNT\n 3. LOGOUT \n";
    line();
}

void please(string a) {
    cout << "Please enter your " << a << ": ";
}

void information(string& Name, string& lastName, string& Adress, int& pass, int& tel, int& year, int& month, int& day, int& ID) 
{
    char Is;
    do 
    {
        bool cor = false;

        please("name");
        cin.ignore();
        getline(cin, Name);
        please("last name");
        getline(cin, lastName);
        please("address");
        getline(cin, Adress);
        please("telephone number");
        cin >> tel;
        while (cin.fail()) 
        {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter Tellfon (numbers only): ";
            cin >> tel;
        }
        please("Year of birth");
        cin >> year;
        while (cin.fail()) 
        {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter Year (numbers only): ";
            cin >> year;
        }
        please("month");
        cin >> month;
       while (cin.fail() || month < 1 || month > 12) 
        {
        cout << "Invalid input. Please enter a valid month (1-12)." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Month: ";
        cin >> month;
        }
        please("day of the month");
        cin >> day;
        while (cin.fail())
        {
        cout << "Invalid input. Please enter an integer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter Day (numbers only): ";
        cin >> day;
        }

        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) 
        {
        while (day < 1 || day > 31)
            {
                cout << "Invalid input for the selected month. Enter a day between 1 and 31." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter Day (not more than 31): ";
                cin >> day;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            while (day < 1 || day > 30)
            {
                cout << "Invalid input for the selected month. Enter a day between 1 and 30." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter Day (not more than 30): ";
                cin >> day;
            }
        }
        else if (month == 2) 
        {
        // Handle February separately for leap years, assuming non-leap year for simplicity
            while (day < 1 || day > 28) 
            {
                cout << "Invalid input for February. Enter a day between 1 and 28." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter Day (not more than 28): ";
                cin >> day;
            }
        }

        please("ID");
        cin >> ID;
        while (cin.fail()) 
        {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter ID (numbers only): ";
            cin >> ID;
        }
        please("password (numbers only)");
        cin >> pass;

        while (cin.fail()) 
        {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter password (numbers only): ";
            cin >> pass;
        }

        cout << "Your names are " << Name << " " << lastName << endl
             << "You are " << age(year) << " years old." << endl
             << "Your address is " << Adress << endl
             << "Your telephone number is " << tel << endl
             << "Your ID number is " << ID << endl;

        cout << "Is your information correct? Enter 'n' if it is not: ";
        cin>>Is;
    } while (Is == 'N' || Is == 'n');
}

int age(int year)
{
    return 2024 - year;
}

void login(int& pass1, int& ID1) 
{
    cout << "Enter your ID and password to login." << endl;

    int chance = 3;

    while (chance > 0) 
    {
        int UID, UPass;

        please("ID");
        cin >> UID;

        please("Password");
        cin >> UPass;

        if (UID == ID1 && UPass == pass1) 
        {
            cout << "Login successful!" << endl;
            return;
        } 
        else 
        {
            cout << "Incorrect ID or password. " << endl;
            chance--;
        }
    }

    cout << "Login failed. Exiting program." << endl;
    exit(EXIT_SUCCESS); // Terminate the program if login fails
}

void page() 
{
    cout << "1. Depositing Money\t 2. Withdrawing Money \t 3. Transfer Money\t 4. Recete \t 5. logout" << endl;
    line();
}
void customer(int& mon, int& plus, int& sub) 
{
    int f2;
    do 
    {
        line();
        page();
        please("your operation");
        cin >> f2;
        if (f2 == 1) 
        {
            cout << "enter the amount of money" << endl;
            cin >> plus;
            mon += plus;
            cout << "The operation was done successfully " << endl;

        } 
        else if (f2 == 2) 
        {
            cout << "enter the amount of money" << endl;
            cin >> sub;
            mon -= sub;
            cout << "The operation was done successfully " << endl;
        } 
        else if (f2 == 3) 
        {
            string IBN;
            int IBN2;
            cout << "Enter the IBN\n ";
            cin.ignore();
            getline(cin, IBN);
            cout << "enter the amount of money" << endl;
            cin >> IBN2;
            cout << "The operation was done successfully " << endl;
            mon -= IBN2;
        }
        else if (f2==4)
        {
            paper(mon);
        }
        if (f2==5)
        {
            exit(EXIT_SUCCESS);
        }
        
        
    } while (f2!=1||f2!=2||f2!=3|| f2!=4 || f2!=5);
}
void save(string& Name, string& lastName, string& Adress, int& pass, int& tel, int& year, int& month, int& day, int& ID)
{
    ofstream file;
    file.open("info.txt", ios::app);
    file<<"Name: "<<Name<<lastName<<endl<<"Adress "<< Adress<<endl<< tel<<endl<< "Date of the birth "<<year<<"/ "<< month<<"/ "<<day<<endl<<"ID "<<ID<<endl;
}
void secret(int& ID, int& pass) 
{
    ofstream sfile;
    sfile.open("secret.txt", ios::app);
    sfile << ID << endl << pass << endl;
    sfile.close();
}
void secret(int& ID, int& pass) 
{
    ofstream sfile;
    sfile.open("secret.txt", ios::app);
    sfile << ID << endl << pass << endl;
    sfile.close();
}
pair<int, int> resecret() 
{
    int pass1 = 0;
    int ID1 = 0;
    ifstream inputFile;
    inputFile.open("secret.txt");

    if (!inputFile.is_open()) 
    {
        cerr << "Error: Unable to open file 'secret.txt'\n";
        return make_pair(0, 0); // Return an error code
    }

    // Move the file pointer to the beginning of the file
    inputFile.seekg(0, ios::beg);

    // Read the first line and convert it to an integer
    if (!(inputFile >> ID1)) 
    {
        cerr << "Error: Unable to read a valid integer from the first line.\n";
        return make_pair(0, 0); // Return an error code
    }

    // Move the file pointer to the beginning of the second line
    inputFile.seekg(0, ios::beg);

    // Move the file pointer to the beginning of the second line
    inputFile.ignore(numeric_limits<streamsize>::max(), '\n');

    // Read the second line and convert it to an integer
    if (!(inputFile >> pass1)) 
    {
        cerr << "Error: Unable to read a valid integer from the second line.\n";
        return make_pair(0, 0); // Return an error code
    }

    inputFile.close();
    return make_pair(ID1, pass1); // Return success
}
void paper2(int& mon, string &iban)
{
    ofstream sfile;
    sfile.open("IBAN.txt", ios::app);
    sfile<<"Your translate is "<< mon <<"translate it to "<< iban<<endl;
    sfile.close();
}
void paper(int& mon)
{
    ofstream sfile;
    sfile.open("racete.txt", ios::app);
    sfile<<"Your Money is "<< mon <<endl;
    sfile.close();
}