//
//  text_functions.hpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 5/19/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//

#ifndef text_functions_hpp
#define text_functions_hpp

#include <string>

const int console_height = 57;
const int console_width = 211;

void clearConsole();
void scrollDown(int lines, int millisec);
void centerText(std::string str);
void wait(int millisec);
void newline();
void newline(int lines);
void typeText(std::string text);
void centerType(std::string text);

#endif /* text_functions_hpp */
