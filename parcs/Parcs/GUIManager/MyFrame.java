import javax.swing.*;
import java.awt.*;
import com.borland.jbcl.layout.*;

public class MyFrame extends JFrame {
    JButton jButton1 = new JButton();
    XYLayout xYLayout1 = new XYLayout();

    public MyFrame() {
	try {
	    jbInit();
	}
	catch(Exception ex) {
	    ex.printStackTrace();
	}
    }

    void jbInit() throws Exception {
	jButton1.setText("jButton1");
	this.getContentPane().setLayout(xYLayout1);
	this.setDefaultCloseOperation(EXIT_ON_CLOSE);
	this.setEnabled(true);
	this.getContentPane().add(jButton1, new XYConstraints(24, 6, -1, -1));
    }

    public static void main(String[] args) {
	MyFrame myFrame = new MyFrame();
    }
}
