#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>

class Span{
    private:
        std::vector<int> _vec;
        unsigned int     _len;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span &copy);
        ~Span();
        Span &operator=(const Span &copy);
        void    addNumber(int number);
        unsigned int   shortestSpan();
        unsigned int   longestSpan();

        class FullVector: public std::exception{
            public:
                virtual const char* what() const throw(){
                    return ("Vector is already full!");
                }
        };

        class InvalidVcSize: public std::exception{
            public:
                virtual const char* what() const throw(){
                    return ("This vector is unsortable!");
                }
        };

        template <typename range>
        void    rangeIterator(range begin, range end){
            unsigned int count = std::distance(begin, end);
            if (_vec.size() + count > _len)
                throw InvalidVcSize();
            _vec.insert(_vec.end(), begin, end);
        }
};

#endif