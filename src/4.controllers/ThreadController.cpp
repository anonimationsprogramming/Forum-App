#include "ThreadController.h"
#include "../3.services/ThreadService.h"
#include "../1.models/Thread.h"
#include "../1.models/User.h"
#include <iostream>
#include <string>

Thread ThreadController::newThread(User& user)
{

  std::string title;
  std::string body;
  int authorId {0};

  std::cout << "Title: ";
  std::getline(std::cin, title);

  std::cout << "Body: ";
  std::getline(std::cin, body);

  Thread thread;

  ThreadRepo repo;
  ThreadService ts(repo);

  thread.authorId = user.id;
  authorId = thread.authorId;

  try
  {
    thread = ts.newThread(authorId, user, title, body);

    std::cout << "Thread created with id " <<  thread.id << "\n\n";

  }

  catch (const std::exception& e)
  {
    std::cout << e.what() << '\n';
  }
  return thread;
}

