#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
    try
    {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest: " << sp.shortestSpan() << std::endl; // 2
        std::cout << "Longest: " << sp.longestSpan() << std::endl;   // 14
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== Too many numbers ===" << std::endl;
    try
    {
        Span sp(2);

        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3); // exception
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== Not enough numbers ===" << std::endl;
    try
    {
        Span sp(5);

        sp.addNumber(42);
        std::cout << sp.shortestSpan() << std::endl; // deve lançar exceção
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== Duplicates ===" << std::endl;
    try
    {
        Span sp(3);

        sp.addNumber(10);
        sp.addNumber(10);
        sp.addNumber(50);

        std::cout << "Shortest: " << sp.shortestSpan() << std::endl; // 0
        std::cout << "Longest: " << sp.longestSpan() << std::endl;   // 40
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== Negative numbers ===" << std::endl;
    try
    {
        Span sp(3);

        sp.addNumber(-10);
        sp.addNumber(5);
        sp.addNumber(20);

        std::cout << "Shortest: " << sp.shortestSpan() << std::endl; // 15
        std::cout << "Longest: " << sp.longestSpan() << std::endl;   // 30
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== Range insert ===" << std::endl;
    try
    {
        Span sp(10);
        std::vector<int> source;

        for (int i = 1; i <= 10; i++)
            source.push_back(i);

        sp.rangeIterator(source.begin(), source.end());

        std::cout << "Shortest: " << sp.shortestSpan() << std::endl; // 1
        std::cout << "Longest: " << sp.longestSpan() << std::endl;   // 9
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== Range too large ===" << std::endl;
    try
    {
        Span sp(3);
        std::vector<int> source;

        source.push_back(1);
        source.push_back(2);
        source.push_back(3);
        source.push_back(4);

        sp.rangeIterator(source.begin(), source.end()); // deve lançar exceção
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}