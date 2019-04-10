// Main für Hausaufgabe 2
#include "labyrinth.hh"

int main() {
	Labyrinth lab;
	lab.Print();
	lab.Build();
	lab.Print();
	lab.Export("lab.txt");
	Labyrinth lab2;
	lab2.Import("lab.txt");
	lab2.Print();
	lab2.PlaceCoins();
	lab2.Print();
}
