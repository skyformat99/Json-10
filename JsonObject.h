/*
 * JsonObject.h
 *
 *  Created on: Dec 5, 2017
 *      Author: lx
 */

#ifndef JSONOBJECT_H_
#define JSONOBJECT_H_

#include <string>
#include "JsonValue.h"

class JsonObject
{
public:
	JsonObject();
	~JsonObject();

public:
	class Iterator
	{
		friend class JsonObject;
		int i;
		JsonObject *o;
	public:
		Iterator();
		Iterator(JsonObject *obj, int index);
		~Iterator();

		std::string key() const;
		JsonValue value() const;

		bool operator==(const Iterator &other) const;
		bool operator!=(const Iterator &other) const;
		Iterator &operator++();
		Iterator operator++(int);
		Iterator &operator--();
		Iterator operator--(int);
	};
	friend class Iterator;

public:
	JsonValue operator[] (std::string key) const;
	Iterator insert(std::string key, JsonValue value);
	void clean();
	bool isEmpty();
	Iterator begin();
	Iterator end();
	std::string keyAt(int i);
	Iterator find(std::string key);

private:
	struct _map
	{
		std::string key;
		JsonValue value;
		struct _map *next;
	};
	struct _map *top;
	struct _map *bottom;
	int length;
};

#endif /* JSONOBJECT_H_ */
