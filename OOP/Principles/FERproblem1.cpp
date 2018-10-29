/*
Potrebno je modelirati klase i su�elja koje se koriste u aplikaciji za prodaju vozila (vehicle). Postoje tri vrste
vozila: automobil (car), kamion (truck) i motocikl (motorcycle). Svaka vrsta vozila ima definiran naziv
proizvo�a�a (manufacturer), oznaku modela (model), jedinstveni serijski broj �asije (id), snagu (power),
broj putnika (numberOfPassangers) i cijenu (regularPrice). Gettere i settere nije potrebno pisati.
Automobili dodatno imaju oznaku posjedovanja klimatizacije (hasAC) i broja vrata (numberOfDoors). Kamioni
imaju definiranu nosivost (maxWeight), a motocikli oznaku tipa (type) koja mora biti jedna od sljede�ih:
chopper, sport, racing i off-road. Za vozila je potrebno napraviti metodu public double
getPrice(boolean isVIP) koja za korisnike koji nisu VIP vra�a regularnu (tj. definiranu) cijenu vozila, a za
VIP korisnike vra�a regularnu cijenu umanjenu za odre�eni postotak ovisno o tipu vozila tako da je popust na
motocikle 15%, na automobile 10%, a na kamione 5%. Prilikom rje�avanja zadatka po potrebi je mogu�e
dodati nove metode. Vrste vozila koje se mogu iznajmljivati su automobili i motocikli, a njih je potrebno
modelirati su�eljem koje ima dvije metode: public void addRentingPrice(double rentingPrice) i
public double getRentingPrice().
*/
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vehicle {
protected:
	string manufacturer;
	string model; 
	int id; 
	double horsePower; 
	int numberOfPassengers; 
	double regularPrice; 
public: 
	virtual double getPrice(const bool isVip) = 0; 
};

class Car : public Vehicle {

	bool hasAC;
	int numberOfDoors; 
	double rentingPrice; 
public:
	double getPrice(const bool isVip);
	void addRentingPrice(double rentingPrice);
	double getRentingPrice();
};

class Truck : public Vehicle {

	float maxWeight;
public:
	double getPrice(const bool isVip);
};

enum type {CHOPPER, SPORT, RACING, OFFROAD};
class Motocycle : public Vehicle {

	type myType; 
	double rentingPrice;
public:
	double getPrice(const bool isVip);
	void addRentingPrice(double rentingPrice);
	double getRentingPrice(); 
};

int main()
{

	

}
double Car::getPrice(const bool isVip) {
	if (!isVip) {
		return this->regularPrice; 
	}
	return (0.9 * this->regularPrice); 
}

double Truck::getPrice(const bool isVip) {
	if (!isVip) {
		return this->regularPrice;
	}
	return (0.95 * this->regularPrice);
}

double Motocycle::getPrice(const bool isVip) {
	if (!isVip) {
		return this->regularPrice;
	}
	return (0.85 * this->regularPrice);
}
double Motocycle::getRentingPrice() {
	return this->rentingPrice; 
}
void Motocycle::addRentingPrice(double rentingPrice) {
	this->rentingPrice = rentingPrice; 
}
double Car::getRentingPrice() {
	return this->rentingPrice;
}
void Car::addRentingPrice(double rentingPrice) {
	this->rentingPrice = rentingPrice;
}
