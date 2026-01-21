#pragma once
using namespace std;
#include <string>
#include <queue>
#include "clsDate.h"
#include "clsMyStackArr.h"

class clsQueueLine 
{

private:

	short _ServiceTime;
	string _Prefix;

	short _TotalTickets ;
	short _ServedClients;
	short _WaitingClients;

	short OrderCount ;
	
	struct stTicket
	{

		string PrefixNumber;
		string Date;
		short WaitingClients;
		short ServiceTime;

	};
	
	queue<stTicket> MyQueue;

public:
	
	clsQueueLine(string Prefix, short ServiceTime)
	{
		_ServiceTime = ServiceTime;
		_Prefix = Prefix;

		_TotalTickets = 0;

		_ServedClients = 0;
		_WaitingClients = 0;
		OrderCount = 0;

		
	}
	
	void IssueTicket()
	{
		stTicket NewTicket;

		NewTicket.PrefixNumber = _Prefix + to_string(OrderCount++);
		NewTicket.Date = clsDate::GetSystemDateTimeString();
		NewTicket.WaitingClients = _WaitingClients;
		NewTicket.ServiceTime = _ServiceTime * _WaitingClients;

		_WaitingClients++;
		_TotalTickets++;

		MyQueue.push(NewTicket);

	}
	
	void PrintInfo()
	{
		cout << "\n\n\t\t\t\t-------------------\n";
		cout << "\t\t\t\tQueue Info\n";
		cout << "\t\t\t\t-------------------\n";
		cout << "\t\t\t\tPrefix = " << _Prefix << "\n";
		cout << "\t\t\t\tTotal Tickets = " << _TotalTickets << "\n";
		cout << "\t\t\t\tServed Clients = " << _ServedClients << "\n";
		cout << "\t\t\t\tWaiting Clients = " << _WaitingClients << "\n";
	}

	void PrintAllTickets()
	{
		stTicket Ticket;
		queue<stTicket> Temp = MyQueue;

		cout << "\n\n\t\t\t\t\tTickets\n";
		for (short i = 0; i < MyQueue.size(); i++)
		{
			cout << "\t\t\t\t-------------------\n";
			Ticket = Temp.front();
			cout << "\t\t\t\t" << Ticket.PrefixNumber << "\n";
			cout <<  "\t\t\t\t" << Ticket.Date << "\n";
			cout << "\t\t\t\tWaiting Clients = " << Ticket.WaitingClients << "\n";
			cout << "\t\t\t\tService Time In:\n";
			cout << "\t\t\t\t" << Ticket.ServiceTime << "\n";
			cout << "\t\t\t\t-------------------\n";
			Temp.pop();
		}
	}

	void PrintTicketsLineRTL()
	{
		stTicket TicketPrefix;
		queue<stTicket> Temp = MyQueue;

		cout << "\n\t\t\t\tTickets: ";

		for (short i = 0; i < MyQueue.size(); i++)
		{
			TicketPrefix = Temp.front();
			cout << TicketPrefix.PrefixNumber << " -->";
			Temp.pop();
		}
		cout << endl;
	}

	void PrintTicketsLineLTR()
	{
		stTicket TicketPrefix;
		queue<stTicket> TempQueue = MyQueue;
		clsMyStackArr<stTicket> TempStack;

		while (TempQueue.size() > 0)
		{
			TempStack.push(TempQueue.front());
			TempQueue.pop();
		}


		cout << "\n\t\t\t\tTickets: ";

		while (TempStack.Size() > 0)
		{
			TicketPrefix = TempStack.front();
			cout << TicketPrefix.PrefixNumber << " <--";
			TempStack.pop();
		}
		cout << endl;

	}


	void ServeNextClient()
	{
		MyQueue.pop();
		_ServedClients++;
   	    _WaitingClients--;
	}

};