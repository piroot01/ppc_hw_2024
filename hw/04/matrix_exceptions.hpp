#ifndef __MATRIX_EXCEPTION_HPP__
#define __MATRIX_EXCEPTION_HPP__

#include <exception>

struct matrix_bad_sizes: public std::exception 
    {const char * what () const throw (){return "matrix_bad_sizes";}};
// Vyjimka pri zadani negativniho rozmeru
struct matrix_negative_size: public std::exception 
    {const char * what () const throw (){return "matrix_negative_size";}};
// Vyjimka pri chybe nacteni rozmeru matice
struct matrix_in_bad_header: public std::exception 
    {const char * what () const throw (){return "matrix_in_bad_header";}}; 
// Vyjimka pri chybe nacteni prvku matice
struct matrix_in_bad_body: public std::exception 
    {const char * what () const throw (){return "matrix_in_bad_body";}};
// Vyjimka pri otevirani souboru matice
struct cannot_open_file: public std::exception 
    {const char * what () const throw (){return "cannot_open_file";}};


#endif
