// ---------------------------------------------------------------------//
// Author:      Maroof
// File Name:   String.cpp
// File Type:   Cpp File
// Purpose:     Implementation of String class.
// Description: 
//  * Perform operations on two strings
//  * Read README.md for high level details for functions
//  * Further details provided in the functions
// ---------------------------------------------------------------------//

#include "String.hpp"
#include <iostream>
#include <stdio.h>

using namespace lib;


//------------------------------------------------------------------------//
/* Function:Default Constructor
 * @Params: No Parameters
 * @Description: Called when object is constructed
 * @Usage: 
 *      > String* test1 = new String;
 *      > String test2;
 */

String::String(){}

//------------------------------------------------------------------------//
/* Function: Destructor
 * @Params: No Parameters
 * @Description: Called when object is deleted
 * @Usage: 
 *      > delete test1;
 */

String::~String(){
   
    // Free Dynamically allocated member variables to prevent memory leaks 
    delete[] m_str1;
    delete[] m_str2;
}


//------------------------------------------------------------------------//
/* Function: Read Input from console
 * @Params: No Parameters
 * @Description: 
 *      * Function to read input and call other functions to handle input
 *      * Returns true if read is successful
 *      * Returns false if read is unsuccessful
 * @Usage: 
 *       > String* test1 = new String;
 *       > test1->readInput();
 */

bool String::readInput(){
    
    // Reading input for first string:
    std::cout << "Enter String 1:";
    char c;                 // Temporary Character
    char* str1_ptr = m_str1;  // Running pointer to store values
    ErrorCode error_1 = NO_ERROR; // Error handling for input 1
    
    // Read input buffer character by character
    do{
        c = getc(stdin);

        // Check if input character is valid.
        if(!checkChar(c)){
            error_1 = INVALID_INPUT;
            break;
        }
        
        // Store character in the input string
        *str1_ptr = c;
        
        // Update pointer and length 
        ++str1_ptr;
        ++m_strLen1;
        
        // Resize the array if the capacity has been reached!
        if(m_strLen1+1 == m_strCapacity1){
            resize(m_str1,str1_ptr,m_strCapacity1);    
        }
    
    } while(c!='\n');
    
    // Add '\0' to terminate the string
    if(m_strLen1!=0){
        --m_strLen1; //  This is done because the do-while loop increments the value for \n too!
        *(str1_ptr-1) = '\0';
    }
    
    // Add error code if the input string is null
    if(m_strLen1 ==0 && error_1 != INVALID_INPUT) error_1 = NULL_INPUT;

    fseek(stdin,0,SEEK_END); // Synonymous to clearing input buffer
    
    // Reading input for second string:
    std::cout << "Enter String 2:";
    char* str2_ptr = m_str2;  // Pointer to first element
    ErrorCode error_2 = NO_ERROR;// Error handling for input 2
    
    // Process similar for string 1 :p
    do{
        c = getc(stdin);
        if(!checkChar(c)){
            error_2 = INVALID_INPUT;
            break;
        } 
        *str2_ptr = c;
        ++str2_ptr;
        ++m_strLen2;
        
        if(m_strLen2+1 == m_strCapacity2){
            resize(m_str2,str2_ptr,m_strCapacity2);    
        }
    
    } while(c!='\n');
    
    if(m_strLen2!=0){
        --m_strLen2;
        *(str2_ptr-1) = '\0';
    }
    
    if(m_strLen2 ==0 && error_2 != INVALID_INPUT) error_2 = NULL_INPUT;

    fseek(stdin,0,SEEK_END); // Synonymous to clearing input buffer
    return errorCheck(error_1,error_2); // Return true if the inputs were read sucessfully
}

//------------------------------------------------------------------------//
/* Function: Resize String;
 * @Params: 
 *     * str -> string to be resized
 *     * iterationIndex -> Current iteration index. Updates it to reflect 
 *                          the current position during previous iterations 
 *     * capacity -> Reads the current capacity and changes it to double.
 * @Description: This function implements table doubling method for resizing array
 * @Usage: Restricted! Should not access outside class
 */

void String::resize(char* &str,char* &iterationIndex, long& capacity){
    
    // Dynamically allocate new contigious memory
    char* temp = new char[capacity*2];
    
    // Copy array values from previous array
    for(int i=0;i<capacity-1;++i){
        *(temp+i)=*(str+i);
    }
    
    // Update iteration index to point to the current index used in iteration
    iterationIndex = (temp+capacity-1);

    // Update capacity
    capacity = 2*capacity;

    // Delete dynamically allocated memory and update str pointer
    delete str;
    str = temp;
}

//------------------------------------------------------------------------//
/* Function: Check for each chacter
 * @Params:
 *      * inputChar -> character variable
 * @Description: 
 *      * Checks if the input cahracter lies within a range
 *      * If the character lies withing the ASCII values then the function 
 *        returns true or else it returns false
 * @Usage: Restricted use
 */

bool String::checkChar(const char& inputChar){
    
    // Convert char to int to compare:
    const int ASCII_value = static_cast<const int>(inputChar);

    if( ASCII_value >= 48 && ASCII_value <=57){ // Checks if the character is a number
        return true;
    }else if( ASCII_value >= 65 && ASCII_value <=90 ){ // Checks if the character is alpahbet (A-Z)
        return true;
    }else if(ASCII_value >= 97 && ASCII_value <=122){ // Checks if the character is an alphabet (a-z)
        return true;
    }else if(ASCII_value == 10){ // Checks if it is an enter '\n'.
        return true;
    }

    return false;
}


//------------------------------------------------------------------------//
/* Function: Check for error in input
 * @Params: 
 *      * error_1 -> takes error code #1 (enum)
 *      * error_@ -> takes error code #2 (enum)
 * @Desription:
 *      * Takes two error codes and displays the error based on error type
 * @Usage: Restricted use to class only!
 */

bool String::errorCheck(ErrorCode error_1,ErrorCode error_2){
    
    if(error_1 == NO_ERROR && error_2==NO_ERROR) return true;
    
    std::cout << "//-------------------------Report-------------------------//" << std::endl;
    
    if(error_1 == INVALID_INPUT && error_2 == INVALID_INPUT){
        std::cout << "** String 1 and String 2 should only contain ASCII alpha-numeric values!" << std::endl;
    }else if(error_1 == INVALID_INPUT){
        std::cout << "** String 1 should only contain ASCII alpha-numeric values!" << std::endl;
    }else if(error_2 ==INVALID_INPUT){
        std::cout << "** String 2 should only contain ASCII alpha-numeric values!" << std::endl;
    }

    
    if(error_1 == NULL_INPUT && error_2 == NULL_INPUT){
        std::cout << "** String 1 and String 2 should not be null!" << std::endl;
        
    }else if(error_1 == NULL_INPUT){
        std::cout << "** String 1 should not be null!" << std::endl;
    }else if(error_2 == NULL_INPUT){
        std::cout << "** String 2 should not be null!" << std::endl;
    }

    std::cout << "//--------------------------End--------------------------//" << std::endl;
    
    return false;

}

//------------------------------------------------------------------------//
/* Function: Compare function
 * @Params: No parameters
 * @Description: Returns the difference between two strings
 * @Usage: Restricted ouside class!
 */

int String::compare(){
    
    int shortLen = m_strLen1 <= m_strLen2? m_strLen1 : m_strLen2;
    int returnValue = 0;

    for(int i=0;i<shortLen;++i){
        
        // If the values are not equal, then set return value to the difference in ASCII value
        if((*(m_str1+i))!=(*(m_str2+i))){
            //if(i%2==1) returnValue = 256*(static_cast<int>(*(m_str1+i)) - static_cast<int>(*(m_str2+i)));
            //else returnValue = (static_cast<int>(*(m_str1+i)) - static_cast<int>(*(m_str2+i)));
            returnValue = (static_cast<int>(*(m_str1+i)) - static_cast<int>(*(m_str2+i)));
            break;
        }
    
    }
    
    // If string 1 and string 2 chars are same:
    if(returnValue==0){
        returnValue = m_strLen1-m_strLen2;
    }
    
    // Returns 0,+ve or -ve value based on string lengths
    return(returnValue);

}


//------------------------------------------------------------------------//
/* Function: In place inverting the string
 * @Params: No Parameters
 * @Description: Performs in place inversion for both the strings using XOR
 * @Usage: Restricted access! 
 */

void String::invert(){
    
    // Invert String 1 using XOR:
    char* startPtr = m_str1; // Save starting pointers
    char* endPtr = m_str1;  // Save ending pointer
    while(endPtr && *endPtr!='\0') ++endPtr; // Find the end pointer
    for(--endPtr; startPtr<endPtr; ++startPtr,--endPtr){
        *startPtr = (*startPtr)^(*endPtr);  // First char = (first char)^(second char)
        *endPtr = (*startPtr)^(*endPtr);    // End char = (first char)^(second char)
        *startPtr = (*startPtr)^(*endPtr);  // First char = (first char)^(second char) 
    }

    // Invert String 2:
    startPtr = m_str2;
    endPtr = m_str2;
    while(endPtr && *endPtr!='\0') ++endPtr;
    for(--endPtr; startPtr<endPtr; ++startPtr,--endPtr){
        *startPtr = (*startPtr)^(*endPtr);
        *endPtr = (*startPtr)^(*endPtr);
        *startPtr = (*startPtr)^(*endPtr);
    }

}

//------------------------------------------------------------------------//
/* Function: Concat the strings
 * @Params: No Parameters
 * @Description: Function to concatenate two strings which returns a pointer
 *               to array charecters
 * @Usage: Restricted access
 */

char* String::concat(){
    
    char* resultStr = new char[m_strLen1 + m_strLen2 + 1]; // Dynamically allocating concat string;
    char* currentIndex = resultStr; 

    // Inserting string 1:
    char* str_index = m_str1;   // Coping pointer to start of string index
    for(int i=0;i<m_strLen1;i++){
        *currentIndex = *str_index; // Updating string 1 contents to new string
        ++currentIndex;
        ++str_index;
    }

    // Inserting string 2:
    str_index = m_str2;
    for(int i=0;i<m_strLen2;i++){
        *currentIndex = *str_index; // Updating string 2 contents to new string
        ++currentIndex;
        ++str_index;
    }
    *currentIndex = '\0'; // Append termination char
    return resultStr;
    
}

//------------------------------------------------------------------------//
/* Function: Merge two strings 
 * @Params: No Parameters
 * @Description: Retuns the merged two strings in new array of chars
 * @Usage: Restricted Usage!
 */

char* String::merge(){


    char* resultStr = new char[m_strLen1 + m_strLen2 +1]; // Create an appropriate sized char
    char* currentIndex = resultStr;

    char* str1_index = m_str1;
    char* str2_index = m_str2;

    while((*str1_index!='\0') && (*str2_index!='\0')){
        
        *currentIndex = *str1_index;    
        ++currentIndex;
        *currentIndex = *str2_index;

        // Update pointers
        ++currentIndex;
        ++str1_index;
        ++str2_index;
    
    }
    
    // Check if string 1 reached its end
    if(*str1_index == '\0'){

        // Update remaining of string 2
        while(*str2_index!='\0'){
            *currentIndex = *str2_index;
            ++currentIndex;
            ++str2_index;
        }
    }else if(*str2_index == '\0'){

        // Update remaining of string 1
        while(*str1_index!='\0'){
            *currentIndex = *str1_index;
            ++currentIndex;
            ++str1_index;
        }
    }

    *currentIndex = '\0'; // Null termination
    return resultStr;
}

//------------------------------------------------------------------------//
/* Function: Print Final Report
 * @Params: No Parameters
 * @Description: Print a report if input have been sucessfully read
 * @Usage: 
 *      > myObj->printReport()
 */

void String::printReport(){
    
    std::cout << "//-------------------------Report-------------------------//" << std::endl;
    
    int compareValue = compare();
    std::cout << "** The returned value for both strings is: " << compareValue << std::endl;

    if(compareValue == 0){
        char* output = merge();
        std::cout << "** The returned string is: " << output << std::endl;
        delete output;
        output = nullptr;
    }else if(compareValue < 0 ){
        invert();
        char* output = concat();
        std::cout << "** The returned string is: " << output << std::endl;
        delete output;
        output = nullptr;
    }else{
        invert();
        char* output = merge();
        std::cout << "** The returned string is: " << output << std::endl;
        delete output;
        output = nullptr;
    }

    std::cout << "//--------------------------End--------------------------//" << std::endl;

}

