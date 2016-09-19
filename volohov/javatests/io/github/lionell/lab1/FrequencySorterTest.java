package io.github.lionell.lab1;

import com.google.common.collect.Lists;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import java.util.List;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class FrequencySorterTest {
  @Test
  public void testSort() {
    List<String> words = Lists.newArrayList("first", "second", "third");
    FrequencySorter.sort(words);
    assertThat(words).containsExactly("first", "third", "second").inOrder();
  }
}
