#include "PmergeMe.hpp"

pMerge::pMerge()
    : odd(0),
      hasOdd(false),
      start_Vec(0),
      start_Deq(0),
      endVec(0),
      endDeq(0)
{
}

pMerge::pMerge(const pMerge &copy)
    : odd(copy.odd),
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

pMerge::~pMerge()
{
}

pMerge &pMerge::operator=(const pMerge &copy)
{
    if (this != &copy)
    {
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


std::vector<int> pMerge::organizingPairs(std::vector<Pair> &container)
{
    for (std::vector<Pair>::iterator it = container.begin();
         it != container.end();
         ++it)
    {
        if (it->first > it->second)
            std::swap(it->first, it->second);
    }

    return fordJhonson_vec(container);
}

std::deque<int> pMerge::organizingPairs(std::deque<Pair> &conatiner)
{
    for (std::deque<Pair>::iterator it = conatiner.begin();
         it != conatiner.end();
         ++it)
    {
        if (it->first > it->second)
            std::swap(it->first, it->second);
    }

    return fordJhonson_deque(conatiner);
}


void pMerge::handlingInput(std::string &input)
{
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

    bool doneFirst = false;
    int first = 0;

    while (stream >> token)
    {
        std::istringstream converter(token);

        char extra;

        if (!(converter >> value) || converter >> extra)
            throw std::runtime_error("Error: Only numbers");

        if (value > INT_MAX || value < 0)
            throw std::runtime_error("Error: Too big");

        if (!doneFirst)
        {
            first = static_cast<int>(value);
            doneFirst = true;
        }
        else
        {
            _vec.push_back(
                std::make_pair(
                    first,
                    static_cast<int>(value)
                )
            );

            _deque.push_back(
                std::make_pair(
                    first,
                    static_cast<int>(value)
                )
            );

            doneFirst = false;
        }
    }

    if (doneFirst)
    {
        odd = first;
        hasOdd = true;
    }

    start_Vec = getTime();

    _mainchain = organizingPairs(_vec);

    if (hasOdd)
    {
        std::vector<int>::iterator pos =
            std::lower_bound(
                _mainchain.begin(),
                _mainchain.end(),
                odd
            );

        _mainchain.insert(pos, odd);
    }

    endVec = getTime();

    start_Deq = getTime();

    std::deque<int> dequeResult =
        organizingPairs(_deque);

    if (hasOdd)
    {
        std::deque<int>::iterator pos =
            std::lower_bound(
                dequeResult.begin(),
                dequeResult.end(),
                odd
            );

        dequeResult.insert(pos, odd);
    }

    endDeq = getTime();
}

std::vector<int> pMerge::fordJhonson_vec(std::vector<Pair> &vec)
{

    if (vec.empty())
        return std::vector<int>();

    if (vec.size() == 1)
    {
        std::vector<int> result;

        result.push_back(vec[0].first);
        result.push_back(vec[0].second);

        return result;
    }

    std::vector<Pair> recursivePairs;

    bool hasOdd = false;
    int odd = 0;

    size_t i = 0;

    while (i + 1 < vec.size())
    {
        recursivePairs.push_back(
            std::make_pair(
                vec[i].second,
                vec[i + 1].second
            )
        );

        i += 2;
    }

    if (i < vec.size())
    {
        odd = vec[i].second;
        hasOdd = true;
    }

    std::vector<int> sortedSeconds =
        organizingPairs(recursivePairs);

    if (hasOdd)
    {
        std::vector<int>::iterator pos =
            std::lower_bound(
                sortedSeconds.begin(),
                sortedSeconds.end(),
                odd
            );

        sortedSeconds.insert(pos, odd);
    }

    std::vector<Pair> orderedPairs;
    std::vector<Pair> remainingPairs = vec;

    for (size_t s = 0; s < sortedSeconds.size(); ++s)
    {
        for (std::vector<Pair>::iterator it = remainingPairs.begin();
             it != remainingPairs.end();
             ++it)
        {
            if (it->second == sortedSeconds[s])
            {
                orderedPairs.push_back(*it);
                remainingPairs.erase(it);
                break;
            }
        }
    }

    vec = orderedPairs;


    std::vector<int> mainchain;

    mainchain.push_back(vec[0].first);

    for (std::vector<Pair>::iterator it = vec.begin();
         it != vec.end();
         ++it)
    {
        mainchain.push_back(it->second);
    }

    std::vector<size_t> order =
        buildInsertionOrder_vec(vec.size());

    for (std::vector<size_t>::iterator it = order.begin();
         it != order.end();
         ++it)
    {
        size_t index = *it;

        int value = vec[index].first;

        std::vector<int>::iterator pos =
            std::lower_bound(
                mainchain.begin(),
                mainchain.end(),
                value
            );

        mainchain.insert(pos, value);
    }

    return mainchain;
}


std::deque<int> pMerge::fordJhonson_deque(std::deque<Pair> &deq)
{
    if (deq.empty())
        return std::deque<int>();

    if (deq.size() == 1)
    {
        std::deque<int> result;

        result.push_back(deq[0].first);
        result.push_back(deq[0].second);

        return result;
    }

    std::deque<Pair> recursivePairs;

    bool hasOdd = false;
    int odd = 0;

    size_t i = 0;

    while (i + 1 < deq.size())
    {
        recursivePairs.push_back(
            std::make_pair(
                deq[i].second,
                deq[i + 1].second
            )
        );

        i += 2;
    }

    if (i < deq.size())
    {
        odd = deq[i].second;
        hasOdd = true;
    }

    std::deque<int> sortedSeconds =
        organizingPairs(recursivePairs);

    if (hasOdd)
    {
        std::deque<int>::iterator pos =
            std::lower_bound(
                sortedSeconds.begin(),
                sortedSeconds.end(),
                odd
            );

        sortedSeconds.insert(pos, odd);
    }

    std::deque<Pair> orderedPairs;
    std::deque<Pair> remainingPairs = deq;

    for (size_t s = 0; s < sortedSeconds.size(); ++s)
    {
        for (std::deque<Pair>::iterator it = remainingPairs.begin();
             it != remainingPairs.end();
             ++it)
        {
            if (it->second == sortedSeconds[s])
            {
                orderedPairs.push_back(*it);
                remainingPairs.erase(it);
                break;
            }
        }
    }

    deq = orderedPairs;

    std::deque<int> mainchain;

    mainchain.push_back(deq[0].first);

    for (std::deque<Pair>::iterator it = deq.begin();
         it != deq.end();
         ++it)
    {
        mainchain.push_back(it->second);
    }

    std::deque<size_t> order =
        buildInsertionOrder_deque(deq.size());

    for (std::deque<size_t>::iterator it = order.begin();
         it != order.end();
         ++it)
    {
        size_t index = *it;

        int value = deq[index].first;

        std::deque<int>::iterator pos =
            std::lower_bound(
                mainchain.begin(),
                mainchain.end(),
                value
            );

        mainchain.insert(pos, value);
    }

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

    return jacobsthal(n - 1)
        + 2 * jacobsthal(n - 2);
}

double getTime()
{
    struct timespec time;

    clock_gettime(CLOCK_MONOTONIC, &time);

    return (
        time.tv_sec * 1000000.0
        + time.tv_nsec / 1000.0
    );
}


int pMerge::getOdd()
{
    return odd;
}

double pMerge::getStart_Vec()
{
    return start_Vec;
}

double pMerge::getStart_Deq()
{
    return start_Deq;
}

double pMerge::getEndDeq()
{
    return endDeq;
}

double pMerge::getEndVec()
{
    return endVec;
}

std::vector<int> pMerge::getMainchain()
{
    return _mainchain;
}