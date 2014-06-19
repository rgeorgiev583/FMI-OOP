#include "dfa.h"

DFA::DFA() {}

DFA::DFA(const set<Letter>& _alphabet, const set<State<T> >& _states, const State<T>& _initialState, const set<State<T> >& _finalStates):
    alphabet(_alphabet), states(_states), initialState(_initialState), finalStates(_finalStates) {}

DFA::DFA(const Letter* _alphabet, const State<T>* _states, size_t stateCount, const State<T>& _initialState, const State<T>* _finalStates,
    size_t finalStateCount):
{
    while (*_alphabet)
    {
        strcpy(alphabet, _alphabet);

    }
}
