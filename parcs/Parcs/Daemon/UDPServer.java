import java.io.*;
import java.net.*;
import parcs.Const;

/**
 * <p>Для ответа демона на эхо-запросы и, возможно, других UDP-сервисов</p>
 * @(#)UDPServer.java
 */
class UDPServer  extends Thread {
    boolean quit = false;

    public void run() {
        DatagramSocket sock = null;
        try {
            sock = new DatagramSocket(Const.DAEMON_UDP_PORT);
            //System.out.println("Accepting UDP packets on port "+UDP_PORT+"...");
            while (!quit) {
                byte[] data = new byte[100];
                DatagramPacket packet = new DatagramPacket(data, 100);

                try { sock.receive(packet);	}
                catch (IOException e) {
                    System.err.println(e);
                    continue;
                }

                DatagramPacket pack;
                //byte[] result;
                switch (data[0]) {
                    case Const.DM_UDP_PING:
						pack = new DatagramPacket(data, 1, data.length-1,
						packet.getAddress(), packet.getPort());
						break;
                    default: continue;
                }
                //System.out.println("Sending ping answer to "+packet.getAddress());
                sock.send(pack);
            }  //while
        } catch (BindException e){
		    System.err.println("UDP port "+Const.DAEMON_UDP_PORT+" already in use.\n"
				+"May be another copy of Daemon launched.\n"
				+"Try to use command line option --dmudpport <port>");
	    } catch (Exception e) {
            e.printStackTrace();
            return;
        }
        finally { if(sock!=null)sock.close();}
    }
}
