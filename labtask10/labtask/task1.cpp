#include <iostream>
using namespace std;

class Vehicles {
protected:
	double mileage;
	double Price;

	public:
		Vehicles(double mileage = 0, double Price = 0) {
			this->mileage = mileage;
			this->Price = Price;
		}
};

class Car: public Vehicles {
protected:
	double cost;
	int warranty; /* in years */
	int seating_capacity;
	string fuel_type;

public:
		Car(double milage, double price, double cost = 0, int warranty = 0, int seating_capacity = 0, string fuel_type = " "): Vehicles(milage, price) {
			this->cost = cost;
			this->warranty = warranty;
			this->seating_capacity = seating_capacity;
			this->fuel_type = fuel_type;
		}

		double getCost() {
			return cost;
		}

		void setCost(double cost) {
			this->cost = cost;
		}

		int getWarranty() {
			return warranty;
		}

		void setWarranty(int warranty) {
			this->warranty = warranty;
		}

		int getSeatingCapacity() {
			return seating_capacity;
		}

		void setSeatingCapacity(int seating_capacity) {
			this->seating_capacity = seating_capacity;
		}

		string getFuelType() {
			return fuel_type;
		}

		void setFuelType(string fuel_type) {
			this->fuel_type = fuel_type;
		}
};

class Bike: public Vehicles {
protected:
	int cylinders;
	int gears;
	string cooling_type;
	string wheel_type;
	int fuel_tank_size;

	public:
		Bike(int milage, int price, int cylinders = 0, int gears = 0, string cooling_type = " ", string wheel_type = " ", int fuel_tank_size = 0): Vehicles(milage, price) {
			this->cylinders = cylinders;
			this->gears = gears;
			this->cooling_type = cooling_type;
			this->wheel_type = wheel_type;
			this->fuel_tank_size = fuel_tank_size;
		}

		int getCylinders() {
			return cylinders;
		}

		void setCylinders(int cylinders) {
			this->cylinders = cylinders;
		}

		int getGears() {
			return gears;
		}

		void setGears(int gears) {
			this->gears = gears;
		}

		string getCoolingType() {
			return cooling_type;
		}

		void setCoolingType(string cooling_type) {
			this->cooling_type = cooling_type;
		}

		string getWheelType() {
			return wheel_type;
		}

		void setWheelType(string wheel_type) {
			this->wheel_type = wheel_type;
		}
};

class Audi : public Car {
	string model;

	public:
		Audi(string model, double mileage, double price, double cost, int warranty, int seating_capacity, string fuel_type) : Car(mileage, price, cost, warranty, seating_capacity, fuel_type) {
			this->model = model;
		}

		void print() {
			cout << endl << "Model: " << model;
			cout << endl << "Mileage: " << mileage;
			cout << endl << "Price: " << Price;
			cout << endl << "Cost: " << cost;
			cout << endl << "Warranty: " << warranty;
			cout << endl << "Seating Capacity: " << seating_capacity;
			cout << endl << "Fuel Type: " << fuel_type;
		}
};

class Ford : public Car {
protected:
string model;

	public:
		Ford(string model, double mileage, double price, double cost, int warranty, int seating_capacity, string fuel_type) : Car(mileage, price, cost, warranty, seating_capacity, fuel_type) {
			this->model = model;
		}

		void print() {
			cout << endl << "Model: " << model;
			cout << endl << "Mileage: " << mileage;
			cout << endl << "Price: " << Price;
			cout << endl << "Cost: " << cost;
			cout << endl << "Warranty: " << warranty;
			cout << endl << "Seating Capacity: " << seating_capacity;
			cout << endl << "Fuel Type: " << fuel_type;
		}
};

class Bajaj : public Bike {
protected:
	string make;

public:
	Bajaj(string make, double milage, double price, int cylinder, int gears, string cooling_type, string wheel_type, int fuel_tank_size) : Bike(milage, price, cylinder, gears, cooling_type, wheel_type, fuel_tank_size) {
		this->make = make;
	}

	void print() {
		cout << endl << "Make: " << make;
		cout << endl << "Mileage: " << mileage;
		cout << endl << "Price: " << Price;
		cout << endl << "Cylinders: " << cylinders;
		cout << endl << "Gears: " << gears;
		cout << endl << "Cooling Type: " << cooling_type;
		cout << endl << "Wheel Type: " << wheel_type;
		cout << endl << "Fuel Tank Size: " << fuel_tank_size;
	}
};

class TVS: public Bike {
protected:
	string make;

	public:
		TVS(string make , double milage, double price, int cylinder, int gears, string cooling_type, string wheel_type, int fuel_tank_size): Bike (milage, price, cylinder ,gears ,cooling_type , wheel_type , fuel_tank_size) {
			this->make = make;
		}

		void print() {
			cout << endl << "Make: " << make;
			cout << endl << "Mileage: " << mileage;
			cout << endl << "Price: " << Price;
			cout << endl << "Cylinders: " << cylinders;
			cout << endl << "Gears: " << gears;
			cout << endl << "Cooling Type: " << cooling_type;
			cout << endl << "Wheel Type: " << wheel_type;
			cout << endl << "Fuel Tank Size: " << fuel_tank_size;
		}
};

int main() {
    Audi a1("Audi A4", 10, 100000, 100000, 2, 5, "Diesel");
    Ford f1("Ford Figo", 10, 100000, 100000, 2, 5, "Diesel");
    Bike b1(10, 100000, 4, 5, "Liquid", "Alloy", 15);
    Bajaj b2("Bajaj Pulsar", 10, 100000, 4, 5, "Liquid", "Alloy", 15);
    TVS t1("TVS Apache", 10, 100000, 4, 5, "Liquid", "Alloy", 15);


	a1.print();

	f1.print();

	b2.print();

	t1.print();

	return 0;
}