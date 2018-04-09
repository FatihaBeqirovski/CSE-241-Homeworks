#include "Cell.h"
using namespace cell;
Cell::Cell(){
	setRow(0);
	setCol(0);
	setValue('.');
	
}
/*     This is the constructor for Cell class. It sets col and row values.    */
Cell::Cell(int rows,int cols){
	setRow(rows);
	setCol(cols);
	//setValue('.');
}
 /*    Destructor for Cell class. This one is used to kill livingCells.      */
Cell::~Cell(){
	//if(this->getValue()!='.')
	//--livingCells;
}
/*This function overload ==operator for Cell class. It checks if both sides   */
/*								equal or not. 					    		  */
bool Cell::operator==(const Cell& rSide)const{
	if(row==rSide.row && col==rSide.col && value==rSide.value && position==rSide.position)
		return true;
	else 
		return false;
}
/*Overloads the ++ prefix operator for class Cell. It converts user 1 to user2*/
/*user 2 into computer and computer player into empty cell.                   */
Cell Cell::operator++(){	
	if (value=='X')
		value='O';
	else if (value=='O')
		value='.';
	else if (value=='.')
		value='X';
	else 
		{
		}
	return *this;
}
/*Overloads the ++ postfix operator for class Cell. It converts user 1 to user2*/
/*user 2 into computer and computer player into empty cell.                   */
Cell Cell::operator++(int ignore){
	Cell temp=*this;
	if (value=='X')
		value='O';
	else if (value=='O')
		value='.';
	else if (value=='.')
		value='X';
	else 
		{
		}
	return temp;
}
/*Overloads the -- prefix operator for class Cell. It converts user 1 to user2*/
/*user 2 into computer and computer player into empty cell.                   */
const Cell& Cell::operator--(){	
	if (value=='X')
		value='O';
	else if (value=='O')
		value='.';
	else if (value=='.')
		value='X';
	else 
		{
		}
	return *this;
}
/*Overloads the --postfix operator for class Cell. It converts user 1 to user2*/
/*user 2 into computer and computer player into empty cell.                   */
const Cell Cell::operator--(int ignore){
	Cell temp=*this;
	if (value=='X')
		value='O';
	else if (value=='O')
		value='.';
	else if (value=='.')
		value='X';
	else 
		{
		}
	return temp;
}
/*Overloads the << operator for Cell class.*/
/*ostream& operator<<(ostream& out, Cell& prog){
    out<<prog.getRow()<<" "<<prog.getCol()<<" "<<prog.getPosition()<<" "<<prog.getValue()<<" \n";
    return out;
}*/
/*Overloads the >> operator for Cell class.*/
/*istream& operator>>(istream& in, Cell& prog) {
    int rowt;
    in >> rowt;
    prog.setRow(rowt);
    int colt;
    in >> colt;
    prog.setCol(colt);
    char positions;
    in >> positions;
    prog.setPosition(positions);
    return in;
}*/
/**********ALL THE SETTERS AND GETTERS NEEDED ARE IMPLEMENTED BELOW.***********/
int Cell::getRow()const{
	return row;
}
int Cell::getCol()const{
	return col;
}
char Cell::getValue()const{
	return value;
}
void Cell::setRow(int rows){
	row=rows;
}
void Cell::setCol(int cols){
	col=cols;
}
void Cell::setValue(char values){
	value=values;
}
char Cell::getPosition()const{
	return position;
}
void Cell::setPosition(char values){
	position=values;
}


