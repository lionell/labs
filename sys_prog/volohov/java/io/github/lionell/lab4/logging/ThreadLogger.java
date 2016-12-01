package io.github.lionell.lab4.logging;

import java.text.MessageFormat;
import java.util.logging.ConsoleHandler;
import java.util.logging.Formatter;
import java.util.logging.Handler;
import java.util.logging.LogRecord;
import java.util.logging.Logger;

/** Created by lionell on 10/15/16. */
public class ThreadLogger {
  public static Logger of(Class c) {
    Logger logger = Logger.getLogger(c.getName());
    logger.setUseParentHandlers(false);
    ConsoleHandler consoleHandler = new ConsoleHandler();
    consoleHandler.setFormatter(new ThreadFormatter());
    for (Handler handler : logger.getHandlers()) {
      logger.removeHandler(handler);
    }
    logger.addHandler(consoleHandler);
    return logger;
  }

  private static class ThreadFormatter extends Formatter {
    private final MessageFormat messageFormat = new MessageFormat("{0} {1}\n");

    @Override
    public String format(LogRecord record) {
      Object[] arguments = new Object[2];
      arguments[0] =
          String.format(
              "%-15s",
              "[" + Thread.currentThread().getName() + ":" + Thread.currentThread().getId() + "]:");
      arguments[1] = record.getMessage();
      return messageFormat.format(arguments);
    }
  }
}
