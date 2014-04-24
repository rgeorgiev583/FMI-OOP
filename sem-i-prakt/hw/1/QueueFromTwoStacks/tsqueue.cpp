#include "tsqueue.h"

void TwoStackQueue::refill_pop_stack()
{
    while (!push_stack.empty())
    {
        pop_stack.push(push_stack.top());
        push_stack.pop();
    }
}

bool TwoStackQueue::empty() const
{
    return push_stack.empty() && pop_stack.empty();
}

int TwoStackQueue::front()
{
    if (empty())
        return DEFAULT;
    if (pop_stack.empty())
        refill_pop_stack();
    return pop_stack.top();
}

void TwoStackQueue::push(int data)
{
    push_stack.push(data);
}

bool TwoStackQueue::pop()
{
    if (empty())
        return false;
    if (pop_stack.empty())
        refill_pop_stack();
    return pop_stack.pop();
}
