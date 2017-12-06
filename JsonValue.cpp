/*
 * JsonValue.cpp
 *
 *  Created on: Dec 5, 2017
 *      Author: lx
 */

#include "JsonValue.h"
#include <sstream>

JsonValue::JsonValue()
{
	this->strData = "";
	t = Null;
}

JsonValue::~JsonValue()
{
}

JsonValue::JsonValue(std::string strValue)
{
	this->stringData = strValue;
	this->strData = strValue;
	t = String;
}

JsonValue::JsonValue(bool bValue)
{
	this->b = bValue;
	t = Bool;
	this->strData = bValue?"true":"false";
}

JsonValue::JsonValue(double dValue)
{
	this->dbl = dValue;
	t = Double;
	std::stringstream ss;
	ss << dValue;
	this->strData = ss.str();
}

JsonValue::JsonValue(JsonArray jaValue)
{
	this->jaBase = jaValue;
	t = Array;
}

bool JsonValue::isEmpty()
{
	return strData.empty();
}

JsonValue::Type JsonValue::type()
{
	return t;
}
