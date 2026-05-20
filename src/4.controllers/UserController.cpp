#include "UserController.h"
#include "../3.services/UserService.h"
#include <iostream>
#include <string>
#include <optional>

User UserController::registerUser()
{
  std::string name;
  std::string email;
  std::string password;


  std::cout << "Name: ";
  std::getline(std::cin, name);

  std::cout << "Email: ";
  std::getline(std::cin, email);

  std::cout << "Password: ";
  std::getline(std::cin, password);

  UserService us(repo);
  User user = us.registerUser(name, email, password);
  try
  {
    if (user.name != name || user.email != email || user.passwordHash != password)
    {
      return User{};
    }

    std::cout << "User created with id " << user.id << "\n\n";
  }

  catch (const std::exception& e)
  {
    std::cout << e.what() << '\n';
  }
  return user;
}


User UserController::loginUser()
{
  std::string email;
  std::string password;

  std::cout << "Email: ";
  std::getline(std::cin, email);

  std::cout << "Password: ";
  std::getline(std::cin, password);

  UserService us(repo);

  User user = us.loginUser(email, password);

  try
  {
    if (user.email != email || user.passwordHash != password)
    {
      return User{};
      std::cout << "Incorrect user or password " << user.id << '\n';
    }
      std::cout << "User " << user.name << " logged in\n\n";
  }

  catch (const std::exception& e)
  {
    std::cout << e.what() << '\n';
  }
  return user;
}

