#include "route_planner.h"
#include <algorithm>

RoutePlanner::RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y) : m_Model(model)
{
    // Convert inputs to percentage:
    start_x *= 0.01;
    start_y *= 0.01;
    end_x *= 0.01;
    end_y *= 0.01;

    start_node = &m_Model.FindClosestNode(start_x, start_y);
    end_node = &m_Model.FindClosestNode(end_x, end_y);
}


float RoutePlanner::CalculateHValue(RouteModel::Node const *node)
{
    // return node->distance(*(this->end_node));
    return node->distance(*end_node);
}

void RoutePlanner::AddNeighbors(RouteModel::Node *current_node)
{
    current_node->FindNeighbors();

    for (auto n : current_node->neighbors)
    {
        n->parent = current_node;
        n->h_value = CalculateHValue(n);
        n->g_value = current_node->g_value + current_node->distance(*n);
        n->visited = true;
        open_list.push_back(n);
    }
}

bool cmpFn(RouteModel::Node *n1, RouteModel::Node *n2)
{
    return (n1->g_value + n1->h_value) > (n2->g_value + n2->h_value);
}
RouteModel::Node *RoutePlanner::NextNode()
{
    std::sort(this->open_list.begin(), this->open_list.end(), &cmpFn);
    RouteModel::Node *nodeWithLowestSum = this->open_list.back();

    this->open_list.pop_back();

    return nodeWithLowestSum;
}

std::vector<RouteModel::Node> RoutePlanner::ConstructFinalPath(RouteModel::Node *current_node)
{
    // Create path_found vector
    this->distance = 0.0f;
    std::vector<RouteModel::Node> path_found;

    // TODO: Implement your solution here.
    while (current_node != nullptr)
    {
        path_found.push_back(*current_node);

        if (current_node->parent != nullptr)
            this->distance += current_node->distance(*(current_node->parent));

        current_node = current_node->parent;
    }

    this->distance *= m_Model.MetricScale(); // Multiply the distance by the scale of the map to get meters.

    std::reverse(path_found.begin(), path_found.end());

    return path_found;
}

void RoutePlanner::AStarSearch()
{
    RouteModel::Node *current_node = nullptr;

    // TODO: Implement your solution here.
    this->start_node->visited = true;
    this->open_list.push_back(this->start_node);

    while (open_list.size() > 0)
    {
        current_node = this->NextNode();
        if(current_node->distance(*(this->end_node)) == 0)
        {
            m_Model.path = this->ConstructFinalPath(current_node);
            return;
        }
        else 
        {
            this->AddNeighbors(current_node);
        }
    }
}
