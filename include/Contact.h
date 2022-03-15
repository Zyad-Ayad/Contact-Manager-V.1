#include <vector>
#include "User.h"

using namespace std;

#ifndef CONTACT_H
#define CONTACT_H


class Contact
{
    public:
        Contact();


        void AddUser();//if there is less than 100 users it add new user otherwise it print an error


        bool EditUser();// Search for user by id and call user object edit function .
        // if no users found it return false


        int CountUsers() const {return usersCount;}; // return the current count of users


        void SearchUser() const; //Gets a keyword and show every user has that word in any data user has


        bool DeleteUser(); // Gets id if user with id exist function asks again if sure to delete (whether you accepted or denied it return true) .
        //if there was no user with given id it returns false


        void ShowAll() const;// loop over every user in users array and call show function


        void saveintofile() const;//create new file with given name(or replace of already exist)
        //then it pass the file name to every user so users(aka. objects) can append their data in that file


        virtual ~Contact();

    protected:

    private:
        User* users[100]; // save user objects
        int usersCount; // save users count for loops


};

#endif // CONTACT_H
