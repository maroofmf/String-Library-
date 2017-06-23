// ---------------------------------------------------------------------//
// Author:      Maroof
// File Name:   String.hpp
// File Type:   Header File
// Purpose:     Forward Declartion for String class.
// Description: Functionality given in README.md file
// ---------------------------------------------------------------------//

#ifndef _STRING_HPP
#define _STRING_HPP

namespace lib 
{

// Error Codes:
enum ErrorCode{
    NO_ERROR,
    INVALID_INPUT,
    NULL_INPUT,
};

class String{
    
    // Declare & Define private variables and methods
    private:
        long m_strLen1{0};   
        long m_strLen2{0};
        // Initial string capacity is selected based on statistics (average length of sentences)
        long m_strCapacity1{2};
        long m_strCapacity2{2};
        char* m_str1 = new char[m_strCapacity1];
        char* m_str2 = new char[m_strCapacity2];
        

    // Declare public methods;
    public:
        
        String();
        ~String();
        bool readInput();
        void resize(char* &str,char* &iterationIndex, long& capacity);
        bool checkChar(const char& inputChar); 
        bool errorCheck(ErrorCode error_1,ErrorCode error_2);
        int compare();
        void invert();
        char* concat();
        char* merge();
        void printReport();

};

}

#endif

