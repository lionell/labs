package io.github.lionell.lab3;

import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;

/** Created by lionell on 10/6/16. */
public class Highlighter {
  public static String highlight(String text) {
    List<Lexeme> lexemes = new ArrayList<>();

    lexemes.addAll(findLexemes(text, Lexeme.Type.COMMENT));
    lexemes.addAll(findLexemes(text, Lexeme.Type.MACRO));
    lexemes.addAll(findLexemes(text, Lexeme.Type.KEYWORD));
    lexemes.addAll(findLexemes(text, Lexeme.Type.LITERALS));
    lexemes.addAll(findLexemes(text, Lexeme.Type.OPERATOR));
    lexemes.addAll(findLexemes(text, Lexeme.Type.NUMBER));
    lexemes.addAll(findLexemes(text, Lexeme.Type.TYPE));
    lexemes.addAll(findLexemes(text, Lexeme.Type.PUNCTUATION));

    return highlightLexemes(text, lexemes);
  }

  private static List<Lexeme> findLexemes(String text, Lexeme.Type type) {
    Matcher m = type.compilePattern().matcher(text);
    List<Lexeme> lexemes = new ArrayList<>();
    while (m.find()) {
      lexemes.add(new Lexeme(type, m.start(), m.end()));
    }
    return lexemes;
  }

  private static String highlightLexemes(String text, List<Lexeme> lexemes) {
    final String ANSI_RESET = "\u001B[0m";
    StringBuilder builder = new StringBuilder(text);

    lexemes.sort(
        (x, y) ->
            x.getEnd() > y.getEnd() || x.getEnd() == y.getEnd() && x.getStart() < y.getStart()
                ? -1
                : 1);
    int l = text.length();
    for (Lexeme lexeme : lexemes) {
      if (lexeme.getEnd() <= l) {
        builder.insert(lexeme.getEnd(), ANSI_RESET);
        builder.insert(lexeme.getStart(), lexeme.getType().getColor().getAsciiCode());
        l = lexeme.getStart();
      }
    }
    return builder.toString();
  }
}
