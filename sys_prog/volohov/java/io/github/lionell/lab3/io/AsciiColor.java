package io.github.lionell.lab3.io;

/** Created by lionell on 10/6/16. */
public enum AsciiColor {
  GREY("\u001B[30m"),
  RED("\u001B[31m"),
  GREEN("\u001B[32m"),
  BLUE("\u001B[34m"),
  PURPLE("\u001B[35m"),
  CYAN("\u001B[36m"),
  WHITE("\u001B[37m");

  private String asciiCode;

  AsciiColor(String asciiCode) {
    this.asciiCode = asciiCode;
  }

  public String getAsciiCode() {
    return asciiCode;
  }
}
