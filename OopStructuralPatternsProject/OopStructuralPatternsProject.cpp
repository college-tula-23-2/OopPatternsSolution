#include <iostream>
#include "Adapter.h"

void AdapterExample();

int main()
{
    AdapterExample();
}

void AdapterExample()
{
    Client client;
    client.PrintSensorsData();
    system("pause");
}