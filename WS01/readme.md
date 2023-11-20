#SEP200 - Lab 1: The Bank Manager
Due:
This lab will test your ability to overload operators.

You have been given five files: BankMain.cpp, BankManager.cpp, BankManager.h, InvestmentAccount.cpp and InvestmentAccount.h.
BankMain.cpp has been completely implemented for you. BankManager.cpp and BankManager.h are missing one function, the overload of the == operator. InvestmentAccount.cpp and InvestmentAccount.h are mostly empty. The only functions implemented are PurchaseStocks and SellStocks. The others have not.

For BankManager.cpp, implement the overloading of the == operator such that true is returned if the names of the investment accounts are the same, false otherwise. Do not forget the function prototype in the header file BankManager.h. On the other hand, you might wish to overload the == operator inside theInvestmentAccount class instead.
For InvestmentAccount.cpp, implement the overload of the += operator. This should add cash to the investment account. If the amount to be added is negative, print out the error message "Invalid transaction". Do not forget the function prototype in the header file InvestmentAccount.h.
For InvestmentAccount.cpp, implement the overload of the -= operator. This should subtract cash from the investment account. If the amount to be subtracted is negative, print out the error message "Invalid transaction". If there isn't enough cash in the account, print out the error message "Not enough funds in the account for <name>". Be sure to insert the name in the error message. See the sample run below as an example. Do not forget the function prototype in the header file InvestmentAccount.h
Implement the constructors for InvestmentAccount. The variables name and cash should default to "" and 0.0 respectively.
Implement all getter functions for InvestmentAccount - GetName(), GetValue(), GetStocks() and GetCash().
Implement the destructor for InvestmentAccount. Be sure to wipe out all information.
A sample run is as follows:

    David Sands has $18900 in stocks and $1100 in cash.
    Kamla Patel has $27880 in stocks and $2120 in cash.
    Wing Chung has $44678 in stocks and $5322 in cash.
    
    Not enough funds in the account for Kamla Patel.
    David Sands has $18900 in stocks and $6100 in cash.
    Kamla Patel has $27880 in stocks and $2120 in cash.
    Wing Chung has $44678 in stocks and $15322 in cash.
    
    clients 2 and 3 are the same
To assist you with this lab, you might want to look at the following sample code about sports organizations which uses operator overloading for comparisons and for streaming output data:
Team.h and SportsOrganization.cpp.

Be sure to document your code with the file name, your name and student number. Add comments throughout the code where necessary.

Questions
Do you prefer the overloading of += and -= (ie *client[0] += 5000; *client[1] -= 5000;) or would you prefer it if InvestmentAccount had functions to add cash and withdraw cash? Why?
Do you prefer the overloading of == (ie if (*client[0] == client3) {..} or would you prefer to call a function to compare two clients? Why?
Why might it be necessary to wipe out all information in the destructor of InvestmentAccount?
Lab Submission:
Please email your files and the answers to the questions to: miguel.watler@senecacollege.ca

NOTE: My last name is Watler not Walter.
Late Policy
You will be docked 10% if your lab is submitted 1-2 days late.
You will be docked 20% if your lab is submitted 3-4 days late.
You will be docked 30% if your lab is submitted 5-6 days late.
You will be docked 40% if your lab is submitted 7 days late.
You will be docked 50% if your lab is submitted over 7 days late.
