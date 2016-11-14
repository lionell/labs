package io.github.lionell.lab4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.logging.Logger;

import io.github.lionell.lab4.logging.ThreadLogger;

/** Created by lionell on 10/10/16. */
public class Main {
  private final Logger logger = ThreadLogger.of(Main.class);
  private static final String HOST = "127.0.0.1";
  private volatile Boolean result;

  public static void main(String[] args) {
    new Main().start(args[0]);
  }

  private synchronized void updateResult(boolean value) {
    if (result == null) {
      result = value;
    } else {
      result &= value;
    }
    notifyAll();
  }

  public void start(String arg) {
    try {
      Socket socket1 = new Socket(HOST, 12345);
      Socket socket2 = new Socket(HOST, 12346);
      Thread thread1 = new Thread(new RemoteEvaluator(socket1, arg), "evaluator2");
      Thread thread2 = new Thread(new RemoteEvaluator(socket2, arg), "evaluator3");
      thread1.start();
      thread2.start();
      synchronized (this) {
        while (result == null) {
          wait();
        }
      }
      if (!result) {
        socket1.close();
        socket2.close();
      }
      thread1.join();
      thread2.join();
    } catch (IOException | InterruptedException e) {
      e.printStackTrace();
    }
    logger.info("Finished with result: " + result);
  }

  private class RemoteEvaluator implements Runnable {
    private final Logger logger = ThreadLogger.of(RemoteEvaluator.class);
    private final Socket socket;
    private final String arg;

    private RemoteEvaluator(Socket socket, String arg) {
      this.socket = socket;
      this.arg = arg;
    }

    @Override
    public void run() {
      logger.info("Initializing...");
      try (BufferedReader reader =
          new BufferedReader(new InputStreamReader(socket.getInputStream()))) {
        try (PrintWriter writer = new PrintWriter(socket.getOutputStream(), true)) {
          writer.println(arg);
          logger.info("Task sent.");
          boolean res = Boolean.parseBoolean(reader.readLine());
          logger.info("Received result: " + res);
          updateResult(res);
        }
      } catch (IOException e) {
      }
      logger.info("Shutting down...");
    }
  }
}
