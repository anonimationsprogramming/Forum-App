#pragma once

#include <string>

struct Reply
{
  int id {0};
  int user_id {0};
  int thread_id {0};
  std::string title;
  std::string body;
};
