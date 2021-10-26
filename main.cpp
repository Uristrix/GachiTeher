#include "GachiTaker.h"
#include <vector>
int main()
{
    std::vector<int> num_move{23,24,32,23,23,32,12};
    Game game(num_move);
    game.start();
    return 0;
}
