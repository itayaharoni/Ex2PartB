#include <unordered_map>
#include <string>
#include <climits>
#include "Direction.hpp"
using namespace std;
namespace ariel{
class Board{
    unordered_map<unsigned int, std::unordered_map<unsigned int, char>> board;
    unsigned int min_row=UINT_MAX;
    unsigned int max_row=0;
    unsigned int min_col=UINT_MAX;
    unsigned int max_col=0;
    public:
    void post(unsigned int row,unsigned int col,ariel::Direction direction,string message);
    string read(unsigned int row,unsigned int col,ariel::Direction direction,unsigned int length);
    void show();
};
};