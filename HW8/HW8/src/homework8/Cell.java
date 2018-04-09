/*
   Cell class takes row, col, position and player values.
*/
package homework8;

public class Cell {

    private int row;
    private int col;
    private char position;
    private char player;
    private char value;

    /**
     * Getter for player variable.
     * @return player value.
     */
    public char getPlayer(){
        return player;
    }
    /**
     * Setter for variable player.
     */
    public void setPlayer(char playeer){
        player=playeer;
    }
    /**
     * Getter for row variable.
     * @return row value.
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
     * Getter for col variable.
     * @return col value.
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
     * Getter for position variable.
     * @return position value.
     */
    public char getPosition(){
        return position;
    }
    /**
     * Setter for variable position.
     */
    public void setPosition(char positionn){
        position=positionn;
    }
    /**
     * Getter for value variable.
     * @return value.
     */
    public char getValue(){
        return value;
    }
    /**
     * Setter for variable value.
     */
    public void setValue(char values){
        value=values;
    }

}

