# Workshop 1: The Bank Manager
## Due Date: Friday, May 27, 2022 before 23:59
## Workshop Objectives  
This workshop will test your ability to overload operators.

## Submission Policy
The workshop should contain ***only work done by you this term*** or provided by your professor.  Work done in another term (by you or somebody else), or work done by somebody else and not **clearly identified/cited** is considered plagiarism, in violation of the Academic Integrity Policy.

Every file that you submit must contain (as a comment) at the top **your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

- If the file contains only your work, or work provided to you by your professor, add the following message as a comment at the top of the file:

    > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

- If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which parts of the assignment are given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrong doing.

## Introduction and Workshop Tasks
You have been given five files: `BankMain.cpp`, `BankManager.cpp`, `BankManager.h`, `InvestmentAccount.cpp` and `InvestmentAccount.h`.

- `BankMain.cpp` has been completely implemented for you. 
- `BankManager.cpp` and `BankManager.h` are missing one function, the overload of the **== operator**. 
- `InvestmentAccount.cpp` and `InvestmentAccount.h` are **mostly empty**. The only functions implemented are **PurchaseStocks** and **SellStocks**. The others have not.


	- For `BankManager.cpp`, implement the overloading of the **== operator** such that true is returned if the names of the investment accounts are the same, false otherwise. Do not forget the function prototype in the header file `BankManager.h`
	- For `InvestmentAccount.cpp`, implement the overload of the **+= operator**. This should add cash to the investment account. If the amount to be added is negative, print out the error message `"Invalid transaction"`. Do not forget the function prototype in the header file `InvestmentAccount.h`.
	- For `InvestmentAccount.cpp`, implement the overload of the **-= operator**. This should subtract cash from the investment account. If the amount to be subtracted is negative, print out the error message `"Invalid transaction"`. If there isn't enough cash in the account, print out the error message `"Not enough funds in the account for <name>"`. Be sure to insert the name in the error message. See the sample run below as an example. Do not forget the function prototype in the header file `InvestmentAccount.h`
	- Implement the constructors for `InvestmentAccount`. The variables name and cash should default to `""` and `0.0` respectively.
	- Implement all getter functions for `InvestmentAccount`: `GetName()`, `GetValue()`, `GetStocks()` and `GetCash()`.
	- Implement the destructor for `InvestmentAccount`. **Be sure to wipe out all information**.

- To assist you with this lab, you might want to look at the following sample code about sports organizations which use operator overloading for comparisons and streaming output data: `Team.h` and `SportsOrganization.cpp`.

Be sure to document your code with the file name, your name and student number. Add comments throughout the code where necessary.


### Sample Output
A sample run is as follows:
```
    David Sands has $18900 in stocks and $1100 in cash.
    Kamla Patel has $27880 in stocks and $2120 in cash.
    Wing Chung has $44678 in stocks and $5322 in cash.
    
    Not enough funds in the account for Kamla Patel.
    David Sands has $18900 in stocks and $6100 in cash.
    Kamla Patel has $27880 in stocks and $2120 in cash.
    Wing Chung has $44678 in stocks and $15322 in cash.
    
    clients 2 and 3 are the same
```
## Reflection
Study your workshop solution, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop.
Create a **text** file named `reflect.txt` that contains the answers to the following questions 

1. Do you prefer the overloading of += and -= (ie `*client[0] += 5000;` `*client[1] -= 5000;`) or would you prefer it if InvestmentAccount had functions to add cash and withdraw cash? Why?
2.	Do you prefer the overloading of == (ie if (`*client[0] == client3) {..}` or would you prefer to call a function to compare two clients? Why?
3.	Why might it be necessary to wipe out all information in the destructor of InvestmentAccount?


## Submission

Test and demonstrate the execution of your program using the data given to you and make sure your code is generating output similar to the above example.



- Please email five files: `BankMain.cpp`, `BankManager.cpp`, `BankManager.h`, `InvestmentAccount.cpp` and `InvestmentAccount.h` in addition to the `reflect.txt` to email address: <mufleh.al-shatnawi@senecacollege.ca>

- Email Subject Line should be **`SEP200-NAA-WS01`**

####  Late submissions will incur a 25% penalty each day.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.

