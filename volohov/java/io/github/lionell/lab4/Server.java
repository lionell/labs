package io.github.lionell.lab4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.function.Predicate;
import java.util.logging.Logger;

/** Created by lionell on 10/10/16. */
public class Server implements Runnable {
  private final Logger logger = Logger.getLogger(Server.class.getName());
  private final int port;
  private final Predicate<String> fun;

  public Server(int port, Predicate<String> fun) {
    this.port = port;
    this.fun = fun;
  }

  @Override
  public void run() {
    try (ServerSocket socket = new ServerSocket(port)) {
      logger.info("Waiting for clients.");
      try (Socket client = socket.accept()) {
        logger.info("Connection successful.");
        Thread thread = new Thread(new Evaluator(client));
        thread.start();
        thread.wait();
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  private class Evaluator implements Runnable {
    private final Logger logger = Logger.getLogger(Server.class.getName());
    private final Socket socket;

    private Evaluator(Socket socket) {
      this.socket = socket;
    }

    @Override
    public void run() {
      try (BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()))) {
        try (PrintWriter out = new PrintWriter(socket.getOutputStream(), true)) {
          String arg = in.readLine();
          logger.info("Received: " + arg);
          Boolean res = fun.test(arg);
          logger.info("Result: " + res);
          out.println(res);
        }
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
  }
}
