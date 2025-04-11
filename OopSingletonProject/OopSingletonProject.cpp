#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;

class Singleton
{
    static Singleton* instance;
    Singleton()
    {
        // impemetation
    }
    Singleton(Singleton&) = delete;
    Singleton* operator=(Singleton&) = delete;
public:
    static Singleton* GetInstance()
    {
        if (!instance)
            instance = new Singleton();
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;

class OperationSystem
{
    static OperationSystem* system;

    std::string title;
    OperationSystem(std::string title) : title{ title } {}
public:
    std::string Title() { return title; }

    static OperationSystem* StartSystem(std::string title)
    {
        std::lock_guard<std::mutex> lock(m);
        if (!system)
            system = new OperationSystem(title);
        return system;
    }
};
OperationSystem* OperationSystem::system = nullptr;


class Computer
{
    OperationSystem* system;
public:
    OperationSystem* System() { return system; }

    void LounchSystem(std::string title)
    {
        system = OperationSystem::StartSystem(title);
    }
};

void ComputerStart(std::string osTitle)
{
    Computer* computer = new Computer();

    computer->LounchSystem(osTitle);
    std::cout << computer->System()->Title() << "\n";
}


int main()
{
    std::thread computer1(ComputerStart, "Ubuntu");
    std::thread computer2(ComputerStart, "Windows");
    std::thread computer3(ComputerStart, "Debian");

    computer1.join();
    computer2.join();
    computer3.join();
}
