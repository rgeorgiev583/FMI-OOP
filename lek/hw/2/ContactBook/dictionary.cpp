/*
 * dictionary.cpp
 *
 *  Created on: 14.06.2014
 *      Author: radoslav
 */

#ifndef DICTIONARY_CPP_
#define DICTIONARY_CPP_

#include "dictionary.h"

using std::cout;
using std::endl;

const size_t ALLOC_INIT = 4, ALLOC_QUOT = 1.5;

template<typename K, typename V>
void Dictionary<K, V>::extend(size_t pos)
{
	if (length + 1 == capacity)
	{
		capacity *= ALLOC_QUOT;

		K* newkeys = new K[capacity];
		V* newvalues = new V[capacity];

		for (size_t i = 0; i < pos; i++)
		{
			newkeys[i] = keys[i];
			newvalues[i] = values[i];
		}

		for (size_t i = pos; i < length; i++)
		{
			newkeys[i + 1] = keys[i];
			newvalues[i + 1] = values[i];
		}

		delete[] keys;
		delete[] values;
		keys = newkeys;
		values = newvalues;
	}
	else if (length > 0)
		for (long i = (long) length - 1; i >= (long) pos; i--)
		{
			keys[i + 1] = keys[i];
			values[i + 1] = values[i];
		}

	length++;
}

template<typename K, typename V>
void Dictionary<K, V>::shrink(size_t pos)
{
	if (length > 0)
		for (size_t i = pos; i < length - 1; i++)
		{
			keys[i] = keys[i + 1];
			values[i] = values[i + 1];
		}

	length--;
}

template<typename K, typename V>
void Dictionary<K, V>::create()
{
	keys = new K[ALLOC_INIT];
	values = new V[ALLOC_INIT];
	length = 0;
	capacity = ALLOC_INIT;
}

template<typename K, typename V>
void Dictionary<K, V>::copy(const Dictionary<K, V>& other)
{
	keys = new K[other.length];
	values = new V[other.length];

	for (size_t i = 0; i < other.length; i++)
	{
		keys[i] = other.keys[i];
		values[i] = other.values[i];
	}

	length = other.length;
	capacity = other.capacity;
}

template<typename K, typename V>
void Dictionary<K, V>::destroy()
{
	delete[] keys;
	delete[] values;

	keys = NULL;
	values = NULL;
	length = 0;
	capacity = 0;
}

template<typename K, typename V>
V* Dictionary<K, V>::base_find(const K& key)
{
	size_t i = 0;

	while (i < length && keys[i] < key)
		i++;

	return i < length && keys[i] == key ? &values[i] : NULL;
}

template<typename K, typename V>
Dictionary<K, V>::Dictionary()
{
	create();
}

template<typename K, typename V>
Dictionary<K, V>::Dictionary(const Dictionary<K, V>& other)
{
	copy(other);
}

template<typename K, typename V>
Dictionary<K, V>& Dictionary<K, V>::operator=(const Dictionary<K, V>& other)
{
	if (&other != this)
	{
		destroy();
		copy(other);
	}

	return *this;
}

template<typename K, typename V>
Dictionary<K, V>::~Dictionary()
{
	destroy();
}

template<typename K, typename V>
const K* Dictionary<K, V>::begin_keys() const
{
	return keys;
}

template<typename K, typename V>
const V* Dictionary<K, V>::begin_values() const
{
	return values;
}

template<typename K, typename V>
const K* Dictionary<K, V>::end_keys() const
{
	return keys + length;
}

template<typename K, typename V>
const V* Dictionary<K, V>::end_values() const
{
	return values + length;
}

template<typename K, typename V>
bool Dictionary<K, V>::empty() const
{
	return !keys && !values;
}

template<typename K, typename V>
size_t Dictionary<K, V>::size() const
{
	return length;
}

template<typename K, typename V>
V& Dictionary<K, V>::operator[](const K& key)
{
	size_t i = 0;

	while (i < length && keys[i] < key)
		i++;

	if (i == length || keys[i] != key)
	{
		extend(i);
		keys[i] = key;
	}

	return values[i];
}

template<typename K, typename V>
const V& Dictionary<K, V>::operator[](const K& key) const
{
	V* value = base_find(key);
	return value ? *value : values[0];
}

template<typename K, typename V>
bool Dictionary<K, V>::insert(const K& key, const V& value)
{
	if (!base_find(key))
	{
		operator[](key) = value;
		return true;
	}
	else
		return false;
}

template<typename K, typename V>
bool Dictionary<K, V>::erase(const K& key)
{
	size_t i = 0;

	while (i < length && keys[i] < key)
		i++;

	if (i < length && keys[i] == key)
	{
		shrink(i);
		return true;
	}
	else
		return false;
}

template<typename K, typename V>
bool Dictionary<K, V>::erase(K* ppos)
{
	if (ppos && ppos >= keys && ppos - keys < length)
	{
		shrink(ppos - keys);
		return true;
	}
	else
		return false;
}

template<typename K, typename V>
bool Dictionary<K, V>::erase(V* ppos)
{
	if (ppos && ppos >= values && ppos - values < length)
	{
		shrink(ppos - values);
		return true;
	}
	else
		return false;
}

template<typename K, typename V>
void Dictionary<K, V>::clear()
{
	destroy();
	create();
}

template<typename K, typename V>
V* Dictionary<K, V>::find(const K& key)
{
	return base_find(key);
}

template<typename K, typename V>
const V* Dictionary<K, V>::find(const K& key) const
{
	return base_find(key);
}

template<typename K, typename V>
bool Dictionary<K, V>::exists(const K& key) const
{
	return base_find(key);
}

template<typename K, typename V>
void Dictionary<K, V>::print(ostream& os = cout) const
{
	os << "{"     << endl;

	for (size_t i = 0; i < length - 1; i++)
		os << "    `" << keys[i] << "\': `" << values[i] << "\'," << endl;

	os << "    `" << keys[length - 1] << "\': `" << values[length - 1]
       << "\'"    << endl;
	os << "}"     << endl;
}

template<typename K, typename V>
void Dictionary<K, V>::printValues(ostream& os = cout) const
{
	for (size_t i = 0; i < length; i++)
		os << values[i] << endl;
}

template<typename K, typename V>
ostream& operator<<(ostream& os, const Dictionary<K, V>& d)
{
	d.print(os);
	return os;
}

#endif /* DICTIONARY_CPP_ */
