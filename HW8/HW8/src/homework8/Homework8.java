            /* HOMEWORK 8 - IMPLEMENTS CONNECT FOUR WITH GUI. */
package homework8;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

/**
 *
 * @author FATIHA BEQIROVSKI 151044091
 */

public class Homework8 {

    public static void main(String[] args) {
        
    //String name = JOptionPane.showInputDialog(null, "Please enter Game Mode P for PVP or C for PVC: ", "Mode", JOptionPane.QUESTION_MESSAGE );
    String message = "Please enter Game Mode P for PVP or C for PVC";
    String name = null;  
    do
    {
        name =JOptionPane.showInputDialog(message);
        message = "<html><b style='color:red'>Please enter Game Mode P for PVP or C for PVC: </b><br>"
                + "Use P p or C c letters only.";          
    } while(name.charAt(0) != 'P' && name.charAt(0)!='p'  && name.charAt(0)!='C' && name.charAt(0)!='c');

    System.out.println("Mode : " + name);
    
       
    String name1 = JOptionPane.showInputDialog(null, "Please enter size of board: ", "Size", JOptionPane.QUESTION_MESSAGE );
    int s= Integer.parseInt(name1);
    if(s<4 || s>40)
    {
        JOptionPane.showMessageDialog(null,"Size has to be an integer from 4-40", "Warning", JOptionPane.OK_OPTION);    
        name1= JOptionPane.showInputDialog(null, "Please enter size of board: ", "Size", JOptionPane.QUESTION_MESSAGE );
        s= Integer.parseInt(name1);
    }
    
    ConnectFour obj = new ConnectFour(s);
    obj.modeTaker(name);

    
    JFrame frame = new JFrame("ConnectFour");
    frame.setSize(517,550);
    frame.add(obj);
    MouseEventDemo obj1= new MouseEventDemo(obj);
    frame.addMouseListener(obj1);
    frame.setVisible(true);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setVisible(false);
    frame.setVisible(true);
    
    while(obj.end == true){
      
        frame.setVisible(false);

    }
    
    }
    
}
