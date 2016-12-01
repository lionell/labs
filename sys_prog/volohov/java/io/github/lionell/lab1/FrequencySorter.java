package io.github.lionell.lab1;

import com.google.common.collect.ImmutableSet;

import java.util.List;

/**
 * Sort list of words based on frequency of vowel letters in words.
 *
 * @author lionell
 */
public class FrequencySorter {
  static void sort(List<String> words) {
    words.sort(FrequencySorter::compare);
  }

  private static boolean isVowel(char c) {
    return ImmutableSet.of('a', 'e', 'i', 'o', 'u', 'y').contains(c);
  }

  private static int count(String a) {
    int vowelCount = 0;
    for (char c : a.toCharArray()) {
      if (isVowel(c)) {
        vowelCount++;
      }
    }
    return vowelCount;
  }

  private static int compare(String a, String b) {
    return count(a) * b.length() - count(b) * a.length();
  }
}
