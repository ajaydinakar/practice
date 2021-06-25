import java.util.LinkedList;
class DFSRecursion {
  public static void main(String[] args) {
    System.out.println("Hello world!");
    DFSRecursion dfs=new DFSRecursion();
DFSRecursion.Graph g = dfs.new Graph(11);
 
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
 
        System.out.println("The Depth First Traversal of the graph from 0  is as follows :");
 
        g.DFS(0);
  }
 

  class Graph
  {
    private int v;
    private LinkedList<Integer> adj[];

    Graph(int v)
    {
      this.v =v;
      adj=new LinkedList[v];
      for(int i=0;i<v;i++)
      {
        adj[i]=new LinkedList<>();
      }
    }
void addEdge(int src,int des)
{
  adj[src].add(des);
}
    void DFS_UTILRecursion(int n,boolean nodes[])
    {
nodes[n]=true;
System.out.println(n+ " ");
int a=0;
for(int i=0;i<adj[n].size();i++)
{
a=adj[n].get(i);
  if(!nodes[a])
  {
DFS_UTILRecursion(a,nodes);

  }
}



    }
    void DFS(int n)
{
  boolean already[]=new boolean[v];
  DFS_UTILRecursion(n,already);
}

  }
}
