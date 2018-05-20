package HostsServer;

import java.io.*;
import java.net.*;
import java.util.*;

/**
 * Класс, обеспечивающий гарантированное получение UDP-пакетов
 * Не отлажен достаточно
 */
public class UDPReceiver {
	private static Map senders = Collections.synchronizedMap(new HashMap());
/*	private class Item {
		SocketAddress address;
		long seq;
		byte[] answer = null;
		Item(SocketAddress addr, long s){
			address=addr; seq=s;
		}
		public boolean equals(Object obj) {
			return (obj instanceof Item) &&
					address.equals( ( (Item) obj).address);
		}
	}
*/
private class Query {
   long seq;
   byte[] answer = null;
   Query(long s){ seq=s; }
}
   private SocketAddress curKey = null;
   private Query curQuery = null;
	/**
	 * Ищет ответ на запрос, если такой уже был, в списке senders. Если такого
	 * запроса в списке нет, он добавляется в список и возвращается результат null
	 * @param addr IP-адрес и порт отправителя
	 * @param seq номер запроса в последовательности запросов данного отправителя
	 * @return ответ на запрос, или null, если это новый запрос
	 */
	private byte[] searchAnswer(SocketAddress addr, long seq){
		Query obj = (Query)senders.get(addr);
		if ((obj==null)||(obj.seq < seq)){
			curKey = addr;
			curQuery = new Query(seq);
			return null;
		} else if (obj.seq > seq) { //если запрос устаревший, curquery = null
			curQuery = null; return null;
		} else return obj.answer;
	}

	/**
	 * считывает из сокета новый запрос, ответы на последние запросы посылаются
	 * заново, неверные запросы отвергаются
	 * @param sock сокет сервера, должен быть открыть
	 * @return содержимое нового запроса
	 */
	public byte[] receiveNew(DatagramSocket sock){
		final byte HEAD_SIZE = 8;
		while(true){
			byte[] data = new byte[512];
			DatagramPacket pack = new DatagramPacket(data, 512);
			try { sock.receive(pack); }
			catch (IOException e) {
				System.err.println(e);
				continue;
			}

			int pack_len = pack.getLength();
			if (pack_len < HEAD_SIZE) continue;
			DataInputStream in = new DataInputStream(new ByteArrayInputStream(
					pack.getData(), pack.getOffset(), pack_len));
			//анализируем запрос
			byte[] result;
			try {
				long pack_seq = in.readLong(); //номер запроса в последовательности запросов
				result = new byte[pack_len - HEAD_SIZE];

				byte[] last_answ = searchAnswer(pack.getSocketAddress(), pack_seq);
				if (last_answ==null){
					if (curQuery==null) continue;  //запрос устаревший, игнорируем
					in.read(result);  //запрос новый
				}
				else {  //повторный запрос, повторяем ответ
					DatagramPacket answ = new DatagramPacket(last_answ,
							last_answ.length, pack.getSocketAddress());
					sock.send(answ);
					continue;
				}
			}
			catch (IOException e) {
				System.err.println(e);
				continue;
			}
			return result;  //возвращаем запрос, определенный как новый
		}
    }

	/**
	 * Возвращает клиенту ответ из массива data, добавляя информацию о номере
	 * запроса, и заносит ответ в список, ассоциируя его с адресом клиента
	 * @param sock локальный сокет
	 * @param data передаваемый ответ
	 */
	public void sendAnswer(DatagramSocket sock, byte[] data){
		final byte HEAD_SIZE = 8;
		ByteArrayOutputStream out = new ByteArrayOutputStream(
				(data!=null?data.length:0) + HEAD_SIZE);
		DataOutputStream dout = new DataOutputStream(out);
		try {
			dout.writeLong(curQuery.seq);
			if (data!=null) dout.write(data);
		} catch (IOException e) {}
		byte[] buf = out.toByteArray();

		//отправляем ответ
		try {
			DatagramPacket answ = new DatagramPacket(buf, buf.length, curKey);
			sock.send(answ);
		}
		catch (IOException e) {	System.err.println(e);}

	    //заносим ответ в список
		curQuery.answer = buf;
		senders.put(curKey, curQuery);
	}
}
