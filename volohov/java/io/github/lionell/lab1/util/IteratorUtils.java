package io.github.lionell.lab1.util;

import java.util.Iterator;
import java.util.Random;

/**
 * Contains common operations with java.util.Iterator class.
 *
 * @author lionell
 */
public class IteratorUtils {
  public static int getRandom(Iterator<Integer> it, int limit) {
    for (int i = 0; i < new Random(17).nextInt(limit); i++) {
      it.next();
    }
    return it.next();
  }
}
