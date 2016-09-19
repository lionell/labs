package io.github.lionell.lab1;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import java.util.Set;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class CliquesFinderTest {
  @Test
  public void testFindWithMaxDistanceEqualsTwo() {
    CliquesFinder finder = new CliquesFinder(ImmutableList.of("aa", "ab", "bb", "ba"));
    Set<Set<String>> cliques = finder.findCliques();
    assertThat(cliques)
        .containsExactly(ImmutableSet.of("aa", "bb"), ImmutableSet.of("ab", "ba"))
        .inOrder();
    // TODO(lionell): Remove this inOrder() call, when GitHub issue is resolved.
    // See https://github.com/google/error-prone/issues/461
  }

  @Test
  public void testFindWithMaxDistanceEqualsOne() {
    CliquesFinder finder = new CliquesFinder(ImmutableList.of("aa", "ab", "ac", "ad"));
    Set<Set<String>> cliques = finder.findCliques();
    assertThat(cliques)
            .containsExactly(ImmutableSet.of("aa", "ab", "ac", "ad"))
            .inOrder();
    // TODO(lionell): Remove this inOrder() call, when GitHub issue is resolved.
    // See https://github.com/google/error-prone/issues/461
  }
}
