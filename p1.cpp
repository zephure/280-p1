//
//  p1.cpp
//  
//  Name : Kern Luo
//  Class : EECS 280
//  Prof : Ringenberg
//  Date : 8 Jan 2015
//

#include <cstdlib>
#include <cmath>
#include "io.h"

using namespace std;

//      EFFECTS: prints out the values for the payment info table given the user's inputs
//               for the monthly payment, interest rate, and duration of the loan.
//      MODIFIES: standard output stream
int PrintTable(double p, double r, double years);

int main() {
    
    double monthlyPayment, rate, loanYears;
        
    //using GetParam to retrieve the 3 parameters needed
    monthlyPayment = GetParam("Please enter the monthly payment: ", 1, 100000);
    rate = GetParam("Please enter the interest rate: ", 0, 1);
    loanYears = GetParam("Please enter the duration of the loan, in years: ", 1, 100);
    
    //if the duration entered by the user is not a whole integer number, this repeats the prompt
    bool keepgoing = true;
    while (keepgoing) {
        
        if (fmod(loanYears, 1) != 0) {
            loanYears = GetParam("Please enter the duration of the loan, in years: ", 1, 100);
        }
        else if (fmod(loanYears, 1) == 0) {
            keepgoing = false;
        }
        
    }
    
    PrintTable(monthlyPayment, rate, loanYears);
    
    return 0;
    
}

//      EFFECTS: prints out the values for the payment info table given the user's inputs
//               for the monthly payment, interest rate, and duration of the loan.
//      MODIFIES: standard output stream
int PrintTable(double p, double r, double years) {
    
    //print the header first
    PrintHeader();
    
    //represent the duration of the loan in months
    int months = years * 12;
    
    double balance, principal, interest;
    
    //this is the first month case where the final outstanding balance becomes zero
    balance = p / (1 + r / 12);
    interest = (r / 12) * balance;
    principal = p - interest;
    
    PrintMonthlyData(months, principal, interest, balance);
    months--;
    
    //now continue to print out the rest of the lines until the month number reaches zero
    while(months > 0) {
        
        balance = (balance + p) / (1 + r / 12);
        interest = (r / 12) * balance;
        principal = p - interest;
        
        PrintMonthlyData(months, principal, interest, balance);
        
        months--;
    }
    
    return 0;

}
