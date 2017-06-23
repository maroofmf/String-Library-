#include <iostream>
#include <stdio.h>
#include "String.hpp"

int main(){
    
    char status = 'y';
    bool readStatus = true;

    while(status!='n'){
        lib::String* compareObj = new lib::String;
        readStatus = compareObj->readInput();
        
        if(readStatus){
            compareObj->printReport();
        }

        // Code to check if the user wants to repeat the process
        std::cout << "Do you want to restart? (y/n):";
        status = getc(stdin);
        fseek(stdin,0,SEEK_END);

        // Deallocale memory
        delete compareObj;
        compareObj= nullptr;
    }

}
