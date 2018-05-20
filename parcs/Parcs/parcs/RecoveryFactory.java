package parcs;

/**
 * <p>Title: </p>
 * <p>Description: </p>
 * <p>Copyright: Copyright (c) 2004</p>
 * <p>Company: </p>
 * @author not attributable
 * @version 1.0
 */

public class RecoveryFactory {
	public final static byte MODE_DISABLED = 0;
	public final static byte MODE_ENABLED  = 1;
	public final static byte MODE_RECOVER  = 2;

	public RecoveryFactory() {
	}

	public IRecovery Create(byte type) {
		return Create(type, null);
	}

	public IRecovery Create(byte type, String name) {
		switch (type) {
			case MODE_DISABLED:
				return null;
			case MODE_ENABLED:
				return new SafeRun(name);
			case MODE_RECOVER:
				return new Recover(name);
			default:
				System.err.println("Error : Unknown recovery type " + type);
				return null;
		}
	}
}