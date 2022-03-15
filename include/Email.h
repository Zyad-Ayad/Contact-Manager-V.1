#include <string>
using namespace std;

#ifndef EMAIL_H
#define EMAIL_H


class Email
{
    public:
        Email();
        bool SetEmail(string); // Gets new email address and check if it valid
        // if valid replace with current email and return true otherwise return false


        bool SetType(string);//return true of type is not empty otherwise return false


        bool SetDescription(string);//return true of type is not empty otherwise return false


        void Edit(); // this function call object setters functions


        string GetType() const {return type;}; // return email type


        string GetEmail() const {return email;}; // return email address


        string GetDescription() const {return description;}; // return email description


        virtual ~Email();

    private:
        string email;
        string type;
        string description;


};

#endif // EMAIL_H
