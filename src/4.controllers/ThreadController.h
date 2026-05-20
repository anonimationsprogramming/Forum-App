#pragma once

#include "../1.models/Thread.h"
#include "../1.models/User.h"

class ThreadController
{
  public:
    Thread newThread(User& user);
};
