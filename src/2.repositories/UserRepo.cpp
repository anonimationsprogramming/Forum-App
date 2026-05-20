#include "UserRepo.h"
#include "../1.models/User.h"
#include <vector>
#include <optional>

static std::vector<User> users;
static int next_id {1};

void UserRepo::insertUser(User& user)
{
  user.id = next_id++;
  users.push_back(user);
}

User UserRepo::findByEmail(const std::string& search_email)
{
  for (const auto& user : users)
  {
    if (user.email == search_email)
    {
      return user;
    }
  }
  return User{};
}

User UserRepo::findById(int search_id)
{
  for (const auto& user : users)
  {
    if (user.id == search_id)
    {
      return user;
    }
  }
  return User{};
}
