#pragma once

#include "../1.models/User.h"
#include "../2.repositories/UserRepo.h"
#include <string>

class UserService
{
  public:
    User registerUser(
      const std::string& name,
      const std::string& email,
      const std::string& password);

    User loginUser(const std::string& email,
                   const std::string& password);

    UserService(UserRepo& repo) : repo(repo) {}

  private:
    UserRepo repo;
};
