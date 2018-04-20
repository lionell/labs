import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.io.File;
import parcs.*;

public class Bluck {
    public static void main(String[] args) throws Exception {
        task curtask = new task();
        curtask.addJarFile("DFS.jar");
        Node n = fromFile(curtask.findFile("input"));

        AMInfo info = new AMInfo(curtask, null);
        point p = info.createPoint();
        channel c = p.createChannel();
        p.execute("DFS");
        c.write(n);

        System.out.println("Waiting for result...");
        System.out.println("Result: " + c.readLong());
        curtask.end();
    }

    public static Node fromFile(String filename) throws Exception {
        Scanner sc = new Scanner(new File(filename));
        int m = sc.nextInt();
        int s = sc.nextInt();
        List<Node> nodes = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            nodes.add(new Node(i + 1));
        }
        for (Node n: nodes) {
            n.setTime(sc.nextInt());
            int k = sc.nextInt();
            for (int j = 0; j < k; j++) {
                n.addDep(nodes.get(sc.nextInt() - 1));
            }
        }
        return nodes.get(s);
    }
}
