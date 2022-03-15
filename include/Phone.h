#include <string>
using namespace std;

#ifndef PHONE_H
#define PHONE_H


class Phone
{
    public:
        Phone();
        bool SetPhone(string);// Gets new phone number and check if it valid
        //if valid replace it with current one and return true otherwise return false


        bool SetType(string);//return true of type is not empty otherwise return false


        bool SetDescription(string);//return true of type is not empty otherwise return false


        void Edit();//This calls setters functions of user(aka. object) [SetPhone(), SetType(), SetDES..]


        string GetPhone() const {return phone;}; // returns  phone number


        string GetType() const {return type;};// returns phone type


        string GetDescription() const {return description;};//return phone description


        virtual ~Phone();


    private:
        string phone;
        string type;
        string description;


};

#endif // PHONE_H
