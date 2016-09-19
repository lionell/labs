package io.github.lionell.lab1.io;

import java.io.*;
import java.util.Arrays;
import java.util.Iterator;

/**
 * Created by lionell on 9/10/16.
 */
public class WordReader implements Iterator<String> {
    private BufferedReader br;
    private Iterator<String> iterator;

    public WordReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    public WordReader(String s) {
        try {
            br = new BufferedReader(new FileReader(s));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private boolean tryFetch() {
        while (iterator == null || !iterator.hasNext()) {
            try {
                String line = br.readLine();
                if (line != null && line.length() > 0) {
                    iterator = Arrays.asList(line.split("\\W+")).iterator();
                } else {
                    return false;
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return true;
    }

    public String next() {
        tryFetch();
        return iterator.next();	
    }

    public boolean hasNext() {
        return tryFetch() && iterator.hasNext();
    }

    public void close() {
        try {
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
