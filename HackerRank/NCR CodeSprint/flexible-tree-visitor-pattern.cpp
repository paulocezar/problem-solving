#include <iostream>
#include <vector>

enum Color {
    RED, GREEN
};

class Tree;
class TreeNode;
class TreeLeaf;

class TreeVis {
public:
    virtual int getResult() = 0;
    virtual void visitNode(TreeNode*) = 0;
    virtual void visitLeaf(TreeLeaf*) = 0;
};

class Tree {
    int value;
    Color color;
    int depth;

public:
    Tree(int value, Color color, int depth) : value(value), color(color), depth(depth) {}
    int getValue() {
        return value;
    }
    Color getColor() {
        return color;
    }
    int getDepth() {
        return depth;
    }
    virtual void accept(TreeVis& visitor) = 0;
};

class TreeNode : public Tree {
    std::vector<Tree*> children;

public:
    TreeNode(int value, Color color, int depth) : Tree(value, color, depth) {}
    void accept(TreeVis& visitor) {
        visitor.visitNode(this);

        for(int i = 0; i < children.size(); ++i) {
            children[i]->accept(visitor);
        }
    }
    void addChild(Tree* child) {
        children.push_back(child);
    }
};

class TreeLeaf : public Tree {

public:
    TreeLeaf(int value, Color color, int depth) : Tree(value, color, depth) {}
    void accept(TreeVis& visitor) {
        visitor.visitLeaf(this);
    }
};


// --- SOLUTION STARTS HERE ---
const long long MOD = 1e9 + 7;

class SumInLeavesVisitor : public TreeVis {
public:
    int getResult() {
        return sum;
    }

    void visitNode(TreeNode* node) {
    }

    void visitLeaf(TreeLeaf* leaf) {
        sum += leaf->getValue();
    }
private:
  int sum = 0;
};


class ProductOfRedNodesVisitor : public TreeVis {
public:
    int getResult() {
        return prod;
    }

    void visitNode(TreeNode* node) {
      doit(node);
    }

    void visitLeaf(TreeLeaf* leaf) {
      doit(leaf);
    }

    void doit(Tree* node) {
      if (node->getColor() == RED) {
        prod *= ((long long) node->getValue());
        prod %= MOD;
      }
    }
private:
  long long prod = 1LL;
};

class FancyVisitor : public TreeVis {
public:
    int getResult() {
        return abs(dif);
    }

    void visitNode(TreeNode* node) {
      if ((node->getDepth() & 1) == 0) {
        dif += node->getValue();
      }
    }

    void visitLeaf(TreeLeaf* leaf) {
      if (leaf->getColor() == GREEN) {
        dif -= leaf->getValue();
      }
    }
private:
  int dif = 0;
};


#include <queue>
#include <iostream>

Tree* solve()
{
    //read the tree from STDIN and return its root as a return value of this function
  int n;
  std::cin >> n;

  std::vector<int> x(n);
  std::vector<int> c(n);
  std::vector<int> pa(n, -1);
  std::vector<int> d(n, -1);

  for (int &v : x) std::cin >> v;
  for (int &v : c) std::cin >> v;

  std::vector<int> gr[n];
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v; u--, v--;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  d[0] = 0;
  pa[0] = 0;
  std::queue<int> q;
  q.push(0);
  std::vector<Tree*> nodes(n);

  while (!q.empty()) {
    int u = q.front(); q.pop();

    if (gr[u].size() == 1) {
      nodes[u] = new TreeLeaf(x[u], c[u] ? GREEN : RED, d[u]);
    } else {
      nodes[u] = new TreeNode(x[u], c[u] ? GREEN : RED, d[u]);
      for (int v : gr[u]) {
        if (pa[v] == -1) {
          pa[v] = u;
          d[v] = d[u] + 1;
          q.push(v);
        }
      }
    }

    if (pa[u] != u) {
      ((TreeNode*)nodes[pa[u]])->addChild(nodes[u]);
    }
  }

  return nodes[0];
}
// --- SOLUTION ENDS HERE ---

int main() {
    Tree* root = solve();
  SumInLeavesVisitor vis1 = SumInLeavesVisitor();
    ProductOfRedNodesVisitor vis2 = ProductOfRedNodesVisitor();
    FancyVisitor vis3 = FancyVisitor();

    root->accept(vis1);
    root->accept(vis2);
    root->accept(vis3);

    int res1 = vis1.getResult();
    int res2 = vis2.getResult();
    int res3 = vis3.getResult();

    std::cout << res1 << std::endl;
    std::cout << res2 << std::endl;
    std::cout << res3 << std::endl;

    return 0;
}
