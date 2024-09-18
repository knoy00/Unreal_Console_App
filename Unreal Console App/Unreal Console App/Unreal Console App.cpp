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