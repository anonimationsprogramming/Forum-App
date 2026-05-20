
#pragma once

#include "../2.repositories/ThreadRepo.h"
#include "../1.models/User.h"
#include "../1.models/Thread.h"
#include <string>

class ThreadService
{
  public:
    Thread newThread(int& authorId,
		     const User& user,
		     const std::string& title,
                     const std::string& body);

    ThreadService(ThreadRepo& repo) : tr(repo) {}

  private:
    ThreadRepo& tr;
};
