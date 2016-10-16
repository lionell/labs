package io.github.lionell.lab4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Queue;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.function.Function;
import java.util.logging.Logger;

import io.github.lionell.lab4.logging.ThreadLogger;

/** Created by lionell on 10/10/16. */
public class Server {
  private final Logger logger = ThreadLogger.of(Server.class);
  private final int port;
  private final Function<String, Boolean> func;

  public Server(int port, Function<String, Boolean> func) {
    this.port = port;
    this.func = func;
  }

  public void run() {
    try (ServerSocket server = new ServerSocket(port)) {
      logger.info("Listening on port " + port + "...");
      while (true) {
        new Thread(new Handler(server.accept()), "handler").start();
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  private class Handler implements Runnable {
    private final Logger logger = ThreadLogger.of(Handler.class);
    private final Socket socket;
    private final Queue<Task> newJobs = new LinkedBlockingQueue<>();
    private final Queue<Task> finishedJobs = new LinkedBlockingQueue<>();
    private Thread readerThread;
    private Thread writerThread;
    private Thread evaluatorThread;
    private volatile boolean running = true;

    private Handler(Socket socket) {
      this.socket = socket;
    }

    @Override
    public void run() {
      String clientAddress = socket.getInetAddress().toString().substring(1);
      logger.info("Client at " + clientAddress + " connected.");
      try (BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()))) {
        try (PrintWriter out = new PrintWriter(socket.getOutputStream(), true)) {
          synchronized (this) {
            readerThread = new Thread(new Reader(in), "reader");
            readerThread.start();
            writerThread = new Thread(new Writer(out), "writer");
            writerThread.start();
            evaluatorThread = new Thread(new Evaluator(), "evaluator");
            evaluatorThread.start();
            while (running) {
              wait();
            }
          }
        }
      } catch (IOException | InterruptedException e) {
        e.printStackTrace();
      }
      readerThread.interrupt();
      writerThread.interrupt();
      evaluatorThread.interrupt();
      try {
        readerThread.join();
        writerThread.join();
        evaluatorThread.join();
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
      logger.info("Client at " + clientAddress + " disconnected.");
    }

    private synchronized void shutdown() {
      running = false;
      notify();
    }

    private class Evaluator implements Runnable {
      @Override
      public void run() {
        logger.info("Initializing...");
        try {
          while (running) {
            Task task = getTask();
            logger.info(task + " started.");
            Boolean res = func.apply(task.getX());
            if (res != null) {
              task.setRes(res);
              logger.info(task + " finished.");
              putTask(task);
            } else {
              logger.info(task + " was interrupted.");
            }
          }
        } catch (InterruptedException ignored) {
        }
        logger.info("Shutting down...");
        shutdown();
      }

      private Task getTask() throws InterruptedException {
        synchronized (newJobs) {
          while (newJobs.isEmpty()) {
            newJobs.wait();
          }
          return newJobs.remove();
        }
      }

      private void putTask(Task t) {
        synchronized (finishedJobs) {
          finishedJobs.add(t);
          finishedJobs.notifyAll();
        }
      }
    }

    private class Writer implements Runnable {
      private final Logger logger = ThreadLogger.of(Writer.class);
      private final PrintWriter writer;

      private Writer(PrintWriter writer) {
        this.writer = writer;
      }

      @Override
      public void run() {
        logger.info("Initializing...");
        try {
          while (true) {
            Task task = getTask();
            writer.println(task.isRes());
            logger.info(task + " sent.");
          }
        } catch (InterruptedException ignored) {
        }
        logger.info("Shutting down...");
        shutdown();
      }

      private Task getTask() throws InterruptedException {
        synchronized (finishedJobs) {
          while (finishedJobs.isEmpty()) {
            finishedJobs.wait();
          }
          return finishedJobs.remove();
        }
      }
    }

    private class Reader implements Runnable {
      private final Logger logger = ThreadLogger.of(Reader.class);
      private final BufferedReader reader;

      private Reader(BufferedReader reader) {
        this.reader = reader;
      }

      @Override
      public void run() {
        logger.info("Initializing...");
        try {
          String msg;
          while ((msg = reader.readLine()) != null) {
            if (msg.equals("kill")) {
              evaluatorThread.interrupt();
            } else {
              synchronized (newJobs) {
                Task task = Task.of(msg);
                logger.info(task + " received.");
                newJobs.add(task);
                newJobs.notifyAll();
              }
            }
          }
        } catch (IOException ignored) {
        }
        logger.info("Shutting down...");
        shutdown();
      }
    }
  }

  private static class Task {
    private static int taskId;
    private final int id;
    private final String x;

    private Boolean res;

    private Task(int id, String x) {
      this.id = id;
      this.x = x;
    }

    public static synchronized Task of(String x) {
      return new Task(taskId++, x);
    }

    public int getId() {
      return id;
    }

    public String getX() {
      return x;
    }

    public Boolean isRes() {
      return res;
    }

    public void setRes(boolean res) {
      this.res = res;
    }

    @Override
    public String toString() {
      return "Task{" + "id=" + id + ", x=" + x + (res != null ? ", res=" + res : "") + '}';
    }
  }
}
