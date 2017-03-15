//
//  Token.hpp
//  Calculator
//
//  Created by 高远 on 14/03/2017.
//  Copyright © 2017 高远. All rights reserved.
//

#ifndef Token_hpp
#define Token_hpp

#include <iostream>
#include <string>
using namespace std;

class Token {
private:
    bool isNumber;
    double value;
    int precedence;
    char opr;
public:
    Token(string token);
    Token(double value);
    bool is_Number();
    double getValue();
    int getPrecedence();
    char getOpr();
};
#endif /* Token_hpp */
