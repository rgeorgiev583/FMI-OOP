#include <map>
#pragma once

typedef char Letter;

template<typename T>
struct State
{
    T id;
    map<Letter, State*> next;

    State();
    State(const T&);
    State(const T&, Letter, const State&);
    State(const T&, const map<Letter, State*>&);

    State* getNext(Letter);
};
