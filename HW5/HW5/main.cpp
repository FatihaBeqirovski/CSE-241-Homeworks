#include <cstring>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "ConnectFourAbstract.h"
#include "ConnectFourPlus.h"
#include "ConnectFourDiag.h"
#include "ConnectFourPlusUndo.h"

using namespace std;
using namespace cell;
using namespace base;
using namespace pluss;
using namespace diagonal;
using namespace undo;

int main(){
    char choice;
    int row;
	int col; 
	
	cout<<"Please enter the game mode. " <<endl; 
	cout<< "P for plus, D for diagonal and U for undo: "<<endl;
    cin>>choice;
    while(choice!='D' && choice!='d' && choice!='P' && choice!='p' && choice!='U' && choice!='u'){
    	cerr<<"You didn't enter valid mode. Please try again."<<endl;
    	cout<<"P for plus, D for diagonal and U for undo: ";
   		cin>>choice;
    }
    ConnectFourAbstract *base;
    
    if(choice=='P' || choice=='p'){
    	base=new ConnectFourPlus(row,col);
    }else if(choice=='D' || choice=='d'){
    	base=new ConnectFourDiag(row,col);
    }
    else if(choice=='U' || choice=='u'){
    	base=new ConnectFourPlusUndo(row,col);
    }
   

	base->playGame(0);
  
	return 0;
}
