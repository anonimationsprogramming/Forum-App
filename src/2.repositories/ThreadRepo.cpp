#include "ThreadRepo.h"
#include "../1.models/Thread.h"
#include <string>
#include <vector>

static std::vector<Thread> threads;
static int nextThreadId {1};

void ThreadRepo::addThread(Thread& thread)
{
  thread.id = nextThreadId++;
  threads.push_back(thread);
}
