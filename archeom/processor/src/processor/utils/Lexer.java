package processor.utils;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;

/**
 * Created by lionell on 24.02.16.
 *
 * @author Ruslan Sakevych
 */
public class Lexer {

    public static ArrayList<String[]> process(String filename) {
        ArrayList<String[]> lexemes = new ArrayList<>();
        BufferedReader reader;
        try {
            reader = new BufferedReader(new FileReader(filename));
            String line;
            while ((line = reader.readLine()) != null) {
                lexemes.add(line.split(" "));
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return lexemes;
    }
}
