package parcs;

public class Const {
	public static short HOSTSSERVER_TCP_PORT = 3333;
	public static short HOSTSSERVER_UDP_PORT = 3333;
	public static short DAEMON_TCP_PORT = 2222;
	public static short DAEMON_UDP_PORT = 2222;
	public static short POINT_CONNECTION_PORT = 1111;

	public final static byte HS_CREATE_POINT =  1;
	public final static byte HS_DELETE_POINT =  2;
	public final static byte HS_BEGIN_TASK   = 11;
	public final static byte HS_END_TASK     = 12;
	public final static byte HS_SET_FUNC     = 13;

	public final static int HS_WAIT = Integer.MAX_VALUE;

	public final static byte DM_EXECUTE_CLASS  = 1;
	public final static byte DM_LOAD_CLASSES   = 2;
	public final static byte DM_LOAD_JARFILES  = 3;
	public final static byte DM_ECHO           = 7;
	public final static byte DM_PERFORMANCE    = 8;
    public final static byte DM_RECEIVE_TASK   = 10;
	public final static byte DM_CONNECT_POINT  = 11;
	public final static byte DM_CONNECT_WAIT   = 12;
	public final static byte DM_ADD_POINT_DATA = 13;

	public final static byte DM_UDP_PING      = 7;

	public static boolean NO_TIMEOUTS = false;

	/**
	 * обрабатывает аргументы командной строки
	 * @return последний параметр, если он не был распознан, иначе null
	 */
	public static String parseArgs(String[] args){
		for (int i=1; i<args.length; i++) {
			String s = args[i];
			try{
				if (s.equals("--notimeouts")) NO_TIMEOUTS = true;
				else if (s.equals("--dmport")) {
					if (++i>=args.length) break;
					DAEMON_TCP_PORT = new Short(args[i]).shortValue();
				}
				else if (s.equals("--dmudpport")) {
					if (++i>=args.length) break;
					DAEMON_UDP_PORT = new Short(args[i]).shortValue();
				}
				else if (s.equals("--hsport")) {
					if (++i>=args.length) break;
					HOSTSSERVER_TCP_PORT = new Short(args[i]).shortValue();
				}
				else if (s.equals("--hsudpport")) {
					if (++i>=args.length) break;
					HOSTSSERVER_UDP_PORT = new Short(args[i]).shortValue();
				}
				else if (i==args.length-1 && s.charAt(0)!='-') return s;
			} catch (NumberFormatException e){i--;}
		}
		return null;
	}
}
