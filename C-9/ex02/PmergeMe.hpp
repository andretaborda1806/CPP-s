#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <sstream>
#include <string>
#include <climits>
#include <algorithm>
#include <sys/time.h>



class pMerge{
    public:

        pMerge(void);
        pMerge(const pMerge &copy);
        ~pMerge(void);
        pMerge &operator=(const pMerge &copy);

        void                handlingInput(std::string &input);
        int                 getOdd();
        double              getStart_Vec();
        double              getStart_Deq();
        double              getEndVec();
        double              getEndDeq();
        std::vector<int>    getVec();
        std::vector<int>    getMainchain();

    private:

        typedef std::pair<int, int> Pair;

        int odd;
        bool hasOdd;

        double start_Vec;
        double start_Deq;

        double endVec;
        double endDeq;

        std::vector<Pair> _vec;
        std::deque<Pair> _deque;

        std::vector<int> _mainchain;

        void    organizingPairs(std::vector<Pair> &container);
        void    organizingPairs(std::deque<Pair> &container);

        std::vector<int> fordJhonson_vec(std::vector<Pair> &container);
        std::deque<int>  fordJhonson_deque(std::deque<Pair> &container);

        std::vector<size_t> buildInsertionOrder_vec(size_t size);
        std::deque<size_t> buildInsertionOrder_deque(size_t size);

        size_t jacobsthal(size_t n);
};

double getTime();

#endif