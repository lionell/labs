package io.github.lionell.lab4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.concurrent.Callable;
import java.util.logging.Logger;

/** Created by lionell on 10/10/16. */
public class Client implements Callable<Boolean> {
  private final Logger logger = Logger.getLogger(Client.class.getName());
  private final String host;
  private final int port;
  private final String arg;

  public Client(String host, int port, String arg) {
    this.host = host;
    this.port = port;
    this.arg = arg;
  }

  @Override
  public Boolean call() throws Exception {
    logger.info("Connecting " + host + ":" + port);
    try (Socket socket = new Socket(host, port)) {
      try (PrintWriter out = new PrintWriter(socket.getOutputStream(), true)) {
        try (BufferedReader in =
            new BufferedReader(new InputStreamReader(socket.getInputStream()))) {
          logger.info("Sending job");
          out.println(arg);
          boolean res = Boolean.parseBoolean(in.readLine());
          logger.info("Received result " + Boolean.toString(res));
          return res;
        }
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
    return null;
  }
}
