// Random Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


//Get
int sumArray(int numbers[], int arrayLength) {
	int returnedValue = 0;
	for (int i = 0; i < arrayLength; i++)
	{
		returnedValue += numbers[i];
	}
	return returnedValue;
}

float getOffset(float percentage, float expectedPercentage) {
	return abs(percentage - expectedPercentage);
}

float getPercentage(int amount, int totalAmount) {
	//std::cout << amount << " : " << totalAmount << " : " << (float)amount / totalAmount;
	return ((float)amount / totalAmount);
}

float getAverageOffset(int numbers[], int arrayLength) {
	float totalOffset = 0;
	for (int i = 0; i < arrayLength; i++)
	{
		totalOffset += getOffset(getPercentage(numbers[i], sumArray(numbers, arrayLength)), (float)1 / arrayLength);
	}
	return totalOffset / arrayLength;
}

int getNumberIndexWithHighestOffset(int numbers[], int arrayLength) {

	int highestSoFar = 0;
	float offset = 0;
	for (int i = 0; i < arrayLength; i++)
	{
		float foundOffset = getOffset(getPercentage(numbers[i], sumArray(numbers, arrayLength)), (float)1 / arrayLength);
		if (foundOffset > offset) {
			offset = foundOffset;
			highestSoFar = i;
		}
	}
	return highestSoFar;
}

int getNumberIndexWithSmallestOffset(int numbers[], int arrayLength) {

	int highestSoFar = 0;
	float offset = 1;
	for (int i = 0; i < arrayLength; i++)
	{
		float foundOffset = getOffset(getPercentage(numbers[i], sumArray(numbers, arrayLength)), (float)1 / arrayLength);
		if (foundOffset < offset) {
			offset = foundOffset;
			highestSoFar = i;
		}
	}
	return highestSoFar;
}


//Display
void displayHighestOffset(int numbers[], int arrayLength) {
	int index = getNumberIndexWithHighestOffset(numbers, arrayLength);
	std::cout << "Maximum Offet: Number " << index + 1 << " (" << getOffset(getPercentage(numbers[index], sumArray(numbers, arrayLength)), (float)1 / arrayLength) * 100 << "%)" << std::endl;;
}

void displaySmallestOffset(int numbers[], int arrayLength) {
	int index = getNumberIndexWithSmallestOffset(numbers, arrayLength);
	std::cout << "Minimum Offet: Number " << index + 1 << " (" << getOffset(getPercentage(numbers[index], sumArray(numbers, arrayLength)), (float)1 / arrayLength) * 100 << "%)" << std::endl;;
}

void displayNumber(int number, int value, float numberPercent) {
	std::cout << "Number " << number << ": " << value << " times (" << numberPercent * 100 << "%)" << std::endl;
}

void displayNumbers(int numbers[], int arrayLength) {
	for (int i = 0; i < arrayLength; i++)
	{
		displayNumber(i + 1, numbers[i], getPercentage(numbers[i], sumArray(numbers, arrayLength)));
	}
}

void displayAverageOffset(int numbers[], int arrayLength) {
	std::cout << "Average Offet: " << getAverageOffset(numbers, arrayLength) * 100 << "%" << std::endl;
}

//Roll
int rollRandomNumber(int maxNumber, int randomSeed) {
	std::srand(randomSeed);
	return rand() % 20+1;
}

void rollRandomNumbers(int amountRolled) {
	int numbers[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int randomSeed = std::time(nullptr) * std::time(nullptr) * 1000;

	for (int i = 0; i < amountRolled; i++)
	{
		numbers[rollRandomNumber(20,randomSeed)-1]++;
		randomSeed++;
	}
	displayNumbers(numbers, 20);
	std::cout << std::endl << "--------------------" << std::endl << std::endl;
	displayHighestOffset(numbers, 20); 
	displaySmallestOffset(numbers, 20);
	displayAverageOffset(numbers, 20);
}


int main()
{
	rollRandomNumbers(10000);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
