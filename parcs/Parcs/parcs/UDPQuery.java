package parcs;
import java.net.*;
import java.io.*;

/**
 * @(#)UDPQuery.java
 */
class UDPQuery{
    private static long seq = System.currentTimeMillis()<<16; //Ќомер очереди пакета
    long cur_seq = seq++; //номер текущего пакета
    private byte[] result = null; //–езультат запроса
    public DatagramPacket packet;

    public UDPQuery(byte[] data, int length, InetAddress address, int port) {
        ByteArrayOutputStream out = new ByteArrayOutputStream(length+10);  //начальный размер массива (примерный)
        DataOutputStream dout = new DataOutputStream(out);
        try {
            dout.writeLong(cur_seq);
            dout.write(data, 0, length);
        } catch (IOException e) {}
        byte[] buf = out.toByteArray();
        packet = new DatagramPacket(buf, buf.length, address, port);
    }

    /**
     * ѕосылает запрос, сформированный конструктором, серверу хостов ≈сли ответ не
     * приходит, запрос посылаетс€ несколько раз. –езультат можно получить функцией
     * getResult()
     * @param sock локальный сокет
     * @return возвращает true, если получен ответ на запрос, и false, если после
     *   нескольких запросов ответ не получен
     */
    public boolean sendQuery(DatagramSocket sock){
        long t1,t2;
        int sentCount=0; //сколько раз неудачно отослан запрос
        do {
            try {
                sock.send(packet);
				t1 = System.currentTimeMillis();
                byte[] data = new byte[512];
                DatagramPacket pack = new DatagramPacket(data, 512);

                sock.setSoTimeout(500);
                sock.receive(pack);
                t2 = System.currentTimeMillis();
                System.out.println("UDP answer received in "+(t2-t1)+"sec");

                if (!parseAnswer(pack)) continue;
                return true;
            } catch (SocketTimeoutException e){
                sentCount++; continue;
            }
            catch (IOException e) {
                System.err.println(e);
                continue;
            }
        } while(sentCount<8);
        return false;
    }

    /**
     * ѕосылает запрос, сформированный конструктором, серверу хостов, использу€
     * свободный UDP-порт. ≈сли ответ не
     * приходит, запрос посылаетс€ несколько раз. –езультат можно получить функцией
     * getResult()
     * @return возвращает true, если получен ответ на запрос, и false, если после
     *   нескольких запросов ответ не получен
     */
    public boolean sendQuery(){
        try { return sendQuery(new DatagramSocket()); }
        catch (SocketException e){
            System.err.println(e);
            return false;
        }
    }

    /**
     * ќбрабатывает полученный от сервера ответ, возвращает true, если ответ
     * корректный
     */
	public boolean parseAnswer(DatagramPacket pack){
        int pack_len = pack.getLength();
        final byte HEAD_SIZE = 8;
        if (pack_len < HEAD_SIZE) return false;
        DataInputStream in = new DataInputStream(new ByteArrayInputStream(
                pack.getData(), pack.getOffset(), pack_len));
        try {
            long pack_seq = in.readLong();
            result = new byte[pack_len - HEAD_SIZE];
            in.read(result);
            //System.arraycopy(pack.getData(), pack.getOffset() + headsize, result, 0, pack_len);
            if (pack_seq!=cur_seq) return false;
        } catch (IOException e) {
            System.err.println(e);
            return false;
        }
        return true;
    }
    public byte[] getResult(){ return result; }
}
