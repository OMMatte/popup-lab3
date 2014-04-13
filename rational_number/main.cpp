//  Created by Mathias Lindblom on 2014-01-27.
//  Copyright (c) 2014 Mathias Lindblom. All rights reserved.
//

#include <iostream>
#include <stdexcept>

#include "RationalNumber.h"

#define PLUS '+'
#define MINUS '-'
#define MULTIPLY '*'
#define DIVIDE '/'

int main(int argc, const char * argv[]) {
    int nr_operations;
    char c;
    RationalNumber<long> first, second, result;
    
    scanf("%i", &nr_operations);
    
    for(int i = 0; i < nr_operations; i++) {
        
        std::cin >> first;
        scanf(" %c ", &c);
        std::cin >> second;
        if(c == PLUS) {
            result = first + second;
        } else if(c == MINUS) {
            result = first - second;
        } else if(c == MULTIPLY) {
            result = first * second;
        } else if(c == DIVIDE) {
            result = first / second;
        } else {
            throw std::invalid_argument( &"Unknown mathematical operator: " [c] );
        }
        std::cout << result << std::endl;
    }

    return 0;
}
