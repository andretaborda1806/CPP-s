#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <utility>
# include <sstream>
# include <stdexcept>
# include <algorithm>
# include <climits>
# include <ctime>

typedef std::pair<int, int> Pair;

double getTime();

class pMerge
{
private:

    int odd;
    bool hasOdd;

    double start_Vec;
    double start_Deq;
    double endVec;
    double endDeq;

    std::vector<Pair> _vec;
    std::deque<Pair> _deque;

    std::vector<int> _mainchain;

public:

    pMerge();
    pMerge(const pMerge &copy);
    ~pMerge();

    pMerge &operator=(const pMerge &copy);

    std::vector<int> organizingPairs(std::vector<Pair> &container);
    std::deque<int> organizingPairs(std::deque<Pair> &container);

    void handlingInput(std::string &input);

    std::vector<int> fordJhonson_vec(std::vector<Pair> &vec);
    std::deque<int> fordJhonson_deque(std::deque<Pair> &deq);

    std::vector<size_t> buildInsertionOrder_vec(size_t size);
    std::deque<size_t> buildInsertionOrder_deque(size_t size);

    size_t jacobsthal(size_t n);

    int getOdd();
    double getStart_Vec();
    double getStart_Deq();
    double getEndDeq();
    double getEndVec();

    std::vector<int> getMainchain();
};

#endif