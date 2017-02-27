#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

namespace std {   };
using namespace std;

istream& operator>>(istream& is, vector<vector<size_t> >& graph)
{
   size_t i = 0, j = 0;

   is >> i;
   graph.resize(i);

   while (is >> i >> j)
   {
      --i; --j;
      if (i != j)
      {
         graph[i].push_back(j);
      }
   }

   return is;
}

void topological_sort_using_DFS(vector<vector<size_t> >& graph, vector<bool>& explored, size_t i, vector<size_t>& sorted, size_t& t)
{
   explored[i] = true;

   for (size_t j = 0; j < graph[i].size(); ++j)
   {
      if (explored[graph[i][j]] == false)
      {
         topological_sort_using_DFS(graph, explored, graph[i][j], sorted, t);
      }
   }

   --t;
   sorted[t] = i;

   return;
}

void topological_sort_using_DFS_loop(vector<vector<size_t> >& graph, vector<size_t>& sorted)
{
   vector<bool> explored(graph.size(), false);
   size_t t = graph.size();

   for (size_t i = 0; i < graph.size(); ++i)
   {
      if (explored[i] == false)
      {
         topological_sort_using_DFS(graph, explored, i, sorted, t);
      }
   }

   assert(t == 0);

   return;
}

int main(int argc, char* argv[])
{
   vector<vector<size_t> > graph;

   if (argc > 1)
   {
      ifstream ifs;
               ifs.open(argv[1]);

      ifs >> graph;

      ifs.close();
   }

   assert(graph.size() == 7);

   vector<size_t> sorted(graph.size(), 0);
   topological_sort_using_DFS_loop(graph, sorted);

   cout << "Input Graph Size: " << graph.size() << endl
        << "Possible Topological sorted order: ";
   for (size_t i = 0; i < sorted.size(); ++i)
   {
      cout << (sorted[i] + 1) << ", ";
   }

   cout << endl;

   cin.get();

   return 0;
}
