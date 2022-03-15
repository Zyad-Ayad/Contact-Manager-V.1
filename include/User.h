#include <string>
#include "Phone.h"
#include "Email.h"
#include "Address.h"


using namespace std;

#ifndef USER_H
#define USER_H


class User
{
    public:
        User();


        bool Search(string) const; // gets a keyword and returns true if this word in any of user data


        string GetFirstName() const {return FirstName;};// return user first name


        string GetLastName() const {return LastName;};// return user last name


        string GetGender() const {return gender;};// return user gender


        string GetCity() const {return city;};// return user city


        string GetAddedDate() const {return AddedDate;}; // return user added date


        int GetID() const {return id;}; // return user id


        void Show(); // prints all user data


        void Edit(); // this function edit most of user data [general, email, address, phone]
        // edit function can add or remove [emails, addresses, phones]


        void saveintofile(string); // save user data in given file
        // saved data is the same as printed data by Show() function


        virtual ~User();



    private:
        int id; // user id ( can't edit )
        string FirstName;
        string LastName;
        string gender;
        string city;
        string AddedDate;
        Email* emails [5]; // array of user emails
        Address* addresses[5]; // array of user addresses
        Phone* phones[5]; // array of user phones
        int phonesCount; //save phones count for loops
        int emailsCount; //save emails count for loops
        int addressesCount; // save addresses count for loops
        static int NextUserId; // save next user id. 2 users can't have same id even if one of them is deleted!

};

#endif // USER_H
