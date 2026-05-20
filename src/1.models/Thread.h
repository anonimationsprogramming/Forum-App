#pragma once

#include "User.h"
#include <string>

struct Thread
{
  int id {0};
  int authorId {0};
  User user;
  std::string title;
  std::string body;
};
