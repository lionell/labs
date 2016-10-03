package io.github.lionell.lab2;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

import io.github.lionell.lab2.util.Pair;

/** Created by lionell on 10/4/16. */
public class Checker {
  public static boolean equals(NFA a, NFA b) {
    if (!a.getSigma().equals(b.getSigma()) || a.getEpsilon() != b.getEpsilon()) {
      return false;
    }
    Set<Character> sigma = a.getSigma();

    Pair<Set<String>, Set<String>> q0 = Pair.of(a.getQ0(), b.getQ0());
    Queue<Pair<Set<String>, Set<String>>> q = new LinkedList<>();
    Set<Set<String>> va = new HashSet<>();
    Set<Set<String>> vb = new HashSet<>();
    q.add(q0);
    while (!q.isEmpty()) {
      Pair<Set<String>, Set<String>> p = q.poll();
      if (a.isTerminal(p.getFirst()) != b.isTerminal(p.getSecond())) {
        return false;
      }
      va.add(p.getFirst());
      vb.add(p.getSecond());
      for (char c : sigma) {
        if (!va.contains(a.next(p.getFirst(), c)) || !vb.contains(b.next(p.getSecond(), c))) {
          q.add(Pair.of(a.next(p.getFirst(), c), b.next(p.getSecond(), c)));
        }
      }
    }
    return true;
  }
}
