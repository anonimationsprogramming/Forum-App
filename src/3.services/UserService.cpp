#include "UserService.h"
#include "../2.repositories/UserRepo.h"
#include "../1.models/User.h"
#include <stdexcept>

User UserService::registerUser(const std::string& name,
                                             const std::string& email,
                                             const std::string& password)
{
  User user;

  if (user.email == email)
  {
    throw; // already exists
  }

  user.name = name;
  user.email = email;
  user.passwordHash = password; // later: hash this

  repo.insertUser(user);

  return user;
}

User UserService::loginUser(const std::string& email,
                                          const std::string& password)
{

  auto userFind = repo.findByEmail(email);

  if (userFind.email != email)
  {
    throw; // user not found
  }

  if (userFind.passwordHash != password)
  {
    throw; // wrong password
  }
  User user = userFind;
  user.email = email;
  user.passwordHash = password;

  return user;
}

