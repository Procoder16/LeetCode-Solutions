class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int mid;
        while(low <= high){
            mid = (low + high)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(target < nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
    }
};

import java.util.*;

public class Main {

    static void bfs(int n, List<Integer>[] adj) {
        List<Integer> vis = new ArrayList<>(Collections.nCopies(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            if (vis.get(i) == 0) {
                vis.set(i, 1);
                Queue<Integer> q = new LinkedList<>();
                q.add(i);
                while (!q.isEmpty()) {
                    int node = q.poll();
                    System.out.print(node + " ");
                    for (int it : adj[node]) {
                        if (vis.get(it) == 0) {
                            q.add(it);
                            vis.set(it, 1);
                        }
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n, m;
        System.out.print("ENTER THE NUMBER OF NODES:");
        n = sc.nextInt();
        System.out.print("ENTER THE NUMBER OF EDGES:");
        m = sc.nextInt();

        //ADJACENCY LIST
        List<Integer>[] adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }

        System.out.println("ENTER THE PAIRS OF NODES:");
        for (int i = 0; i < m; i++) {
            int u, v;
            u = sc.nextInt();
            v = sc.nextInt();

            adj[u].add(v);
            adj[v].add(u);
        }

        System.out.print("THE BFS TRAVERSAL OF THE GRAPH IS AS FOLLOWS:\n");
        bfs(n, adj);
    }
}