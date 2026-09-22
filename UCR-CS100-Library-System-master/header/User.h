#ifndef USER_H
#define USER_H

#include <string>

class User {
 public:
  User(int inUserID, std::string inUserName, std::string inUserPassword);
  virtual ~User() = default;
  bool resetPassword(const std::string& newPassword);
  int getID() const;
  std::string getUserName() const;
  std::string getPassword() const;
  int getAccountType() const { return accountType; }

 private:
  int userID;
  std::string userName;
  std::string userPassword;

 protected:
  int accountType;
};

#endif
