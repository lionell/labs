package io.github.lionell.lab4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.concurrent.CountDownLatch;
import java.util.logging.Logger;

/** Created by lionell on 10/10/16. */
public class Main implements Runnable {
  private final Logger logger = Logger.getLogger(RemoteEvaluator.class.getName());
  private static final String HOST = "127.0.0.1";
  private Boolean result;

  public static void main(String[] args) {
    new Main().run();
  }

  synchronized private void setResult(boolean value) {
    if (result == null) {
      result = value;
    } else {
      result &= value;
    }
  }

  @Override
  public void run() {
    String arg = "arg";
    CountDownLatch latch = new CountDownLatch(1);
    RemoteEvaluator remoteEvaluator1 = new RemoteEvaluator(12345, arg, latch);
    RemoteEvaluator remoteEvaluator2 = new RemoteEvaluator(12346, arg, latch);
    Thread thread1 = new Thread(remoteEvaluator1);
    Thread thread2 = new Thread(remoteEvaluator2);
    thread1.start();
    thread2.start();
    try {
      latch.await();
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    if (result) {
      try {
        thread1.join();
        thread2.join();
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
    logger.info("FINAL: " + result);
  }

  private class RemoteEvaluator implements Runnable {
    private final Logger logger = Logger.getLogger(RemoteEvaluator.class.getName());
    private final int port;
    private final String arg;
    private final CountDownLatch latch;

    public RemoteEvaluator(int port, String arg, CountDownLatch latch) {
      this.port = port;
      this.arg = arg;
      this.latch = latch;
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
            setResult(res);
            latch.countDown();
          }
        }
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
  }
}
