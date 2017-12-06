/*
 * JsonObject.cpp
 *
 *  Created on: Dec 5, 2017
 *      Author: lx
 */

#include "JsonObject.h"
#include <iterator>

JsonObject::JsonObject()
{
	top = NULL;
	bottom = NULL;
	length = 0;
}

JsonObject::~JsonObject()
{
	clean();
}

JsonValue JsonObject::operator[] (std::string key) const
{
	return JsonValue();
}

std::string JsonObject::keyAt(int i)
{
	return "";
}

void JsonObject::clean()
{
	struct _map *node = top;
	struct _map *tmp = node;
	while(node->next != NULL)
	{
		tmp = node;
		node = node->next;
		delete tmp;
	}
}

JsonObject::Iterator JsonObject::find(std::string key)
{
	struct _map *node = top;
	int i = 0;
	while(node != NULL)
	{
		if (node->key == key)
		{
			break;
		}
		++i;
		node = node->next;
	}
	return JsonObject::Iterator(this, i);
}

JsonObject::Iterator JsonObject::insert(std::string key, JsonValue value)
{
	if (this->find(key) != this->end())
	{
		struct _map * node = new struct _map;
		node->key = key;
		node->value = value;
		++length;
		bottom->next = node;
		bottom = node;
		return JsonObject::Iterator(this, length);
	}
	else
	{
		struct _map *node = top;
		int i = 0;
		while(node->next != NULL)
		{
			if (node->key == key)
			{
				node->value = value;
				break;
			}
			++i;
			node = node->next;
		}
		return JsonObject::Iterator(this, i);
	}
}

bool JsonObject::isEmpty()
{
	return length == 0;
}

JsonObject::Iterator JsonObject::begin()
{
	JsonObject::Iterator begin(this, 1);
	return begin;
}

JsonObject::Iterator JsonObject::end()
{
	JsonObject::Iterator end(this, length + 1);
	return end;
}

JsonObject::Iterator::Iterator()
{
	o = NULL;
	i = 0;
}

JsonObject::Iterator::Iterator(JsonObject *obj, int index)
{
	o = obj;
	i = index;
}

JsonObject::Iterator::~Iterator()
{
	//
}

std::string JsonObject::Iterator::key() const
{
	return o->keyAt(i);
}

JsonValue JsonObject::Iterator::value() const
{
	return (*o)[o->keyAt(i)];
}

bool JsonObject::Iterator::operator==(const JsonObject::Iterator &other) const
{
	return i == other.i;
}

bool JsonObject::Iterator::operator!=(const JsonObject::Iterator &other) const
{
	return i != other.i;
}

JsonObject::Iterator &JsonObject::Iterator::operator++()
{
	++i;
	return *this;
}

JsonObject::Iterator JsonObject::Iterator::operator++(int)
{
	JsonObject::Iterator r = *this;
	++i;
	return r;
}

JsonObject::Iterator &JsonObject::Iterator::operator--()
{
	--i;
	return *this;
}

JsonObject::Iterator JsonObject::Iterator::operator--(int)
{
	JsonObject::Iterator r = *this;
	--i;
	return r;
}
