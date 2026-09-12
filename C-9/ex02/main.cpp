#include "PmergeMe.hpp"
#include <iomanip>

int main(int argc, char **argv)
{
    try{
        if (argc < 2)
            throw std::runtime_error("Error: invalid amount of chars");

        pMerge merge;

        std::string str;
        for (int i = 1; i < argc; ++i)
        {
            if (i > 1)
                str += " ";
            str += argv[i];
        }

        merge.handlingInput(str);
        std::cout << "Before: " << str << std::endl;
        
        std::cout << "After: ";

        std::vector<int> mainchain = merge.getMainchain();
        for (std::vector<int>::iterator it = mainchain.begin(); it < mainchain.end(); ++it){
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        double startVec = merge.getStart_Vec();
        double startDeq = merge.getStart_Deq();
        double endVec = merge.getEndVec();
        double endDeq = merge.getEndDeq();

        std::cout << std::fixed << std::setprecision(5);
        std::cout << "Time to process a range of " << merge.getMainchain().size() << " elements with std::vector : " << endVec - startVec << " us" << std::endl;
        std::cout << "Time to process a range of " << merge.getMainchain().size() << " elements with std::deque : " << endDeq - startDeq << " us" << std::endl;
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
}