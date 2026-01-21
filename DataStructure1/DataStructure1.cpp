#include <iostream>
#include "clsQueueLine.h"

using namespace std;

int main()
{

    clsQueueLine MyLine("A0",4);

    MyLine.IssueTicket();
    MyLine.IssueTicket();
    MyLine.IssueTicket();
    MyLine.IssueTicket();

    cout << "MyLine Info: \n";
    MyLine.PrintInfo();

    MyLine.PrintTicketsLineRTL();
    MyLine.PrintTicketsLineLTR();

    MyLine.PrintAllTickets();

    cout << "Queue after serving one client: \n";
    MyLine.ServeNextClient();
    MyLine.PrintInfo();
    MyLine.PrintAllTickets();

    system("pause>0"); // Windows-only, used to pause console


}