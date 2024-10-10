#include <iostream>
#include <string>
#include <thread>
#include <cstdlib>
#include <windows.h>
#include <chrono>
#include <regex>
#include <vector>

using namespace std;

string USER_NAME = "kelvin";
string USER_PASSWORD = "0000";

string ADMIN_NAME = "kelvin";
string ADMIN_PASSWORD = "0000";


double currentUserBalance = 300000;
double momoBalance = 5000;
double bankBalance = 900000;
string momoNumber = "0501939533";

HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

void welcomeHeading();
void adminHeader();
void loginHeader();
void adminPanel();
void userPanel();
bool login(string& correctName, string& correctPassword, const string& userType);
void clearScreen();
void fastMO();
void otherNetworks();
double userBalance();
void myAccount();
void depositMoney();
double taxes(double amountNum, double currentUserBalance);
void info(double transferFee, double eLevy, double amountNum, string amount, string phoneNumber);
bool checkNumber(string networkType, string networkCodeOne, string networkCodeTwo);
void addFavorite();
void deleteFavorite(vector <string> favoriteNumbers);

vector <string> favoriteNames;
vector <string> favoriteNumbers;


//----------------------------------------------------------------loading function-----------------------------------------------------------------//
void load();
void shortLoading();
void loading();

//--------------------------------------------------------------------User Menu-------------------------------------------------------------------//
void transactToBank();
void sendMoney();
void withdrawMoney();
void makePayments();
void financialServices();
void transact();
void favorites();

//------------------------------------------------------------------MAIN FUNCTION----------------------------------------------------------------//

int main() {
    clearScreen();
    welcomeHeading();
    string reply;

    while (true) {
        cout << "1. Administrator Panel" << endl;
        cout << "2. User Panel" << endl;
        cout << "3. Exit Program" << endl;
        cout << endl;

        cout << "Select Option: ";
        cin >> reply;

        if (reply == "1") {
            string userType = "ADMIN";
            if (login(ADMIN_NAME, ADMIN_PASSWORD, userType)) {
                adminPanel();
            }
        }
        else if (reply == "2") {
            string userType = "USER";
            if (login(USER_NAME, USER_PASSWORD, userType)) {
                userPanel();
            }
        }
        else if (reply == "3") {
            exit(0);
        }
        else {
            cout << endl;
            cout << "You entered an invalid input. Try again." << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            cout << endl;
            clearScreen();
            welcomeHeading();
        }
    }
    return 0;
}

//------------------------------------------------------------------Loading screen-------------------------------------------------------------//
void loading() {
    for (int i = 0; i < 3; ++i) {
        if (i == 1) {
            cout << "Verified..." << endl;
        }
        else if (i == 2) {
            SetConsoleTextAttribute(consoleHandle, BACKGROUND_GREEN);
            cout << "Logged in successfully" << endl;
            SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        }
        else {
            cout << "Verifying..." << endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

void shortLoading() {
    for (int i = 0; i < 2; i++) {

        if (i == 1) {
            cout << "Transaction complete..." << endl;
        }
        else {
            cout << "Sending. Please wait..." << endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

//------------------------------------------------------------------Loading Error---------------------------------------------------------------//
void loadingError() {
    for (int i = 0; i < 5; ++i) {
        if (i == 2) {
            cout << "Please wait..." << endl;
        }
        else if (i == 3) {
            cout << "Please wait..." << endl;
        }
        else if (i == 4) {
            SetConsoleTextAttribute(consoleHandle, BACKGROUND_RED);
            cout << "Invalid credentials. Try again." << endl;
            SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
        }
        else {
            cout << "Verifying..." << endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

void loggingOut() {
    for (int i = 0; i < 2; ++i) {
        if (i == 1) {
            cout << "Logging out..." << endl;
        }
        else {
            cout << "Please wait..." << endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        main();
    }
}

void load() {
    for (int i = 0; i < 1; i++) {
        cout << "Loading. Please wait..." << endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

void welcomeHeading() {
    cout << "\t\t\t\t\t\t------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t\t Welcome to Unreal Mobile Money Services" << endl;
    cout << "\t\t\t\t\t\t------------------------------------------------------" << endl;
    cout << endl;
}

void adminHeader() {
    cout << "\t\t\t\t\t Administrator Panel" << endl;
}

void loginHeader() {
    cout << "\t\t\t\t\t\t\t\t\t User Panel" << endl;
}

bool login(string& correctName, string& correctPassword, const string& userType) {
    int attempt = 0;
    string input_name;
    string input_pass;

    while (attempt < 3) {
        welcomeHeading();
        if (userType == "ADMIN") {
            adminHeader();
        }
        else {
            loginHeader();
        }
        cout << endl;

        cout << "Enter " << userType << " name" << endl;
        cout << "Enter name: ";
        cin >> input_name;
        cout << endl;

        cout << "Enter " << userType << " password" << endl;
        cout << "Enter password: ";
        cin >> input_pass;
        cout << endl;

        if (input_name == correctName && input_pass == correctPassword) {
            loading();
            welcomeHeading();
            if (userType == "ADMIN") {
                adminHeader();
                cout << "Welcome back, " << correctName << endl;
            }
            else {
                loginHeader();
                cout << "Welcome back, " << correctName << endl;
            }
            return true;
        }
        else {
            loadingError();
            attempt++;
        }
    }
    cout << "You exhausted your trial attempts." << endl;
    return false;
}

void adminPanel() {
    int input;
    while (true) {
        clearScreen();
        adminHeader();
        cout << "Administrator Panel" << endl;
        cout << "1. Add New User" << endl;
        cout << "2. Log Out" << endl;
        cout << endl;

        cout << "Select Option: ";
        cin >> input;

        if (input == 2) {
            loggingOut();
            break;
        }
    }
}

void userPanel() {
    string input;
    while (true) {
        clearScreen();
        cout << "User Panel" << endl;

        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

        cout << endl;

        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Welcome back, " << USER_NAME << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Your current balance is GHS " << userBalance() << endl;
        cout << endl;
        cout << "1. Send Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Deposit Money" << endl;
        cout << "4. Financial Services" << endl;
        cout << "5. My Account" << endl;
        cout << "6. Log Out" << endl;
        cout << endl;

        cout << "Select Option: ";
        cin >> input;

        if (input == "1") {
            sendMoney();
        }
        else if (input == "2") {
            withdrawMoney();
        }
        else if (input == "3") {
            depositMoney();
        }
        else if (input == "4") {
            financialServices();
        }
        else if (input == "5") {
            myAccount();
        }
        else if (input == "6") {
            loggingOut();
            break;
        }
        else {
            cout << endl;
            cout << "Invalid option. Please try again." << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        }
    }
}

//--------------------------------------------------------------Send money options and functios------------------------------------------------------------------------//
void sendMoney() {
    clearScreen();
    cout << "--------------------------------------------------------------------- SEND MONEY ---------------------------------------------------------------------------" << endl;
    cout << endl;

    cout << "1. FastMO Cash User" << endl;
    cout << "2. Mobile Network" << endl;
    cout << "3. To Bank Account" << endl;
    cout << "4. Unregistered FastMO Cash User" << endl;
    cout << "5. Favorites" << endl;
    cout << "0. Go Back" << endl;

    while (true) {
        string choice;
        cout << endl;
        cout << "Select option: ";
        cin >> choice;

        if (choice == "1") {
            fastMO();
        }
        else if (choice == "2") {
            otherNetworks();
        }
        else if (choice == "3") {
            transactToBank();
        }
        else if (choice == "4") {
            cout << "Sending money to Unregistered FastMO Cash User..." << endl;
        }
        else if (choice == "5") {
            favorites();
        }
        else if (choice == "0") {
            userPanel();
        }
        else {
            cout << endl;
            cout << "Invalid option. Please try again." << endl;
            cout << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }

}

//-------------------------------------------------------------------Function for FASTMO---------------------------------------------------------------------------//

void fastMO() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    string phoneNumber;
    string confirmPhoneNumber;

    cout << endl;
    cout << endl;
    cout << "------------------------------------------------------------------ Send To FastMO User ---------------------------------------------------------------------" << endl;
    cout << endl;

Transact:
    while (true) {
        cout << "Enter recipient phone number (10 digits)" << endl;

        cout << "Enter here: ";  cin >> phoneNumber;

        cout << endl;
        if (phoneNumber.length() == 10 && regex_match(phoneNumber, regex("[0-9]+"))) {

            while (true) {
                cout << "Re-enter recipient number" << endl;


                cout << "Enter here: ";  cin >> confirmPhoneNumber;

                if (phoneNumber == confirmPhoneNumber) {

                    while (true) {
                        string amount;
                        long long amountNum;
                        cout << endl;


                        cout << "Enter Amount" << endl;

                        cout << "Enter here: ";  cin >> amount;

                        if (regex_match(amount, regex("[0-9]+"))) {
                            amountNum = stoll(amount);
                            double amountValid = amountNum <= userBalance();
                            double amountLeft = userBalance() - amountNum;
                            double taxCharge = taxes(amountNum, currentUserBalance);

                            if (amountValid && taxCharge <= amountLeft) {
                                int count = 0;
                                while (count < 3) {
                                    string userPin;
                                    cout << endl;
                                    cout << "Enter USER pin" << endl;

                                    cout << "Enter here: "; cin >> userPin;

                                    if (userPin == USER_PASSWORD) {
                                        int count = 0;

                                        while (true) {
                                            int confirmTransaction;

                                            cout << endl;

                                            cout << "You are making a transaction of GHS " << amount << " to " << phoneNumber << endl;
                                            cout << endl;

                                            cout << "1. Confirm" << endl;
                                            cout << "2. Cancel" << endl;

                                            cout << "Enter here: "; cin >> confirmTransaction;
                                            if (confirmTransaction == 1) {
                                                cout << endl;
                                                shortLoading();
                                                cout << endl;
                                                cout << endl;

                                                double eLevy, transferFee;
                                                eLevy = taxes(amountNum, currentUserBalance) / 2;
                                                transferFee = taxes(amountNum, currentUserBalance) / 2;

                                                info(transferFee, eLevy, amountNum, amount, phoneNumber);

                                                while (true) {
                                                    cout << "Would you like to perform another transaction?" << endl;
                                                    cout << "(Y / N)" << endl;

                                                    char newTransaction;
                                                    cout << "Select Option: "; cin >> newTransaction;
                                                    cout << endl;

                                                    if (newTransaction == 'Y' || newTransaction == 'y') {
                                                        load();
                                                        while (true) {
                                                            clearScreen();
                                                            cout << endl;
                                                            cout << "--------------------------------------------------------------------- SEND MONEY ---------------------------------------------------------------------------" << endl;
                                                            cout << endl;
                                                            goto Transact;
                                                        }
                                                    }

                                                    else if (newTransaction == 'N' || newTransaction == 'n') {

                                                        cout << "Returning to main menu. Please wait" << endl;
                                                        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                                                        userPanel();
                                                    }

                                                    else {

                                                        cout << endl;
                                                        cout << "Enter a valid option." << endl;
                                                        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                                                    }
                                                }
                                            }
                                            else if (confirmTransaction == 2) {
                                                cout << endl;
                                                cout << endl;

                                                cout << "Your transaction was cancelled.";
                                                cout << endl;

                                                cout << "Returning to main menu. Please wait" << endl;
                                                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                                                return;
                                            }
                                            else {

                                                return;
                                            }

                                            /* return;*/
                                        }
                                    }

                                    else {
                                        count++;
                                        cout << endl;

                                        SetConsoleTextAttribute(consoleHandle, BACKGROUND_RED);
                                        cout << "Incorrect PIN.";
                                        SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);

                                        cout << " You have " << (3 - count) << " tries left." << endl;
                                    }
                                }

                                cout << endl;
                                std::this_thread::sleep_for(chrono::milliseconds(2000));
                                cout << "Too many tries." << endl;
                                cout << "Logging out" << endl;
                                cout << endl;
                                loggingOut();
                                main();
                            }
                            else {
                                cout << endl;
                                cout << "Your balance is insufficient to make this transaction. Your current balance is GHS " << currentUserBalance << endl;
                                cout << "Try again." << endl;

                            }
                        }
                        else {
                            cout << endl;
                            cout << "Enter a valid amount" << endl;
                        }
                    }
                }
                else {
                    cout << endl;
                    SetConsoleTextAttribute(consoleHandle, BACKGROUND_RED);

                    cout << "Numbers do not match. Try again" << endl;

                    SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
                    cout << endl;
                }
            }
        }
        else {
            cout << "Please enter a valid phone number" << endl;
            cout << endl;
        }
    }
}

//-----------------------------------------------------------------Function for Other networks--------------------------------------------------------------------//

void otherNetworks() {

    cout << endl;
    cout << endl;

    while (true) {
        int reply;
        cout << "------------------------------------------------------------------ Send To Other networks ------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "1. Vodafone" << endl;
        cout << "2. MTN" << endl;
        cout << "3. AirtelTigo" << endl;
        cout << "0. Go back" << endl;
        cout << endl;
        cout << "Select option: "; cin >> reply;

        if (reply == 1) {
            checkNumber("Vodafone", "020", "050");
            return;
        }
        else if (reply == 2) {
            checkNumber("MTN", "024", "054");
            return;
        }
        else if (reply == 3) {
            checkNumber("AirtelTigo", "026", "027");
            return;
        }
        else if (reply == 0) {
            userPanel();
        }
        else {
            cout << endl;
            cout << "Invalid option. Please try again." << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            cout << endl;
        }
    }

}


void bankAccount() {
    cout << "---------------------------------------------------------------- Send To Bank Account ------------------------------------------------------------------" << endl;
    cout << endl;
    transactToBank();
}

//-----------------------------------------------------------------Function to clear screen-----------------------------------------------------------------------//
void clearScreen() {
#ifdef _WIN32
    system("CLS");
#else
    cout << "\033[2J\033[1;1H";
#endif
}

void withdrawMoney() {

    while (true) {
        clearScreen();
        cout << "1. Withdraw from Agent" << endl;
        cout << "2. Withdraw from ATM" << endl;
        cout << endl;
        string choice;
    Withdraw_Menu:
        cout << "Select option: ";
        cin >> choice;

        if (choice == "1") {
            cout << endl;

            while (true) {
                string agentTill1;
                string agentTill2;

                cout << endl;
                cout << "Enter agent till number (10 digits)" << endl;
                cout << "Enter here: ";  cin >> agentTill1;
                if (agentTill1.length() == 10 && regex_match(agentTill1, regex("[0-9]+"))) {
                    cout << endl;

                    while (true) {
                        cout << "Re-enter agent till number (10 digits)" << endl;
                        cout << "Enter here: ";  cin >> agentTill2;

                        if (agentTill1 == agentTill2) {
                            cout << endl;

                            while (true) {
                                string amount;
                                double withdrawalAmount;

                                cout << "Enter Amount" << endl;
                                cout << "Enter here: "; cin >> amount;

                                if (regex_match(amount, regex("[0-9]+"))) {
                                    withdrawalAmount = stod(amount);

                                    if (withdrawalAmount <= userBalance()) {

                                        while (true) {
                                            cout << endl;
                                            string confirmWithdrawal;
                                            cout << "You are making a withdrawal of GHS" << withdrawalAmount << " from agent " << agentTill1 << "." << endl;
                                            cout << "1. Continue" << endl;
                                            cout << "2. Cancel" << endl;
                                            cout << endl;
                                            cout << "Select option: ";
                                            cin >> confirmWithdrawal;

                                            if (confirmWithdrawal == "1") {
                                                cout << endl;
                                                currentUserBalance -= withdrawalAmount;

                                                cout << "Withdrawal complete." << endl;
                                                cout << "Your new balance is GHS" << currentUserBalance << endl;
                                                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                                                cout << endl;
                                                cout << endl;
                                                cout << "Returning to main menu. Please wait" << endl;
                                                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                                                userPanel();
                                            }

                                            else if (confirmWithdrawal == "2") {
                                                cout << endl;
                                                cout << "Cancelling transaction. Please wait" << endl;
                                                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                                                cout << endl;
                                                cout << endl;
                                                cout << "Returning to main menu. Please wait." << endl;
                                                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                                                userPanel();
                                            }

                                            else {
                                                cout << endl;
                                                cout << "Invalid input. Try again" << endl;
                                                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                                                cout << endl;
                                            }
                                        }

                                    }
                                    else {
                                        cout << endl;
                                        cout << "Your balance is insufficient to make this transaction. Your current balance is GHS " << currentUserBalance << endl;
                                        cout << "Try again." << endl;
                                        cout << endl;
                                    }
                                }

                                else {
                                    cout << endl;
                                    cout << "Invalid input. Try again" << endl;
                                    cout << endl;
                                }
                            }

                        }

                        else {
                            cout << endl;
                            cout << "Numbers do not match. Try again" << endl;
                            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                            cout << endl;
                        }
                    }
                }
                else {
                    cout << endl;
                    cout << "Invalid input. Try again" << endl;
                    cout << endl;
                }
            }
        }

        else if (choice == "2") {
            cout << endl;
            cout << "" << endl;
        }

        else {
            cout << endl;
            cout << "Invalid input. Try again" << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            cout << endl;

        }
    }

}

double userBalance() {
    return currentUserBalance;
}


//----------------------------------------------------------------Function to transact to bank------------------------------------------------------------------//
void transactToBank() {
    while (true) {
        string accountNumber;
        string confirmAccountNumber;

        cout << endl;
        cout << "Enter Account number" << endl;

        cout << "Enter here: ";  cin >> accountNumber;

        cout << endl;
        if (accountNumber.length() == 10 && regex_match(accountNumber, regex("[0-9]+"))) {

            while (true) {
                cout << "Re-enter Account number" << endl;


                cout << "Enter here: ";  cin >> confirmAccountNumber;

                if (accountNumber == confirmAccountNumber) {

                    while (true) {
                        string amount;
                        double amountNum;
                        cout << endl;


                        cout << "Enter Amount" << endl;

                        cout << "Enter here: ";  cin >> amount;

                        if (regex_match(amount, regex("[0-9]+"))) {
                            amountNum = stod(amount);

                            if (amountNum <= userBalance()) {
                                int count = 0;

                                while (count < 3) {
                                    string userPin;
                                    cout << endl;
                                    cout << "Enter USER pin" << endl;

                                    cout << "Enter here: "; cin >> userPin;

                                    if (userPin == USER_PASSWORD) {
                                        int count = 0;

                                        while (true) {
                                            int confirmTransaction;

                                            cout << endl;

                                            cout << "You are making a transaction of GHS " << amount << " to " << accountNumber << endl;
                                            cout << endl;

                                            cout << "1. Confirm" << endl;
                                            cout << "2. Cancel" << endl;

                                            cout << "Enter here: "; cin >> confirmTransaction;
                                            if (confirmTransaction == 1) {
                                                cout << endl;
                                                shortLoading();

                                                cout << endl;
                                                cout << endl;

                                                currentUserBalance -= amountNum;
                                                cout << "Your transcation was successful. You sent GHS " << amount << " to " << accountNumber << "." << endl;
                                                cout << "Your new balance is GHS" << currentUserBalance << endl;

                                                cout << endl;
                                                cout << endl;

                                                while (true) {

                                                    cout << "Would you like to perform another transaction?" << endl;
                                                    cout << "(Y / N)" << endl;

                                                    char newTransaction;
                                                    cout << "Select Option: "; cin >> newTransaction;
                                                    cout << endl;

                                                    if (newTransaction == 'Y' || newTransaction == 'y') {

                                                        load();

                                                        while (true) {
                                                            cout << endl;
                                                            cout << "--------------------------------------------------------------------- SEND MONEY ---------------------------------------------------------------------------" << endl;
                                                            cout << endl;
                                                            transact();
                                                        }
                                                    }

                                                    else if (newTransaction == 'N' || newTransaction == 'n') {

                                                        cout << "Returning to main menu. Please wait" << endl;
                                                        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
                                                        return;
                                                    }

                                                    else {

                                                        cout << endl;
                                                        cout << "Enter a valid option." << endl;

                                                    }

                                                }


                                            }
                                            else if (confirmTransaction == 2) {
                                                cout << endl;
                                                cout << endl;

                                                cout << "Your transaction was cancelled.";
                                                cout << endl;

                                                cout << "Returning to main menu. Please wait" << endl;
                                                std::this_thread::sleep_for(std::chrono::milliseconds(5000));
                                                userPanel();
                                            }
                                            else {

                                                return;
                                            }

                                            /* return;*/
                                        }

                                    }

                                    else {
                                        count++;
                                        cout << endl;

                                        SetConsoleTextAttribute(consoleHandle, BACKGROUND_RED);
                                        cout << "Incorrect PIN.";
                                        SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);

                                        cout << " You have " << (3 - count) << " tries left." << endl;
                                    }


                                }
                                cout << endl;
                                std::this_thread::sleep_for(chrono::milliseconds(2000));
                                cout << "Too many tries." << endl;
                                cout << "Logging out" << endl;
                                cout << endl;
                                loggingOut();
                                main();

                            }
                            else {
                                cout << endl;
                                cout << "Your balance is insufficient to make this transaction. Your current balance is GHS " << currentUserBalance << endl;
                                cout << "Try again." << endl;

                            }
                        }
                        else {
                            cout << endl;
                            cout << "Enter a valid amount" << endl;
                        }
                    }

                }
                else {
                    cout << endl;
                    SetConsoleTextAttribute(consoleHandle, BACKGROUND_RED);

                    cout << "Numbers do not match. Try again" << endl;

                    SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
                    cout << endl;
                }
            }

        }
        else {
            cout << "Please enter a valid phone number" << endl;
            cout << endl;
        }
    }
}

void transact() {
    while (true) {
        string phoneNumber;
        string confirmPhoneNumber;

        cout << endl;
        cout << "Enter phone number" << endl;

        cout << "Enter here: ";  cin >> phoneNumber;

        cout << endl;
        if (phoneNumber.length() == 10 && regex_match(phoneNumber, regex("[0-9]+"))) {

            while (true) {
                cout << "Re-enter Account number" << endl;


                cout << "Enter here: ";  cin >> confirmPhoneNumber;

                if (phoneNumber == confirmPhoneNumber) {

                    while (true) {
                        string amount;
                        double amountNum;
                        cout << endl;


                        cout << "Enter Amount" << endl;

                        cout << "Enter here: ";  cin >> amount;

                        if (regex_match(amount, regex("[0-9]+"))) {
                            amountNum = stod(amount);

                            if (amountNum <= userBalance()) {
                                int count = 0;

                                while (count < 3) {
                                    string userPin;
                                    cout << endl;
                                    cout << "Enter USER pin" << endl;

                                    cout << "Enter here: "; cin >> userPin;

                                    if (userPin == USER_PASSWORD) {
                                        int count = 0;

                                        while (true) {
                                            int confirmTransaction;

                                            cout << endl;

                                            cout << "You are making a transaction of GHS " << amount << " to " << phoneNumber << endl;
                                            cout << endl;

                                            cout << "1. Confirm" << endl;
                                            cout << "2. Cancel" << endl;

                                            cout << "Enter here: "; cin >> confirmTransaction;
                                            if (confirmTransaction == 1) {
                                                cout << endl;
                                                shortLoading();

                                                cout << endl;
                                                cout << endl;

                                                currentUserBalance -= amountNum;
                                                cout << "Your transcation was successful. You sent GHS " << amount << " to " << phoneNumber << "." << endl;
                                                cout << "Your new balance is GHS" << currentUserBalance << endl;

                                                cout << endl;
                                                cout << endl;

                                                while (true) {

                                                    cout << "Would you like to perform another transaction?" << endl;
                                                    cout << "(Y / N)" << endl;

                                                    char newTransaction;
                                                    cout << "Select Option: "; cin >> newTransaction;
                                                    cout << endl;

                                                    if (newTransaction == 'Y' || newTransaction == 'y') {

                                                        load();

                                                        while (true) {
                                                            cout << endl;
                                                            cout << "--------------------------------------------------------------------- SEND MONEY ---------------------------------------------------------------------------" << endl;
                                                            cout << endl;
                                                            transact();
                                                        }
                                                    }

                                                    else if (newTransaction == 'N' || newTransaction == 'n') {

                                                        cout << "Returning to main menu. Please wait" << endl;
                                                        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
                                                        return;
                                                    }

                                                    else {

                                                        cout << endl;
                                                        cout << "Enter a valid option." << endl;

                                                    }

                                                }


                                            }
                                            else if (confirmTransaction == 2) {
                                                cout << endl;
                                                cout << endl;

                                                cout << "Your transaction was cancelled.";
                                                cout << endl;

                                                cout << "Returning to main menu. Please wait" << endl;
                                                std::this_thread::sleep_for(std::chrono::milliseconds(5000));
                                                userPanel();
                                            }
                                            else {

                                                return;
                                            }

                                            /* return;*/
                                        }

                                    }

                                    else {
                                        count++;
                                        cout << endl;

                                        SetConsoleTextAttribute(consoleHandle, BACKGROUND_RED);
                                        cout << "Incorrect PIN.";
                                        SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);

                                        cout << " You have " << (3 - count) << " tries left." << endl;
                                    }


                                }
                                cout << endl;
                                std::this_thread::sleep_for(chrono::milliseconds(2000));
                                cout << "Too many tries." << endl;
                                cout << "Logging out" << endl;
                                cout << endl;
                                loggingOut();
                                main();

                            }
                            else {
                                cout << endl;
                                cout << "Your balance is insufficient to make this transaction. Your current balance is GHS " << currentUserBalance << endl;
                                cout << "Try again." << endl;

                            }
                        }
                        else {
                            cout << endl;
                            cout << "Enter a valid amount" << endl;
                        }
                    }

                }
                else {
                    cout << endl;
                    SetConsoleTextAttribute(consoleHandle, BACKGROUND_RED);

                    cout << "Numbers do not match. Try again" << endl;

                    SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
                    cout << endl;
                }
            }

        }
        else {
            cout << "Please enter a valid phone number" << endl;
            cout << endl;
        }
    }
}

void favorites() {
    cout << endl;
    cout << endl;
    cout << "------------------------------------------------------------------ Send To Favorite ---------------------------------------------------------------------" << endl;
    cout << endl;

    if (favoriteNames.empty()) {
        cout << "Your favorite list is empty" << endl;
        cout << endl;
        int input;
        cout << "Press 0 to return to main menu" << endl;

        while (true) {
            cout << "Enter here: ";
            cin >> input;

            if (input == 0) {
                userPanel();
            }
            else {
                cout << endl;
                cout << "Invalid Input. Try again." << endl;
            }
        }
    }
    else {
    List:
        int favInput;
        cout << "Choose a number from your list" << endl;
        for (int i = 0; i < favoriteNames.size(); i++) {
            cout << endl;
            cout << i + 1 << ". " << favoriteNames[i] << " - " << favoriteNumbers[i] << endl;
        }
        while (true) {                                                                                                   //while loop to select favorite option
            cout << endl;
            cout << "Enter here: ";
            cin >> favInput;
            cout << endl;

            if (favInput <= favoriteNames.size()) {                                                                     //if statement to verify is input is within the list
                while (true) {
                    string amount;
                    double amountNum;
                    cout << endl;
                    cout << "Enter Amount" << endl;
                    cout << "Enter here: "; cin >> amount;

                    if (regex_match(amount, regex("[0-9]+"))) {
                        amountNum = stod(amount);

                        if (amountNum <= userBalance()) {
                            int count = 0;

                            while (count < 3) {
                                string userPin;
                                cout << endl;
                                cout << "Enter USER pin" << endl;

                                cout << "Enter here: "; cin >> userPin;

                                if (userPin == USER_PASSWORD) {
                                    int count = 0;

                                    while (true) {
                                        int confirmTransaction;

                                        cout << endl;

                                        cout << "You are making a transaction of GHS " << amount << " to " << favoriteNumbers[favInput - 1] << endl;
                                        cout << endl;

                                        cout << "1. Confirm" << endl;
                                        cout << "2. Cancel" << endl;

                                        cout << "Enter here: "; cin >> confirmTransaction;
                                        if (confirmTransaction == 1) {
                                            cout << endl;
                                            shortLoading();

                                            cout << endl;
                                            cout << endl;

                                            currentUserBalance -= amountNum;
                                            cout << "Your transcation was successful. You sent GHS " << amount << " to " << favoriteNumbers[favInput - 1] << "." << endl;
                                            cout << "Your new balance is GHS" << currentUserBalance << endl;

                                            cout << endl;
                                            cout << endl;

                                            while (true) {

                                                cout << "Would you like to perform another transaction?" << endl;
                                                cout << "(Y / N)" << endl;

                                                char newTransaction;
                                                cout << "Select Option: "; cin >> newTransaction;
                                                cout << endl;

                                                if (newTransaction == 'Y' || newTransaction == 'y') {
                                                    load();
                                                    while (true) {
                                                        clearScreen();
                                                        cout << endl;
                                                        cout << "--------------------------------------------------------------------- SEND MONEY ---------------------------------------------------------------------------" << endl;
                                                        cout << endl;
                                                        goto List;
                                                    }
                                                }

                                                else if (newTransaction == 'N' || newTransaction == 'n') {

                                                    cout << "Returning to main menu. Please wait" << endl;
                                                    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
                                                    userPanel();
                                                }

                                                else {

                                                    cout << endl;
                                                    cout << "Enter a valid option." << endl;
                                                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                                                }
                                            }
                                        }
                                        else if (confirmTransaction == 2) {
                                            cout << endl;
                                            cout << endl;

                                            cout << "Your transaction was cancelled.";
                                            cout << endl;

                                            cout << "Returning to main menu. Please wait" << endl;
                                            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                                            return;
                                        }
                                        else {

                                            return;
                                        }

                                        /* return;*/
                                    }
                                }
                                else {
                                    count++;
                                    cout << endl;

                                    SetConsoleTextAttribute(consoleHandle, BACKGROUND_RED);
                                    SetConsoleTextAttribute(consoleHandle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);

                                    cout << " You have " << (3 - count) << " tries left." << endl;
                                }
                            }
                            cout << endl;
                            std::this_thread::sleep_for(chrono::milliseconds(2000));
                            cout << "Too many tries." << endl;
                            cout << "Logging out" << endl;
                            cout << endl;
                            loggingOut();
                            main();
                        }
                        else {
                            cout << endl;
                            cout << "Your balance is insufficient to make this transaction. Your current balance is GHS " << currentUserBalance << endl;
                            cout << "Try again." << endl;

                        }
                    }
                    else {
                        cout << endl;
                        cout << "Enter a valid amount" << endl;
                    }
                }
            }
            else {
                cout << endl;
                cout << "Enter a valid number" << endl;
            }
        }

    }
}

//----------------------------------------------------------------Function for My Account Menu----------------------------------------------------------//
void myAccount() {

myAccount:
    clearScreen();
    cout << endl;
    cout << endl;
    cout << "---------------------------------------------------------------- My Account -------------------------------------------------------------------------------" << endl;
    cout << endl;

    cout << "1. Add new favorite" << endl;
    cout << "2. Remove contact from favorite" << endl;
    cout << "3. Change username or password" << endl;
    cout << "4. Check balance" << endl;
    cout << "0. Go back" << endl;

    while (true) {
        int choice;
        cout << endl;
        cout << "Enter here: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << endl;
            cout << "Enter name" << endl;

            while (true) {
                addFavorite();
            }
        }
        else if (choice == 2) {
            deleteFavorite(favoriteNumbers);
            //remove contact
        }

        else if (choice == 3) {
            //change credentials
            int changeCred;
            cout << endl;
            cout << "1. Change password" << endl;
            cout << "2. Change username" << endl;
            cout << endl;

            while (true) {
                cout << "Enter here: ";
                cin >> changeCred;

                if (changeCred == 1) {
                    cout << endl;
                    cout << "Enter old password" << endl;

                    int count = 0;
                    while (count < 3) {
                        string oldPass;
                        cout << "Enter here: ";
                        cin >> oldPass;
                        if (oldPass == USER_PASSWORD) {

                        Newpass:
                            string newPass;
                            cout << endl;
                            cout << "Enter your new password" << endl;
                            cout << "Enter here: ";
                            cin >> newPass;

                            while (true) {
                                string confirmNewPass;
                                cout << endl;
                                cout << "Re-enter your new password" << endl;
                                cout << "Enter here: ";
                                cin >> confirmNewPass;

                                if (newPass == confirmNewPass) {
                                    USER_PASSWORD = newPass;
                                    cout << endl;
                                    cout << "New password created!" << endl;
                                    std::this_thread::sleep_for(std::chrono::milliseconds(1300));
                                    cout << endl;
                                    cout << "Returning to main menu. Please wait." << endl;
                                    std::this_thread::sleep_for(std::chrono::milliseconds(200));
                                    userPanel();
                                }

                                else {
                                    cout << endl;
                                    cout << "Password did not match. Try again" << endl;
                                    goto Newpass;
                                }
                            }
                        }
                        else {
                            count++;
                            cout << endl;
                            cout << "Invalid Pin. Please try again." << endl;
                            cout << "You have " << 3 - count << " tries left" << endl;
                        }
                    }
                    cout << endl;
                    cout << "Max attempts reached. Logging out" << endl;
                    loggingOut();
                }
                else if (changeCred == 2) {
                    string newUsername;
                    cout << endl;
                    cout << "Enter your new username" << endl;
                    cout << "Enter here: ";
                    cin >> newUsername;
                    USER_NAME = newUsername;
                    cout << endl;
                    cout << "New username created!" << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1300));
                    cout << endl;
                    cout << "Returning to main menu. Please wait" << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                    userPanel();
                }

                else {
                    cout << endl;
                    cout << "Invalid input. Try again" << endl;
                }
            }
        }

        else if (choice == 4) {
            clearScreen();
            cout << endl;
            cout << "1. Your Unreal account balance is GHS" << userBalance() << endl;
            cout << endl;

            cout << "2. Your bank account is GHS" << bankBalance << endl;
            cout << endl;

            cout << "3. Your Mobile Money account balance is GHS" << momoBalance << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;

            cout << "Press 0 to go back" << endl;

            while (true) {
                char goBack;
                cout << "Enter here: "; cin >> goBack;

                if (goBack == '0') {
                    goto myAccount;
                }
                else {
                    cout << endl;
                    cout << "Invalid input. Try again." << endl;
                }
            }
        }
        else if (choice == 0) {
            userPanel();
        }
        else {
            cout << endl;
            cout << "Invalid input. Try again" << endl;
        }
    }
}