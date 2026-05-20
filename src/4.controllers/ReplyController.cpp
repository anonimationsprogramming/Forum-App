#include "ReplyController.h"
#include "../3.services/ReplyService.h"
#include "../3.services/ThreadService.h"
#include "../1.models/Reply.h"
#include "../1.models/Thread.h"
#include "../1.models/User.h"
#include <iostream>
#include <string>


Reply ReplyController::newReply(User& user, Thread& thread)
{
  std::string title;
  std::string body;

  std::cout << "Title: ";
  std::getline(std::cin, title);

  std::cout << "Body: ";
  std::getline(std::cin, body);

  Reply reply;
  ReplyService rs;

  try
  {
    reply = rs.newReply(user.id, thread.id, title, body);
    std::cout << "Reply created with id " << reply.id << " by user " << user.name << " to thread " << thread.id << "\n\n";
  }

  catch(const std::exception& e)
  {
    std::cout << e.what() << '\n';
  }
  return reply;
}
