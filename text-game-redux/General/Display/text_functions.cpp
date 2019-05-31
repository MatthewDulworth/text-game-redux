//
//  text_functions.cpp
//  text-game-redux
//
//  Created by Matthew Dulworth on 5/19/19.
//  Copyright © 2019 Matthew Dulworth. All rights reserved.
//
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include "text_functions.hpp"
using namespace std;


// -------------------------------------------------------------------------------------------------
// forward declarations of text functions
// -------------------------------------------------------------------------------------------------
void clearConsole();
void scrollDown(int lines, int millisec);
void centerText(string str);
void wait(int millisec);
void newline();
void newline(int lines);
void typeText(string text);
void centerType(string text);


// -------------------------------------------------------------------------------------------------
// text functions
// -------------------------------------------------------------------------------------------------

// clears the screen
void clearConsole(){
    for(int i=0; i<console_height+2; ++i)
        cout << endl;
}

//scrolls down
void scrollDown(int lines, int millisec){
    for(int i=0; i<lines; ++i){
        cout << endl;
        wait(millisec);
    }
}

// centers the text
void centerText(string str){
    unsigned long center = ( (console_width - str.length()) / 2);
    
    for(int i=0; i<center; ++i)
        cout << " ";
    
    cout << str << endl;
}

// pauses program for an amount of time in milliseconds
void wait(int millisec){
    this_thread::sleep_for(chrono::milliseconds(millisec));
}

// prints a newline
void newline(){
    cout << endl;
}

// prints a number of newlines
void newline(int lines){
    for(int i=0; i<lines; ++i)
        cout << endl;
}

// ouputs text as if it is being typed
void typeText(string text){
    for(int i=0; i<text.length(); ++i)
    {
        cout << text[i];
        wait(50);
        
        if(text[i] == ' '){
            wait(30);
        }
        
    }
    cout << endl;
}


void centerType(string text){
    unsigned long center = ( (console_width - text.length()) / 2);
    
    for(int i=0; i<center; ++i)
        cout << " ";
    
    typeText(text);
    cout << endl;
}
