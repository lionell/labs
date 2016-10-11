package io.github.lionell.lab4;

import java.util.logging.Logger;

public class Runner1 {
  private static final Logger logger = Logger.getLogger(Runner1.class.getName());
  private static final int PORT = 12345;

  public static void main(String[] args) {
    logger.info("Start listening at port " + PORT);
    Server server =
        new Server(
            PORT,
            s -> {
              try {
                Thread.sleep(5000);
              } catch (InterruptedException e) {
                e.printStackTrace();
              }
              return false;
            });
    server.run();
  }
}
