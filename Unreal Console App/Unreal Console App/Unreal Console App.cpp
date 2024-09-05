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