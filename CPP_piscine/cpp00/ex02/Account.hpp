// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void );       //Получить кол-во счетов
	static int	getTotalAmount( void );      //Получить общую сумму средств всех счестов
	static int	getNbDeposits( void );       //Получить общее количество взносов
	static int	getNbWithdrawals( void );    //Получить общее кол-во снятий средств
	static void	displayAccountsInfos( void );//Получить общую информацию по счетам

	Account( int initial_deposit );           //Открыть счет (Первоночальная сумма взноса)
	~Account( void );

	void	makeDeposit( int deposit );       //Сделать дополнительный взнос(сумма взноса)
	bool	makeWithdrawal( int withdrawal ); //Вывести средства (сума снятия)
	int		checkAmount( void ) const;        //Узнать общую сумму средств на счете
	void	displayStatus( void ) const;      //Отобразить статус(текущее состояние) счета



private:

	static int	_nbAccounts;            //Кол-во аккаунтов
	static int	_totalAmount;           //Итого: сумма средств по всем счетам
	static int	_totalNbDeposits;       //Общее кол-во дополнительных взносов
	static int	_totalNbWithdrawals;    //Общее кол-во снятия средств

	static void	_displayTimestamp( void );

	int				_accountIndex;     //Номер счета
	int				_amount;           //Кол-во средств на счету
	int				_nbDeposits;       //Кол-во взносов
	int				_nbWithdrawals;    //Кол-во снятий

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
