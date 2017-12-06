/*
 * JsonDocument.h
 *
 *  Created on: Dec 5, 2017
 *      Author: lx
 */

#ifndef JSONDOCUMENT_H_
#define JSONDOCUMENT_H_

#include <string>
#include "JsonObject.h"

class ParseError;

class JsonDocument {
public:
	JsonDocument();
	~JsonDocument();

public:
	static JsonDocument Parse(std::string json, ParseError* error = NULL);
	JsonObject object() const;

private:
	bool isStart(std::string json);
	bool isMatched(std::string json);

private:
	JsonObject obj;
};

#endif /* JSONDOCUMENT_H_ */
