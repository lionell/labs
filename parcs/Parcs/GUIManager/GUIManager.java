import java.awt.*;
import javax.swing.*;
import javax.swing.border.*;
import javax.swing.event.*;
import java.awt.event.*;
import java.util.*;
import java.io.*;
import parcs.*;
import HostsServer.*;

class GUIManager extends JPanel {
	JFrame frame = new JFrame("PARCS Manager");
	JTextField hostName = new JTextField(22);
	JButton loadBut = new JButton("Load list");
	JButton saveBut = new JButton("Save list");
	JButton addBut = new JButton("Add host");
	JButton testBut = new JButton("Test hosts");
	JButton execBut = new JButton("Execute");
	JButton removeBut = new JButton("Remove");
	JButton cloadBut = new JButton("Load task");
	JTextField taskName = new JTextField(20);

	private TCPHostsServer hServer;
	private HostsServer servModel;
	private static String lookNFeel, taskFileName;
	SetListModel hList = new SetListModel();
	JList jList = new JList(hList);
	JScrollPane sc = new JScrollPane(jList);
    JLabel statusLabel = new JLabel();
    JPanel taskPanel = new JPanel();
    JCheckBox useperfCBox = new JCheckBox();

	GUIManager() {
		super(true);
		loadDefaultHostsFile();
		try { jbInit();	}
		catch(Exception e) { e.printStackTrace();}
		if (taskFileName != null) taskName.setText(taskFileName);

		if (hList.isEmpty()) hServer = new TCPHostsServer();
		else hServer = new TCPHostsServer(hList.getListCopy());
		servModel = hServer.getServerModel();
		servModel.setUpdateHandler(new UpdateHandler(){
			public synchronized void updatePointsNumber(int hostIndex, int pnum) {
				//hList.setNumber(hostIndex, pnum);
				if (hostIndex==jList.getSelectedIndex())
					repaintStatusBar((String)jList.getSelectedValue());
			}
			public synchronized void updateHostInfo(String hname) {
				if (hname.equals( (String)jList.getSelectedValue() ))
					repaintStatusBar(hname);
			}
			public synchronized void testsFinished() {
				servModel.sortList();
		    	hList.setNewList(servModel.getHostList());
				testBut.setEnabled(true);
				testBut.setText("Test hosts");
		    }
		});
	}

	private static void readSettingsFile() {
		try {
			BufferedReader in = new BufferedReader(new FileReader("settings.ini"));
			taskFileName = in.readLine();
			lookNFeel = in.readLine();
			in.close();
		}
		catch (Exception e) {}
	}
	private void writeSettingsFile() {
		try {
			PrintWriter out = new PrintWriter(new FileWriter("settings.ini"));
			out.println(taskName.getText());
			if (lookNFeel!=null) out.println(lookNFeel);
			out.close();
		}
		catch (Exception e) {}
	}
	public static void main(String[] args) {
		readSettingsFile();
//		long t = System.currentTimeMillis();
		if (lookNFeel!=null && lookNFeel.equals("System"))
			try { UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
	    	} catch(Exception e) { e.printStackTrace();}
//	    System.out.println(System.currentTimeMillis()-t);
	    new GUIManager();
	}

//=========================================================================
//	Add new host to list
	class AddButtonListener implements ActionListener {
		public void actionPerformed(ActionEvent ae) {
			String hname = hostName.getText();
			if (!hname.equals("") && hList.add(hname))
		    	servModel.addHost(hname);
			hostName.setText("");
		}
	}

//	Clear hosts list
	class RemoveButtonListener implements ActionListener {
		public void actionPerformed(ActionEvent ae) {
			int ind = jList.getSelectedIndex();
			if (ind>=0) hList.remove(ind);
		}
	}

//	Test available hosts
	class TestButtonListener implements ActionListener {
		public void actionPerformed(ActionEvent ae) {
		    if (!hList.isEmpty()) servModel.setHostList(hList.getListCopy());
			testBut.setEnabled(false);
			testBut.setText("Testing...");
		    servModel.testHosts();
		}
	}

//	Execute problem
	class ExecButtonListener implements ActionListener {
		public void actionPerformed(ActionEvent ae) {
			final String taskname = taskName.getText();
			if (taskname.equals("")) return;
			if (!(new File(taskname).canRead())) {
				JOptionPane.showMessageDialog(frame, "Cannot read file "+taskname,
						" Error", JOptionPane.ERROR_MESSAGE);
				return;
			}

		    java.util.List hostList = hList.getListCopy();
			if (!hList.isEmpty()) servModel.setHostList(hostList);

			if (servModel.testHosts)
				servModel.testUntestedHosts();
			servModel.waitTestingEnd();

			if (!hServer.isAlive()) hServer.start();

			(new Executor(taskname)).start();
/*			(new Thread() { public void run() {
				(new Executor(taskname)).run();
				hServer.quit();
			    }}).start();*/
/*					try {
						Class cl = Class.forName(classname.getText());
                        Method m = cl.getMethod("main", new Class[] {String[].class});
                        Object obj = cl.newInstance();
           				m.invoke(obj, new Object[] {new String[] {}});
					}
					catch(Exception e) {
						e.printStackTrace();
					}
*/
		}
	}

//	Load class file
	class CLoadButtonListener implements ActionListener {
		public void actionPerformed(ActionEvent ae) {
			JFileChooser fc = new JFileChooser(".");

			ExampleFileFilter filter = new ExampleFileFilter();
			//filter.addExtension("class");
			filter.addExtension("jar");
			//filter.addExtension("zip");
			fc.setFileFilter(filter);

			//fc.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
			int returnVal = fc.showOpenDialog(cloadBut);
            if(returnVal == JFileChooser.APPROVE_OPTION) {
            	String str = fc.getSelectedFile().getPath();
            	taskName.setText(str);
			}
		}
	}

//	Load hosts list from file
	private void loadDefaultHostsFile(){
		File f = new File("hosts.list");
		if (f.canRead()) {loadHostsFile(f); return;}
		f = new File("../HostsServer/hosts.list");
		if (f.canRead()) loadHostsFile(f);
	}
	private void loadHostsFile(File f){
		if (f == null) return;
		try {
			FileInputStream fr = new FileInputStream(f);
			BufferedReader r = new BufferedReader(new InputStreamReader(fr));
			hList.clear();
			String s;
			while ((s=r.readLine())!=null)
				hList.add(s);
			r.close();
		}
		catch(IOException e) {}
	}
	class LoadButtonListener implements ActionListener {
		public void actionPerformed(ActionEvent ae) {
			JFileChooser fc = new JFileChooser(".");
			//fc.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
			//ExampleFileFilter filter = new ExampleFileFilter();
			//filter.addExtension("list");
			//fc.setFileFilter(filter);
			int returnVal = fc.showOpenDialog(loadBut);
            if(returnVal == JFileChooser.APPROVE_OPTION)
				loadHostsFile(fc.getSelectedFile());
		}
	}

//	Save hosts list to file
	class SaveButtonListener implements ActionListener {
		public void actionPerformed(ActionEvent ae) {
			//String f = (String)JOptionPane.showInputDialog(saveBut,"Input file name:","File Name",JOptionPane.PLAIN_MESSAGE);
			JFileChooser fc = new JFileChooser(".");
			int returnVal = fc.showSaveDialog(saveBut);
			if (returnVal!=JFileChooser.APPROVE_OPTION) return;
			File f = fc.getSelectedFile();
			if (f != null) {
				FileWriter fo;
				try {
					fo = new FileWriter(f);
					Iterator it = hList.getList().iterator();
					while (it.hasNext()) {
						fo.write(it.next().toString() + '\n');
					}
					fo.close();
				}
				catch (IOException e) {}
			}
		}
	}
	class ListSelectListener implements ListSelectionListener {
		public void valueChanged(ListSelectionEvent e) {
			String hname = (String)jList.getSelectedValue();
			if (hname==null) {statusLabel.setText(""); return;}
			repaintStatusBar(hname);
		}
	}
	private void repaintStatusBar(String hname) {
		XHostInfo host = servModel.getHostInfo(hname);
		String s;
		if (host!=null) {
			if (host.ping<0) s="Does not answer.";
			else s = "Points number: "+host.pointsNumber+". Performance: "
					+host.perform+". Ping: "+host.ping+".";
		} else s="";
		statusLabel.setText(s);
	}


	class UsePerfCBoxListener implements ChangeListener {
		public void stateChanged(ChangeEvent e) {
			servModel.testHosts = useperfCBox.isSelected();
		}
	}

	protected final class AppCloser extends WindowAdapter {
		public void windowClosing(WindowEvent e) {
			writeSettingsFile(); System.exit(0);
		}
	}

//=======================================================================

    private void jbInit() throws Exception {
	frame.getContentPane().setBackground(SystemColor.control);
	//frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	frame.addWindowListener(new AppCloser());
	frame.setResizable(false);

	//this.setMinimumSize(null);
	this.setLayout(null);
	removeBut.setBounds(new Rectangle(283, 46, 84, 25));
	testBut.setBounds(new Rectangle(282, 254, 87, 26));
	testBut.setMargin(new Insets(2, 10, 2, 10));
	execBut.setBounds(new Rectangle(7, 47, 80, 26));
	sc.setToolTipText("Machines list");
	sc.setBounds(new Rectangle(13, 46, 260, 234));
	addBut.setBounds(new Rectangle(283, 17, 84, 25));
	hostName.setBounds(new Rectangle(14, 18, 258, 20));
	taskName.setBackground(Color.white);
	taskName.setDebugGraphicsOptions(0);
	taskName.setBounds(new Rectangle(6, 21, 309, 20));
	cloadBut.setBounds(new Rectangle(319, 18, 33, 26));
	cloadBut.setMargin(new Insets(2, 6, 2, 6));
	cloadBut.setText("...");
	saveBut.setBounds(new Rectangle(283, 114, 86, 24));
	loadBut.setBounds(new Rectangle(283, 89, 86, 24));
	statusLabel.setFont(new java.awt.Font("Dialog", 0, 11));
	statusLabel.setBounds(new Rectangle(13, 284, 357, 20));
	taskPanel.setBounds(new Rectangle(10, 303, 362, 80));
	taskPanel.setLayout(null);
	useperfCBox.setText("Use hosts performance");
	useperfCBox.setBounds(new Rectangle(132, 48, 197, 23));
	this.add(sc);
	this.add(hostName);
	this.add(loadBut);
	this.add(saveBut);
	this.add(addBut);
	this.add(removeBut);
	taskPanel.add(useperfCBox, null);
	taskPanel.add(taskName, null);
	taskPanel.add(cloadBut, null);
	taskPanel.add(execBut, null);
	this.add(statusLabel, null);
	this.add(testBut);
	this.add(taskPanel, null);
	frame.getContentPane().add(this, null);
	frame.setContentPane(this);
	//frame.getContentPane().add(this, null);
		addBut.addActionListener( new AddButtonListener());
		loadBut.addActionListener( new LoadButtonListener());
		cloadBut.addActionListener( new CLoadButtonListener());
		saveBut.addActionListener( new SaveButtonListener());
		testBut.addActionListener( new TestButtonListener());
		execBut.addActionListener( new ExecButtonListener());
		removeBut.addActionListener( new RemoveButtonListener());
		jList.addListSelectionListener( new ListSelectListener());
		useperfCBox.addChangeListener(new UsePerfCBoxListener());
		//setLayout(new FlowLayout(FlowLayout.CENTER));

		taskPanel.setBorder(new TitledBorder("Task file"));
		//this.setPreferredSize(new Dimension(1000,1000));
		frame.setSize(new Dimension(385, 422));
		//frame.pack();

	InputMap map = hostName.getInputMap(JComponent.WHEN_FOCUSED);
	map.put(KeyStroke.getKeyStroke(KeyEvent.VK_ENTER, 0), "addHostAction");
	hostName.getActionMap().put("addHostAction", new AbstractAction(){
		public void actionPerformed(ActionEvent e) { addBut.doClick();}
	});

		frame.show();
    }
}
