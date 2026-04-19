#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain{
    public:
        Brain();
        Brain(const Brain &copy);
        ~Brain();
        Brain &operator=(const Brain &copy);
        std::string *getBrain();
        void setBrain(std::string *newIdeas);
        void setIdea(std::string newIdea, int index);
    private:
        std::string ideas[100];
};

#endif