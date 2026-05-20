#include "ReplyService.h"
#include "../2.repositories/ReplyRepo.h"
#include "../1.models/Reply.h"
#include "../1.models/Thread.h"
#include "../1.models/User.h"

Reply ReplyService::newReply(int& user_id,
			     int& thread_id,
			     std::string& title,
	                     std::string& body)
{
  ReplyRepo rr;
  Reply reply;

  User user;
  user_id = user.id;

  reply.user_id = user_id;
  reply.thread_id = thread_id;
  reply.title = title;
  reply.body = body;

  if(reply.user_id != user_id || reply.thread_id != thread_id)
  {
    throw;
  }

  rr.addReply(reply);

  return reply;
}
