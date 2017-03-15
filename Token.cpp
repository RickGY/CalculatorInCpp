//
//  Token.cpp
//  Calculator
//
//  Created by 高远 on 14/03/2017.
//  Copyright © 2017 高远. All rights reserved.
//

#include "Token.hpp"
#include <iostream>
#include <string>
using namespace std;

Token::Token(string token){
    value = atof(token.c_str());
    if (value == 0.0){
        isNumber = false;
        opr = token.at(0);
        if( opr == '+' || opr == '-'){
            precedence = 1;
        }
        else if ( opr == '*' || opr == '/'){
            precedence = 2;
        }
        else if (opr == '('){
            precedence = 3;
        }
        else{
            precedence = 4;
        }
    }
    else{
        isNumber = true;
    }
}

Token::Token(double value){
    this -> value = value;
    this -> isNumber = true;
}
bool Token::is_Number(){
    return isNumber;
}

double Token::getValue(){
    return value;
}

int Token::getPrecedence(){
    return precedence;
}

char Token::getOpr(){
    return opr;
}

