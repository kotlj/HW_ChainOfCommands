
#include <iostream>
#include <string>

class IElectric
{
public:
    virtual void SwitchPower(std::string command) = 0;
};

class Light : public IElectric
{
private:
    bool power;
    IElectric* next;
public:
    Light()
    {
        power = false;
        next = nullptr;
    }
    void setNext(IElectric* _next)
    {
        next = _next;
    }
    void SwitchPower(std::string command) override
    {
        if (command != "Switch light" && next != nullptr)
        {
            next->SwitchPower(command);
        }
        else
        {
            if (power)
            {
                std::cout << "light off\n";
                power = false;
            }
            else
            {
                std::cout << "light on\n";
                power = true;
            }
        }
    }
};
class AirConditioner : public IElectric
{
private:
    bool power;
    IElectric* next;
public:
    AirConditioner()
    {
        power = false;
        next = nullptr;
    }
    void setNext(IElectric* _next)
    {
        next = _next;
    }
    void SwitchPower(std::string command) override
    {
        if (command != "Switch Air Condition" && next != nullptr)
        {
            next->SwitchPower(command);
        }
        else
        {
            if (power)
            {
                std::cout << "Air Conditioner off\n";
                power = false;
            }
            else
            {
                std::cout << "Air Conditioner on\n";
                power = true;
            }
        }
    }
};
class MusicSystem : public IElectric
{
private:
    bool power;
    IElectric* next;
public:
    MusicSystem()
    {
        power = false;
        next = nullptr;
    }
    void setNext(IElectric* _next)
    {
        next = _next;
    }
    void SwitchPower(std::string command) override
    {
        if (command != "Switch light" && next != nullptr)
        {
            next->SwitchPower(command);
        }
        else
        {
            if (power)
            {
                std::cout << "Music system off\n";
                power = false;
            }
            else
            {
                std::cout << "Music system on\n";
                power = true;
            }
        }
    }
};

class Client
{
private:
    Light* _light;
    AirConditioner* _airConditioner;
    MusicSystem* _musicSystem;
public:
    Client()
    {
        _light = new Light;
        _airConditioner = new AirConditioner;
        _musicSystem = new MusicSystem;
        _light->setNext(_airConditioner);
        _airConditioner->setNext(_musicSystem);
    }
    void SwitchLight(std::string command)
    {
        _light->SwitchPower(command);
    }

    ~Client()
    {
        delete _musicSystem;
        delete _airConditioner;
        delete _light;
    }
};

int main()
{
    Client client;
    client.SwitchLight("Switch Air Condition");
}