#include "pch.h"
#include "InterestCalculator.h"
#include <iostream>
#include <limits>
#include <iomanip>


// functions for input validation

void InterestCalculator::readInitialInvestment()
{
    double investment;
    while (true)
    {
        std::cout << "Initial Investment Amount: ";
        std::cin >> investment;

        // Check if the input is valid and there are no leftover characters
        if (std::cin.fail() || investment < 0 || std::cin.peek() != '\n')
        {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "Invalid input. Please enter a positive number." << std::endl;
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the rest of the input buffer
            setInitialInvestment(investment);
            break;
        }
    }
}

void InterestCalculator::readMonthlyDeposit()
{
    double deposit;
    while (true)
    {
        std::cout << "Monthly Deposit: ";
        std::cin >> deposit;

        // Check if the input is valid and there are no leftover characters
        if (std::cin.fail() || deposit < 0 || std::cin.peek() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a positive number." << std::endl;
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the rest of the input buffer
            setMonthlyDeposit(deposit);
            break;
        }
    }
}

void InterestCalculator::readInterestRate()
{
    int rate;
    while (true)
    {
        std::cout << "Annual Interest: ";
        std::cin >> rate;

        // Check if the input is valid and there are no leftover characters
        if (std::cin.fail() || rate < 0 || std::cin.peek() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a positive number." << std::endl;
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the rest of the input buffer
            setInterestRate(rate);
            break;
        }
    }
}

void InterestCalculator::readDuration()
{
    int duration;
    while (true)
    {
        std::cout << "Duration: ";
        std::cin >> duration;

        // Check if the input is valid and there are no leftover characters
        if (std::cin.fail() || duration < 0 || std::cin.peek() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a positive number." << std::endl;
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the rest of the input buffer
            setDuration(duration);
            break;
        }
    }
}

// getter/setter functions

void InterestCalculator::setInitialInvestment(double t_investment)
{
	m_initialInvestment = t_investment;
}

double InterestCalculator::getInitialInvestment() const
{
	return m_initialInvestment;
}

void InterestCalculator::setMonthlyDeposit(double t_deposit)
{
	m_monthlyDeposit = t_deposit;
}

double InterestCalculator::getMonthlyDeposit() const
{
	return m_monthlyDeposit;
}

void InterestCalculator::setInterestRate(int t_rate)
{
	m_interestRate = t_rate;
}

int InterestCalculator::getInterestRate() const
{
	return m_interestRate;
}

void InterestCalculator::setDuration(int t_duration)
{
	m_duration = t_duration;
}

int InterestCalculator::getDuration() const
{
	return m_duration;
}

void InterestCalculator::setTotal(double t_total)
{
    m_total = t_total;
}

double InterestCalculator::getTotal() const
{
    return m_total;
}

void InterestCalculator::setInterestTotal(double t_interestTotal)
{
    m_interestTotal = t_interestTotal;
}

double InterestCalculator::getInterestTotal() const
{
    return m_interestTotal;
}

// print functions
// these are all formatted to look nice together

void InterestCalculator::mainMenu()
{
    // Printing the header of the program
    char border = '*';
    for (int i = 0; i < 32; ++i)
        std::cout << border;
    std::cout << '\n';
    for (int i = 0; i < 10; ++i)
        std::cout << border;
    std::cout << " DATA INPUT ";
    for (int i = 0; i < 10; ++i)
        std::cout << border;
    std::cout << "\n\n";
}

void InterestCalculator::withoutDepositsHeader()
{
    std::cout << '\n';
    for (int i = 0; i < 60; ++i)
    {
        std::cout << "=";
    }
    std::cout << "\n  Balance and Interest Without Additional Monthly Deposits\n";
    for (int i = 0; i < 60; ++i) 
    {
        std::cout << "=";
    }
    std::cout << "\n  Year        Year End Balance    Year End Earned Interest\n";
    for (int i = 0; i < 60; ++i)
    {
        std::cout << "-";
    }
}

void InterestCalculator::withDepositsHeader()
{
    std::cout << '\n';

    for (int i = 0; i < 60; ++i)
    {
        std::cout << "=";
    }
    std::cout << "\n     Balance and Interest With Additional Monthly Deposits\n";
    for (int i = 0; i < 60; ++i)
    {
        std::cout << "=";
    }
    std::cout << "\n  Year        Year End Balance    Year End Earned Interest\n";
    for (int i = 0; i < 60; ++i)
    {
        std::cout << "-";
    }
}

void InterestCalculator::outputResult(int t_year)
{
    std::cout << std::left << std::setw(3) <<"\n" << t_year << std::right << std::setw(20) << "$" << std::fixed << std::setprecision(2) << getTotal() << "                  $" << getInterestTotal();
}

// calculation functions
void InterestCalculator::userInputs()
{
	// Calling input funcitons with validation
	readInitialInvestment();
	readMonthlyDeposit();
	readInterestRate();
	readDuration();
}

void InterestCalculator::calculateInterestWithDeposits()
{
    withDepositsHeader();
    setTotal(getInitialInvestment());
    double tempTotal;
    double monthlyInterest;
    double yearlyInterest = 0.0;

    // this for loop represents the years
    for (int j = 0; j < getDuration(); ++j)
    {
        // this for loop represents the interest compounded every month in the year
        for (int i = 0; i < 12; ++i)
        {
            //calculates how much interest is accrued every month
            monthlyInterest = (getTotal() + getMonthlyDeposit()) * ((getInterestRate()/100.0)/12);
            tempTotal = (getTotal() + getMonthlyDeposit()) + monthlyInterest; // adds the monthly interest to the total and deposits
            setTotal(tempTotal);
            yearlyInterest += monthlyInterest; // keeps a running total of the accrued interest this year for easier printing

        }
        setInterestTotal(yearlyInterest);
        setTotal(tempTotal);
        outputResult(j + 1); // outputting this years totals. j+1 is the current year in the cycle
        yearlyInterest = 0; // resetting the annual interest so it can be printed correctly
    }
}

void InterestCalculator::calculateInterestWithoutDeposits()
{
    withoutDepositsHeader();
    setTotal(getInitialInvestment());
    double tempTotal;
    double tempInterest;

    // this funciton does not require compounding every month as there are no deposits
    for (int j = 0; j < getDuration(); ++j)
    {
        tempTotal = getTotal() + (getTotal() * (getInterestRate()/100.0));
        tempInterest = getTotal() * (getInterestRate() / 100.0);
        setTotal(tempTotal);
        setInterestTotal(tempInterest);
        outputResult(j + 1); // outputting this years totals. j+1 is the current year in the cycle
    }
}
