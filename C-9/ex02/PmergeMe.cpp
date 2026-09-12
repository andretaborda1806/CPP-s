#include "PmergeMe.hpp"

pMerge::pMerge(): odd(0), hasOdd(false), start_Vec(0), start_Deq(0), endVec(0), endDeq(0){}

pMerge::pMerge(const pMerge &copy): 
odd(copy.odd),
hasOdd(copy.hasOdd),
start_Vec(copy.start_Vec),
start_Deq(copy.start_Deq),
endVec(copy.endVec),
endDeq(copy.endDeq),
_vec(copy._vec),
_deque(copy._deque),
_mainchain(copy._mainchain)
{

}

pMerge::~pMerge(){}

pMerge &pMerge::operator=(const pMerge &copy){
    if (this != &copy){
        _vec = copy._vec;
        _deque = copy._deque;
        odd = copy.odd;
        hasOdd = copy.hasOdd;
        endDeq = copy.endDeq;
        endVec = copy.endVec;
        start_Vec = copy.start_Vec;
        start_Deq = copy.start_Deq;
        _mainchain = copy._mainchain;
    }
    return *this;
}

void    pMerge::organizingPairs(std::vector<Pair> &container)
{
    for (std::vector<Pair>::iterator it = container.begin();
         it != container.end(); ++it)
    {
        if (it->first > it->second)
            std::swap(it->first, it->second);
    }
    fordJhonson_vec(container);
}

void    pMerge::organizingPairs(std::deque<Pair> &container)
{
    for (std::deque<Pair>::iterator it = container.begin();
         it != container.end(); ++it)
    {
        if (it->first > it->second)
            std::swap(it->first, it->second);
    }
    fordJhonson_deque(container);
}

void    pMerge::handlingInput(std::string &input){

    _vec.clear();
    _deque.clear();
    _mainchain.clear();
    odd = 0;
    hasOdd = false;
    start_Vec = 0;
    start_Deq = 0;
    endVec = 0;
    endDeq = 0;

    std::istringstream stream(input);
    std::string token;
    long long value;
    bool    doneFirst = false;
    int first;

    while (stream >> token){
        std::istringstream converter(token);
        char extra;

        if (!(converter >> value) || converter >> extra)
            throw std::runtime_error("Error: Only numbers");
        if (value > INT_MAX || value < 0)
            throw std::runtime_error("Error: Cant fit in int or <0");
        if (!doneFirst){
            first = static_cast<int>(value);
            doneFirst = true;
        }
        else{
            _vec.push_back(std::make_pair(first, static_cast<int>(value)));
            _deque.push_back(std::make_pair(first, static_cast<int>(value)));
            doneFirst = false;
        }

    }

    if (doneFirst){
        odd = first;
        hasOdd = true;
    }


    start_Vec = getTime();

    organizingPairs(_vec);

    if (_vec.empty())
    {
        _mainchain.push_back(odd);
        endVec = getTime();
    }

    start_Deq = getTime();
    organizingPairs(_deque);

    if (_deque.empty())
        endDeq = getTime();
}

std::vector<int>    pMerge::fordJhonson_vec(std::vector<Pair> &vec){

    if (vec.empty())
        return std::vector<int>();

    std::vector<int> mainchain;
    for (std::vector<Pair>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        mainchain.push_back(it->first);
        mainchain.push_back(it->second);
    }

    if (hasOdd)
    {
        std::vector<int>::iterator pos =
            std::lower_bound(
                mainchain.begin(),
                mainchain.end(),
                odd
            );

        mainchain.insert(pos, odd);
    }

    std::sort(mainchain.begin(), mainchain.end());

    endVec = getTime();

    _mainchain = mainchain;

    return mainchain;
}


std::deque<int> pMerge::fordJhonson_deque(std::deque<Pair> &deq)
{
    if (deq.empty())
        return std::deque<int>();

    std::deque<int> mainchain;
    for (std::deque<Pair>::iterator it = deq.begin(); it != deq.end(); ++it)
    {
        mainchain.push_back(it->first);
        mainchain.push_back(it->second);
    }

    if (hasOdd)
    {
        std::deque<int>::iterator pos = 
        std::lower_bound(
                mainchain.begin(),
                mainchain.end(),
                odd
            );

        mainchain.insert(pos, odd);
    }

    std::sort(mainchain.begin(), mainchain.end());
    endDeq = getTime();
    return mainchain;
}


std::vector<size_t> pMerge::buildInsertionOrder_vec(size_t size)
{
    std::vector<size_t> order;
    
    size_t previous = 1;
    size_t n = 3;
    
    while (previous < size)
    {
        size_t current = jacobsthal(n);
        
        if (current > size)
        current = size;
    
        for (size_t i = current; i > previous; --i)
            order.push_back(i - 1);

        previous = current;
        n++;
    }

    return order;
}

std::deque<size_t> pMerge::buildInsertionOrder_deque(size_t size)
{
    std::deque<size_t> order;
    
    size_t previous = 1;
    size_t n = 3;
    
    while (previous < size)
    {
        size_t current = jacobsthal(n);
        
        if (current > size)
        current = size;
    
        for (size_t i = current; i > previous; --i)
            order.push_back(i - 1);

        previous = current;
        n++;
    }

    return order;
}


size_t pMerge::jacobsthal(size_t n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

double getTime()
{
    struct timespec time;

    clock_gettime(CLOCK_MONOTONIC, &time);

    return (time.tv_sec * 1000000.0 + time.tv_nsec / 1000.0);
}

int     pMerge::getOdd(){
    return odd;
}

double  pMerge::getStart_Vec(){
    return start_Vec;
}

double  pMerge::getStart_Deq(){
    return start_Deq;
}

double  pMerge::getEndDeq(){
    return endDeq;
}

double  pMerge::getEndVec(){
    return endVec;
}

std::vector<int>    pMerge::getMainchain(){
    return _mainchain;
}


