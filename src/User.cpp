#include "../header/User.h"

std::string User::getUserName() const
{
    return userName;
}

std::string User::getPassword() const
{
    return userPassword;
}

int User::getID() const {
    return userID;
}


User::User(int inUserID, std::string inUserName, std::string inUserPassword)
{
    userID = inUserID;
    userName = inUserName;
    userPassword = inUserPassword;
}

bool User::resetPassword(const std::string &newPassword)
{
 if (newPassword.empty()) {
        return false;
    }
    userPassword = newPassword;
    return true;
}
