#include "state.h"

State::State() {}

State::State(const T& _id): id(_id) {}

State::State(const T& _id, Letter a, const State& q): id(_id)
{
    next[a] = q;
}

State::State(const T& _id, const map<Letter, State*>& _next): id(_id), next(_next) {}

State* State::getNext(Letter a)
{
    return next[a];
}
