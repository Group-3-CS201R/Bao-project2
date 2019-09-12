// Name: Bao Ngo
// Email: bndbv@mail.umkc.edu
// Class: CS 201R 
// Instructor: Michael Essmyer
// Assignment 2

#include<iostream>
#include <string>
#include<cmath>
using namespace std;

//declaring functions
int input();
double totalArea(int Wall, double Height, double Width, int Side);
int PaintingCans(double Area);
int PaintingInterior(int numCan);
int PaintingExterior(int numCan);
int PaintingBothsides(int numCan);

//main function
int main() {
	int option; //get user choice
	int side; // interior, exterior or both
	int numCan;
	int Wall;
	int Cost;
	double Length;
	double Width;
	double Area;
	option = input();
	switch (option) {
	case 1:
		side = 1;
		cout << "Enter number of wall: ";
		cin >> Wall;
		cout << "Enter the length of wall (feet): ";
		cin >> Length;
		cout << "Enter the width of wall (feet): ";
		cin >> Width;
		Area = totalArea(Wall, Length, Width, side);
		cout << "Total painted area :  " << Area << " (square feet) " << endl;
		numCan = PaintingCans(Area);
		cout << "Can needed :  " << numCan << " can(s)" << endl;
		Cost = PaintingInterior(numCan);
		cout << "The cost of painting interior :  $" << Cost <<  endl;
		break;
	case 2:
		side = 1;
		cout << "Enter number of wall: ";
		cin >> Wall;
		cout << "Enter the length of wall (feet): ";
		cin >> Length;
		cout << "Enter the width of wall (feet): ";
		cin >> Width;
		Area = totalArea(Wall, Length, Width, side);
		cout << "Total painted area :  " << Area << " (square feet) " << endl;
		numCan = PaintingCans(Area);
		cout << "Can needed :  " << numCan << " can(s) " << endl;
		Cost = PaintingExterior(numCan);
		cout << "The cost of painting exterior :  $" << Cost << endl;
		break;
	case 3:
		side = 2;
		cout << "Enter number of wall: ";
		cin >> Wall;
		cout << "Enter the length of wall (feet): ";
		cin >> Length;
		cout << "Enter the width of wall (feet): ";
		cin >> Width;
		Area = totalArea(Wall, Length, Width, side);
		cout << "Total painted area :  " << Area << " (square feet) " << endl;
		numCan = PaintingCans(Area);
		cout << "Can needed :  " << numCan << " can(s) " << endl;
		Cost = PaintingBothsides(numCan);
		cout << "The cost of painting exterior :  $" << Cost << endl;
		break;
	default:
		cout << "You have to choose option from the menu" << endl;
		cin >> option;
		break;
	}
	system("pause");
	return 0;
}

// function for getting input from the user
int input() {
	int option;
	cout << "Welcome to paint shop" << endl;
	cout << "We have couple of options that you can choose from:" << endl;
	cout << "1- Paint the interior of the house" << endl;
	cout << "2- Paint the exterior of the house" << endl;
	cout << "3- Paint both interior and exterior of the house" << endl;
	cout << "What option fits you more ? ";
	cin >> option;
	cout << endl;
	while (option != 1 && option != 2 && option != 3) {
		cout << "You have to choose option from the menu" << endl;
		cin >> option;
	}
	return option;
}

// function for calculating total area
double totalArea(int Wall, double Length, double Width, int Side) {
	double area;
	area = Length * Width * Wall * Side;
	return area;
}

//function for calculating the number of cans
int PaintingCans(double Area) {
	int areaPercan = 400;
	float numCan;
	numCan = Area / areaPercan;
	return (int) ceil(numCan);
}

//function for getting the total cost of the interior of the house
int PaintingInterior(int numCan) {
	int priceInterior = 100;
	int moneyInterior = numCan * priceInterior;
	return moneyInterior;
}

//function for getting the total cost of the exterior of the house
int PaintingExterior(int numCan) {
	int priceExterior = 150;
	int moneyExterior = numCan * priceExterior;
	return moneyExterior;
}

//function for getting the total cost of both sides of the house
int PaintingBothsides(int numCan) {
	return PaintingInterior(numCan) + PaintingExterior(numCan);
}
