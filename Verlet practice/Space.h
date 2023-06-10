#pragma once
#include "raylib.h"
#include <vector>
#include "Verlet_object.h"
#include "Circle.h"
#include <string>
#include <thread>
using namespace std;

const int GRID_SIZE_X = 40;
const int GRID_SIZE_Y = 40;

struct Grid {
    int indexX;
    int indexY;
    std::vector<Verlet_object*> members;
};

struct Space {
    Grid grid[GRID_SIZE_X][GRID_SIZE_Y];

public:
    void UpdateGridPartitioning() {
        for (int i = 0; i < GRID_SIZE_X; i++) {
            for (int j = 0; j < GRID_SIZE_Y; j++) {
                grid[i][j].indexX = i;
                grid[i][j].indexY = j; 
                grid[i][j].members.clear();
            }
        }

        for (Verlet_object* obj : Verlet_object::objects) {
            int cellX = (obj->current_pos.x / (GetScreenWidth() / GRID_SIZE_X) < 0) ? 0 :
                ((obj->current_pos.x / (GetScreenWidth() / GRID_SIZE_X) >= GRID_SIZE_X) ? GRID_SIZE_X - 1 :
                    obj->current_pos.x / (GetScreenWidth() / GRID_SIZE_X));

            int cellY = (obj->current_pos.y / (GetScreenHeight() / GRID_SIZE_Y) < 0) ? 0 :
                ((obj->current_pos.y / (GetScreenHeight() / GRID_SIZE_Y) >= GRID_SIZE_Y) ? GRID_SIZE_Y - 1 :
                    obj->current_pos.y / (GetScreenHeight() / GRID_SIZE_Y));
            grid[cellX][cellY].members.push_back(obj);
        }
    }

    void PerformCollisionDetection() {
        for (int i = 0; i < GRID_SIZE_X; i++) {
            for (int j = 0; j < GRID_SIZE_Y; j++) {
                // Iterate through the objects in the cell
                for (Verlet_object* obj1 : grid[i][j].members) {
                    // Check for collisions with other objects in the same cell
                    for (Verlet_object* obj2 : grid[i][j].members) {
                        if (obj2 != obj1 && CheckCollisionCircles(obj1->current_pos, RADIUS, obj2->current_pos, RADIUS)) {
                            obj1->collide(obj2);
                        }
                    }

                    // Check for collisions with objects in neighboring cells
                    for (int dx = -1; dx <= 1; dx++) {
                        for (int dy = -1; dy <= 1; dy++) {
                            int neighborX = i + dx;
                            int neighborY = j + dy;

                            // Check if the neighbor cell is valid
                            if (IsValidCell(neighborX, neighborY)) {
                                for (Verlet_object* obj2 : grid[neighborX][neighborY].members) {
                                    if (obj2 != obj1 && CheckCollisionCircles(obj1->current_pos, RADIUS, obj2->current_pos, RADIUS)) {
                                        obj1->collide(obj2);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Function to check if a cell index is valid
    bool IsValidCell(int cellX, int cellY) {
        return (cellX >= 0 && cellX < GRID_SIZE_X && cellY >= 0 && cellY < GRID_SIZE_Y);
    }
    void DrawGrid() {
        const int cellWidth = GetScreenWidth() / GRID_SIZE_X;
        const int cellHeight = GetScreenHeight() / GRID_SIZE_Y;

        for (int i = 0; i < GRID_SIZE_X; i++) {
            for (int j = 0; j < GRID_SIZE_Y; j++) {
                int cellX = i * cellWidth;
                int cellY = j * cellHeight;
                DrawRectangleLines(cellX, cellY, cellWidth, cellHeight, GREEN);
             
            }
        }
    }
};