/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package homework8;
import java.awt.*;

import java.awt.Graphics;
import java.util.Random;
import java.util.Scanner;
import static java.sql.JDBCType.NULL;
import java.util.HashSet;
import javax.swing.JOptionPane;
import javax.swing.*;
/**
 *
 * @author User
 */
public class ConnectFour extends JPanel{

    
    public Cell [][] board;
    private int row;
    private int tempRow;
    private int col;
    private int player1;
    private int player2;
    private char players;
    private int mouse1;
    private String gameMode;
    protected boolean end=false;
    private static int turn=0;
    
    /**
     * Getter for variable end.
     * @return if ended or not 
     */
    public boolean getEnd(){
        return end;
    }
    /**
     * Getter for variable row.
     * @return row of the board.
     */ 
    public int getRow(){
        return row;
    }
    /**
     * Setter for variable row.
     */ 
    public void setRow(int rows){
        row=rows;
    }
    /**
     * Getter for variable col.
     * @return col of the board.
     */ 
    public int getCol(){
        return col;
    }
    /**
     * Setter for variable col.
     */ 
    public void setCol(int cols){
        col=cols;
    }
    
    /**
     * Constructor for the class.
     * @param Size of board
     */
    ConnectFour(int Size){
        setRow(Size);
	setCol(Size);
	player1='X';
	player2='O';
        
	initializeBoard();
    }
    /**
     * Constructor of the class.
     * @param rows of board
     * @param cols of board
     */
    ConnectFour(int rows, int cols){
	setRow(rows);
	setCol(cols);
	player1='X';
	player2='O';
	initializeBoard();
	printBoard();
	
    }
    /**
     * Prints the board. 
     */
    public void printBoard(){
	System.out.println("The board currently looks like:");
	for (char t= 'a'; t < 'a'+row;t++)
        {    	System.out.print(t);
                System.out.print(" ");
        
        }System.out.println("\n");
	for(int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
		{
                    System.out.print(board[i][j].getValue() + " ");
		}
                    System.out.print("\n");
	}
    }
    /**
     * This is the gui function. It sets colors of board and players.
     * @param g 
     */
    
    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        
        this.setBackground(Color.BLUE);
        g.setColor(Color.WHITE);
        for(int i =0;i<row;i++){
            
            for(int j=0;j<col;j++){
                if (board[i][j].getValue()=='X' || board[i][j].getValue()=='x')
                    g.setColor(Color.RED);
                else if(board[i][j].getValue()=='O' || board[i][j].getValue()=='o')
                    g.setColor(Color.YELLOW);
                else 
                    g.setColor(Color.WHITE);
                
                    g.fillOval((j*(500/row)),(i*(500/col)), (500/row),(500/col));
             
                }
        }
           
    }
    
    /**
     * Initializes board rows and cols to '.' which indicates that board
     * is empty.
     */
    public void initializeBoard(){
        board= new Cell[40][40];
        for(int i = 0; i<row; i++)
	{
		for(int j = 0; j<col; j++)
		{
                    Cell cell = new Cell();
                    board[i][j]= cell;
		}
	}
        for(int i = 0; i<row; i++)
	{
		for(int j = 0; j<col; j++)
		{
                    board[i][j].setValue('.');
		}
	}
	
    }
    /**
     * This function plays the game. It sets player values to the empty slots.
     * @param mouse takes row and col indexes.
     * 
     */
    public void mouseListen(int mouse){
        mouse1=mouse/(500/row);
        //int checker=-1;
        int count=-1;
        int full;
        boolean end=true;
       
        for(int i=0;i<row;i++){
           if (board[i][mouse1].getValue()=='.')
               count++;
               //checker++;
        }
        if(count != -1)
            count++;
        repaint();
        System.out.println(gameMode);
        if(count != -1){
        if(gameMode.charAt(0) == 'P' || gameMode.charAt(0)=='p'){   
            
            if (checkWin('X')==0 || checkWin('O')==0 )
            {
                if (turn%2==0){

                    board[count-1][mouse1].setValue('X');
                    System.out.println("It's player1's turn!");
                    checkWin('X');                    
                }
                else
                {   
                    
                    board[count-1][mouse1].setValue('O');
                    System.out.println("It's player1's turn!");
                    checkWin('O');  
                }

            turn++;
            printBoard();
            full=fullBoard();
            if (full==1)
                System.out.println("The board is full! It's a draw");
            }

        }
        else if (gameMode.charAt(0)== 'C' || gameMode.charAt(0) =='c')
        {
            if (checkWin('X')==0 || checkWin('O')==0 ){
                board[count-1][mouse1].setValue('X');
                //repaint();
                System.out.println("It's player1's turn!");
                checkWin('X');
                playai('O');
                checkWin('O');

                //repaint();
            }    
            else if (checkWin('X')>0)
                JOptionPane.showMessageDialog(null,"Player X WON!!! ", "Congratulations!", JOptionPane.OK_OPTION);
            else if (checkWin('O')>0)
                JOptionPane.showMessageDialog(null,"Player O WON!!! ", "Congratulations!", JOptionPane.OK_OPTION);


            }
        }else
            JOptionPane.showMessageDialog(null,"That column is full! Try another.","", JOptionPane.OK_OPTION);
    }
        
   /**
    * Checks if the game is over.
    * @return returns 1 if the game board is full or someone has won.
    */ 
    
    public int endGame(){

	for (int i=0;i<row;i++) {
            for (int j = 0; j < col; j++) {	
		if (board[i][j].getValue()=='x' || board[i][j].getValue() == 'o'){				
                    return 1;
		}
		if (fullBoard()==1){
                    return 1;
		}
            }
	}
	return 0;
    }
    /**
     * Checks if the board is full.
     * @return 1 if board is full otherwise returns 0. 
     */
    public int fullBoard (){
	int full=0;

	for (int i=0;i<row;i++)
	{
            for (int j=0;j<col;j++)
            {
                if (board[i][j].getValue()=='.')
                    return 0;
            }
	}
	return 1;
    }
    /**
     * Checks if game mode is PVP or PVC.
     * @param mode can be either P or C.
     */
    public void modeTaker(String mode){
        gameMode=mode;
    }
    
    /**
     * Ai function which plays for computer. It blocks the user if user has 
     * already set 3 pieces vertically or horizontally.
     * @param player 'O' value for computer.
     */
    public void playai(char player){
	int valid = 0;
        Random rand = new Random(); 
	int b = rand.nextInt() % col;
        if(b<0)
            b=b*(-1);
	int count=0;

	for (int j = 0; j<col; j++)
	{
            for(int i = row-1; i>=0; i--)
            {
		if(board[i][j].getValue()== 'X')
                    count+=1;
		else
                    count = 0;
		if (count>2){
                    if(i==row && j==col)
                        board[i-1][j].setValue('O');
                    if(i==row && j!=col)
                        board[i-1][j-1].setValue('O');
                    if(i==row)
                        board[i][j].setValue('O');
                    else
                        board[i-1][j].setValue('O');
                }
            }
            count = 0;
	}
        System.out.println("\n");

	for (int i = 0; i<row; i++)
	{
            for(int j = 0; j<col; j++)
            {
                if(board[i][j].getValue() == 'X')
                    count+=1;
		else
                    count = 0;
		if (count>2){
                    
                    if(i==row && j==col)
                        board[i-1][j].setValue('O');
                    if(i==row && j!=col)
                        board[i-1][j-1].setValue('O');
                    
                    if(j==col)
                        board[i][j].setValue('O');
                    else
                        board[i][j+1].setValue('O');
		}
            }
            count = 0;
	}
	System.out.println("\n");
        
	for(int i = row-1; i >= 0 ; i--)
	{
            if (board[i][b].getValue() == '.')
            {
                
                board[i][b].setValue(player);
		break;
            }
           
	}
	printBoard();
        turn++;
    }
    
    /**
     * After the game is finished it resets the board and sets turn to first
     * player.
     */
    public void restart(){
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                board[i][j].setValue('.');}
        }
        turn = 1;
        
    }
    /**
     * Checks if one of the players has won and prints out dialog boxes.
     * @param player X or O value for players
     * @return Returns 0 if no one has won 
     */
    public int checkWin(char player){
	int h = 0, v = 0, rd = 0, ld = 0, total = 0;
	int full=0;

	h = checkHorizontal(player);
	v = checkVertical(player);
	rd = checkRightDiagonal(player);
	ld =checkLeftDiagonal(player);
	total = h+v+rd+ld;
        System.out.println(total);
	if(total>0){
            System.out.println("Congratulations player "+ player+ "! You won this round of Connect 4!");
            if(player=='X'){
            JOptionPane.showMessageDialog( null, "Congratulations player X", "WINNER" , JOptionPane.OK_OPTION);
            }
            if(player=='O'){
            JOptionPane.showMessageDialog( null, "Congratulations player O", "WINNER" , JOptionPane.OK_OPTION);
            }
            
            int n = JOptionPane.showConfirmDialog( null, "Do you want to start a new game?", "Repeat" , JOptionPane.YES_NO_OPTION);
            
            if (n == 0){
                end = true;
                restart();
                
            }
            else
            {  
                System.exit(0);
            }
        }
	else
	{
            full=fullBoard();
            if(full==1)
            {
                JOptionPane.showMessageDialog( null, "Board is full. It's a Draw.", "WINNER" , JOptionPane.OK_OPTION);
                int k = JOptionPane.showConfirmDialog( null, "Do you want to start a new game?", "Repeat" , JOptionPane.YES_NO_OPTION);
               
                if (k == 0){
                    end = true;
                    restart();

                }
                else
                {

                    System.exit(0);
                }
                    System.out.println("GAME OVER!!! The gameBoard is full. It's a draw.");
            }

	}
	return total;
    }
    /**
     * Checks how many pieces has player placed horizontally.
     * @param player X or O values for players
     * @return count of pieces
     */
    public int checkHorizontal(char player){
	int count=0;
        for (int i = 0; i<row; i++)
	{
            for(int j = 0; j<col; j++)
            {
                if(board[i][j].getValue()==player)
                    count+=1;
		else
                    count = 0;
		if (count>=4)
		{
                    for (int a=0;a<4;a++)
                    {
			if (player=='X')
                            board[i][j-a].setValue('x');
                        else
                            board[i][j-a].setValue('o');
                    }
                    return count;
		}
            }
            count = 0;
	}
        System.out.println("\n");
	return count;
    }
    
     /**
     * Checks how many pieces has player placed vertically.
     * @param player X or O values for players
     * @return count of pieces
     */
    public int checkVertical(char player){
        int count=0;
        for (int j = 0; j<col; j++)
	{
            for(int i = row-1; i>=0; i--)
            {
                if(board[i][j].getValue() == player)
                    count+=1;
                else
                    count = 0;
		if (count>=4)
		{
                    for (int a=0;a<4;a++)
                    {
			if (player=='X')
                            board[i+a][j].setValue('x');
			else
                            board[i+a][j].setValue('o');
                    }
                    return 1;
		}
            }
            count = 0;
	}
	System.out.println("\n");
	return count;
    }
     /**
     * Checks how many pieces has player placed diagonally (right).
     * @param player X or O values for players
     * @return count of pieces
     */
    public int checkRightDiagonal(char player){
	int count=0;
	boolean win = false;
        for(int i = row-1; i>=0; i--)
	{
            for(int j =col-1; j>=0; j--)
            {
                for (int z = 0; z<=row-1 && z<=col-1; z++)
                {
                    if(i-z>-1 && j-z>-1) {
			if (board[i - z][j - z].getValue() == player)
                            count += 1;
			else
                            count = 0;
                    }
                    if (count==4)
                    {
                        for (int a=0;a<4;a++)
                        {
                            if (i-a>-1 && j-a<col){
				if (player=='X')
                                    board[i-a][j-a].setValue('x');
				else
                                    board[i-a][j-a].setValue('o');
                            }
			}
                        win=true;
                    }
		}
		count = 0;
            }
            count = 0;
	}
	if (win)
            return 1;
	else
            return count;
    }
    
     /**
     * Checks how many pieces has player placed diagonally(left).
     * @param player X or O values for players
     * @return count of pieces
     */
    public int checkLeftDiagonal(char player){
        int count=0;
	for(int i = row-1; i>0; i--)
	{
            for(int j = 0; j<col-1; j++)
            {
                for (int z = 0; z<=col-1; z++)
		{
                    if(i-z>-1 && j+z<col){
			if(board[i-z][j+z].getValue() == player)
                            count+=1;

			else
                            count = 0;
                    }
                    if (count==4){
			for (int a=0;a<4;a++)
                        {
                            if(i-a>-1 && j+a<col){
				if (player=='X')
                                    board[i-a][j+a].setValue('x');
				else
                                    board[i-a][j+a].setValue('o');
                            }

			}
			return 1;
                    }
                }
		count = 0;
            }
            count = 0;
	}
        return count;
    }
}
