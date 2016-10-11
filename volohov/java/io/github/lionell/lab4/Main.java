package io.github.lionell.lab4;

/** Created by lionell on 10/10/16. */
public class Main {
  public static final String HOST = "127.0.0.1";

  public static void main(String[] args) {
    Client client1 = new Client(HOST, 12345, "arg");
    Client client2 = new Client(HOST, 12346, "arg");
    Thread thread1 = new Thread(client1);
  }
}
