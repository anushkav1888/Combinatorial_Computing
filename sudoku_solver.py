import z3

def solve_sudoku(puzzle):
    grid = [[z3.Int(f"cell_{i}_{j}") for j in range(9)] for i in range(9)]

  
    solver = z3.Solver()

    for i in range(9):
        for j in range(9):
            solver.add(z3.And(grid[i][j] >= 1, grid[i][j] <= 9))

  
    for i in range(9):
        solver.add(z3.Distinct([grid[i][j] for j in range(9)] ))


    for j in range(9):
        solver.add(z3.Distinct([grid[i][j] for i in range(9)]))

    
    for i in range(0, 9, 3):
        for j in range(0, 9, 3):
            solver.add(z3.Distinct([grid[row][col] for row in range(i, i+3) for col in range(j, j+3)]))

 
    for i in range(9):
        for j in range(9):
            if puzzle[i][j] != 0:
                solver.add(grid[i][j] == puzzle[i][j])

  
    if solver.check() == z3.sat:
        model = solver.model()
        solution = [[model.evaluate(grid[i][j]).as_long() for j in range(9)] for i in range(9)]
        return solution
    else:
        return None
 

inputarr = list(map(int,input().split()))
puzzle = []
for i in range(9):
    puzzle.append(inputarr[9*i:9*i+9])


solution = solve_sudoku(puzzle)


if solution is not None:
    for row in solution:
        print(row)
else:
    print(-1)
