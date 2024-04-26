/*
Name: Chanelle Harris
Project Two: Airgead Banking App
Date: 04/05/2024
Class: CS-210: Program Languages
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    //variables library to use in code
    float initInv, monDep, AnuInt, years, months;
    float totalAm;
    float intAmt, yearTotInt;

    //Display menu 
    cout << "************************************\n";
    cout << "************ Data Input ************\n";
    cout << "************************************\n";
    cout << "Initial Investment Amount: ";
    cin >> initInv;
    cout << "Monthly Deposit: ";
    cin >> monDep;
    cout << "Annual Interest: ";
    cin >> AnuInt;
    cout << "Number of years: ";
    cin >> years;

    months = years * 12;

    // Pause for user to read the input
    system("PAUSE");

    // Display report setup
    cout << "************************************\n";
    cout << "************ Data Review ************\n";
    cout << "************************************\n";
    cout << "Initial Investment Amount: " << initInv << endl;
    cout << "Monthly Deposit: " << monDep << endl;
    cout << "Annual Interest: " << AnuInt << "%" << endl;
    cout << "Number of years: " << years << endl;

    
    system("PAUSE");

    totalAm = initInv;

    // Display calculations without monthly deposits
    cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < years; i++) {
        intAmt = totalAm * (AnuInt / 100);
        totalAm = totalAm + intAmt;
        cout << (i + 1) << "\t\t" << fixed << setprecision(2) << totalAm << "\t\t\t" << intAmt << "\n";
    }

    totalAm = initInv;

    // Display calculations with monthly deposits
    cout << "\nBalance and Interest With Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < years; i++) {
        yearTotInt = 0;
        for (int j = 0; j < 12; j++) {
            intAmt = (totalAm + monDep) * ((AnuInt / 100) / 12);
            yearTotInt = yearTotInt + intAmt;
            totalAm = totalAm + monDep + intAmt;
        }
        cout << (i + 1) << "\t\t" << fixed << setprecision(2) << totalAm << "\t\t\t" << yearTotInt << "\n";
    }

    return 0;
}