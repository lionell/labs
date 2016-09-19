package io.github.lionell.lab1.util;

import java.util.HashSet;
import java.util.Set;

/**
 * Set of Integers based on HashSet, that supports FP-style.
 *
 * @author lionell
 */
public class IntSet {
  private final Set<Integer> set;

  private IntSet(Set<Integer> set) {
    this.set = new HashSet<>(set);
  }

  public static IntSet of() {
    return new IntSet(new HashSet<>());
  }

  public static IntSet range(int l, int r) {
    IntSet s = IntSet.of();
    for (int i = l; i < r; i++) {
      s.add(i);
    }
    return s;
  }

  public static IntSet of(Set<Integer> s) {
    return new IntSet(s);
  }

  public IntSet add(int x) {
    set.add(x);
    return this;
  }

  public IntSet addAll(Set<Integer> s) {
    set.addAll(s);
    return this;
  }

  public IntSet removeAll(Set<Integer> s) {
    set.removeAll(s);
    return this;
  }

  public IntSet retainAll(Set<Integer> s) {
    set.retainAll(s);
    return this;
  }

  public Set<Integer> toSet() {
    return set;
  }
}
