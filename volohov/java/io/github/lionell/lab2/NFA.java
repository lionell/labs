package io.github.lionell.lab2;

import com.google.common.collect.Sets;

import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

import io.github.lionell.lab2.util.Pair;

/** Created by lionell on 10/3/16. */
public class NFA {
  private final Set<Character> sigma;
  private final char epsilon;
  private final String q0;
  private final Map<String, Map<Character, Set<String>>> delta;
  private final Set<String> finals;

  public NFA(
      Set<Character> sigma,
      char epsilon,
      String q0,
      Map<String, Map<Character, Set<String>>> transitions,
      Set<String> finals) {
    this.sigma = sigma;
    this.epsilon = epsilon;
    this.q0 = q0;
    this.delta = transitions;
    this.finals = finals;
  }

  public Set<String> getQ0() {
    return closure(Sets.newHashSet(q0));
  }

  public boolean equalsTo(NFA a) {
    if (!sigma.equals(a.sigma) || epsilon != a.epsilon) {
      return false;
    }

    Pair<Set<String>, Set<String>> q0 = Pair.of(getQ0(), a.getQ0());
    Queue<Pair<Set<String>, Set<String>>> q = new LinkedList<>();
    Set<Set<String>> v1 = new HashSet<>();
    Set<Set<String>> v2 = new HashSet<>();
    q.add(q0);
    while (!q.isEmpty()) {
      Pair<Set<String>, Set<String>> p = q.poll();
      if (isTerminal(p.getFirst()) != a.isTerminal(p.getSecond())) {
        return false;
      }
      v1.add(p.getFirst());
      v2.add(p.getSecond());
      for (char c : sigma) {
        Set<String> n1 = next(p.getFirst(), c);
        Set<String> n2 = a.next(p.getSecond(), c);
        if (!v1.contains(n1) || !v2.contains(n2)) {
          q.add(Pair.of(n1, n2));
        }
      }
    }
    return true;
  }

  private Set<String> closure(Set<String> states) {
    Set<String> res = new HashSet<>(states);
    Set<String> eps = res;
    do {
      eps = move(eps, epsilon);
      res.addAll(eps);
    } while (!eps.isEmpty());
    return res;
  }

  public Set<String> move(Set<String> states, char c) {
    Set<String> res = new HashSet<>();
    for (String state : states) {
      if (delta.containsKey(state) && delta.get(state).containsKey(c)) {
        res.addAll(delta.get(state).get(c));
      }
    }
    return res;
  }

  public Set<String> next(Set<String> states, char c) {
    return closure(move(states, c));
  }

  public boolean isTerminal(Set<String> states) {
    Set<String> intersection = new HashSet<>(finals);
    intersection.retainAll(states);
    return !intersection.isEmpty();
  }

  public static class Builder {
    private Set<Character> sigma = new HashSet<>();
    private char epsilon = '@';
    private String q0;
    private Map<String, Map<Character, Set<String>>> delta = new HashMap<>();
    private Set<String> finals = new HashSet<>();

    public Builder setQ0(String q0) {
      this.q0 = q0;
      return this;
    }

    public Builder setEpsilon(char epsilon) {
      this.epsilon = epsilon;
      return this;
    }

    public Builder addSigma(String sigma) {
      for (char c : sigma.toCharArray()) {
        this.sigma.add(c);
      }
      return this;
    }

    public Builder addFinals(String... finals) {
      this.finals.addAll(Arrays.asList(finals));
      return this;
    }

    public Builder bind(String from, String to, char... chars) {
      for (char c : chars) {
        if (!delta.containsKey(from)) {
          delta.put(from, new HashMap<>());
        }
        if (!delta.get(from).containsKey(c)) {
          delta.get(from).put(c, new HashSet<>());
        }
        delta.get(from).get(c).add(to);
      }
      return this;
    }

    public NFA build() {
      return new NFA(sigma, epsilon, q0, delta, finals);
    }
  }
}
