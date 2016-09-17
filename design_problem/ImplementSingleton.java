/*
Why: To ensure there is only an instance for every class in a Java application.

Where: setup the database connection.
*/

public class ImplementSingleton {

	private ImplementSingleton() {

	}

	private static ImplementSingle instance = new ImplementSingleton();

	public staic Singleton getInstance() {
		return isntance;
	}
}

// lazy initialization
public class Singleton {

	private static Singleton instance = null;

	public static synchronized Singleton getInstance() {

		if (instance == null) {
			instance = new Singleton();
		}

		return instance;
	}

}