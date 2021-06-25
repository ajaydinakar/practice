

import java.util.LinkedList;
import java.util.Stack;
class DFSStack {
  public static void main(String[] args) {
    System.out.println("Hello world!");
     DFSStack dfs=new DFSStack();
DFSStack.Graph g = dfs.new Graph(11);
 
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
    this.v=v;
    adj=new LinkedList[v];
    for(int i=0;i<v;i++)
    {
      adj[i]=new LinkedList<>();
    }
  }

  void addEdge(int src,int dest)
  {
    adj[src].add(dest);
  }

  void DFS(int n)
  {
    boolean nodes[]=new boolean[v];
    Stack<Integer> st=new Stack<>();
    st.push(n);
    int a=0;
    while(!st.empty())
    {
      n=st.peek();
      st.pop();
      if (nodes[n]==false)
      {
      
        System.out.println(n+"");
          nodes[n]=true;
      }
      for(int i=0;i<adj[n].size();i++)
      {
        a=adj[n].get(i);
       if(!nodes[a])
       {
         st.push(a);
       }
      }
    }
  }
}

}
