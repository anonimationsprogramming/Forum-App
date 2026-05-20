#include "ReplyRepo.h"
#include <vector>

static std::vector<Reply> replies;
static int next_id_reply{1};

void ReplyRepo::addReply(Reply& reply)
{
  reply.id = next_id_reply++;
  replies.push_back(reply);
}
