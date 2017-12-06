/*
 * JsonValue.h
 *
 *  Created on: Dec 5, 2017
 *      Author: lx
 */

#ifndef JSONVALUE_H_
#define JSONVALUE_H_

#include <string>
#include "JsonArray.h"
#include "JsonObject.h"

class JsonValue
{
public:
	JsonValue();
	JsonValue(std::string strValue);
	JsonValue(bool bValue);
	JsonValue(double dValue);
	JsonValue(JsonArray jaValue);
	~JsonValue();

public:
	enum Type {
		Null =  0x0,
		Bool = 0x1,
		Double = 0x2,
		String = 0x3,
		Array = 0x4,
		Object = 0x5,
		Undefined = 0x80
	};

public:
	bool isEmpty();
	Type type();

private:
	unsigned int ui;
	bool b;
	double dbl;
	std::string stringData;
	JsonArray jaBase;
	std::string strData;
	Type t;
};

#endif /* JSONVALUE_H_ */
