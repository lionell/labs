package io.github.lionell.lab2;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import static com.google.common.truth.Truth.assertThat;

/** Created by lionell on 10/4/16. */
@RunWith(JUnit4.class)
public class NFATest {
  @Test
  public void testSimple() {
    final String SIGMA = "0123456789+-.";
    final char[] DIGITS = "0123456789".toCharArray();
    NFA.Builder a = new NFA.Builder();
    a.setQ0("q0");
    a.addSigma(SIGMA);
    a.setEpsilon('@');
    a.bind("q0", "q1", "+-@".toCharArray());
    a.bind("q1", "q1", DIGITS);
    a.bind("q1", "q2", '.');
    a.bind("q2", "q3", DIGITS);
    a.bind("q3", "q3", DIGITS);
    a.bind("q1", "q4", DIGITS);
    a.bind("q4", "q3", '.');
    a.bind("q3", "q5", '@');
    a.addFinals("q5");

    NFA.Builder b = new NFA.Builder();
    b.setQ0("q0");
    b.addSigma(SIGMA);
    b.setEpsilon('@');
    b.bind("q0", "q1", "+-@".toCharArray());
    b.bind("q1", "q1", DIGITS);
    b.bind("q1", "q2", '.');
    b.bind("q2", "q3", DIGITS);
    b.bind("q3", "q3", DIGITS);
    b.bind("q1", "q4", DIGITS);
    b.bind("q4", "q3", '.');
    b.addFinals("q3");

    assertThat(a.build().equalsTo(b.build())).isTrue();
  }
}
