
/*Breadth first search Traversal*/
import java.util.LinkedList;
import java.util.Queue;
class BFSTraversal {
  public static void main(String[] args) {
    System.out.println("Hello world!");
BFSTraversal bfs=new BFSTraversal();
BFSTraversal.Graph g = bfs.new Graph(11);
 
     g.addEdge(0,1);
     g.addEdge(0,2);
     g.addEdge(0,3);
     g.addEdge(0,4);
     g.addEdge(0,5);
     g.addEdge(1,6);
     g.addEdge(6,7);
     g.addEdge(2,8);
     g.addEdge(3,9);
     g.addEdge(4,10);
 
        System.out.println("The Breadth First Traversal of the graph from 0 to 7 is as follows :");
 
        g.BFS(0,7);
  }

  class Graph
  {
    private int v;
    private LinkedList<Integer> adj[];
    private Queue<Integer> queue;

    Graph(int v)
    {
      this.v=v;
      adj=new LinkedList[v];
      for(int i=0;i<v;i++)
      {
        adj[i]=new LinkedList<>();
      }
      queue=new LinkedList<Integer>();  
    }
void addEdge(int src,int des)
{
 
 
 
}
void BFS(int n ,int t)
{
  boolean nodes[]=new boolean[v];
  int a=0;
  nodes[n]=true;
  queue.add(n);
  while(queue.size()!=0)
  {
    if(n==t)
    {break;}
n=queue.poll();
System.out.println(n +" ");
for(int i=0;i<adj[n].size();i++)
{
  a=adj[n].get(i);
  if(!nodes[a])
  {

    nodes[a]=true;
    queue.add(a);
  }

}
  }
}
 }

}
