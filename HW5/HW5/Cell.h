#ifndef CELL_H
#define CELL_H
namespace cell {
class Cell {
	   
	private:
        int row;
        int col;
        char position;
        char player;
        char value;
				
	public:
		Cell();
		~Cell();
        Cell(int rows, int columns);
		bool operator ==(const Cell& rSide)const;
		bool operator !=(const Cell& rSide)const;
        Cell operator ++();
        Cell operator ++(int ignore);
		const Cell& operator --();
        const Cell operator --(int ignore);
       // friend ostream&operator<<(ostream& out,  Cell& prog);
       // friend istream& operator>>(istream& in, Cell& prog);
        char getPlayer()const;
        void setPlayer(char player);
        int getRow()const;
        void setRow(int rows);
        int getCol()const;
        void setCol(int cols);
        char getPosition()const;
		void setPosition(char position);
        char getValue() const;
        void setValue(char values);

};
}
#endif
