import java.util.List;
import java.util.ArrayList;
import java.io.Serializable;

public class Node implements Serializable {
    private int id;
    private int time;
    private List<Node> deps;

    public Node(int id) {
        this.id = id;
        this.time = 0;
        this.deps = new ArrayList<>();
    }

    public int getId() {
        return id;
    }

    public int getTime() {
        return time;
    }

    public List<Node> getDeps() {
        return deps;
    }

    public void setTime(int time) {
        this.time = time;
    }

    public void addDep(Node dep) {
        deps.add(dep);
    }
}
