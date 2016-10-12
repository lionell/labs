package io.github.lionell.lab3;

import com.google.common.base.Joiner;

import java.util.regex.Pattern;

import io.github.lionell.lab3.io.AsciiColor;

/** 
 * Created by lionell on 10/6/16.
 * See https://bitbucket.org/birkenfeld/pygments-main/src/3cd23d2769c633ce67475a7d0c08644ac6536fe1/pygments/lexers/compiled.py?at=default&fileviewer=file-view-default
 */
public class Lexeme {
  private final Type type;
  private final int start;
  private final int end;

  public Lexeme(Type type, int start, int end) {
    this.type = type;
    this.start = start;
    this.end = end;
  }

  public Type getType() {
    return type;
  }

  public int getStart() {
    return start;
  }

  public int getEnd() {
    return end;
  }

  public enum Type {
    SINGLE_COMMENT("//(.|\\n)*?[^\\\\]\\n"),
    MULTILINE_COMMENT("/\\*(.|\\n)*?\\*/"),
    COMMENT(AsciiColor.BLUE, SINGLE_COMMENT.pattern, MULTILINE_COMMENT.pattern),

    MACRO(AsciiColor.WHITE, "#(.|\\n)*?[^\\\\]\\n"),

    STRING("\".*\""),
    CHAR("\'.*\'"),
    LITERALS(AsciiColor.PURPLE, STRING.pattern, CHAR.pattern),

    FLOAT("(\\d+\\.\\d*|\\.\\d+|\\d+)([eE][+-]?\\d+)?"),

    HEX("0x[0-9a-fA-F]+[LlUu]*"),
    OCT("0[0-7]+[LlUu]*"),
    DEC("\\d+[LlUu]*"),
    INTEGER(HEX.pattern, OCT.pattern, DEC.pattern),
    NUMBER(AsciiColor.RED, FLOAT.pattern, INTEGER.pattern),

    KEYWORD(
        AsciiColor.RED,
        "(asm|auto|break|case|catch|const|const_cast|continue|"
            + "default|delete|do|dynamic_cast|else|enum|explicit|export|"
            + "extern|for|friend|goto|if|mutable|namespace|new|operator|"
            + "private|protected|public|register|reinterpret_cast|return|"
            + "restrict|sizeof|static|static_cast|struct|switch|template|"
            + "this|throw|throws|try|typedef|typeid|typename|union|using|"
            + "volatile|virtual|while)"),

    OPERATOR(AsciiColor.CYAN, "[~!%^&*+=|?:<>\\/-]"),
    TYPE(
        AsciiColor.GREEN,
        "(bool|int|uint8|uint16|uint32|uint64|long|float|short|double|char|"
            + "unsigned|signed|void|wchar_t)[*&]?"),
    PUNCTUATION(AsciiColor.WHITE, "[()\\[\\],.;]");
    private final AsciiColor color;
    private final String pattern;

    Type(AsciiColor color, String... patterns) {
      this.color = color;
      this.pattern = "(" + Joiner.on('|').join(patterns) + ")";
    }

    Type(String... patterns) {
      this(AsciiColor.GREY, patterns);
    }

    public AsciiColor getColor() {
      return color;
    }

    public Pattern compilePattern() {
      return Pattern.compile(pattern);
    }
  }
}
