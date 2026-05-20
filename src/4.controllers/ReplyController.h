#pragma once

#include "../1.models/User.h"
#include "../1.models/Thread.h"
#include "../1.models/Reply.h"

class ReplyController
{
  public:
    Reply newReply(User& user, Thread& thread);
};
