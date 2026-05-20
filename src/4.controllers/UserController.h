#pragma once

#include "../1.models/User.h"
#include "../2.repositories/UserRepo.h"
#include <optional>

class UserController
{
  public:
    User registerUser();
    User loginUser();

  private:
    UserRepo repo;

};
