#include <iostream>
#include <cstring>
#include <assert.h>
#include "Guest.h"
#include "User.h"
#include "VIP.h"
#include "Admin.h"

/*Didn't have the time to learn C++ unit testing framework, so I
 * wrote those pseudo-tests below :D*/
int main() {

//Guest class testing

    //Default Guest & its derived classes have default ip set
    Guest g1;
    assert(strcmp(g1.getIpAddress(), "127.0.0.1") == 0);

//User class testing

    User u1("127.0.0.1", "user1", "1234", "title1");
    assert(strcmp(u1.getPassword(), "1234") != 0); // User password should be stored encrypted

    //User can change his own password only if he gives the correct old password
    char *old_pass = new char[strlen(u1.getPassword()) + 1];
    strcpy(old_pass, u1.getPassword());
    u1.changePassword("1234", "5678");
    const char *new_pass = u1.getPassword();
    assert(strcmp(old_pass, new_pass) != 0); //assert password is successfully changed

//VIP class testing

    VIP v1("123.456.31.22", "VIP1", "1234", "title1");
    v1.changeTitle("title2"); // VIP can change his own title
    assert(strcmp(v1.getTitle(), "title2") == 0);

//PowerUser class testing

    //PowerUser can gain +1 reputation from other users
    PowerUser p1;
    assert(p1.getReputation() == 0);
    p1.gainReputation(v1);
    assert(p1.getReputation() == 1);

    //PowerUser can't give reputation to himself -> the line below throws exception
    //p1.gainReputation(p1);

//Admin class testing

    //Admin can change his own username
    Admin a1;
    a1.setUsername("admin1");
    assert(strcmp(a1.getUsername(), "admin1") == 0);

    //Admin can change other Users' names
    a1.setUsername("VIP2", v1);
    assert(strcmp(v1.getUsername(), "VIP2") == 0);

    return 0;
}