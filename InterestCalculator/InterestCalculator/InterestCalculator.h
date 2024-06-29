#pragma once
#ifndef INTERESTCALCULATOR_INTERESTCALCULATOR_PROJECT2INTERESTCALCULATOR_H
#define INTERESTCALCULATOR_INTERESTCALCULATOR_PROJECT2INTERESTCALCULATOR_H

class InterestCalculator
{
	public:
		// print function
		void mainMenu();

		// calculation functions
		void userInputs();
		void calculateInterestWithDeposits();
		void calculateInterestWithoutDeposits();

	private:
		// print functions
		void withoutDepositsHeader();
		void withDepositsHeader();
		void outputResult(int t_year);
		
		// functions for input validation
		void readInitialInvestment();
		void readMonthlyDeposit();
		void readInterestRate();
		void readDuration();

		// getter/setter functions for variables
		void setInitialInvestment(double t_investment);
		double getInitialInvestment() const;
		void setMonthlyDeposit(double t_deposit);
		double getMonthlyDeposit() const;
		void setInterestRate(int t_rate);
		int getInterestRate() const;
		void setDuration(int t_duration);
		int getDuration() const;
		void setTotal(double t_total);
		double getTotal() const;
		void setInterestTotal(double t_interestTotal);
		double getInterestTotal() const;

		// member variables
		double m_initialInvestment;
		double m_monthlyDeposit;
		int m_interestRate;
		int m_duration;
		double m_total;
		double m_interestTotal;
};


#endif
