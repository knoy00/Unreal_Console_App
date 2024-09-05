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