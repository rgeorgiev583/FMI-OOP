#include <string>
#include <set>
#pragma once

typedef string Word;

template<typename T>
class DFA
{
    set<Letter> alphabet;
    set<State<T> > states, finalStates;
    State<T> initialState;

public:
    DFA();
    DFA(const set<Letter>&, const set<State<T> >&, const State<T>&, const set<State<T> >&);
    DFA(const Letter*, const State<T>*, size_t, const State<T>&, const State<T>*, size_t);

    State* getNext(const State<T>&, Letter);
    State* getSuccessor(const State<T>&, const Word&);

    bool validate(const string&);
    string generate();
};

