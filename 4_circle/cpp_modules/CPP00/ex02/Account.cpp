/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:25:09 by dkim2             #+#    #+#             */
/*   Updated: 2022/06/23 22:43:02 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

// PRIVATE MEMBER
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//time stamp format : [YYYYMMDD_hhmmss]
void Account::_displayTimestamp( void )
{
	std::time_t currTime = std::time(0);
	struct tm localTime;
	localtime_r(&currTime, &localTime);
	std::cout << std::setfill('0');
	std::cout << "[";
	std::cout << std::setw(4) << localTime.tm_year + 1900;
	std::cout << std::setw(2) << localTime.tm_mon + 1;
	std::cout << std::setw(2) << localTime.tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << localTime.tm_hour;
	std::cout << std::setw(2) << localTime.tm_min;
	std::cout << std::setw(2) << localTime.tm_sec;
	std::cout << "]";
	std::cout << set::setfill('_');
}

Account::Account( void )
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

// PUBLIC STATIC METHOD
int Account::getNbAccounts( void ) {return (_nbAccounts);}

int Account::getTotalAmount( void ) {return (_totalAmount);}

int Account::getNbDeposits( void ) {return (_totalNbDeposits);}

int Account::getNbWithdrawals ( void ) {return (_totalNbWithdrawals);}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}

// PUBLIC METHOD
Account::Account( int initial_deposit )
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
	_nbAccounts--;
}

void Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposits:" << deposit << ";";
	
	_amount += deposit;
	_totalAmount += deposit;
	
	std::cout << "amount:" << _amount << ";";
	
	_nbDeposits++;
	_totalNbDeposits++;
	
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool Account::makeWithdrawal ( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if (_amount - withdrawal < 0)
	{
		std::cout << "withdrwal:refused" << std::endl;
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "amount:" << _amount << ";";
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "nb_withdrawal:" << _nbWithdrawals;
	std::cout << std::endl;
	return (true);
}

int Account::checkAmount( void ) const
{
	return (_amount);
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}
