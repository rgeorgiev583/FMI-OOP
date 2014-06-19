/*
 * formula-parser.h
 *
 *  Created on: 18.06.2014
 *      Author: radoslav
 */

#ifndef FORMULA_PARSER_H_
#define FORMULA_PARSER_H_

#include <cstdlib>
#include <sstream>
#include "formula.h"
#include "constant.h"
#include "binary-operation.h"
#include "read.h"
#include "conditional.h"

using std::string;
using std::ws;
using std::istringstream;

size_t getClosingParenthesisPosition(const string& str)
{
	size_t length = str.length(), i = str.find("(");

	if (i != string::npos && i + 1 < length)
	{
		size_t match_level = 1;

		do
		{
			i++;

			if (str[i] == '(')
				match_level++;
			else if (str[i] == ')')
				match_level--;
		}
		while (i < length && match_level);

		return i < length ? i : string::npos;
	}
	else
		return string::npos;
}

Formula* parseFormula(const string& formula_str)
{
	istringstream formula_stream(formula_str);
	string token;
	Formula *parsed_token = NULL;
	size_t operand_count = 0;

	// двуместна операция
	char op = 0;
	Formula *lhs = NULL;

	// условна операция
	bool past_if = false, past_then = false, past_else = false;
	Formula *condition = NULL, *result = NULL;

    formula_stream >> ws;
    size_t prev_pos = formula_stream.tellg();

	while (getline(formula_stream, token, ' '))
	{
		if (token == "(")
		{
			size_t opar_pos = prev_pos;
			size_t cpar_pos = prev_pos + getClosingParenthesisPosition(
					formula_str.substr(opar_pos)
			);

			if (cpar_pos != string::npos)
			{
				parsed_token = parseFormula(formula_str.substr(opar_pos + 1,
						cpar_pos - 1 - opar_pos));
				formula_stream.seekg(cpar_pos + 1);
				operand_count++;
			}
			else
				return NULL;
		}
		else if (token == "+" ||
				 token == "-" ||
				 token == "*" ||
				 token == "/" ||
				 token == "<" ||
				 token == "=")
		{
			if (parsed_token && operand_count == 1)
			{
				lhs = parsed_token;
				parsed_token = NULL;
				op = token[0];
			}
			else
				return NULL;
		}
		else if (token == "if")
		{
			if (operand_count == 0)
				past_if = true;
			else
				return NULL;
		}
		else if (token == "then")
		{
			if (past_if && parsed_token && operand_count == 1)
			{
				condition = parsed_token;
				parsed_token = NULL;
				past_then = true;
			}
			else
				return NULL;
		}
		else if (token == "else")
		{
			if (past_if && past_then && parsed_token && operand_count == 2 &&
					condition)
			{
				result = parsed_token;
				parsed_token = NULL;
				past_else = true;
			}
			else
				return NULL;
		}
		else if (token == "Read")
		{
			parsed_token = new Read();
			operand_count++;
		}
		else
		{
			double c;
			istringstream token_stream(token);
			token_stream >> c;

			if (!token_stream)
				return NULL;
			else
			{
				parsed_token = new Constant(c);
				operand_count++;
			}
		}

		formula_stream >> ws;
        prev_pos = formula_stream.tellg();
	}

	switch (operand_count)
	{
	case 1:  // израз в скоби, константен израз или израз от тип Read
		return parsed_token;

	case 2:  // двуместна операция
		return op && lhs ? new BinaryOperation(op, lhs, parsed_token) : NULL;

	case 3:  // условна (триместна) операция
		return past_if && past_then && past_else && condition && result ?
				new Conditional(condition, result, parsed_token) : NULL;

	default: // в противен случай формулата е невалидна
		return NULL;
	}

	return NULL;
}

Formula* readFormula()
{
	string formula_str;
	getline(cin, formula_str);
	return !cin ? NULL : parseFormula(formula_str);
}

#endif /* FORMULA_PARSER_H_ */
