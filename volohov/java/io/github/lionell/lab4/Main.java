package io.github.lionell.lab4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.logging.Logger;

/** Created by lionell on 10/10/16. */
public class Main implements Runnable {
  private static final String HOST = "127.0.0.1";
  private Boolean result;

  public static void main(String[] args) {
    new Main().run();
  }

  synchronized void setResult(boolean value) {
    if (result == null) {
      result = value;
    } else {
      result &= value;
    }
  }

  @Override
  public void run() {
    String arg = "arg";
    RemoteEvaluator remoteEvaluator1 = new RemoteEvaluator(12345, arg);
    RemoteEvaluator remoteEvaluator2 = new RemoteEvaluator(12346, arg);
    while (result == null || result == true) {

    }
    Thread thread1 = new Thread(remoteEvaluator1);
    Thread thread2 = new Thread(remoteEvaluator2);
  }

  private class RemoteEvaluator implements Runnable {
    private final Logger logger = Logger.getLogger(RemoteEvaluator.class.getName());
    private final int port;
    private final String arg;

    public RemoteEvaluator(int port, String arg) {
      this.port = port;
      this.arg = arg;
    }

    @Override
    public void run() {
      logger.info("Connecting " + HOST + ":" + port);
      try (Socket socket = new Socket(HOST, port)) {
        try (PrintWriter out = new PrintWriter(socket.getOutputStream(), true)) {
          try (BufferedReader in =
              new BufferedReader(new InputStreamReader(socket.getInputStream()))) {
            logger.info("Sending job");
            out.println(arg);
            boolean res = Boolean.parseBoolean(in.readLine());
            logger.info("Received result " + Boolean.toString(res));
          }
        }
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
  }
}
