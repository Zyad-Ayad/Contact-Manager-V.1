#include <string>
using namespace std;

#ifndef ADDRESS_H
#define ADDRESS_H

class Address
{
    public:
        Address();


        bool SetPlace(string); //if place is empty returns false otherwise return true


        bool SetType(string); //if empty returns false otherwise return true


        bool SetDescription(string); //if  empty returns false otherwise return true


        void Edit();


        string GetType() const { return type;};


        string GetPlace() const { return place;};


        string GetDescription() const { return description;};


        virtual ~Address();

    private:
        string place;
        string type;
        string description;


};

#endif // ADDRESS_H
