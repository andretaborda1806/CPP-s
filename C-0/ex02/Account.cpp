#include "Account.hpp"

#include <iostream>
#include <stdexcept>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit): _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    if (initial_deposit <= 0)
        std::cout <<"Not enought money to open account!";
    else {
        std::cout << "Account created!" << std::endl;
        _nbAccounts++;
        _totalAmount += initial_deposit;
    }
}
Account::~Account(){
}


void    Account::makeDeposit( int deposit){
    if (deposit <= 0)
        std::cout << "Too broke to make a deposit!" << std::endl;
    else{
        std::cout << "Deposit sucessful!" << std::endl;
        _amount += deposit;
        _totalAmount += deposit;
        _totalNbDeposits++;
    }
}

bool    Account::makeWithdrawal(int withdrawal){
    if (withdrawal > 0 && withdrawal <= _amount)
    {
        std::cout << "Sucessfully withdrwaled" << withdrawal << "Your current balance is " << _amount << std::endl;
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _totalAmount -= withdrawal;
        return (true);
    }
    else
    {
        std::cout << "Cant withdrawl, Your current balance is " << _amount << std::endl;
        return (false);
    }
}

int     Account::checkAmount(void) const {
    std::cout << "Your current balance is " << _amount << std::endl;
    return _amount;
}

void    Account::displayStatus(void) const {
    std::cout << "Account number: " << _accountIndex << std::endl;
    std::cout << "Acount balance: " << _amount << std::endl;
    std::cout << "Number of deposits: " << _nbDeposits << std::endl;
    std::cout << "Number of withdrwals: " << _nbWithdrawals << std::endl;
}

int     Account::getNbAccounts(void){
    std::cout << "Number of Accounts: " << _nbAccounts << std::endl;
    return (_nbAccounts);
}

int Account::getTotalAmount(void){
    std::cout << "Total balance: " << _totalAmount << std::endl;
    return (_totalAmount);
}

int Account::getNbDeposits(void){
    std::cout << "Number of deposits made: " << _totalNbDeposits << std::endl;
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void){
    std::cout << "NUmber of withrawals: " << _totalNbWithdrawals << std::endl;
    return _totalNbWithdrawals;
}


void Account::displayAccountsInfos(void){
    std::cout << "Number of Accounts: " << _nbAccounts << std::endl;
    std::cout << "Total balance: " << _totalAmount << std::endl;
    std::cout << "Number of deposits made: " << _totalNbDeposits << std::endl;
    std::cout << "NUmber of withrawals: " << _totalNbWithdrawals << std::endl;
}
