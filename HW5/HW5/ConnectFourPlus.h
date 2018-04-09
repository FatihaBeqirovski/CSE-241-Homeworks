#ifndef CONNECTFOURPLUS_H
#define CONNECTFOURPLUS_H
#include "ConnectFourAbstract.h"

using namespace std;
using namespace cell;
using namespace base;

namespace pluss{
class ConnectFourPlus: public ConnectFourAbstract{
	public:
	ConnectFourPlus();
	ConnectFourPlus(int r, int c);
    protected:
	int checkWin(char player);
};
}
#endif
