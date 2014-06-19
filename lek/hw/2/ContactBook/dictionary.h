/*
 * dictionary.h
 *
 *  Created on: 14.06.2014
 *      Author: radoslav
 */

#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <iostream>
using std::ostream;

template<typename K, typename V>
class Dictionary
{
	K* keys;
	V* values;
	size_t length, capacity;

	void extend(size_t);
	void shrink(size_t);
	void create();
	void copy(const Dictionary&);
	void destroy();

	V* base_find(const K&);
public:
	Dictionary();
	Dictionary(const Dictionary&);
	Dictionary& operator=(const Dictionary&);
	~Dictionary();

	const K* begin_keys() const;
	const V* begin_values() const;
	const K* end_keys() const;
	const V* end_values() const;

	bool empty() const;
	size_t size() const;

	V& operator[](const K&);
	const V& operator[](const K&) const;

	bool insert(const K&, const V&);
	bool erase(const K&);
	bool erase(K*);
	bool erase(V*);
	void clear();

	V* find(const K&);
	const V* find(const K&) const;
	bool exists(const K&) const;

	void print(ostream&) const;
	void printValues(ostream&) const;

	template<typename K1, typename V1>
	friend ostream& operator<<(ostream&, const Dictionary<K1, V1>&);
};

#endif /* DICTIONARY_H_ */
