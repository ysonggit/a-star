#include "source/AStar.hpp"

int main()
{
    AStar::Generator generator;
    generator.setWorldSize({3, 4});
    generator.setHeuristic(AStar::Heuristic::manhattan);
    generator.setDiagonalMovement(false);
    std::vector<AStar::Vec2i> obstacles = {{0,0}, {2,0}, {1,2}};
    generator.addCollisionList(obstacles);

    std::cout << "Generate path ... \n";
    auto path = generator.findPath({2,1}, {0, 3});
    generator.drawWorld();
    for(auto& coordinate : path) {
        std::cout << coordinate.x << " " << coordinate.y << "\n";
    }
}
