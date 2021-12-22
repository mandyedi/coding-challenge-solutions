/*
Title: The Labirinth
Tags: hard, pathfinding, BFS, A*
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>

using namespace std;

//
// Custom types
//
class Point {
public:
    Point() = default;
    Point(int x, int y) : x(x), y(y) {}
    float distance(const Point &p) {
        int d = ((p.x - x) * (p.y - y)) + ((p.y - y) * (p.y - y));
        return sqrt(static_cast<float>(d));
    }
    Point operator + (const Point &p) const {
        return Point(x + p.x, y + p.y);
    }
    int x = 0;
    int y = 0;
};

ostream& operator << (ostream &os, const Point &p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

bool operator == (const Point &a, const Point &b) {
  return a.x == b.x && a.y == b.y;
}

bool operator != (const Point &a, const Point &b) {
  return !(a == b);
}

bool operator < (const Point &a, const Point &b) {
  return std::tie(a.x, a.y) < std::tie(b.x, b.y);
}

class Cell {
public:
    Cell() = default;
    Cell(const Point &p, char type) : Position(p), Type(type) {}
    Point Position = Point();
    char Type = '?';
};

template<typename T, typename priority_t>
struct PriorityQueue {
  typedef std::pair<priority_t, T> PQElement;
  std::priority_queue<PQElement, std::vector<PQElement>,
                 std::greater<PQElement>> elements;

  inline bool empty() const {
     return elements.empty();
  }

  inline void put(T item, priority_t priority) {
    elements.emplace(priority, item);
  }

  T get() {
    T best_item = elements.top().second;
    elements.pop();
    return best_item;
  }
};

typedef pair<string, Point> DirPair;

namespace std {
template <> struct hash<Point> {
  typedef Point argument_type;
  typedef std::size_t result_type;
  std::size_t operator()(const Point& id) const noexcept {
    return std::hash<int>()(id.x ^ (id.y << 4));
  }
};
}

class Map {
public:
    Map() = default;
    Map(int width, int height) : Width(width), Height(height) {}

    void Clear() {
        Cells.clear();
    }

    void UpdateCurrentPosition(int x, int y) {
        CurrentPosition.x = x;
        CurrentPosition.y = y;
    }

    void UpdateCellsWithRow(int rowIndex, const string &row) {
        vector<Cell> cells;
        size_t columnSize = row.size();
        for (size_t columnIndex = 0; columnIndex < columnSize; columnIndex++) {
            cells.push_back(Cell(Point(columnIndex, rowIndex), row[columnIndex]));
        }
        Cells.push_back(cells);
    }


    void DebugPrintMapCells() {
        for (int i = 0; i < Height; i++) {
            for (int j = 0; j < Width; j++) {
                if (i == CurrentPosition.y && j == CurrentPosition.x) {
                    cerr << '*';
                }
                else {
                    cerr << Cells[i][j].Type;
                }
            }
            cerr << endl;
        }
        cerr << endl << endl;
    }

    void Explore(bool &didFinishExplore) {
        cerr << "current pos: " << CurrentPosition << endl;
            bool hasValidMove = false;
            for (auto &direction : Directions) {
                cerr << "direction: " << direction.first << " " << direction.second << endl;
                Point nextPos = CurrentPosition + direction.second;
                cerr << "next pos: " << nextPos << endl;
                if (Cells[nextPos.y][nextPos.x].Type == 'C') {
                    Goal = nextPos;
                }
                if (IsMoveValid(nextPos)) {
                    cerr << "next cell: " << Cells[nextPos.y][nextPos.x].Position << endl;
                    hasValidMove = true;
                    Visited[nextPos.y][nextPos.x] = true;
                    PathExplore.push_back(direction.first);
                    cout << direction.first << endl;
                    break;
                }
            }

            if (hasValidMove == false && PathExplore.size() > 0) {
                const string &lastDirectionString = PathExplore.back();
                PathExplore.pop_back();
                string newDirectionString;
                GetOppositeDirectionString(lastDirectionString, newDirectionString);
                cout << newDirectionString << endl;
            }
            else if (PathExplore.size() == 0) {
                didFinishExplore = true;
            }
    }

    void FindShortestPath() {
        Point start(CurrentPosition);
        unordered_map<Point, Point> cameFrom;
        unordered_map<Point, double> costSoFar;
        AStar(start, Goal, cameFrom, costSoFar);
        vector<Point> path;
        path = ReconstructPath(start, Goal, cameFrom);

        for (auto &point : path) {
            cerr << point << endl;
        }

        for (int i = 0; i + 1 < path.size(); i++) {
            const Point &current = path[i];
            const Point &next = path[i+1];
            if (current.x > next.x) {
                Solution.push_back("LEFT");
            }
            else if (current.x < next.x) {
                Solution.push_back("RIGHT");
            }
            else if (current.y > next.y) {
                Solution.push_back("UP");
            }
            else if (current.y < next.y) {
                Solution.push_back("DOWN");
            }
        }

        int currentSize = Solution.size();
        vector<string> solutionBack;
        string oppositeStrig;
        for (int i = Solution.size() - 1; i >= 0 ; i--) {
            GetOppositeDirectionString(Solution[i], oppositeStrig);
            solutionBack.push_back(oppositeStrig);
        }
        Solution.insert(Solution.end(), solutionBack.begin(), solutionBack.end());

        for (auto &direction : Solution) {
            cerr << direction << endl;
        }
    }

    void Finish() {
        cerr << "next move: " << Solution[SolutionIndex] << endl;
        cout << Solution[SolutionIndex] << endl;
        SolutionIndex++;
    }

private:
    int Width = 0;
    int Height = 0;
    Point CurrentPosition;
    Point Goal;
    vector<vector<Cell>> Cells;
    bool Visited[100][200] = {{false}};
    vector<string> PathExplore;
    vector<string> Solution;
    int SolutionIndex = 0;

    const vector<Point> Moves = {Point(0, -1), Point(1, 0), Point(0, 1), Point(-1, 0)};
    const unordered_map<string, Point> Directions = {DirPair("UP", Moves[0]), DirPair("RIGHT", Moves[1]), DirPair("DOWN", Moves[2]), DirPair("LEFT", Moves[3])};

    bool IsMoveValid(const Point &nextPos) {
        if (nextPos.x >= 0 && nextPos.x < Width) {
            if (nextPos.y >= 0 && nextPos.y < Height) {
                bool visited = Visited[nextPos.y][nextPos.x];
                char nextChar = Cells[nextPos.y][nextPos.x].Type;
                if (visited == false && nextChar == '.') {
                    return true;
                }
            }
        }
        return false;
    }

    // todo: refactor
    bool IsMoveValid2(const Point &nextPos) {
        if (nextPos.x >= 0 && nextPos.x < Width) {
            if (nextPos.y >= 0 && nextPos.y < Height) {
                bool visited = Visited[nextPos.y][nextPos.x];
                char nextChar = Cells[nextPos.y][nextPos.x].Type;
                if (nextChar != '#') {
                    return true;
                }
            }
        }
        return false;
    }

    void GetOppositeDirectionString(const string &direction, string &oppositeDirection) {
        if (direction == "UP") {
            oppositeDirection = "DOWN";
        }
        else if (direction == "RIGHT") {
            oppositeDirection = "LEFT";
        }
        else if (direction == "DOWN") {
            oppositeDirection = "UP";
        }
        else if (direction == "LEFT") {
            oppositeDirection = "RIGHT";
        }
    }

    void AStar(const Point &start, const Point &goal, unordered_map<Point, Point> &cameFrom, unordered_map<Point, double> &costSoFar) {
        PriorityQueue<Point, double> frontier;
        frontier.put(start, 0);

        cameFrom[start] = start;
        costSoFar[start] = 0;

        while (!frontier.empty()) {
            Point current = frontier.get();

            if (current == goal) {
                break;
            }

            for (auto &direction : Directions) {
                Point next = current + direction.second;
                if (IsMoveValid2(next)) {
                    double new_cost = costSoFar[current] + 1.0;
                    if (costSoFar.find(next) == costSoFar.end() || new_cost < costSoFar[next]) {
                        costSoFar[next] = new_cost;
                        double priority = new_cost + Heuristic(next, goal);
                        frontier.put(next, priority);
                        cameFrom[next] = current;
                    }
                }
            }
        }
    }

    double Heuristic(const Point &a, const Point &b) {
        return abs(a.x - b.x) + abs(a.y - b.y);
    }

    vector<Point> ReconstructPath(const Point &start, const Point &goal, unordered_map<Point, Point> cameFrom) {
        vector<Point> path;
        Point current = goal;
        while (current != start) {
            path.push_back(current);
            current = cameFrom[current];
        }
        path.push_back(start);
        reverse(path.begin(), path.end());
        return path;
        }
};

int main()
{
    int R = 0; // number of rows.
    int C = 0; // number of columns.
    int A; // number of rounds between the time the alarm countdown is activated and the time the alarm goes off.
    cin >> R >> C >> A; cin.ignore();
    cerr << "R: " << R << " C: " << C << endl;

    Map map(C, R);

    enum class State {Explore, FindShortestPath, Finish};
    State currentState = State::Explore;

    // game loop
    int count = 0;
    while (1) {
        int KR; // row where Kirk is located.
        int KC; // column where Kirk is located.
        cin >> KR >> KC; cin.ignore();
        map.UpdateCurrentPosition(KC, KR);

        map.Clear();
        for (int rowIndex = 0; rowIndex < R; rowIndex++) {
            string ROW; // C of the characters in '#.TC?' (i.e. one line of the ASCII maze).
            cin >> ROW; cin.ignore();
            map.UpdateCellsWithRow(rowIndex, ROW);
        }

        map.DebugPrintMapCells();

        if (currentState == State::Explore) {
            cerr << "state: Explore\n";
            bool didFinishExplore = false;
            map.Explore(didFinishExplore);
            if (didFinishExplore == true) {
                currentState = State::FindShortestPath;
            }
        }

        if (currentState == State::FindShortestPath) {
            cerr << "state: FindShortestPath" << endl;
            map.FindShortestPath();
            currentState = State::Finish;
        }

        if (currentState == State::Finish) {
            cerr << "state: Finish\n";
            map.Finish();
        }
    }
}
