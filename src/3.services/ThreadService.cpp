#include "ThreadService.h"
#include "UserService.h"
#include "../2.repositories/ThreadRepo.h"
#include "../2.repositories/UserRepo.h"
#include "../1.models/User.h"
#include <stdexcept>
#include <string>

Thread ThreadService::newThread(int& authorId,
				const User& user,
				const std::string& title,
                                const std::string& body)
{
  Thread thread;

  authorId = thread.id;
  thread.authorId = authorId;
  thread.user = user;
  thread.title = title;
  thread.body = body;

  if(thread.authorId != authorId)
  {
    throw;
  }

  tr.addThread(thread);


  return thread;
}
