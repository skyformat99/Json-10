/*
 * JsonDocument.cpp
 *
 *  Created on: Dec 5, 2017
 *      Author: lx
 */

#include "JsonDocument.h"
#include "ParseError.h"

JsonDocument::JsonDocument()
{
	//
}

JsonDocument::~JsonDocument()
{
	//
}

JsonDocument JsonDocument::Parse(std::string json, ParseError* error)
{
	JsonDocument doc;
	if (!doc.isStart(json))
	{
		if (error != NULL)
			error->errorString() = "非正常起始字符";
		return doc;
	}
	if (!doc.isMatched(json))
	{
		if (error != NULL)
			error->errorString() = "括号不匹配";
		return doc;
	}
	return doc;
}

bool JsonDocument::isStart(std::string json)
{
	return (json[0] == '{');
}

bool JsonDocument::isMatched(std::string json)
{
	return false;
}

JsonObject JsonDocument::object() const
{
	return obj;
}
