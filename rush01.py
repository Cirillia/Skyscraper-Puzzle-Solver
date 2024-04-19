def is_valid_solution(grid, clues):
    n = len(grid)

    # Check line-of-sight conditions
    for i in range(n):
        # check from left view
        if clues[i] != 0 and not check_view(grid[i], clues[i]):
            return False
        # check frome right view
        if clues[n + i] != 0 and not check_view(grid[i][::-1], clues[n + i]):
            return False

    # Check column-of-sight conditions
    for i in range(n):
        col = [grid[j][i] for j in range(n)]
        # check from top view
        if clues[3 * n - 1 - i] != 0 and not check_view(col, clues[3 * n - 1 - i]):
            return False
        # check from bottom view
        if clues[2 * n + i] != 0 and not check_view(col[::-1], clues[2 * n + i]):
            return False

    return True

def check_view(buildings, view):
    max_height = 0
    visible_count = 0
    for height in buildings:
        if height > max_height:
            visible_count += 1
            max_height = height
    return visible_count == view

def solve_skyscraper(grid, clues, row=0):
    n = len(grid)

    if row == n:
        # Check if there are duplicated nums whitin columns when all rows fulfill the condition
        for col in range(n):
            if len(set(grid[row][col] for row in range(n))) != n:
                return False
        return is_valid_solution(grid, clues)

    for i in range(n):
        for j in range(i + 1, n):
            grid[row][i], grid[row][j] = grid[row][j], grid[row][i]
            if is_valid_solution(grid, clues) and solve_skyscraper(grid, clues, row + 1):
                return True
            grid[row][i], grid[row][j] = grid[row][j], grid[row][i]  # 回溯

    return False

# Initial grid and clues
grid = [[1, 2, 3, 4], 
        [1, 2, 3, 4],
        [1, 2, 3, 4],
        [1, 2, 3, 4]]
clues = [3, 2, 1, 2, 1, 2, 3, 2, 2, 2, 4, 1, 2, 2, 1, 4]

if solve_skyscraper(grid, clues):
    for row in grid:
        print(row)
else:
    print("No solution found.")

solve_skyscraper(grid, clues, row=0)

