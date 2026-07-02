#include "Span.hpp"

Span::Span(): _len(0){}

Span::Span(unsigned int n): _len(n){}

Span::Span(const Span &copy): _vec(copy._vec), _len(copy._len){}

Span::~Span(){}

Span &Span::operator=(const Span &copy){
    if (this != &copy){
        _vec = copy._vec;
        _len = copy._len;
    }
    return *this;
}

void            Span::addNumber(int number){
    if (_vec.size() == _len)
        throw FullVector();
    else{
        _vec.push_back(number);
    }
}

unsigned int    Span::shortestSpan(){
    if (_vec.size() < 2)
        throw InvalidVcSize();
    std::vector<int> sorted = _vec;
    std::sort(sorted.begin(), sorted.end());
    unsigned int span = static_cast<unsigned int>(sorted[1] - sorted[0]);
    for (size_t i = 2; i < sorted.size(); ++i){
        unsigned int current = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
        if (current < span)
            span = current;
    }
    return span;
}

unsigned int    Span::longestSpan(){
    if (_vec.size() < 2)
        throw InvalidVcSize();
    std::vector<int>::iterator minIt = std::min_element(_vec.begin(), _vec.end());
    std::vector<int>::iterator maxIt = std::max_element(_vec.begin(), _vec.end());
    return static_cast<unsigned int>(*maxIt - *minIt);
}



