#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


using namespace std;

#define SIZE 100
string currentUser;
int cont;

//Member 1's function
void registerNewUser();
void readUserDetails(string[][4], int&);
int login(string[][4], int&, string);

void menu();
//Member 2's function
string itemListFileName = (currentUser + ".txt");
const int MAX_ITEMS = 100;

string itemArray[MAX_ITEMS][4];

void readItemList(int& itemCount);
void addItemList();
void displayItemListFromFile();

//Member 3's function
void readTransaction(double&, string[], double[], int&);
void transaction(double&, string[], double[], int&);
void displayTransactionDetails(double&, string[], double[], int&);

int main() {

    int choice;
    //member 1
    int contRL = 0;
    int numOfUsers;
    string username;
    string userArray[SIZE][4];

    //member 2 
    int itemCount = 0;

    //member 3
    double availableBalance;
    string dateOfTransaction[SIZE];
    double amountOfTransaction[SIZE];
    int noOfTransaction;



    do {
        //decoration
       
        cout << "\033[1;36m"; // Set text color to cyan
        cout << "                               XMIX                                " << endl;
        cout << "                             ZZNOZZPNZ                             " << endl;
        cout << "                           ZWJV     Z052                           " << endl;
        cout << "                       ZZYUKFLX    ZSFFHQWZZZZ                     " << endl;
        cout << "                      ZWPKPXZ           ZZXRLMPUYZZ      ZZZ       " << endl;
        cout << "             ZYWXZ  ZRJSY                    ZZWSMISYZZSJORLVZ     " << endl;
        cout << "           ZU  E  NSIY                             YOGIYZ ZRPM     " << endl;
        cout << "           WM R B ULX                                      QQZ     " << endl;
        cout << "           UO  TB ZZZ     ZPGU                             NTZ     " << endl;
        cout << "           TO  IFG R      Z  R             ZZZZ           VLY      " << endl;
        cout << "   ZZZZ    ROZ            HCDW             E  Q            HWZ     " << endl;
        cout << "   ZWQK    GGL                             GYUM   VGTS     HVZ     " << endl;
        cout << "   ZYXT    MIH                     KL            DF B HJ    GWZ    " << endl;
        cout << "   ZWQK    RTU              UI  XY  KS   HJ    HBN D  Y KLM  MHB   " << endl;
        cout << "ZYXTMIHJOSVWXZZZ              ABC      CBA     YL   VC  KL   LKH   " << endl;
        cout << "         ZZYWTQONMMNPTXZZ                      NM   HJK       XLUZ " << endl;
        cout << "                ZZZZYYWUQMHGJOVYZZ             HU              ZWLY" << endl;
        cout << "                       HSUCDSBDBDUZZUSYY       IL              TTYZ" << endl;
        cout << "                                 ZZXUPLJKNQTUWYZZZ             ZRNZ" << endl;
        cout << "                                        ZYXTMIHJOSVWXYUH       JKHJ" << endl;
        cout << "                                                GSYZVZJDYNDKMZZJK  " << endl << endl;

        cout << "\033[0m";



        cout << "1. Register New User" << endl;
        cout << "2. Login" << endl;
        cout << "3. Quit" << endl;
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            registerNewUser();
            cout << "Do you want to continue login? (1-yes, 2-no): ";
            cin >> contRL;

            if (contRL == 2)
                return 0;
        }
        else if (choice == 2) {

            readUserDetails(userArray, numOfUsers);


            int loggedin = login(userArray, numOfUsers, username);
            if (loggedin == -1) {
                cout << "Login Successfully." << endl;
                break;

            }
            else if (loggedin == -2) {
                cout << "Invalid Login. Invalid password." << endl;
                return 0;
            }
            else if (loggedin == -3) {
                cout << "Invalid login. Invalid username." << endl;
                return 0;
            }
            else {
                cout << "Invalid login. Both username and password are invalid." << endl;
                return 0;
            }
        }
        else if (choice == 3) {
            return 0;
        }
        else {
            cout << "Invalid choice." << endl;
            return 0;
        }
        system("cls");

    } while (contRL == 1);


    //end of member 1

    readItemList(itemCount);
    readTransaction(availableBalance, dateOfTransaction, amountOfTransaction, noOfTransaction);
    do {
        system("cls");

        //decoration
        cout << "\033[1;33m";
        cout << "==================================================================" << endl;
        cout << "| __      __       .__                                ._. ._. ._.|" << endl;
        cout << "|/  \\    /  \\ ____ |  |   ____  ____   _____   ____   | | | | | ||" << endl;
        cout << "|\\   \\/\\/   // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\  | | | | | ||" << endl;
        cout << "| \\        /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/   \\|  \\|  \\||" << endl;
        cout << "|  \\__/\\  /  \\___  >____/\\___  >____/|__|_|  /\\___  >  __  __  __|" << endl;
        cout << "|       \\/       \\/          \\/            \\/     \\/   \\/  \\/  \\/|" << endl;
        cout << "==================================================================" << endl << endl;
        cout << "\033[0m";


        cout << "Username: " << currentUser << endl;

        menu();


        char decision;
        cout << "Choice: ";
        cin >> decision;
        system("cls");

        // convert char to int
        if (isdigit(decision)) {
            //convert char to int
            int select = decision - '0';

            //start of member 2
            if (select == 1) {
                displayItemListFromFile();
                

            }

            else if (select == 2)
            {
                cin.ignore();
                addItemList();

            }
            //end of member 2

            //start of member 3
            else if (select == 3) {
                //call transaction function
                transaction(availableBalance, dateOfTransaction, amountOfTransaction, noOfTransaction);
                cont = 1;
            }

            else if (select == 4) {
                displayTransactionDetails(availableBalance, dateOfTransaction, amountOfTransaction, noOfTransaction);
                cont = 1;
            }

            else if (select == 5)
                return main();

            else
            {
                cout << "Not available. You enter a wrong value" << endl << endl;
                cout << "Please try again ";//attention
                cont = 1;

            }
        }
        else
        {
            cout << "It is not a digit" << endl;
            cout << "Please try again ";
            cont = 1;
        }
        continue;



    } while (cont == 1);
    //end of member 3

    system("Pause");
    return 0;
}

//function of member 1

void registerNewUser() {
    string newUserName, password, gender, dateofbirth;
    cout << "Username:";
    getline(cin, newUserName); // Use getline to read the entire line
    cout << "Password:";
    cin >> password;
    cout << "Gender (Female/Male):";
    cin >> gender;
    cout << "Date of Birth (date/month/year):";
    cin >> dateofbirth;

    ifstream infile("user.txt");
    string currentUser, currentPassword;
    bool result = false;
    while (infile >> currentUser >> currentPassword) {
        if (currentUser == newUserName && currentPassword == password) {
            cout << "Username and password combination already exists. Please try again." << endl;
            infile.close();
            return;
        }
    }
    infile.close();

    ofstream outfile("user.txt", ios::app);
    if (outfile.is_open()) {
        outfile << newUserName << endl;
        outfile << dateofbirth << endl;
        outfile << gender << ' ' << password << endl;
        outfile.close();
        cout << "Successfully registered!" << endl;
    }
    else {
        cout << "Failed to open file." << endl;
    }
}

void readUserDetails(string userArray[][4], int& numOfUsers) {
    ifstream myfile("user.txt");
    if (!myfile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    numOfUsers = 0;
    while (numOfUsers < SIZE && getline(myfile, userArray[numOfUsers][0])) {
        myfile >> userArray[numOfUsers][1] >> userArray[numOfUsers][2] >> userArray[numOfUsers][3];
        myfile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline character
        numOfUsers++;
    }
    myfile.close();
}

int login(string userArray[][4], int& numOfUsers, string username) {
    cout << "Enter username:";
    getline(cin, username);
    cout << "Enter password:";
    string password;
    cin >> password;

    int i = 0;
    for (; i < numOfUsers; i++) {
        if (userArray[i][0] == username && userArray[i][3] == password) {
            currentUser = username;
            return -1;
        }
        else if (userArray[i][0] == username && userArray[i][3] != password) {
            return -2;
        }
        else if (userArray[i][0] != username && userArray[i][3] == password) {
            return -3;
        }
    }

    return i;
}

//Function menu --> To display the selection for the system
void menu() {

    cout << "1. Display Item List" << endl;
    cout << "2. Add Item List" << endl;
    cout << "3. Perform Transaction" << endl;
    cout << "4. Display Transaction History" << endl;
    cout << "5. Quit" << endl;

}

//function of member 2
void readItemList(int& itemCount) {
    ifstream inputFile(currentUser+"_itemList.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening file " << (currentUser + "_itemList.txt") << endl;
        return;
    }

    itemCount = 0;
    while (itemCount < MAX_ITEMS && inputFile >> itemArray[itemCount][0] >> itemArray[itemCount][1] >> itemArray[itemCount][2] >> itemArray[itemCount][3]) {
        itemCount++;
    }
    inputFile.close();

}

void addItemList() {

    int option;

    do {
        ofstream outputFile(currentUser+"_itemList.txt", ios::app);
        if (!outputFile.is_open()) {
            cout << "Error opening file " << (currentUser+"_itemList.txt") << " for appending." << endl;
            return;
        }

        cout << "\nDo you want to add a new item? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'n' || choice == 'N') {
            system("cls");
            return;
        }

        string newItem[4];
        cout << "Enter the code of the item: ";
        cin >> newItem[0];
        cout << "Enter the name of the item: ";
        cin.ignore();
        getline(cin, newItem[1]);
        cout << "Enter the quantity: ";
        cin >> newItem[2];

        cout << "Enter the purchasing price per kg: ";
        cin >> newItem[3];

        outputFile << newItem[1] << endl;
        outputFile << newItem[0] << endl;
        outputFile << newItem[2] << " ";
        outputFile << newItem[3] << " ";
        outputFile << endl;

        cout << "Continue? (1-yes, 2-no): ";
        cin >> option;
        if (option == 1) {
            system("cls");
            cin.ignore();
        }
        else {
            cout << "return? (1-yes, 2-no): ";
            cin >> cont;
        }

        outputFile.close();

    } while (option == 1);
    system("pause");
}

void displayItemListFromFile() {
    ifstream inputFile(currentUser+"_itemList.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening file " << (currentUser+"_itemList.txt") << endl;
        return;
    }

    int itemCount = 0;
    int option;

    do {
        while (inputFile >> itemArray[itemCount][0] >> itemArray[itemCount][1] >> itemArray[itemCount][2] >> itemArray[itemCount][3]) {
            cout << "Code: " << itemArray[itemCount][0] << "\n"
                << "Name: " << itemArray[itemCount][1] << "\n"
                << "Quantity: " << itemArray[itemCount][2] << "\n"
                << "Price per kg: " << itemArray[itemCount][3] << "\n" << endl;
            itemCount++;
        }


        inputFile.close();
        cout << "Debug: Read " << itemCount << " items from file." << endl;

        cout << "Continue? (1-yes, 2-no): ";
        cin >> option;
        if (option == 1) {
            system("cls");
            cin.ignore();
        }
        else {
            cout << "return? (1-yes, 2-no): ";
            cin >> cont;
        }

    } while (option == 1);
    system("pause");
}

//function of member 3
void readTransaction(double& availableBalance, string dateOfTransaction[], double amountOfTransaction[], int& noOfTransaction) {

    noOfTransaction = 0;
    ifstream myFile(currentUser + "_Transaction.txt");
    //create a new user if file doesn't exist
    if (!myFile.is_open())
    {
        ofstream newFile(currentUser + "_Transaction.txt");
        newFile << "0\n" << endl;
        newFile.close();
        //open the file to read again
        myFile.open(currentUser + "_Transaction.txt");
    }

    myFile >> availableBalance;

    while (myFile >> dateOfTransaction[noOfTransaction])
    {
        myFile >> amountOfTransaction[noOfTransaction];
        noOfTransaction++;
    }

    myFile.close();
}

void transaction(double& availableBalance, string dateOfTransaction[], double amountOfTransaction[], int& noOfTransaction) {
    //Cout "transaction() is not implemented" if the function is not implemented
    int option;
    do {

        ifstream inFile(currentUser + "_Transaction.txt");
        inFile >> availableBalance;
        cout << "  _n____n_" << endl;
        cout << "o( *> w <*)o" << endl;
        cout << "   -------" << endl;

        cout << "Available Balance : RM" << availableBalance << endl << endl;
       
        inFile.close();

        cout << "Amount of Transaction: RM";
        cin >> amountOfTransaction[noOfTransaction];
        availableBalance += amountOfTransaction[noOfTransaction];
        cout << "Date of Transaction: ";
        cin >> dateOfTransaction[noOfTransaction];

        ofstream outFile;
        outFile.open(currentUser + "_Transaction.txt", ios::in);
        outFile << availableBalance;
        outFile.close();

        ofstream addFile(currentUser + "_Transaction.txt", ios::out | ios::app);
        addFile << dateOfTransaction[noOfTransaction] << " " << amountOfTransaction[noOfTransaction] << endl;
        addFile.close();
        ++noOfTransaction;
        cout << "Continue? (1-yes, 2-no): ";
        cin >> option;
        if (option == 1) {
            system("cls");
            cin.ignore();
        }
        else
            system("pause");
    } while (option == 1);

}

void displayTransactionDetails(double& availableBalance, string dateOfTransaction[], double amountOfTransaction[], int& noOfTransaction) {
    //Cout "displayTransactionDetails() is not implemented" if the function is not implemented

    int numberOfTransaction = 0;
    int numTransaction = 0;
    cout << "       .  ." << endl; 
    cout << "      /| /|" << endl;
    cout << "     /^|/^|" << endl;
    cout << "    ( '>W<`) " << endl;
    cout << "    /     |/" << endl;
    cout << "   /      |·\t" << "Available Amount: RM" << setprecision(2) << fixed << availableBalance << endl;
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl<<endl;

    while (numberOfTransaction != noOfTransaction)
    {
        cout << "Transaction " << ++numberOfTransaction << endl;
        cout << "Date: " << dateOfTransaction[numTransaction] << endl;
        if (amountOfTransaction[numTransaction] < 0)
            cout << "Spent Amount: RM " << setprecision(2) << fixed << amountOfTransaction[numTransaction] << endl << endl;
        else
            cout << "Top up balance: RM" << setprecision(2) << fixed << amountOfTransaction[numTransaction] << endl << endl;
        ++numTransaction;
    }
    system("PAUSE");

}