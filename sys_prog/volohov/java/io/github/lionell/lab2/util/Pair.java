package io.github.lionell.lab2.util;

/** Created by lionell on 10/4/16. */
public class Pair<F, S> {
  private final F f;
  private final S s;

  private Pair(F f, S s) {
    this.f = f;
    this.s = s;
  }

  public static <F, S> Pair<F, S> of(F f, S s) {
    return new Pair<>(f, s);
  }

  public F getFirst() {
    return f;
  }

  public S getSecond() {
    return s;
  }
}
