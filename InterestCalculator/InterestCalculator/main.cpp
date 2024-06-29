#include "pch.h"
#include "InterestCalculator.h"
#include <memory>

int main()
{
	// creating a new object of InterestCalculator class
	auto interestCalculator = std::make_unique<InterestCalculator>();

	// calling the public funcitons of the InterestCalculator class
	interestCalculator->mainMenu();
	interestCalculator->userInputs();
	interestCalculator->calculateInterestWithoutDeposits();
	interestCalculator->calculateInterestWithDeposits();
}
