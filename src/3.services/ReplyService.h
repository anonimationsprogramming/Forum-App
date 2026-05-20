#pragma once

#include "../1.models/User.h"
#include "../1.models/Thread.h"
#include "../1.models/Reply.h"
#include <string>

class ReplyService
{
  public:
    Reply newReply(int& user_id,
		   int& thread_id,
		   std::string& title,
		   std::string& body);
};
