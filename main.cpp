#include <iostream>
#include "Contact.h"


using namespace std;

int main()
{
    system("color 0A");
    Contact mycontacts;

    int input = -1;

    while(input != 0)
    {
        cout << "\n\t\t########################################################\n"
             << "\t\t#                                                      #\n"
             << "\t\t#                                                      #\n"
             << "\t\t#            1 - Add User                              #\n"
             << "\t\t#            2 - Edit User                             #\n"
             << "\t\t#            3 - Delete User                           #\n"
             << "\t\t#            4 - Search User                           #\n"
             << "\t\t#            5 - Count Users                           #\n"
             << "\t\t#            6 - Show All Users                        #\n"
             << "\t\t#            7 - Save into file                        #\n"
             << "\t\t#            0 - Exit                                  #\n"
             << "\t\t#                                                      #\n"
             << "\t\t#                                                      #\n"
             << "\t\t#                                                      #\n"
             << "\t\t########################################################\n\n\t\t>>  ";
             cin>> input;

             switch(input)
             {
             case 1:
                {
                    mycontacts.AddUser();
                }
                break;
             case 2:
                {
                    if(!mycontacts.EditUser())
                    {
                        cout << "\n\t\tError : UNEXPECTED ERROR { please check your input }";
                    }
                }
                break;
             case 3:
                {
                    if(!mycontacts.DeleteUser())
                    {
                        cout << "\n\t\tError : UNEXPECTED ERROR { please check your input }";
                    }
                }
                break;
             case 4:
                {
                    mycontacts.SearchUser();
                }
                break;
             case 5:
                {
                    cout << "\n\n\t\tYou have [ "<<mycontacts.CountUsers() << " ] Contacts!\n\n";
                }
                break;
             case 6:
                {
                    mycontacts.ShowAll();
                }
                break;
             case 7:
                {
                    mycontacts.saveintofile();
                }
             }
    }

    return 0;
}
