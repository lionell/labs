package io.github.lionell.lab1;

import com.google.common.collect.ImmutableSet;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

import io.github.lionell.lab1.util.IntSet;
import io.github.lionell.lab1.util.IteratorUtils;

/**
 * Finds all maximum cliques in graph based on Hamming distance between words. Edge between two
 * words exists iff distance is equal to maximal one(for whole graph G).
 *
 * @author lionell
 */
public class CliquesFinder {
  private final List<String> words;
  private final List<Set<Integer>> g;
  private final Set<Set<Integer>> ans = new HashSet<>();

  public CliquesFinder(List<String> words) {
    this.words = words;
    g = createGraph();
  }

  Set<Set<String>> findCliques() {
    find(IntSet.of().toSet(), IntSet.range(0, words.size()).toSet(), IntSet.of().toSet());
    return generateResult();
  }

  private void find(Set<Integer> r, Set<Integer> p, Set<Integer> x) {
    if (p.isEmpty()) {
      if (x.isEmpty() && r.size() > 1) {
          ans.add(ImmutableSet.copyOf(r));
      }
      return;
    }

    int u = IteratorUtils.getRandom(p.iterator(), p.size());
    for (int v : IntSet.of(p).addAll(x).removeAll(g.get(u)).toSet()) {
      find(
          IntSet.of(r).add(v).toSet(),
          IntSet.of(p).retainAll(g.get(v)).toSet(),
          IntSet.of(x).retainAll(g.get(v)).toSet());
      p.remove(v);
      x.add(v);
    }
  }

  private List<Set<Integer>> createGraph() {
    int maxDistance = findMaxDistance();
    System.out.println("Max distance = " + maxDistance);
    List<Set<Integer>> g = new ArrayList<>();
    for (int i = 0; i < words.size(); i++) {
      g.add(new HashSet<>());
    }
    for (int i = 0; i < words.size(); i++) {
      for (int j = i + 1; j < words.size(); j++) {
        if (distance(words.get(i), words.get(j)) == maxDistance) {
          g.get(i).add(j);
          g.get(j).add(i);
        }
      }
    }
    return g;
  }

  private int findMaxDistance() {
    int res = 0;
    for (int i = 0; i < words.size(); i++) {
      for (int j = i + 1; j < words.size(); j++) {
        res = Math.max(res, distance(words.get(i), words.get(j)));
      }
    }
    return res;
  }

  private static int distance(String a, String b) {
    int res = Math.abs(a.length() - b.length());
    for (int i = 0; i < Math.min(a.length(), b.length()); i++) {
      if (a.charAt(i) != b.charAt(i)) {
        res++;
      }
    }
    return res;
  }

  private Set<Set<String>> generateResult() {
    Set<Set<String>> res = new HashSet<>();
    for (Set<Integer> v : ans) {
      res.add(v.stream().map(words::get).collect(Collectors.toSet()));
    }
    return res;
  }
}
