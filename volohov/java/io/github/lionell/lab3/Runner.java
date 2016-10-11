package io.github.lionell.lab3;

import com.google.common.base.Charsets;
import com.google.common.io.Files;

import java.io.File;
import java.io.IOException;

public class Runner {

  public static void main(String[] args) throws IOException {
    if (args.length > 0) {
      String text = Files.toString(new File(args[0]), Charsets.UTF_8);
      System.out.println(Highlighter.highlight(text));
    }
  }
}
