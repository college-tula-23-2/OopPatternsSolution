#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class ISensor
{
	std::string name;
public:
	virtual double GetTemperature() = 0;
	std::string& Name() { return name; }
};

class CelsiumSensor : public ISensor
{
public:
	CelsiumSensor()
	{
		srand(time(nullptr));
		Name() = "Celsium: ";
	}

	double GetTemperature() override
	{
		return -20.0 + rand() % 41;
	}
};

class FahrenheitSensor
{
public:
	FahrenheitSensor()
	{
		srand(time(nullptr));
	}

	double GetFahrenheitTemperature()
	{
		return (- 20.0 + rand() % 41) * 9 / 5 + 32;
	}
};

class FahrenheitSensorAdapter : public ISensor
{
	FahrenheitSensor* fahrenheitSensor;
public:
	FahrenheitSensorAdapter(FahrenheitSensor* fahrenheitSensor)
		: fahrenheitSensor { fahrenheitSensor }
	{ 
		Name() = "Fahrenheit: ";
	};

	double GetTemperature() override
	{
		return (fahrenheitSensor->GetFahrenheitTemperature() - 32) * 5 / 9;
	}
};

class Client
{
	std::vector<ISensor*> sensors;

public:
	Client()
	{
		srand(time(nullptr));
		ISensor* sensor;

		for (int i{}; i < 10; i++)
		{
			if(i % 2)
				sensor = new CelsiumSensor();
			else
				sensor = new FahrenheitSensorAdapter(new FahrenheitSensor());
			sensors.push_back(sensor);
		}
		
		/*std::generate_n(std::back_inserter(sensors),
			10,
			[&sensor]()
			{
				int flag = rand() % 2;
				if (flag)
					sensor = new CelsiumSensor();
				else
					sensor = new FahrenheitSensorAdapter(new FahrenheitSensor());
				return sensor;
			});*/
	}

	void PrintSensorsData()
	{
		std::for_each(sensors.begin(), sensors.end(),
			[](ISensor* sensor) 
			{ 
				std::cout << sensor->Name() << sensor->GetTemperature() << "\n"; 
			});
	}
};

