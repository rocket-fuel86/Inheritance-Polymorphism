#include <iostream>
using namespace std;


class Engine
{
private:
	double volume;
	string fuelType;
	int horsePower;
public:
	Engine(double volume, string fuelType, int horsePower) : volume(volume), fuelType(fuelType), horsePower(horsePower) {}

	double getVolume() const
	{
		return volume;
	}

	string getFuelType() const
	{
		return fuelType;
	}

	int getPower() const
	{
		return horsePower;
	}

	void displayCharacteristics() const
	{
		cout << endl << "Volume: " << volume << ", Fuel type: " << fuelType << ", Horsepower: " << horsePower << endl;
	}

	bool operator==(const Engine& other)
	{
		if (other.volume == this->volume && other.fuelType == this->fuelType && other.horsePower == this->horsePower)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(const Engine& other)
	{
		if (other.volume == this->volume && other.fuelType == this->fuelType && other.horsePower == this->horsePower)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};


class Transmission
{
private:
	string type;
public:
	Transmission(string type) : type(type) {}

	string getType() const
	{
		return type;
	}

	void displayCharacteristics() const
	{
		cout << endl << "Transmission type: " << type << endl;
	}

	bool operator==(const Transmission& other)
	{
		if (other.type == this->type)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(const Transmission& other)
	{
		if (other.type == this->type)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};


class Vehicle
{
protected:
	string type;
	string brand;
	string model;
	int year;
	double price;
	Engine* engine;
	Transmission* transmission;
public:
	Vehicle(string type, string brand, string model, int year, double price, Engine* engine, Transmission* transmission)
	{
		this->type = type;
		this->brand = brand;
		this->model = model;
		this->year = year;
		this->price = price;
		this->engine = engine;
		this->transmission = transmission;
	}

	string getTypeVehicle() const
	{
		return type;
	}

	string getBrand() const
	{
		return brand;
	}

	string getModel() const
	{
		return model;
	}

	int getYear() const
	{
		return year;
	}

	double getPrice() const
	{
		return price;
	}

	Engine* getEngine() const
	{
		return engine;
	}

	Transmission* getTransmission() const
	{
		return transmission;
	}

	void setTypeVehicle(string type)
	{
		this->type = type;
	}

	void setBrand(string brand)
	{
		this->brand = brand;
	}

	void setModel(string model)
	{
		this->model = model;
	}

	void setYear(int year)
	{
		this->year = year;
	}

	void setPrice(double price)
	{
		this->price = price;
	}

	void setEngine(Engine* engine)
	{
		this->engine = engine;
	}

	void setTransmission(Transmission* transmission)
	{
		this->transmission = transmission;
	}

	virtual void displayDetails() const
	{
		cout << endl << "Type: " << type << ", Brand: " << brand << ", Model: " << model << ", Year: " << year << ", Price: " << price << endl;
		engine->displayCharacteristics();
		transmission->displayCharacteristics();
		cout << endl;
	}

	bool operator==(const Vehicle& other)
	{
		if (other.type == type && other.brand == brand && other.model == model && other.year == year && other.price == price && other.engine == engine && other.transmission == transmission)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(const Vehicle& other)
	{
		if (other.type == type && other.brand == brand && other.model == model && other.year == year && other.price == price && other.engine == engine && other.transmission == transmission)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	virtual ~Vehicle() {}
};

class Sedan : public Vehicle
{
private:
	bool hasHatch;
public:
	Sedan(string brand, string model, int year, double price, Engine* engine, Transmission* transmission, bool hasHatch) : Vehicle("Sedan", brand, model, year, price, engine, transmission)
	{
		this->hasHatch = hasHatch;
	}

	virtual void displayDetails() const override
	{
		cout << endl << "Type: " << type << ", Brand: " << brand << ", Model: " << model << ", Year: " << year << ", Price: " << price << ", Has hatch: " << hasHatch << endl;
		engine->displayCharacteristics();
		transmission->displayCharacteristics();
		cout << endl;
	}
};

class Truck : public Vehicle
{
private:
	float liftingCapacity;
public:
	Truck(string brand, string model, int year, double price, Engine* engine, Transmission* transmission, float liftingCapacity) : Vehicle("Truck", brand, model, year, price, engine, transmission)
	{
		this->liftingCapacity = liftingCapacity;
	}

	virtual void displayDetails() const override
	{
		cout << endl << "Type: " << type << ", Brand: " << brand << ", Model: " << model << ", Year: " << year << ", Price: " << price << ", Lifting capacity: " << liftingCapacity << endl;
		engine->displayCharacteristics();
		transmission->displayCharacteristics();
		cout << endl;
	}
};

class Motorcycle : public Vehicle
{
private:
	double fuelConsumption;
public:
	Motorcycle(string brand, string model, int year, double price, Engine* engine, Transmission* transmission, double fuelConsumption) : Vehicle("Motorcycle", brand, model, year, price, engine, transmission)
	{
		this->fuelConsumption = fuelConsumption;
	}

	virtual void displayDetails() const override
	{
		cout << endl << "Type: " << type << ", Brand: " << brand << ", Model: " << model << ", Year: " << year << ", Price: " << price << ", Fuel consumption: " << fuelConsumption << endl;
		engine->displayCharacteristics();
		transmission->displayCharacteristics();
		cout << endl;
	}
};

class Moped : public Vehicle
{
private:
	double maxSpeed;
public:
	Moped(string brand, string model, int year, double price, Engine* engine, Transmission* transmission, double maxSpeed) : Vehicle("Moped", brand, model, year, price, engine, transmission)
	{
		this->maxSpeed = maxSpeed;
	}

	virtual void displayDetails() const override
	{
		cout << endl << "Type: " << type << ", Brand: " << brand << ", Model: " << model << ", Year: " << year << ", Price: " << price << ", Max speed: " << maxSpeed << endl;
		engine->displayCharacteristics();
		transmission->displayCharacteristics();
		cout << endl;
	}
};

void SearchByType(const Vehicle* vehicles[], const int size, string type)
{
	cout << endl << "Searching by type:" << endl;

	for (int i = 0; i < size; i++)
	{
		if (vehicles[i]->getTypeVehicle() == type)
		{
			vehicles[i]->displayDetails();
		}
	}
}

void SearchByProd(const Vehicle* vehicles[], const int size, int year)
{
	cout << endl << "Searching by year prod:" << endl;

	for (int i = 0; i < size; i++)
	{
		if (vehicles[i]->getYear() == year)
		{
			vehicles[i]->displayDetails();
		}
	}
}

void SearchByPrice(const Vehicle* vehicles[], const int size, double minPrice, double maxPrice)
{
	cout << endl << "Searching by price:" << endl;

	for (int i = 0; i < size; i++)
	{
		if (vehicles[i]->getPrice() >= minPrice && vehicles[i]->getPrice() <= maxPrice)
		{
			vehicles[i]->displayDetails();
		}
	}
}

void SearchBySeveralParameters(const Vehicle* vehicles[], const int size, string brand, string model, int year)
{
	cout << endl << "Searching by several parameters:" << endl;

	for (int i = 0; i < size; i++)
	{
		if (vehicles[i]->getBrand() == brand && vehicles[i]->getModel() == model && vehicles[i]->getYear() == year)
		{
			vehicles[i]->displayDetails();
		}
	}
}

int main()
{
	Engine engine1(2.0, "Gasoline", 150);
	Transmission transmission1("Manual");
	Sedan sedan("Toyota", "Camry", 2020, 25000, &engine1, &transmission1, true);

	Engine engine2(5.0, "Diesel", 400);
	Transmission transmission2("Automatic");
	Truck truck("Volvo", "FH", 2021, 70000, &engine2, &transmission2, 15.0);

	Engine engine3(1.5, "Gasoline", 120);
	Transmission transmission3("Manual");
	Motorcycle motorcycle("Honda", "CBR", 2022, 12000, &engine3, &transmission3, 4.5);

	Engine engine4(0.5, "Gasoline", 10);
	Transmission transmission4("Automatic");
	Moped moped("Vespa", "LX", 2021, 3000, &engine4, &transmission4, 90.0);

	const Vehicle* vehicles[] = { &sedan, &truck, &motorcycle, &moped };

	SearchByType(vehicles, 4, "Truck");
	SearchByProd(vehicles, 4, 2020);
	SearchByPrice(vehicles, 4, 10000, 30000);
	SearchBySeveralParameters(vehicles, 4, "Honda", "CBR", 2022);
}