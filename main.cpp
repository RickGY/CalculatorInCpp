//
//  main.cpp
//  Calculator
//
//  Created by 高远 on 14/03/2017.
//  Copyright © 2017 高远. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include "Token.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    stack<Token> valueStack;
    stack<Token> oprStack;
    vector<Token> expression;
    
    cout << "Pls enter the expression to evaluate, all elements should be properly delimited by '\\s'." << endl;
    
    string input;
    while(getline(cin, input, ' ')){
        //cout << input << endl;
        Token token(input);
        expression.push_back(token);
    }
    //cout << expression.size() << endl;
    for(int i = 0; i < expression.size(); ++i){
        //cout << i << endl;
        Token token = expression[i];
        if(token.is_Number()){
            valueStack.push(token);
        }
        else{
            if(oprStack.size() == 0){
                oprStack.push(token);
            }
            else{
                if (token.getPrecedence() == 3){
                    oprStack.push(token);
                }
                else if(token.getPrecedence() == 4){
                    while (oprStack.top().getPrecedence() != 3){
                        double value2 = valueStack.top().getValue();
                        valueStack.pop();
                        double value1 = valueStack.top().getValue();
                        valueStack.pop();
                        
                        char opr = oprStack.top().getOpr();
                        oprStack.pop();
                        double value3;
                        if( opr == '+'){
                            value3 = value1 + value2;
                        }
                        else if (opr == '-'){
                            value3 = value1 - value2;
                        }
                        else if (opr == '*'){
                            value3 = value1 * value2;
                        }
                        else{
                            value3 = value1 / value2;
                        }
                        Token newValue(value3);
                        valueStack.push(newValue);
                    }// end of while loop
                    oprStack.pop();
                } // end of the case of right parenthesis
                else if(token.getPrecedence() > oprStack.top().getPrecedence() || oprStack.top().getPrecedence() == 3){
                    oprStack.push(token);
                } // end of the case the calculation operator has a higher precedence than the top of oprStack
                else{
                    while(oprStack.size() != 0 && oprStack.top().getPrecedence() >= token.getPrecedence() && oprStack.top().getPrecedence() != 3){
                        double value2 = valueStack.top().getValue();
                        valueStack.pop();
                        double value1 = valueStack.top().getValue();
                        valueStack.pop();
                        
                        char opr = oprStack.top().getOpr();
                        oprStack.pop();
                        double value3;
                        if( opr == '+'){
                            value3 = value1 + value2;
                        }
                        else if (opr == '-'){
                            value3 = value1 - value2;
                        }
                        else if (opr == '*'){
                            value3 = value1 * value2;
                        }
                        else{
                            value3 = value1 / value2;
                        }
                        Token newValue(value3);
                        valueStack.push(newValue);
                    } // end of while loop
                    //push the token in
                    oprStack.push(token);
                }// end of the case the calculation operator has a lower or equal precedence than the top of the oprStack
            }// end of the case of non-empty oprStack
        }// end of the case of operator token is examined
    }// end of the for loop
    while (oprStack.size() != 0){
        double value2 = valueStack.top().getValue();
        valueStack.pop();
        double value1 = valueStack.top().getValue();
        valueStack.pop();
        
        char opr = oprStack.top().getOpr();
        oprStack.pop();
        double value3;
        if( opr == '+'){
            value3 = value1 + value2;
        }
        else if (opr == '-'){
            value3 = value1 - value2;
        }
        else if (opr == '*'){
            value3 = value1 * value2;
        }
        else{
            value3 = value1 / value2;
        }
        Token newValue(value3);
        valueStack.push(newValue);
    }
    //cout << valueStack.size() << endl;
    cout << "The result is " << valueStack.top().getValue() << endl;
    return 0;
}

