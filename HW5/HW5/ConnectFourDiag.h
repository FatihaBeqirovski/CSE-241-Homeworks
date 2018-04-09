#ifndef CONNECTFOURDIAG_H
#define CONNECTFOURDIAG_H
#include "ConnectFourAbstract.h"
using namespace std;
using namespace cell;
using namespace base;

namespace diagonal{
class ConnectFourDiag: public ConnectFourAbstract{
	public:
    ConnectFourDiag();
	ConnectFourDiag(int r, int c);
	
	private:
	int checkWin(char player);
};
}
#endif
