#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;        //присваиваем статическим переменным начальное значение
int	Account::_totalAmount = 0;       //static - общee для всех
int	Account::_totalNbDeposits = 0;   // они static просто не пишем тут
int	Account::_totalNbWithdrawals = 0;//все есть в классе

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount <<
	";created" << std::endl; //выводится первые 8 строк
	_nbAccounts++;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t sec = std::time(NULL); //сколько секунд прошло с
	std::tm tm = *std::localtime(&sec); // преобразование в норм формат
	std::cout << "[" << std::setfill('0')
			<< std::setw(4) << tm.tm_year + 1900
			<< std::setw(2) << tm.tm_mon + 1
			<< std::setw(2) << tm.tm_mday << "_"
			<< std::setw(2) << tm.tm_hour
			<< std::setw(2) << tm.tm_min
			<< std::setw(2) << tm.tm_sec << "] ";
}

int Account::getNbAccounts()
{
	return (Account:: _nbAccounts);
}

int Account::getTotalAmount()
{
	return (Account:: _totalAmount);
}

int Account::getNbDeposits()
{
	return (Account:: _totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (Account:: _totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:"<< getNbAccounts() << ";total:" <<
	getTotalAmount() << ";deposits:" << getNbDeposits() << ";widthdrawals:" <<
	getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_totalNbDeposits++;
	_totalAmount += deposit;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount <<
	";deposit:" << deposit << ";amount:"<< _amount + deposit <<";nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (_amount >= withdrawal)
	{
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount <<
		";withdrawal:" << withdrawal << ";amount:"<< _amount - withdrawal <<";nb_withdrawals:" << _nbDeposits << std::endl;
		_amount -= withdrawal;
		return (true);
	}
	else
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount <<
		";withdrawal:refused" << std::endl;
		return (false);
	}
}

int Account::checkAmount() const
{
	return (Account::_totalAmount);
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount <<
	";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
