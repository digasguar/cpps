#include <vector>
#include <deque>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>


class PmergeMe
{
private:
    std::deque<int> _deque;
    std::vector<int> _vector;
public:
    class WrongInputExeption : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    PmergeMe(int argc,char **argv);

    ~PmergeMe();

    PmergeMe(const PmergeMe &other);

    PmergeMe &operator=(const PmergeMe &other);

    void initialize(int argc, char ** argv);

    std::vector<int> get_Vector();

    std::deque<int> get_Deque();

    std::vector<int> procesVector(std::vector<int> list);

    std::deque<int> procesDeque(std::deque<int> deque);

    void execute();

    template <typename T, typename P>
    T makePairs(P& nums)
    {
        T pairs;
        for (size_t i = 0; i + 1 < nums.size(); i+=2)
        {
            if (nums[i] < nums[i + 1])
            {
                pairs.push_back(std::make_pair(nums[i], nums[i + 1]));
            }
            else
            {
                pairs.push_back(std::make_pair(nums[i + 1], nums[i]));
            }
        }
        return (pairs);
    }
    std::vector<size_t> jacobsthalIndices(size_t n);

    template <typename Container, typename T>
    void binaryInsert(Container &mainChain, const T &value)
    {
        typename Container::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), value);

        mainChain.insert(pos, value);
    }

    template <typename Container, typename PairContainer>
        void insertLosers(Container &mainChain, const PairContainer &pairs, bool hasStraggler, int straggler)
        {
            Container losers;
            for (size_t i = 0; i < pairs.size(); i++)
                losers.push_back(pairs[i].first);
            std::vector<size_t> jac = jacobsthalIndices(losers.size());
            std::vector<bool> inserted(losers.size(), false);
            for (size_t k = 1; k < jac.size(); k++)
            {
                size_t idx = jac[k];
                if (idx >= losers.size())
                    idx = losers.size() - 1;
                while (idx > 0 && !inserted[idx])
                {
                    binaryInsert(mainChain, losers[idx]);
                    inserted[idx] = true;
                    idx--;
                }
            }
            for (size_t i = 0; i < losers.size(); i++)
            {
                if (!inserted[i])
                    binaryInsert(mainChain, losers[i]);
            }
            if (hasStraggler)
                binaryInsert(mainChain, straggler);
        }
};

bool validateInput(char **argv);