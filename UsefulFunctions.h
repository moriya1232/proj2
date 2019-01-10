//
// Created by moriya on 13/12/18.
//

#ifndef PROJECT_USEFULFUNCTION_H
#define PROJECT_USEFULFUNCTION_H

using namespace std;

#include "Expression.h"
#include "Number.h"
#include "Divide.h"
#include "Multiplication.h"
#include "Minus.h"
#include "Plus.h"
#include <regex>


using namespace std;


/**
 *check if operator
 * @param c
 * @return true or false
 */
static bool checkIfOperator(char c) {
    if (c == '+' || c == '-' || c == '/' || c == '*' || c=='\342')
        return true;
    return false;
}


/**
 *check if < or > or = for to knoe if it condition
 * @param c
 * @return true or false
 */
static bool checkIfCondition(char c) {
    if (c == '=' || c == '<' || c == '>') {
        return true;
    }
    return false;
}

/**
 * check if it is a digit
 * @param c
 * @return true or false
 */
static bool checkIfDigit(char c) {
    if (c - '0' >= 0 && c - '0' < 10)
        return true;
    return false;
}


/**
 *check if letter
 * @param c
 * @return true or false
 */
static bool checkIfLetter(char c) {
    if ((c - '0' >= 'a' - '0' && c - '0' <= 'z' - '0') || (c - '0' >= 'A' - '0' && c - '0' <= 'Z' - '0'))
        return true;
    return false;
}


/**
 *check if small letter
 * @param c
 * @return true or false
 */
static bool checkIfSmallLetter(char c) {
    if ((c - '0' >= 'a' - '0' && c - '0' <= 'z' - '0'))
        return true;
    return false;
}


/**
 *check if }
 * @param c
 * @return true or false
 */
static bool ifStackHasGreaterOperator(char oper, string oper2) {
    string oper1 = to_string(oper);
    if (oper1 == "+" || oper1 == "-")
        if (oper2 == "*" || oper2 == "/")
            return true;
    return false;
}

/**
 *check if {
 * @param c
 * @return true or false
 */
static bool checkOpenClosure(char c) {
    if (c == '(')
        return true;
    return false;
}

/**
 *check id }
 * @param c
 * @return true or false
 */
static bool checkCloseClosure(char c) {
    if (c == ')')
        return true;
    return false;
}
/**
 * extract the number
 * @param line
 * @return the number
 */
static string extractNum (string line) {
    string result = "";
    for (int i=0;checkIfDigit(line[i]);i++) {
        result+=line[i];
    }
    return result;
}

/**
 * this function remove spaces from right
 * @param line
 * @return the string after the change
 */
static string removeSpacingFromBegin(string line) {
    for(int i=0; line[i] == ' ' || line[i] == '\t' || line[i] == '\b';) {
        line = line.substr(1, line.length()-1);
    }
    return line;
}

/**
 * this function remoce spaces from the end
 * @param line
 * @return the string after the change
 */
static string removeSpacingFromEnd(string line) {
    int i = line.length()-1;
    for(; line[i] == ' ' || line[i] == '\t' || line[i] == '\b';--i) {}
    line = line.substr(0, i+1);
    return line;
}

/**
 * remove the spcaes after tnf befor the word
 * @param line
 * @return the string after the change
 */
static string removeSpaces(string line) {
    line = removeSpacingFromBegin(line);
    line = removeSpacingFromEnd(line);
    return line;
}

/**
 * remove the apostrophes
 * @param line
 * @return the string after the change
 */
static string removeApostrophes(string line) {
    line = removeSpaces(line);
    if (line[0] == '"' && line[line.length() - 1] == '"') {
        line = line.substr(1);
        line = line.substr(0, line.length() - 1);
    }
    return line;
}

/**
 * remove the {
 * @param line
 * @return line after the change
 */
static string removeOpenSpiPar(string line) {
    line = removeSpaces(line);
    if(line[line.length()-1] == '{') {
        line = line.substr(0,line.length()-2);
    }
    return line;
}
/**
 * remove the equal in the string
 * @param line
 * @return the string after the change
 */
static string removeEqual(string line) {
    for(int i=0;line[i] == ' ' || line[i] == '=' ;) {
        line = line.substr(1, line.length()-1);
    }
    return line;
}
/**
 * removr the paranthesis from line
 * @param line
 * @return the string after the change
 */
static string removeParenthesis(string line) {
    line = removeSpaces(line);
    int counter = 0;
    if (line[0] == '(' && line[line.length()-1] == ')') {
        for (int i=1;i<line.length()-1;++i) {
            char c = line[i];
            if (c==')') {
                if (counter==0) {
                    counter--;
                    break;
                } else {
                    counter--;
                }
            } else if (c=='(') {
                counter++;
            }
        } if(counter==0) {
            line = line.substr(1, line.length() - 2);
        }
    }
    return line;
}


/**
 * check if the line exist number
 * @param ex
 * @return true or false
 */
static bool existNum(string ex){
    if (ex == "") {
        return false;
    }
    char c = ex[0];
    for(int i=0; i<ex.length(); i++) {
        if (checkIfDigit(ex[i])) {
            return true;
        }
        c=ex[i];
    }
    return false;
}


/**
 * extract the first word from line
 * @param line
 * @return word
 */
static string extractWordFromLine(string line) {
    line = removeSpaces(line);
    string result = "";
    int i = 0;
    while (line[i] != ' ' && line[i] != '\n' && i < line.length() && line[i] != '\t') {
        result += line[i];
        i++;
    }
    return result;
}

/**
 * ectract the expressin
 * @param line
 * @return the expressin
 */
static string extractExpression(string line) {
    line = removeSpaces(line);
    string ex = "";
    for (int i=0; checkIfDigit(line[i]) || checkIfSmallLetter(line[i]); i++ ){
        ex+=line[i];
    }
    return ex;
}
/**
 * ectract the sign
 * @param line
 * @return the sign
 */
static string extractSign(string line) {
    line = removeSpaces(line);
    string sign = "";
    for (int i=0; checkIfCondition(line[i]); i++ ){
        sign+=line[i];
    }
    return sign;
}



#endif //PROJECT_USEFULLFUNCTION_H