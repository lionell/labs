package parcs;

import java.io.*;

class ServerQuery {
	private static boolean TCPrespond = true;  //работает ли сервер хостов на TCP-порту
	private static boolean UDPrespond = true;  //работает ли сервер хостов на UDP-порту

	public byte[] data = null;	//данные для запроса
	private byte[] answer = null; //результат
	private ByteArrayOutputStream dataOut = null;

	public ServerQuery() {}
	public ServerQuery(byte[] data) { this.data = data; }

	public byte[] getAnswer() { return answer;}

	/**
	 * Создает и возвращает ссылку на поток для записи данных запроса, если функция
	 * не вызывалась, используется буфер data
	 * @return поток вывода
	 */
	public DataOutputStream getOutputStream() {
		return new DataOutputStream(dataOut = new ByteArrayOutputStream());
	}
	/**
	 * Создает и возвращает ссылку на поток для записи данных запроса, если функция
	 * не вызывалась, используется буфер data
	 * @param size начальный размер буфера потока
	 * @return поток вывода
	 */
	public DataOutputStream getOutputStream(int size) {
		return new DataOutputStream(dataOut = new ByteArrayOutputStream(size));
	}
	/**
	 * Создает и возвращает ссылку на поток для чтения ответа сервера
	 * @return поток ввода
	 */
	public DataInputStream getInputStream(){
		return new DataInputStream(new ByteArrayInputStream(answer));
	}

	/**
	 * Соединяется с TCP-сервером хостов для посылки запроса, если это не удается,
	 * посылает UDP-запрос
	 * @param serv адрес сервера
	 * @return ответ сервера, или null, если ответ не получен
	 */
	public byte[] send(HostInfo serv) {
		return send(serv, -1);
	}

	/**
	 * Соединяется с TCP-сервером хостов для посылки запроса, если это не удается,
	 * посылает UDP-запрос
	 * @param serv адрес сервера
	 * @param answerlength ожидаемая длина ответа, или -1, если неизвестна
	 * @return ответ сервера, или null, если ответ не получен
	 */
	public byte[] send(HostInfo serv, int answerlength) {
		if (serv==null) return null;
		if (TCPrespond || !UDPrespond)
			if ( !(TCPrespond=serv.cycleConnect(Const.HOSTSSERVER_TCP_PORT)) ) {
				System.err.println("TCP hosts server is not responding on " +
					serv.name + ":" + Const.HOSTSSERVER_TCP_PORT);
			}

		if (TCPrespond) {
			try {
				if (serv==null) System.err.println("Error: serv==null");
				else if (serv.socket==null)
					System.err.println("Error: socket==null");
				BufferedInputStream inp = new BufferedInputStream(serv.socket.getInputStream());
				OutputStream out = serv.socket.getOutputStream();

				if (dataOut!=null) dataOut.writeTo(out);
				else if (data!=null) out.write(data);
				else System.err.println("Error: ServerQuery.data==null");
				out.flush();

				if (answerlength==0) {serv.closeSocket();return null;}
				if (answerlength!=-1) answer = new byte[answerlength];

				int av, total=0;
				do {
					/*if (Const.NO_TIMEOUTS)
						do av = inp.available(); while(av==0);
					else {
						long t = System.currentTimeMillis();
						do { av = inp.available(); }
						while ( (av==0) && (System.currentTimeMillis()-t < 10000) );
					}

					if (av==0) {    //таймаут
						TCPrespond = false;
						System.err.println("Error: Answer from TCP hosts server not received");
					}
					else {
						if (answerlength==-1) answer = new byte[av];*/
						total += inp.read(answer, total, answer.length-total);
					//}
				} while (total < answer.length);
			}
			catch (IOException e) {
				//System.err.println("ServerQuery.send: "+e);
				e.printStackTrace();
				return null;
			}
			finally { serv.closeSocket(); }
		}

		if (!TCPrespond) {
			if (dataOut!=null) data = dataOut.toByteArray();
			UDPQuery pack = new UDPQuery(data, data.length, serv.ipAddress,
										 Const.HOSTSSERVER_UDP_PORT);
			if (!pack.sendQuery()){
				System.err.println("UDP hosts server is not responding on " +
								   serv+":"+Const.HOSTSSERVER_UDP_PORT);
				UDPrespond = false;
				return null;
		    }

			if (answerlength==0) return null;
			answer = pack.getResult();
			if ((answerlength!=-1) && (answerlength!=answer.length)) {
				System.err.println("The answer from hosts server is invalid");
				return null;
			}
		}
		return answer;
	}
}
