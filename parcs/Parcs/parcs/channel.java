package parcs;
import java.io.*;
import java.net.*;

/**
 *  анал дл€ св€зи между двум€ точками.  анал создаетс€ в родительской точке (на
 * стороне клиента) вызовом из алгоритмического модул€ функции
 * point.createChannel(). Ќа стороне сервера объект channel создаетс€ демоном и
 * передаетс€ в качестве параметра созданному алгоритмическому модулю.
 */
public class channel {
	/**
	 * Socket с коротым св€зан данный канал
	 */
	public Socket sock = null;
	public boolean works = false;    //работает ли канал передачи
	public InputStream in;
	public OutputStream out;
	public DataInputStream din;
	public DataOutputStream dout;
	public ObjectInputStream objin;
	public ObjectOutputStream objout;
	public ClassLoader loader;

	public int from;
	public int index;
	public IRecovery recovery = null;

class ExtObjectInputStream extends ObjectInputStream {
	public ExtObjectInputStream(InputStream in) throws IOException {super(in);}

	protected Class resolveClass(ObjectStreamClass desc)
		    throws IOException, ClassNotFoundException {
		if (loader==null) return super.resolveClass(desc);
		String name = desc.getName();
		return Class.forName(name, false, loader);
	}
}

	public channel(InputStream in, OutputStream out, boolean works) {
		this(in, out); this.works = works;
	}
	public channel(OutputStream out, InputStream in, boolean works) {
		this(out, in); this.works = works;
	}

	/**
	 * «акрывает данный канал
	 */
	public void close()
	{
		if (sock != null)
		{
			if (!sock.isClosed())
				try {
					sock.close();
				}
				catch (IOException ex) {
				}
			sock = null;
			works = false;
		}
	}

	public channel(InputStream in, OutputStream out, int from, int index, IRecovery recovery) {
		this(in, out); this.from = from; this.index = index; this.recovery = recovery;
	}

	public channel(OutputStream out, InputStream in, int from, int index, IRecovery recovery) {
		this(out, in); this.from = from; this.index = index; this.recovery = recovery;
	}

	private channel(InputStream in, OutputStream out) {
		this.in=in; this.out=out;
		din = new DataInputStream(in);
		dout = new DataOutputStream(out);
		try {
			objin = new ExtObjectInputStream(in);
			objout = new ObjectOutputStream(out);
			out.flush();
		}
		catch (IOException e) { System.err.println("channel: "+e);}
    }

	/*
	 * —оздает канал св€зи со стороны клиента. ќтличаетс€ от метода channel(InputStream in,
	 * OutputStream out) тем, что создание потоков ObjectInputStream и
	 * ObjectOutputStream происходит в обратном пор€дке. “аким, образом если метод
	 * channel(InputStream in, OutputStream out) используетс€ сервером, то клиент
	 * должен использовать данный метод
	 */
	private channel(OutputStream out, InputStream in) {
		this.in=in; this.out=out;
		din = new DataInputStream(in);
		dout = new DataOutputStream(out);
		try {
			objout = new ObjectOutputStream(out);
			out.flush();
			objin = new ExtObjectInputStream(in);
		}
		catch (IOException e) { System.err.println("channel: "+e);}
	}

	/**
	 * записывает в канал число типа byte
	 */
	public void write(byte x) { sendp(x); }
	public void sendp(byte x) {
        if (!works) return;
        try {   dout.writeByte(x);
                dout.flush();
        }catch(IOException e) {works = false;}
		if (recovery != null)
			recovery.Write(from, index, IRecovery.T_BYTE, new Byte(x));
    }

	/**
	 * записывает в канал число типа int
	 */
	public void write(int x) { sendp(x); }
	public void sendp(int x) {
        if (!works) return;
        try {    dout.writeInt(x);
                dout.flush();
        }catch(IOException e) {works = false;}
		if (recovery != null)
			recovery.Write(from, index, IRecovery.T_INT, new Integer(x));
    }

	/**
	 * записывает в канал число типа long
	 */
	public void write(long x) { sendp(x); }
	public void sendp(long x) {
        if (!works) return;
        try {    dout.writeLong(x);
                dout.flush();
        }catch(IOException e) {works = false;}
		if (recovery != null)
			recovery.Write(from, index, IRecovery.T_LONG, new Long(x));
    }

	/**
	 * записывает в канал число типа double
	 */
	public void write(double x) { sendp(x); }
	public void sendp(double x) {
        if (!works) return;
        try {    dout.writeDouble(x);
                dout.flush();
        }catch(IOException e) {works = false;}
		if (recovery != null)
			recovery.Write(from, index, IRecovery.T_DOUNBLE, new Double(x));
    }

	/**
	 * записывает в канал объект, реализующий интефейс Serializable
	 */
	public void write(Serializable obj) { sendp(obj); }
	public void sendp(Serializable obj) {
        if (!works) return;
        try {
			objout.writeObject(obj);
			objout.flush();
        }
        catch (IOException e) {
			System.err.println(e);
			works = false;
        }
		if (recovery != null)
			recovery.Write(from, index, IRecovery.T_OBJ, obj);
    }

	/**
	 * записывает в канал массив байт
	 */
	public void write(byte[] buf) { sendp(buf); }
	public void sendp(byte[] buf) {
        if (!works) return;
        try {   dout.write(buf);
                dout.flush();
        }
        catch (IOException e) {
			System.err.println(e);
			works = false;
        }
		if (recovery != null)
			recovery.Write(from, index, buf);
    }

	/**
	 * считывает из канала число типа byte
	 */
	public byte readByte() { return getp_b(); }
	public byte getp_b() {
        if (!works) return 0;
        do {
            try { return din.readByte();}
            catch(EOFException e) {}
            catch(IOException e) {works = false;return 0;}
        }
        while(true);
    }

	/**
	 * считывает из канала число типа int
	 */
	public int readInt() { return getp_i(); }
	public int getp_i() {
        if (!works) return 0;
        do {
            try { return din.readInt();}
            catch(EOFException e) {}
            catch(IOException e) {works = false;return 0;}
        }
        while(true);
    }

	/**
	 * считывает из канала число типа long
	 */
	public long readLong() { return getp_l(); }
	public long getp_l(){
        if (!works) {return 0;}
        do {
            try { return din.readLong();}
            catch(EOFException e) {}
            catch(IOException e) {works = false;return 0;}
        }
        while(true);
    }

	/**
	 * считывает из канала число типа double
	 */
	public double readDouble() { return getp_d(); }
	public double getp_d() {
        if (!works) return 0;
        do {
            try { return din.readDouble();}
            catch(EOFException e) {}
            catch(IOException e) {works = false;return 0;}
        }
        while(true);
    }

	/**
	 * считывает из канала массив байт
	 */
	public void read(byte[] buf) { getp(buf); }
	public void getp(byte[] buf) {
        if (!works) return;
        do {
            try {din.read(buf);return;}
            catch(EOFException e){}
            catch (IOException e) {works = false; return;}
        }
        while(true);
    }

	/**
	 * считывает из канала объект
	 */
	public Object readObject() { return getp_o(); }
	public Object getp_o() {
		if (!works) return null;
		/*if (Const.NO_TIMEOUTS) while (!works) System.out.print("|");
		else {
			long t = System.currentTimeMillis();
		    while (!works && System.currentTimeMillis()-t<5000)
				System.out.print("!");
		}*/
		do {
            try { return objin.readObject();
            } catch (Exception e) {
				System.err.println("readObject: "+e);
				works = false;return null;
			}
        } while (true);
    }
}
