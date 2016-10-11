package io.github.lionell.lab3;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import static com.google.common.truth.Truth.assertThat;

/** Created by lionell on 10/4/16. */
@RunWith(JUnit4.class)
public class CppTest {
  @Test
  public void testSimple() {
    assertThat(true).isTrue();
  }
}
