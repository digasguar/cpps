#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char** argv)
{
    initialize(argc , argv);

    execute();
}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    this->_deque = other._deque;
    this->_vector = other._vector;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
    this->_deque = other._deque;
    this->_vector = other._vector;
    return (*this);
}

const char *PmergeMe::WrongInputExeption::what() const throw()
{
    return ("Error\n");
}

void PmergeMe::initialize(int argc, char ** argv)
{
    for(int i = 1; i < argc; i++)
    {
        int value = atoi(argv[i]);
        this->_deque.push_back(value);
        this->_vector.push_back(value);
    }
}

std::vector<size_t> PmergeMe::jacobsthalIndices(size_t n)
{
    std::vector<size_t> jac;
    jac.push_back(0);
    jac.push_back(1);

    while (jac.back() < n)
    {
        size_t size = jac.size();
        size_t next = jac[size - 1] + 2 * jac[size - 2];
        jac.push_back(next);
    }
    return (jac);
}

std::deque<int> PmergeMe::procesDeque(std::deque<int> deque)
{
    if (deque.size() <= 1)
        return deque;

    typedef std::pair<int, int> Pair;

    std::deque<Pair> pairs = makePairs<std::deque<Pair>, std::deque<int> >(deque);
    std::deque<int> winners;
    bool hasStraggler = (deque.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler)
        straggler = deque.back();
    for (size_t i = 0; i < pairs.size(); i++)
        winners.push_back(pairs[i].second);
    std::deque<int> mainChain = procesDeque(winners);
    insertLosers(mainChain, pairs, hasStraggler, straggler);
    return (mainChain);
}

std::vector<int> PmergeMe::procesVector(std::vector<int> vector)
{
    if (vector.size() <= 1)
        return vector;

    typedef std::pair<int, int> Pair;

    std::vector<Pair> pairs = makePairs<std::vector<Pair>, std::vector<int> >(vector);
    std::vector<int> winners;
    bool hasStraggler = (vector.size() % 2 != 0);
    int straggler = 0;
    if (hasStraggler)
        straggler = vector.back();
    for (size_t i = 0; i < pairs.size(); i++)
        winners.push_back(pairs[i].second);

    std::vector<int> mainChain = procesVector(winners);
    insertLosers(mainChain, pairs, hasStraggler, straggler);
    return (mainChain);
}

std::vector<int> PmergeMe::get_Vector()
{
    return (this->_vector);
}
std::deque<int> PmergeMe::get_Deque()
{
    return (this->_deque);
}

void PmergeMe::execute()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < this->_vector.size(); i++)
        std::cout << " " << _vector[i] << " ";
    std::cout << "\n";
    clock_t v_start = clock();
    this->_vector = this->procesVector(this->_vector);
    clock_t v_end = clock();
    std::cout << "After: ";
    for (size_t i = 0; i < this->_vector.size(); i++)
        std::cout << " " << _vector[i] << " ";
    std::cout << "\n";

    clock_t d_start = clock();
    this->_deque = this->procesDeque(this->_deque);
    clock_t d_end = clock();

    double vtime = static_cast<double>(v_end - v_start) / CLOCKS_PER_SEC * 1000;
    double dtime = static_cast<double>(d_end - d_start) / CLOCKS_PER_SEC * 1000;

    std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector    : " << vtime << std::endl; 
    std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::deque     : " << dtime << std::endl;
}

bool validateInput(char **argv)
{
    for (int i = 1; argv[i]; i++)
    {
        for(int j = 0; argv[i][j]; j++)
        {
            if (!isdigit(argv[i][j]))
            {
                return (false);
            }
        }
    }
    return (true);
}