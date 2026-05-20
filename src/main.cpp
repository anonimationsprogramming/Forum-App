#include "1.models/User.h"
#include "1.models/Thread.h"
#include "3.services/UserService.h"
#include "3.services/ThreadService.h"
#include "4.controllers/UserController.h"
#include "4.controllers/ThreadController.h"
#include "4.controllers/ReplyController.h"
#include <iostream>
#include <string>

int main()
{
  UserController uc;
  ThreadController tc;
  ReplyController rc;

  User user;
  Thread thread;
  Reply reply;

  std::cout << "Register?<y/n> ";
  std::string new_registry;
  std::getline(std::cin, new_registry);

  if(new_registry == "y")
    user = uc.registerUser();

  std::cout << "Login?<y/n> ";
  std::string new_login;
  std::getline(std::cin, new_login);

  if(new_login == "y")
    user = uc.loginUser();

  std::cout << "New thread?<y/n> ";
  std::string new_thread;
  std::getline(std::cin, new_thread);

  if(new_thread == "y")
    thread = tc.newThread(user);

  std::cout << "New reply?<y/n> ";
  std::string new_reply;
  std::getline(std::cin, new_reply);

  if(new_reply == "y")
    reply = rc.newReply(user, thread);

  return 0;
}
