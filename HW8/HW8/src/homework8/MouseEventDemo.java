package homework8;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class MouseEventDemo implements MouseListener{
   
    public  ConnectFour y;
    /**
     * Takes mouse position coordinate. 
     * @param x 
     */
    public  MouseEventDemo(ConnectFour x){
        y=x;
    }
    /**
     * Shows where the mouse has been pressed.
     * @param e 
     */
    @Override
    public void mousePressed(MouseEvent e) {
       System.out.println("Mouse pressed; # of clicks: "
                    + e.getX());
        y.mouseListen(e.getX());
    }
    /**
     * 
     * @param me 
     */
    @Override
    public void mouseClicked(MouseEvent me) {
       
    }
    /**
     * 
     * @param me 
     */
    @Override
    public void mouseReleased(MouseEvent me) {
    }
    /**
     * 
     * @param me 
     */
    @Override
    public void mouseEntered(MouseEvent me) {
     
    }
    /**
     * 
     * @param me 
     */
    @Override
    public void mouseExited(MouseEvent me) {
        
    }
}