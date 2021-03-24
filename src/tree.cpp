#include "tree.hpp"

Tree::Tree(const Geometry::Point& p)
{
    root = new Node(std::vector<Node *>(), nullptr, p, 0);
    cloud.pts.clear();
    cloud.pts.push_back(Tree::Point{p.x, p.y, root});
    index = new kdTree(2, cloud, nanoflann::KDTreeSingleIndexAdaptorParams(10));
    used.clear();
    rootState = nullptr;
}

void Tree::deleteTree(Node *root)
{
    if (!root) return;
    for (Node *n: root->childrens) {
        deleteTree(n);
        delete n;
    }
}

Tree::~Tree()
{
    delete index;
    deleteTree(root);
}

Tree::Node *Tree::getNearest(const Geometry::Point& p) const
{
    const size_t numResults = 1;
    size_t resIndex;
    double outDistSqr;
    double queryPt[2] = {p.x, p.y};
    nanoflann::KNNResultSet<double> resultSet(numResults);
    resultSet.init(&resIndex, &outDistSqr);
    index->findNeighbors(resultSet, queryPt, nanoflann::SearchParams());
    return cloud.pts[resIndex].link;
}

Tree::Node *Tree::insert(Tree::Node *node, const Geometry::Point& p)
{
    double distance = Geometry::euclideanMetric(node->point, p) + node->distance;
    if (used.find(p.x) != used.end() && used[p.x].find(p.y) != used[p.x].end()) {
        return nullptr;
    }
    Node *newNode = new Node(std::vector<Node *>(), node, p, distance);
    node->childrens.push_back(newNode);
    cloud.pts.push_back(Tree::Point{p.x, p.y, newNode});
    index->addPoints(cloud.pts.size() - 1, cloud.pts.size() - 1);
    return newNode;
}

void Tree::printNode(const Tree::Node *node, std::ostream& out)
{
    nodePrintStateT* parentState;
    if (rootState != nullptr) {
        out << " ";
        nodePrintStateT* s = rootState;
        while (s->childState != nullptr) {
            out << (s->printingLastChild ? "  " : "| ");
            s = s->childState;
        }
        parentState = s;
        out << (parentState->printingLastChild ? "L" : "+");
    } else {
        parentState = nullptr;
    }
    out << '>' << node->point << '\n';
    if (!node->childrens.empty()) {
        nodePrintStateT s;
        if (parentState != nullptr) {
            parentState->childState = &s;
        } else {
            rootState = &s;
        }
        s.childState = nullptr;
        for (size_t i = 0; i < node->childrens.size(); ++i) {
            if (i == node->childrens.size() - 1) {
                s.printingLastChild = true;
                printNode(node->childrens[i], out);
            } else {
                s.printingLastChild = false;
                printNode(node->childrens[i], out);
            }
        }
        if (parentState != nullptr) {
           parentState->childState = nullptr;
        } else {
            rootState = nullptr;
        }
    }
}

void Tree::printTree(std::ostream& out)
{
    printNode(root, out);
}