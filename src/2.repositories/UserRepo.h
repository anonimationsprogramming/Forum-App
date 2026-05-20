#pragma once

#include "../1.models/User.h"
#include <string>
#include <optional>

class UserRepo
{
  public:
    void insertUser(User& user);
    User findByEmail(const std::string& email);
    User findById(int id);
};
