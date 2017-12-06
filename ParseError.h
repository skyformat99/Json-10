/*
 * ParseError.h
 *
 *  Created on: Dec 5, 2017
 *      Author: lx
 */

#ifndef PARSEERROR_H_
#define PARSEERROR_H_

#include <string>

class ParseError {
public:
	ParseError();
	~ParseError();

public:
	std::string errorString();

private:
	std::string errorStr;
};

#endif /* PARSEERROR_H_ */
